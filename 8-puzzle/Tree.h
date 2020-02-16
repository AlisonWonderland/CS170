#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <queue>
// #include "Problem.h"
#include "Node.h"
using namespace std;

class Tree
{
    private:
        // Problem puzzleToSolve; // never changes
        // vector<Node*> visited;
        queue<Node*> frontier; // queue
        vector<Node*> explored;
        Node* root;
    public:
        Tree();
        Tree(Node* root);
        queue<Node*> getFrontier();
        void removeFromFrontier();
        void updateFrontier(Node* expandedNode);
        void updateExplored(Node* expandedNode);
        // void expandNode();
        bool inExplored(Node* node);
        void searchForSolution();
        // check visited()
        // then add it to frontier
};
#endif