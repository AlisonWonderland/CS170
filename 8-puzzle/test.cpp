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
    queue<Node*> nodeFrontier = test.getFrontier();
    Node* temp = NULL;
    if(test.getFrontier().empty())
    {
        cout << "FAILURE" << endl;
    }
    while(!nodeFrontier.empty())
    {
        temp = nodeFrontier.front();
        nodeFrontier.pop();
        // if(temp.isInVisited())
        // {
        //     continue;
        // }
        temp->expand();
        cout << "hello" << endl;
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