#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <queue>
// #include "Problem.h"
#include "Node.h"
using namespace std;

struct CompareCosts{
    bool operator()(Node* a, Node* b){
        return (a->g() + a->h()) > (b->g() + b->h());
    }
};

class Tree
{
    private:
        // Problem puzzleToSolve; // never changes
        // vector<Node*> visited;
        // int nodesExpanded;
        int nodesInQueue;
        int maxNodesInQueue;
        // for prio queue make a function that moves the node in the queue
        priority_queue<Node*, vector<Node*>, CompareCosts> frontier; // queue
        vector<Node*> explored;
        Node* root;
        // string heuristic;
    public:
        Tree();
        // node and search type constructor
        Tree(Node* root);
        // int getNodesExpanded();
        int getMaxNumNodes();
        priority_queue<Node*, vector<Node*>, CompareCosts> getFrontier();
        void removeFromFrontier();
        void updateFrontier(Node* expandedNode);
        void updateExplored(Node* expandedNode);
        // void expandNode();
        bool inExplored(Node* node);
        void searchForSolution();
        bool rootIsGoal();
        Node* getRoot();
        //void ucs()
        //void misplacedSearch()
        //void manhattanSearch()
};
#endif