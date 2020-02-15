#include "Tree.h"
using namespace std;

// Tree::Tree(Problem puzzle)
// {
//     this.puzzleToSolve = puzzle;
// }

Tree::Tree()
{
    this->root = NULL;
}

Tree::Tree(Node* root)
{
    this->frontier.push(root);
    this->root = root;
}

queue<Node*> Tree::getFrontier()
{
    return this->frontier;
}

void Tree::addFrontierNode()
{

}

void Tree::expandNode()
{

}
// add children
// void Tree::addNode()
// {
    
// }