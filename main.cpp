#include "include/Metaheuristic.h"
#include "include/TabuSearch.h"
#include "include/datasets/DataSet.h"
#include "include/datasets/TSPStarDataSet.h"

int main()
{
    DataSet* ds = new TSPStarDataSet();
    Metaheuristic* metaHeuristic = new TabuSearch(ds, 2000, 100);
    metaHeuristic->run();
    metaHeuristic->printSolution();

    delete(metaHeuristic);
    delete(ds);

    return 0;
}
