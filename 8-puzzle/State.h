#include <iostream>
using namespace std;

class State
{
    private:
        vector<int> puzzle;
        bool isFinal;
    public:
        State(vector<int> puzzle);
        bool isFinal();
        void setFinal();
}
