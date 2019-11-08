#include "include/Metaheuristic.h"
#include "include/TabuSearch.h"
#include "include/datasets/DataSet.h"
#include "include/datasets/TSPStarDataSet.h"
#include "include/datasets/KnapsackDataSet.h"

int main()
{
//    DataSet* tspDS = new TSPStarDataSet();
//    Metaheuristic* tspTabuSearch = new TabuSearch(tspDS, 2000, 100);
//    tspTabuSearch->run();
//    tspTabuSearch->printSolution();
//    delete(tspDS);
//    delete(tspTabuSearch);

    DataSet* knapsackDS = new KnapsackDataSet();
    Metaheuristic* knapsackTabuSearch = new TabuSearch(knapsackDS, 1, 3);
    knapsackTabuSearch->run();
    knapsackTabuSearch->printSolution();
    delete(knapsackDS);
    delete(knapsackTabuSearch);

    return 0;
}
