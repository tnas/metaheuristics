#ifndef DATASET_H
#define DATASET_H

#include <string.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdio.h>

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
        virtual double applyObjectiveFunction(unsigned int* solution) = 0;
        virtual void applyMovement(unsigned int from, unsigned int to,
                                   unsigned int* solution, unsigned int* newSolution) = 0;
        virtual bool isImprovement(double iterationValue, double bestValue) = 0;
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
