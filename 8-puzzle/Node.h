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
        // cost
    public:
        Node();
        Node(vector<int> puzzle);
        Node* getChild(string child);
        vector<int> getStatePuzzle();
        void expand();
        // Nodegetchildren()
        // int h();
        // int g();
        // void addChildren(string moveDirection);
};

#endif