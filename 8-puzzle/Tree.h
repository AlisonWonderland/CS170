#include <iostream>
// #include "Problem.h"
#include "Node.h"
using namespace std;

class Tree
{
    private:
        // Problem puzzleToSolve; // never changes
        // vector<Node*> visited;
        // vector<Node*> frontier;
        Node* root;
    public:
        Tree(State state);
        void addFrontierNode();
        void expandNode();
}