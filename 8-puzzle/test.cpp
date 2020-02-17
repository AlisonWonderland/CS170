#include <iostream>
#include <vector>
#include "Tree.h"
// #include "Node.h"
using namespace std;

// maybe put this in tree
// uniform
void buildTree(Tree test)
{
    // in Tree test.getFrontier() == this->frontier
    // queue<Node*> nodeFrontier = test.getFrontier();
    Node* tempNode = NULL;
    int nodesExpanded = 0;
    if(test.getFrontier().empty())
    {
        cout << "FAILURE, frontier empty/no root" << endl;
    }

    cout << "Inital node: " << endl;

    while(!test.getFrontier().empty())
    {
        tempNode = test.getFrontier().front();
        test.removeFromFrontier();
        // check if goal if not then expand
        if(tempNode->hasGoalState())
        {
            cout << "Goal!!!" << endl;
            cout << "Number of nodes expanded: " << nodesExpanded << " nodes."<< endl;
            cout << "Maximum number of nodes in queue at any one time was: " << test.getMaxNumNodes() << endl;
            break;
        }
        // tempNode = test.getFrontier().front();
        // cout << tempNode->getStatePuzzle()[0] << endl;
        // break;
        if(nodesExpanded > 0)
        {
            cout << "The best state to expand with a g(n) = " << tempNode->g() 
                << " and h(n) = " << tempNode->h() <<  " is ..." << endl;
        }
        tempNode->expand();
        ++nodesExpanded;
        test.updateExplored(tempNode);
        test.updateFrontier(tempNode);
        // cout << "hello" << endl;
    }
}

int main() 
{
    vector<int> defaultPuzzle2 = {
        0, 2,
        1, 3
    };

    Node* root = new Node(defaultPuzzle2, 0);
    Tree testTree = Tree(root);

    buildTree(testTree);
    return 0;
}