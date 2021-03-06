#include "State.h"

State::State()
{
    this->isFinal = false;
}

State::State(vector<int> puzzle)
{
    vector<int> defaulGoalPuzzle = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 0
    };
    
    this->puzzle = puzzle;

    if(puzzle == defaulGoalPuzzle)
    {
        this->isFinal = true;
    }
    else
    {
        this->isFinal = false;
    }
}

bool State::isFinalState()
{
    return this->isFinal;
}

void State::setFinal() 
{
    this->isFinal = true;
    return;
}

vector<int> State::getPuzzle()
{
    return this->puzzle;
}

int State::getZeroPos()
{
    for(int i = 0; i < this->puzzle.size(); ++i)
    {
        if(this->puzzle.at(i) == 0)
        {
            return i;
        }
    }
    return -1;
}