#include "DataSet.h"

DataSet::DataSet(unsigned int dimension, unsigned int solutionSize)
{
    this->dimension = dimension;
    this->solutionSize = solutionSize;
    this->initialSolution = new unsigned int[this->solutionSize];
}

DataSet::~DataSet()
{
    for (unsigned int row = 0; row < this->dimension; ++row)
    {
        delete(this->costs[row]);
    }

    delete(this->costs);
    delete(this->initialSolution);
}

float** DataSet::getCosts() const
{
    return this->costs;
}

unsigned int* DataSet::getInitialSolution() const
{
    return this->initialSolution;
}

unsigned int DataSet::getSolutionSize()
{
    return this->solutionSize;
}

unsigned int DataSet::getDimension()
{
    return this->dimension;
}
