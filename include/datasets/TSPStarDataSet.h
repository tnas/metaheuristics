#ifndef TSPSTARDATASET_H
#define TSPSTARDATASET_H

#include "DataSet.h"

class TSPStarDataSet : public DataSet
{
    public:
        enum City { A, B, C , D, E , F, G, H , I, J};

        TSPStarDataSet() : DataSet(DIMENSION, SOLUTION_SIZE) {};
        void buildCostsMatrix();
        void buildInitialSolution();

    protected:

    private:
        const unsigned int DIMENSION = 10;
        const unsigned int SOLUTION_SIZE = 11;
};

#endif // TSPSTARDATASET_H
