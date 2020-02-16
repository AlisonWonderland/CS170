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

void Tree::removeFromFrontier()
{
    // this->frontier = this->frontier.pop();
    this->frontier.pop();
}

// add children from expanded node if needed
// cost isn't being used
// check if final state
void Tree::updateFrontier(Node* expandedNode)
{
    // cout << "adding to frontier" << endl;
    if(expandedNode->getChild("left") != NULL)
    {
        // cout << "not null" << endl;
        if(!this->inExplored(expandedNode->getChild("left")))
        {
            // cout << "adding left" << endl;
            this->frontier.push(expandedNode->getChild("left"));
        }
    }
    if(expandedNode->getChild("right") != NULL)
    {
        // cout << "not null" << endl;
        if(!this->inExplored(expandedNode->getChild("right")))
        {
            // cout << "adding left" << endl;
            this->frontier.push(expandedNode->getChild("right"));
        }
    }
    if(expandedNode->getChild("up") != NULL)
    {
        // cout << "not null" << endl;
        if(!this->inExplored(expandedNode->getChild("up")))
        {
            // cout << "adding left" << endl;
            this->frontier.push(expandedNode->getChild("up"));
        }
    }
    if(expandedNode->getChild("down") != NULL)
    {
        // cout << "not null" << endl;
        if(!this->inExplored(expandedNode->getChild("down")))
        {
            // cout << "adding left" << endl;
            this->frontier.push(expandedNode->getChild("down"));
        }
    }
}

void Tree::updateExplored(Node* expandedNode)
{
    // cout << "updated" << endl;
    for(int i = 0; i < expandedNode->getStatePuzzle().size(); ++i)
    {
        // cout << expandedNode->getStatePuzzle().at(i) << endl;
    }
    this->explored.push_back(expandedNode);
}

bool Tree::inExplored(Node* node)
{
    for(int i = 0; i < this->explored.size(); ++i)
    {
        if(this->explored.at(i)->getStatePuzzle() == node->getStatePuzzle())
        {
            // cout << "in explored??" << endl;
            for(int i = 0; i <node->getStatePuzzle().size(); ++i)
            {
                // cout << node->getStatePuzzle().at(i) << endl;
            }
            return true;
        }
    }
    // if node get puzzle is in explored
    // this->explored.push_back(expandedNode);
    return false;
}

void searchForSolution()
{
    
}

// void Tree::expandNode()
// {

// }
// add children
// void Tree::addNode()
// {
    
// }