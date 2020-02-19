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
        tempNode = test.getFrontier().top();
        test.removeFromFrontier();
        // check if goal if not then expand
        if(tempNode->hasGoalState())
        {
            if(nodesExpanded == 0)
            {
                tempNode->printStatePuzzle();
            }
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

// create new tree class?
// for prio queue:   https://stackoverflow.com/questions/2439283/how-can-i-create-min-stl-priority-queue
void aStar(Tree test)
{
    Node* tempNode = NULL;
    int nodesExpanded = 0;

    // initalize to large value so that we can compare it with the actual smaller costs of the nodes
    int prevGoalCost = 1000000;
    int currGoalCost = 0;

    if(test.getFrontier().empty())
    {
        cout << "FAILURE, frontier empty/no root" << endl;
    }

    cout << "Inital node: " << endl;

    while(!test.getFrontier().empty())
    {
        tempNode = test.getFrontier().top();
        test.removeFromFrontier();
        // check if goal if not then expand
        if(tempNode->hasGoalState())
        {
            if()
            if(nodesExpanded == 0)
            {
                tempNode->printStatePuzzle();
            }
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

    // Node* root = new Node(defaultPuzzle2, 0, "Ucs");
    // Node* root = new Node(defaultPuzzle2, 0, "Manhattan");
    Node* root = new Node(defaultPuzzle2, 0, "Misplaced Tile");
    Tree testTree = Tree(root);

    aStar(testTree);
    return 0;
}