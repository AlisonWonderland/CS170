#include "Node.h"
using namespace std;

Node::Node()
{
    this->left = NULL; 
    this->right = NULL;
    this->up = NULL;
    this->down = NULL;
    this->nodeState = State();
}

Node::Node(vector<int> puzzle)
{
    this->nodeState = State(puzzle);
    this->left = NULL; 
    this->right = NULL;
    this->up = NULL;
    this->down = NULL;
}

Node* Node::getChild(string child)
{
    if(child == "left")
    {
        return this->left;
    }
    else if(child == "right")
    {
        return this->right;
    }
    else if(child == "up")
    {
        return this->up;
    }
    else if(child == "down")
    {
        return this->down;
    }
}

// not needed
// void Node::setChild(string child, vector<int> puzzle)
// {
//     if(child == "left")
//     {
//         return this->left;
//     }
//     else if(child == "right")
//     {
//         return this->right;
//     }
//     else if(child == "up")
//     {
//         return this->up;
//     }
//     else if(child == "down")
//     {
//         return this->down;
//     }
// }

vector<int> Node::getStatePuzzle()
{
    return this->nodeState.getPuzzle();
}

// generate childreen
// could be simplified if using the children vector
void Node::expand()
{
    vector<int> puzzle = this->getStatePuzzle();
    vector<int> tempPuzzle = puzzle; 
    int tempInt = 0;
    int zeroPos = this->nodeState.getZeroPos();

    // move blank down
    if(zeroPos < (puzzle.size() / 2))
    {
        tempInt = tempPuzzle.at(zeroPos);
        tempPuzzle.at(zeroPos) = tempPuzzle.at(zeroPos + 2);
        tempPuzzle.at(zeroPos + 2) = tempInt;
        for(int i = 0; i < tempPuzzle.size(); ++i)
        {
            cout << tempPuzzle.at(i) << endl;
        }
        cout << "down" << endl;
        this->down = new Node(tempPuzzle);
    }

    // reset temp
    tempPuzzle = puzzle;

    // move blank to right 
    if((zeroPos == 0) || (zeroPos == 2))
    {
        tempInt = tempPuzzle.at(zeroPos);
        tempPuzzle.at(zeroPos) = tempPuzzle.at(zeroPos + 1);
        tempPuzzle.at(zeroPos + 1) = tempInt;
        for(int i = 0; i < tempPuzzle.size(); ++i)
        {
            cout << tempPuzzle.at(i) << endl;
        }
        cout << "right" << endl;
        this->right = new Node(tempPuzzle);
    }

    tempPuzzle = puzzle;

    // move blank to up
    if(zeroPos >= (puzzle.size() / 2))
    {
        tempInt = tempPuzzle.at(zeroPos);
        tempPuzzle.at(zeroPos) = tempPuzzle.at(zeroPos - 2);
        tempPuzzle.at(zeroPos - 2) = tempInt;
        for(int i = 0; i < tempPuzzle.size(); ++i)
        {
            cout << tempPuzzle.at(i) << endl;
        }
        cout << "up" << endl;
        this->up = new Node(tempPuzzle);
    }

    tempPuzzle = puzzle;
    // move blank to left
    if((zeroPos == 1) || (zeroPos == 3))
    {
        tempInt = tempPuzzle.at(zeroPos);
        tempPuzzle.at(zeroPos) = tempPuzzle.at(zeroPos - 1);
        tempPuzzle.at(zeroPos - 1) = tempInt;
        for(int i = 0; i < tempPuzzle.size(); ++i)
        {
            cout << tempPuzzle.at(i) << endl;
        }
        cout << "left" << endl;
        this->left = new Node(tempPuzzle);
    }

    //add this node to visited
    // we do return them, then check if vistied, add non visited to frontier
}

// void Node::addChildren(Node* newChild)
// {

// }

// vector<Node*> Node::getChildren(Node* newChild)
// {
//     //add left...down
//     return 
// }