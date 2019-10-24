#include "TabuSearch.h"

TabuSearch::TabuSearch(const DataSet* dataSet, unsigned int iterations)
{
    this->maxIterations = iterations;
    this->dataSet = dataSet;
}

TabuSearch::~TabuSearch()
{
    //dtor
}
