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
    if(test.getFrontier().empty())
    {
        cout << "FAILURE" << endl;
    }
    while(!test.getFrontier().empty())
    {
        tempNode = test.getFrontier().front();
        test.removeFromFrontier();
        // tempNode = test.getFrontier().front();
        // cout << tempNode->getStatePuzzle()[0] << endl;
        // break;
        tempNode->expand();
        test.updateExplored(tempNode);
        test.updateFrontier(tempNode);
        // cout << "hello" << endl;
    }
}

int main() 
{
    vector<int> defaultPuzzle2 = {
        1, 2,
        0, 3
    };

    Node* root = new Node(defaultPuzzle2);
    Tree testTree = Tree(root);

    buildTree(testTree);
    return 0;
}