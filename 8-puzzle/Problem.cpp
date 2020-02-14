#include "Problem.h"

Problem::Problem(vector<int> puzzle)
{
    this.puzzle = puzzle;
    this.init_puzzle = puzzle;
    this.goal_puzzle = {
        1,2,3,
        4,5,6,
        7,8, 0
    };
}