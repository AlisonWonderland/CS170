#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <string>
#include "State.h"
using namespace std;

class Node
{
    private:
        // vector<Node*> children; // only if direction isn't needed
        Node* left; 
        Node* right;
        Node* up;
        Node* down;
        State nodeState;
        int depth;
        // g(n) cost could be depth
        // h(type of heuristic string) cost 
    public:
        Node();
        Node(vector<int> puzzle, int depth);
        Node* getChild(string child);
        int getDepth();
        vector<int> getStatePuzzle();
        void expand();
        bool hasGoalState();
        void printStatePuzzle(vector<int> puzzle);
        // Nodegetchildren()
        int h();
        int g();
        // void addChildren(string moveDirection);
};

#endif