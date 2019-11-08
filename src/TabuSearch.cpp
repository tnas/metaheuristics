#include "TabuSearch.h"

TabuSearch::TabuSearch(DataSet* dataSet, unsigned int iterations, unsigned int movements) : Metaheuristic(iterations, movements)
{
    this->dataSet = dataSet;
    this->movementSolutions = new unsigned int*[this->numberOfMovements];
    for (unsigned int m = 0; m < this->numberOfMovements; ++m)
        this->movementSolutions[m] = new unsigned int[this->dataSet->getSolutionSize()];
    this->movFunctionVals = new double[this->numberOfMovements];
}

TabuSearch::~TabuSearch()
{
    for (unsigned int m = 0; m < this->numberOfMovements; ++m)
        delete(this->movementSolutions[m]);
    delete(this->movementSolutions);
    delete(this->movFunctionVals);
}

void TabuSearch::run()
{
    unsigned int iteration = 0;
    this->currentSolution = this->dataSet->getInitialSolution();
    this->currentFunctionVal = this->dataSet->applyObjectiveFunction(currentSolution);
    this->printSolution();

    vector<vector<int>> tabuList;

    while (iteration < this->maxIterations)
    {
        iteration++;
        int* movements = this->dataSet->generateMovements(this->numberOfMovements);
        int bestIterSolution = -1;

        for (unsigned int m = 0; m < this->numberOfMovements; ++m)
        {
            bool isMovementInTabuList = false;
            for (vector<int> mov : tabuList)
            {
                if (mov.at(0) == movements[2*m] && mov.at(1) == movements[2*m+1])
                {
                    isMovementInTabuList = true;
                    break;
                }
            }
            if (isMovementInTabuList) continue;

            this->dataSet->applyMovement(movements[2*m], movements[2*m+1], this->currentSolution, this->movementSolutions[m]);
            this->movFunctionVals[m] = this->dataSet->applyObjectiveFunction(this->movementSolutions[m]);

            if (this->dataSet->isImprovement(this->movFunctionVals[m], this->currentFunctionVal))
                bestIterSolution = m;
        }

        if (bestIterSolution != -1)
        {
            this->currentFunctionVal = this->movFunctionVals[bestIterSolution];
            cout << "Before: ";
            for (unsigned int obj = 0; obj < this->dataSet->getSolutionSize(); ++obj)
                cout << this->currentSolution[obj];
            cout << endl;
            memcpy(this->currentSolution, this->movementSolutions[bestIterSolution], this->dataSet->getSolutionSize()*sizeof(unsigned int));
            cout << "After: ";
            for (unsigned int obj = 0; obj < this->dataSet->getSolutionSize(); ++obj)
                cout << this->currentSolution[obj];
            cout << endl;
            vector<int> movement { movements[2*bestIterSolution], movements[2*bestIterSolution+1], TabuSearch::TABU_LIST_TIME };
            tabuList.push_back(movement);
        }

        // Updating tabu list
        int tabuPosition = 0;
        for (vector<int> mov : tabuList)
        {
            --mov.at(2);
            if (mov.at(2) == 0)
                tabuList.erase(tabuList.begin() + tabuPosition);
            ++tabuPosition;
        }

        delete(movements);
    }
}

void TabuSearch::printSolution()
{
    cout << "Final Solution: " << this->dataSet->solutionToString(this->currentSolution) << endl;
    cout << "Final Value: " << this->currentFunctionVal << endl;
}
