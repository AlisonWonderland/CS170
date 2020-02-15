#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include "State.h"
using namespace std;

class Node
{
    private:
        // vector<Node*> children;
        Node* left; 
        Node* right;
        Node* up;
        Node* down;
        State nodeState;
    public:
        Node();
        Node(vector<int> puzzle);
        vector<int> getStatePuzzle();
        void expand();
        // void addChildren(string moveDirection);
};

#endif