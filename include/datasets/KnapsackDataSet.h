#ifndef KNAPSACKDATASET_H
#define KNAPSACKDATASET_H

#include "DataSet.h"

class KnapsackDataSet : public DataSet
{
    public:
        enum Object { Weight, Value };

        KnapsackDataSet() : DataSet(KnapsackDataSet::DIMENSION, KnapsackDataSet::DIMENSION)
        {
            this->buildCostsMatrix();
            this->buildInitialSolution();
        };

        void buildCostsMatrix();
        void buildInitialSolution();
        double getKnapsackWeight(unsigned int* solution);
        double applyObjectiveFunction(unsigned int* solution);
        void applyMovement(unsigned int from, unsigned int to,
                           unsigned int* solution, unsigned int* newSolution);
        bool isImprovement(double iterationValue, double bestValue);
        int* generateMovements(unsigned int numberOfMoves);
        string solutionToString(unsigned int* solution);

    protected:

    private:
        const static unsigned int DIMENSION = 15;
        const static unsigned int MAX_WEIGHT = 275;
};

#endif // KNAPSACKDATASET_H
