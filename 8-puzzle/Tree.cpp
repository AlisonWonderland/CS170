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
    // this->nodesExpanded = 0;
    // 1 because the root will always be added to frontier
    this->nodesInQueue = 1;
    this->maxNodesInQueue = 1;
    this->frontier.push(root);
    this->root = root;
}

// int Tree::getNodesExpanded()
// {
//     return this->nodesExpanded;
// }
int Tree::getMaxNumNodes()
{
    return this->maxNodesInQueue;
}

queue<Node*> Tree::getFrontier()
{
    return this->frontier;
}

void Tree::removeFromFrontier()
{
    // this->frontier = this->frontier.pop();
    --this->nodesInQueue;
    // cout << "removing from frontier" << endl;
    this->frontier.pop();
}

// for max do if statement conditional
// don't keep incrementing

// add children from expanded node if needed
// cost isn't being used
// check if final state
void Tree::updateFrontier(Node* expandedNode)
{
    // if(expandedNode->getChild("up") != NULL)
    // {
    //     // cout << "not null" << endl;
    //     if(!this->inExplored(expandedNode->getChild("up")))
    //     {
    //         // cout << "adding left" << endl;
    //         ++this->nodesInQueue;
    //         this->frontier.push(expandedNode->getChild("up"));
    //     }
    // }
    // if(expandedNode->getChild("down") != NULL)
    // {
    //     // cout << "not null" << endl;
    //     if(!this->inExplored(expandedNode->getChild("down")))
    //     {
    //         ++this->nodesInQueue;
    //         // cout << "adding left" << endl;
    //         this->frontier.push(expandedNode->getChild("down"));
    //     }
    // }
    // cout << "adding to frontier" << endl;
    if(expandedNode->getChild("left") != NULL)
    {
        // cout << "not null" << endl;
        if(!this->inExplored(expandedNode->getChild("left")))
        {
            // cout << "adding left" << endl;
            // cout << "Nodes after left: " << this->nodesInQueue << endl;
            ++this->nodesInQueue;
            // cout << "Nodes after left: " << this->nodesInQueue << endl;
            this->frontier.push(expandedNode->getChild("left"));
        }
    }

    if(expandedNode->getChild("right") != NULL)
    {
        // cout << "not null" << endl;
        if(!this->inExplored(expandedNode->getChild("right")))
        {
            // cout << "adding right" << endl;
            // cout << "Nodes after left: " << this->nodesInQueue << endl;
            ++this->nodesInQueue;
            // cout << "Nodes after right: " << this->nodesInQueue << endl;
            this->frontier.push(expandedNode->getChild("right"));
        }
    }

    if(expandedNode->getChild("up") != NULL)
    {
        // cout << "not null" << endl;
        if(!this->inExplored(expandedNode->getChild("up")))
        {
            // cout << "adding up" << endl;
            ++this->nodesInQueue;
            // cout << "Nodes after up: " << this->nodesInQueue << endl;
            this->frontier.push(expandedNode->getChild("up"));
        }
    }
    
    if(expandedNode->getChild("down") != NULL)
    {
        // cout << "not null" << endl;
        if(!this->inExplored(expandedNode->getChild("down")))
        {
            // cout << "adding down" << endl;
            ++this->nodesInQueue;
            // cout << "Nodes after down: " << this->nodesInQueue << endl;
            this->frontier.push(expandedNode->getChild("down"));
        }
    }

    // cout << "Nodes in queue after adding to frontier/queue: " << this->nodesInQueue << endl;

    if(this->nodesInQueue > this->maxNodesInQueue)
    {
        // cout << "greater" << endl;
        this->maxNodesInQueue = this->nodesInQueue;
    }

    // cout << "nodes in queue: " << this->getMaxNumNodes() << endl;
}

// also increment nodesExpanded
void Tree::updateExplored(Node* expandedNode)
{
    // cout << "updated" << endl;
    // for(int i = 0; i < expandedNode->getStatePuzzle().size(); ++i)
    // {
    //     // cout << expandedNode->getStatePuzzle().at(i) << endl;
    // }
    // ++this->nodesExpanded;
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