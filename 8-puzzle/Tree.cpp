#include "Tree.h"
using namespace std;

Tree::Tree()
{
    this->root = NULL;
}

Tree::Tree(Node* root)
{
    // 1 because the root will always be added to frontier
    this->nodesInQueue = 1;
    this->maxNodesInQueue = 1;
    this->frontier.push(root);
    this->root = root;
}

int Tree::getMaxNumNodes()
{
    return this->maxNodesInQueue;
}

priority_queue<Node*, vector<Node*>, CompareCosts> Tree::getFrontier()
{
    return this->frontier;
}

void Tree::removeFromFrontier()
{
    --this->nodesInQueue;
    this->frontier.pop();
}

void Tree::updateFrontier(Node* expandedNode)
{
    if(expandedNode->getChild("left") != NULL)
    {
        if(!this->inExplored(expandedNode->getChild("left")))
        {
            ++this->nodesInQueue;
            this->frontier.push(expandedNode->getChild("left"));
        }
    }

    if(expandedNode->getChild("right") != NULL)
    {
        if(!this->inExplored(expandedNode->getChild("right")))
        {
            ++this->nodesInQueue;
            this->frontier.push(expandedNode->getChild("right"));
        }
    }

    if(expandedNode->getChild("up") != NULL)
    {
        if(!this->inExplored(expandedNode->getChild("up")))
        {
            ++this->nodesInQueue;
            this->frontier.push(expandedNode->getChild("up"));
        }
    }
    
    if(expandedNode->getChild("down") != NULL)
    {
        if(!this->inExplored(expandedNode->getChild("down")))
        {
            ++this->nodesInQueue;
            this->frontier.push(expandedNode->getChild("down"));
        }
    }


    if(this->nodesInQueue > this->maxNodesInQueue)
    {
        this->maxNodesInQueue = this->nodesInQueue;
    }

}

// also increment nodesExpanded
void Tree::updateExplored(Node* expandedNode)
{
    this->explored.push_back(expandedNode);
}

bool Tree::inExplored(Node* node)
{
    for(int i = 0; i < this->explored.size(); ++i)
    {
        if(this->explored.at(i)->getStatePuzzle() == node->getStatePuzzle())
        {
            return true;
        }
    }
    return false;
}

bool Tree::rootIsGoal()
{
    return this->root->hasGoalState();
}
Node* Tree::getRoot()
{
    return this->root;
}