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

vector<int> Node::getStatePuzzle()
{
    return this->nodeState.getPuzzle();
}

// generate childreen
void Node::expand()
{
    vector<int> puzzle = this->getStatePuzzle();
    vector<int> tempPuzzle = puzzle; 
    int tempInt = 0;
    int zeroPos = this->nodeState.getZeroPos();

    if(zeroPos < (puzzle.size() / 2))
    {
        tempInt = tempPuzzle.at(zeroPos);
        tempPuzzle.at(zeroPos) = tempPuzzle.at(zeroPos + 2);
        tempPuzzle.at(zeroPos + 2) = tempInt;
        for(int i = 0; i < tempPuzzle.size(); ++i)
        {
            cout << tempPuzzle.at(i) << endl;
        }
        this->down = new Node(tempPuzzle);
    }

    // reset temp
    tempPuzzle = puzzle;

    if((zeroPos == 0) || (zeroPos == 2))
    {
        tempInt = tempPuzzle.at(zeroPos);
        tempPuzzle.at(zeroPos) = tempPuzzle.at(zeroPos + 1);
        tempPuzzle.at(zeroPos + 1) = tempInt;
        for(int i = 0; i < tempPuzzle.size(); ++i)
        {
            cout << tempPuzzle.at(i) << endl;
        }
        this->down = new Node(tempPuzzle);
    }
}

// void Node::addChildren(Node* newChild)
// {

// }

// vector<Node*> Node::getChildren(Node* newChild)
// {
//     //add left...down
//     return 
// }