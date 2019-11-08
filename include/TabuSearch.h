#ifndef TABUSEARCH_H
#define TABUSEARCH_H

#include "Metaheuristic.h"
#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <vector>

using namespace std;


class TabuSearch : public Metaheuristic
{
    public:
        TabuSearch(DataSet* dataSet, unsigned int iterations, unsigned int movements);
        ~TabuSearch();
        void run();
        double applyObjectiveFunction(unsigned int* solution);
        void applyMovement(unsigned int from, unsigned int to,
                           unsigned int* solution, unsigned int* newSolution);
        void printSolution();

    protected:

    private:
        DataSet* dataSet;
        unsigned int** movementSolutions;
        double* movFunctionVals;
        unsigned int* currentSolution;
        double currentFunctionVal;
        const static unsigned int TABU_LIST_TIME = 3;
};

#endif // TABUSEARCH_H
