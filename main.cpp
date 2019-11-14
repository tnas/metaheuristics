#include "include/Metaheuristic.h"
#include "include/TabuSearch.h"
#include "include/datasets/DataSet.h"
#include "include/datasets/TSPStarDataSet.h"
#include "include/datasets/KnapsackDataSet.h"

int main(int argc, char** argv)
{
    if (argc == 1 || (argc == 2 && strcmp(argv[1], "tsp") == 0))
    {
        cout << "Tabu Search for TSP Problem" << endl;
        DataSet* tspDS = new TSPStarDataSet();
        Metaheuristic* tspTabuSearch = new TabuSearch(tspDS, 2000, 100);
        cout << "--- Initial Solution ---" << endl;
        tspTabuSearch->printSolution();
        tspTabuSearch->run();
        cout << "--- Final Solution ---" << endl;
        tspTabuSearch->printSolution();
        delete(tspDS);
        delete(tspTabuSearch);
    }
    else if (argc == 2 && strcmp(argv[1], "knapsack") == 0)
    {
        cout << "Tabu Search for Knapsack Problem" << endl;
        DataSet* knapsackDS = new KnapsackDataSet();
        Metaheuristic* knapsackTabuSearch = new TabuSearch(knapsackDS, 200, 100);
        cout << "--- Initial Solution ---" << endl;
        knapsackTabuSearch->printSolution();
        knapsackTabuSearch->run();
        cout << "--- Final Solution ---" << endl;
        knapsackTabuSearch->printSolution();
        delete(knapsackDS);
        delete(knapsackTabuSearch);
    }
    else
    {
        cout << "Invalid option for Tabu Search!" << endl;
    }

    return 0;
}
