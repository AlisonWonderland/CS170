#include <iostream>
using namespace std;

class Problem
{
    private:
        vector<int> init_puzzle;
        vector<int> goal_puzzle;
    public:
        // Problem();
        Problem(vector<int> puzzle);
        // pass in the Problem puzzle
        bool puzzleSolved(puzzle);
}

// work with 4 puzzle, write it down. choose which operator(down, up, left, right) to use.