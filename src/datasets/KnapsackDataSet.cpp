#include "KnapsackDataSet.h"

void KnapsackDataSet::buildCostsMatrix()
{
    this->costs = new float*[this->dimension];
    for (unsigned int row = 0; row < this->dimension; ++row)
    {
        this->costs[row] = new float[2];
    }

    this->costs[0][Object::Weight] = 63;
    this->costs[0][Object::Value] = 13;

    this->costs[1][Object::Weight] = 21;
    this->costs[1][Object::Value] = 2;

    this->costs[2][Object::Weight] = 2;
    this->costs[2][Object::Value] = 20;

    this->costs[3][Object::Weight] = 32;
    this->costs[3][Object::Value] = 10;

    this->costs[4][Object::Weight] = 13;
    this->costs[4][Object::Value] = 7;

    this->costs[5][Object::Weight] = 80;
    this->costs[5][Object::Value] = 14;

    this->costs[6][Object::Weight] = 19;
    this->costs[6][Object::Value] = 7;

    this->costs[7][Object::Weight] = 37;
    this->costs[7][Object::Value] = 2;

    this->costs[8][Object::Weight] = 56;
    this->costs[8][Object::Value] = 2;

    this->costs[9][Object::Weight] = 41;
    this->costs[9][Object::Value] = 4;

    this->costs[10][Object::Weight] = 14;
    this->costs[10][Object::Value] = 16;

    this->costs[11][Object::Weight] = 8;
    this->costs[11][Object::Value] = 17;

    this->costs[12][Object::Weight] = 32;
    this->costs[12][Object::Value] = 17;

    this->costs[13][Object::Weight] = 42;
    this->costs[13][Object::Value] = 3;

    this->costs[14][Object::Weight] = 7;
    this->costs[14][Object::Value] = 21;
}

void KnapsackDataSet::buildInitialSolution()
{
    srand((unsigned) time(0));
    unsigned int knapsackWeight = 0;

    for (unsigned int obj = 0; obj < this->solutionSize; ++obj)
        this->initialSolution[obj] = 0;

    while (knapsackWeight < KnapsackDataSet::MAX_WEIGHT)
    {
        unsigned int obj = std::rand() % KnapsackDataSet::DIMENSION;
        this->initialSolution[obj] = 1;
        knapsackWeight += this->costs[obj][Object::Weight];
    }
}

double KnapsackDataSet::getKnapsackWeight(unsigned int* solution)
{
    double totalWeight = 0;

    for (unsigned int obj = 0; obj < this->solutionSize; ++obj)
    {
        if (solution[obj] == 1) totalWeight += this->costs[obj][Object::Weight];
    }

    return totalWeight;
}

double KnapsackDataSet::applyObjectiveFunction(unsigned int* solution)
{
    double functionValue = 0;

    for (unsigned int obj = 0; obj < this->solutionSize; ++obj)
    {
        if (solution[obj] == 1) functionValue += this->costs[obj][Object::Value];
    }

    return functionValue;
}

int* KnapsackDataSet::generateMovements(unsigned int numberOfMoves)
{
    int* movements = new int[2*numberOfMoves]; // pair numbers (2n, 2n+1)

    for (unsigned int m = 0; m < numberOfMoves; ++m)
    {
        movements[2*m] = movements[2*m+1] = std::rand() % KnapsackDataSet::DIMENSION;

        while (movements[2*m] == movements[2*m+1])
        {
            movements[2*m+1] = std::rand() % KnapsackDataSet::DIMENSION;
        }
    }

    return movements;
}

void KnapsackDataSet::applyMovement(unsigned int from, unsigned int to, unsigned int* solution, unsigned int* newSolution)
{
    memcpy(newSolution, solution, this->solutionSize*sizeof(unsigned int));
    newSolution[from] = !newSolution[from];
    newSolution[to] = !newSolution[to];

    if (this->getKnapsackWeight(newSolution) > KnapsackDataSet::MAX_WEIGHT)
    {
        // Undo the movement
        newSolution[from] = !newSolution[from];
        newSolution[to] = !newSolution[to];
    }
}

bool KnapsackDataSet::isImprovement(double iterationValue, double bestValue)
{
    return iterationValue > bestValue;
}

string KnapsackDataSet::solutionToString(unsigned int* solution)
{
    string strSolution = "";
    unsigned int weightFinal = 0;

    for (unsigned int obj = 0; obj < this->solutionSize; ++obj)
    {
        if (solution[obj] == 1)
        {
            strSolution += to_string(obj+1) + " ";
            weightFinal += this->costs[obj][Object::Weight];
        }
    }

    strSolution += "\nTotal Weight: " + to_string(weightFinal);

    return strSolution;
}
