#include "TSPStarDataSet.h"
#include "../../include/datasets/TSPStarDataSet.h"

void TSPStarDataSet::buildCostsMatrix()
{
    this->costs[City::A][0] = 0.00;
    this->costs[City::A][1] = 3.70;
    this->costs[City::A][2] = 6.00;
    this->costs[City::A][3] = 6.00;
    this->costs[City::A][4] = 7.02;
    this->costs[City::A][5] = 9.80;
    this->costs[City::A][6] = 9.68;
    this->costs[City::A][7] = 5.94;
    this->costs[City::A][8] = 5.91;
    this->costs[City::A][9] = 3.66;

    this->costs[City::B][0] = 3.70;
    this->costs[City::B][1] = 0.00;
    this->costs[City::B][2] = 3.76;
    this->costs[City::B][3] = 2.30;
    this->costs[City::B][4] = 3.66;
    this->costs[City::B][5] = 6.10;
    this->costs[City::B][6] = 7.00;
    this->costs[City::B][7] = 3.67;
    this->costs[City::B][8] = 5.88;
    this->costs[City::B][9] = 2.21;

    this->costs[City::C][0] = 6.00;
    this->costs[City::C][1] = 3.76;
    this->costs[City::C][2] = 0.00;
    this->costs[City::C][3] = 3.79;
    this->costs[City::C][4] = 6.01;
    this->costs[City::C][5] = 6.16;
    this->costs[City::C][6] = 9.71;
    this->costs[City::C][7] = 7.10;
    this->costs[City::C][8] = 9.65;
    this->costs[City::C][9] = 5.98;

    this->costs[City::D][0] = 6.00;
    this->costs[City::D][1] = 2.30;
    this->costs[City::D][2] = 3.79;
    this->costs[City::D][3] = 0.00;
    this->costs[City::D][4] = 2.21;
    this->costs[City::D][5] = 3.80;
    this->costs[City::D][6] = 5.91;
    this->costs[City::D][7] = 3.70;
    this->costs[City::D][8] = 6.94;
    this->costs[City::D][9] = 3.66;

    this->costs[City::E][0] = 7.02;
    this->costs[City::E][1] = 3.66;
    this->costs[City::E][2] = 6.01;
    this->costs[City::E][3] = 2.21;
    this->costs[City::E][4] = 0.00;
    this->costs[City::E][5] = 3.74;
    this->costs[City::E][6] = 3.70;
    this->costs[City::E][7] = 2.36;
    this->costs[City::E][8] = 5.94;
    this->costs[City::E][9] = 3.70;

    this->costs[City::F][0] = 9.80;
    this->costs[City::F][1] = 6.10;
    this->costs[City::F][2] = 6.16;
    this->costs[City::F][3] = 3.80;
    this->costs[City::F][4] = 3.74;
    this->costs[City::F][5] = 0.00;
    this->costs[City::F][6] = 5.91;
    this->costs[City::F][7] = 6.10;
    this->costs[City::F][8] = 9.68;
    this->costs[City::F][9] = 7.12;

    this->costs[City::G][0] = 9.68;
    this->costs[City::G][1] = 7.00;
    this->costs[City::G][2] = 9.71;
    this->costs[City::G][3] = 5.91;
    this->costs[City::G][4] = 3.70;
    this->costs[City::G][5] = 5.91;
    this->costs[City::G][6] = 0.00;
    this->costs[City::G][7] = 3.74;
    this->costs[City::G][8] = 6.00;
    this->costs[City::G][9] = 6.02;

    this->costs[City::H][0] = 5.94;
    this->costs[City::H][1] = 3.67;
    this->costs[City::H][2] = 7.10;
    this->costs[City::H][3] = 3.70;
    this->costs[City::H][4] = 2.36;
    this->costs[City::H][5] = 6.10;
    this->costs[City::H][6] = 3.74;
    this->costs[City::H][7] = 0.00;
    this->costs[City::H][8] = 3.58;
    this->costs[City::H][9] = 2.28;

    this->costs[City::I][0] = 5.91;
    this->costs[City::I][1] = 5.88;
    this->costs[City::I][2] = 9.65;
    this->costs[City::I][3] = 6.94;
    this->costs[City::I][4] = 5.94;
    this->costs[City::I][5] = 9.68;
    this->costs[City::I][6] = 6.00;
    this->costs[City::I][7] = 3.58;
    this->costs[City::I][8] = 0.00;
    this->costs[City::I][9] = 3.67;

    this->costs[City::J][0] = 3.66;
    this->costs[City::J][1] = 2.21;
    this->costs[City::J][2] = 5.98;
    this->costs[City::J][3] = 3.66;
    this->costs[City::J][4] = 3.70;
    this->costs[City::J][5] = 7.10;
    this->costs[City::J][6] = 6.02;
    this->costs[City::J][7] = 2.28;
    this->costs[City::J][8] = 3.67;
    this->costs[City::J][9] = 0.00;
}

void TSPStarDataSet::buildInitialSolution()
{
    this->initialSolution[0] = City::J;
    this->initialSolution[1] = City::D;
    this->initialSolution[2] = City::H;
    this->initialSolution[3] = City::B;
    this->initialSolution[4] = City::E;
    this->initialSolution[5] = City::A;
    this->initialSolution[6] = City::F;
    this->initialSolution[7] = City::I;
    this->initialSolution[8] = City::C;
    this->initialSolution[9] = City::G;
    this->initialSolution[10] = City::J;
}



