#ifndef TABUSEARCH_H
#define TABUSEARCH_H

#include "Metaheuristic.h"


class TabuSearch : public Metaheuristic
{
    public:
        TabuSearch(const DataSet* dataSet, unsigned int iterations);
        virtual ~TabuSearch();

    protected:

    private:
        const DataSet* dataSet;
};

#endif // TABUSEARCH_H
