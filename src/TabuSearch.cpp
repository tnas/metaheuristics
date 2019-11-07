#include "TabuSearch.h"


void TabuSearch::run()
{
    unsigned int iteration = 0;
    this->dataSet->buildInitialSolution();
    unsigned int* currentSolution = this->dataSet->getInitialSolution();
    cout << "Initial Solution: ";
    this->printSolution(currentSolution);
    cout << "9,3 (cost): " << this->dataSet->getCosts()[9][3] << endl;

    double currentFunctionVal = this->applyObjectiveFunction(currentSolution);
    cout << "Initial Value: " << currentFunctionVal << endl;

    // Allocating movementSolutions
    unsigned int** movementSolutions = new unsigned int*[this->numberOfMovements];
    for (unsigned int m = 0; m < this->numberOfMovements; ++m)
        movementSolutions[m] = new unsigned int[this->dataSet->getSolutionSize()];
    double* movFunctionVals = new double[this->numberOfMovements];

    while (iteration < this->maxIterations)
    {
        iteration++;
        int* movements = this->dataSet->generateMovements(this->numberOfMovements);
        int bestIterSolution = -1;

        for (unsigned int m = 0; m < this->numberOfMovements; ++m)
        {
            this->applyMovement(movements[2*m], movements[2*m+1], currentSolution, movementSolutions[m]);
            cout << "Movement: (" << movements[2*m] << ", " << movements[2*m+1] << ")" << endl;
            cout << "Movement Solution " << m << ": ";
            this->printSolution(movementSolutions[m]);
            movFunctionVals[m] = this->applyObjectiveFunction(movementSolutions[m]);

            if (movFunctionVals[m] < currentFunctionVal)
                bestIterSolution = m;
        }

        if (bestIterSolution != -1)
        {
            currentFunctionVal = movFunctionVals[bestIterSolution];
            memcpy(currentSolution, movementSolutions[bestIterSolution], this->dataSet->getSolutionSize()*sizeof(unsigned int));
        }

        delete(movements);
    }

    // Deallocating movementSolutions
    for (unsigned int m = 0; m < this->numberOfMovements; ++m)
        delete(movementSolutions[m]);
    delete(movementSolutions);
    delete(movFunctionVals);

    // Printing solution
    cout << "Final Solution: ";
    this->printSolution(currentSolution);
}

double TabuSearch::applyObjectiveFunction(unsigned int* solution)
{
    double functionValue = 0;

    for (unsigned int i = 0; i < this->dataSet->getSolutionSize()-1; ++i)
    {
        cout << "Summing (" << solution[i] << ", " << solution[i+1] << "): " <<
        this->dataSet->getCosts()[solution[i]][solution[i+1]] << endl;
        functionValue += this->dataSet->getCosts()[solution[i]][solution[i+1]];
    }

    return functionValue;
}

void TabuSearch::applyMovement(unsigned int from, unsigned int to, unsigned int* solution, unsigned int* newSolution)
{
    for (unsigned int i = 0; i < this->dataSet->getSolutionSize(); ++i)
    {
        if (solution[i] == from)
        {
            newSolution[i] = to;
        }
        else if (solution[i] == to)
        {
            newSolution[i] = from;
        }
        else
        {
            newSolution[i] = solution[i];
        }
    }
}

void TabuSearch::printSolution(unsigned int* solution)
{
    for (unsigned int i = 0; i < this->dataSet->getSolutionSize(); ++i)
        cout << solution[i] << " ";
    cout << endl;
}

