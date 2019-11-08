#ifndef DATASET_H
#define DATASET_H

#include <string>

using namespace std;

class DataSet
{
    public:
        DataSet(unsigned int dimension, unsigned int solutionSize);
        virtual ~DataSet();
        float** getCosts() const;
        unsigned int* getInitialSolution() const;
        unsigned int getSolutionSize();
        unsigned int getDimension();
        virtual void buildCostsMatrix() = 0;
        virtual void buildInitialSolution() = 0;
        virtual int* generateMovements(unsigned int numberOfMoves) = 0;
        virtual string solutionToString(unsigned int* solution) = 0;

    protected:
        float** costs;
        unsigned int* initialSolution;
        unsigned int dimension;
        unsigned int solutionSize;

    private:
};

#endif // DATASET_H
