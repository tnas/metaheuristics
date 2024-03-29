#ifndef TSPSTARDATASET_H
#define TSPSTARDATASET_H

#include "DataSet.h"

class TSPStarDataSet : public DataSet
{
    public:
        enum City { A, B, C, D, E, F, G, H, I, J };

        TSPStarDataSet() : DataSet(TSPStarDataSet::DIMENSION, TSPStarDataSet::SOLUTION_SIZE)
        {
            this->buildCostsMatrix();
            this->buildInitialSolution();
        };

        void buildCostsMatrix();
        void buildInitialSolution();
        double applyObjectiveFunction(unsigned int* solution);
        void applyMovement(unsigned int from, unsigned int to,
                           unsigned int* solution, unsigned int* newSolution);
        bool isImprovement(double iterationValue, double bestValue);
        int* generateMovements(unsigned int numberOfMoves);
        string solutionToString(unsigned int* solution);

    protected:

    private:
        const static unsigned int DIMENSION = 10;
        const static unsigned int SOLUTION_SIZE = 11;
};

#endif // TSPSTARDATASET_H
