#ifndef TREE_H
#define TREE_H

#include <queue>
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
        int nodesInQueue;
        int maxNodesInQueue;
        priority_queue<Node*, vector<Node*>, CompareCosts> frontier;
        vector<Node*> explored;
        Node* root;
    public:
        Tree();
        Tree(Node* root);
        int getMaxNumNodes();
        priority_queue<Node*, vector<Node*>, CompareCosts> getFrontier();
        void removeFromFrontier();
        void updateFrontier(Node* expandedNode);
        void updateExplored(Node* expandedNode);
        bool inExplored(Node* node);
        void searchForSolution();
        bool rootIsGoal();
        Node* getRoot();
};
#endif