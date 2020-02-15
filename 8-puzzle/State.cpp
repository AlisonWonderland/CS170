#include "State.h"

State::State()
{
    // this->puzzle = puzzle;
    this->isFinal = false;
}

State::State(vector<int> puzzle)
{
    this->puzzle = puzzle;
    // check puzzle here with function. can we use Problem here?
    this->isFinal = false;
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