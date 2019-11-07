#ifndef TSPSTARDATASET_H
#define TSPSTARDATASET_H

#include "DataSet.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class TSPStarDataSet : public DataSet
{
    public:
        enum City { A, B, C, D, E, F, G, H, I, J };

        TSPStarDataSet() : DataSet(TSPStarDataSet::DIMENSION, TSPStarDataSet::SOLUTION_SIZE) {};
        void buildCostsMatrix();
        void buildInitialSolution();
        int* generateMovements(unsigned int numberOfMoves);

    protected:

    private:
        const static unsigned int DIMENSION = 10;
        const static unsigned int SOLUTION_SIZE = 11;
};

#endif // TSPSTARDATASET_H
