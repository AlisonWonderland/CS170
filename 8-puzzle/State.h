#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <vector>
using namespace std;

class State
{
    private:
        vector<int> puzzle;
        bool isFinal;
    public:
        State();
        State(vector<int>);
        bool isFinalState();
        void setFinal();
        vector<int> getPuzzle();
        int getZeroPos();
};

#endif