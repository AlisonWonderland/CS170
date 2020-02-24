#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
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
        Node* parent;
        State nodeState;
        int ucsCost;
        int heuristicCost;
        string heuristic;
    public:
        Node();
        Node(vector<int> puzzle, int ucsCost, string heuristic, Node* parent=NULL);
        int calcHeuristic(string heuristic);
        Node* getChild(string child);
        vector<Node*> getChildren();
        vector<int> getStatePuzzle();
        Node* getParent();
        // void setParent();
        void expand();
        bool hasGoalState();
        void printStatePuzzle();
        int h();
        int g();
};

#endif