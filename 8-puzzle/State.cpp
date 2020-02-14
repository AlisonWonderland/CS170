#include "State.h"

State::State(vector<int> puzzle)
{
    this.puzzle = puzzle;
    this.isFinal = false;
}

bool State::isFinal()
{
    return this.isFinal;
}

void State::setFinal() 
{
    this.isFinal = true;
    return;
}