#ifndef METAHEURISTIC_H
#define METAHEURISTIC_H

#include "datasets/DataSet.h"

class Metaheuristic
{
    public:
        Metaheuristic();
        Metaheuristic(unsigned int maxIterations);
        virtual ~Metaheuristic();

    protected:
        unsigned int maxIterations;

    private:
};

#endif // METAHEURISTIC_H
