#ifndef DATASET_H
#define DATASET_H


class DataSet
{
    public:
        DataSet(unsigned int dimension, unsigned int solutionSize);
        virtual ~DataSet();
        float** getCosts() const;
        unsigned int* getInitialSolution() const;
        unsigned int getSolutionSize();
        virtual void buildCostsMatrix() = 0;
        virtual void buildInitialSolution() = 0;
        virtual int* generateMovements(unsigned int numberOfMoves) = 0;

    protected:
        float** costs;
        unsigned int* initialSolution;
        unsigned int dimension;
        unsigned int solutionSize;

    private:
};

#endif // DATASET_H
