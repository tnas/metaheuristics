#ifndef METAHEURISTIC_H
#define METAHEURISTIC_H

#include "datasets/DataSet.h"

class Metaheuristic
{
    public:
        Metaheuristic(unsigned int maxIterations, unsigned int nMovements) :
            maxIterations(maxIterations),
            numberOfMovements(nMovements) {};
        virtual ~Metaheuristic();
        virtual void run() = 0;
        virtual void printSolution() = 0;

    protected:
        unsigned int maxIterations;
        unsigned int numberOfMovements;

    private:
};

#endif // METAHEURISTIC_H
