#ifndef TABUSEARCH_H
#define TABUSEARCH_H

#include "Metaheuristic.h"
#include <iostream>
#include <string.h>

using namespace std;


class TabuSearch : public Metaheuristic
{
    public:
        TabuSearch(DataSet* dataSet, unsigned int iterations, unsigned int movements) :
            Metaheuristic(iterations, movements),
            dataSet(dataSet) {};
        void run();
        double applyObjectiveFunction(unsigned int* solution);
        void applyMovement(unsigned int from, unsigned int to,
                           unsigned int* solution, unsigned int* newSolution);
        void printSolution(unsigned int* solution);

    protected:

    private:
        DataSet* dataSet;
};

#endif // TABUSEARCH_H
