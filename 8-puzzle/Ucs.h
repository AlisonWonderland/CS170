#include <iostream>
#include "Problem.h"
using namespace std;

class Ucs
{
    private:
        // vector<int> init_puzzle;
        // vector<int> goal_state;
        Problem problem;
    public:
        // Problem();
        Ucs(Problem problem);
        void solvePuzzle();
}