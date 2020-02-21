#include "Node.h"
using namespace std;

Node::Node()
{
    this->left = NULL; 
    this->right = NULL;
    this->up = NULL;
    this->down = NULL;
    this->nodeState = State();
    this->ucsCost = 0;
    this->heuristicCost = 0;
    this->heuristic = "Ucs";
}

// don't have to cal heuristic for 
Node::Node(vector<int> puzzle, int ucsCost, string heuristic)
{
    this->nodeState = State(puzzle);
    this->left = NULL; 
    this->right = NULL;
    this->up = NULL;
    this->down = NULL;
    this->ucsCost = ucsCost;
    this->heuristicCost = calcHeuristic(heuristic);
    this->heuristic = heuristic;
    // this->heuristicCost = calcHeuristic(puzzle);
}

// calc heuristic after being expanded
// change for 3 x 3 puzzle
int Node::calcHeuristic(string heuristic)
{
    if(heuristic == "Ucs")
    {
        return 0;
    }

    vector<int> goalPuzzle = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 0
    };
    vector<int> nodePuzzle = this->getStatePuzzle();
    int puzzleValue = 0;
    int cost = 0; 
    int row = 0; // nodePuzzle.at(i) % 3
    int col = 0; // nodePuzzle.at

    // puzzle col = i % 3 or i % 2
    // puzzle row = floor(i / 3) or floor(i / 3)
    // goal col = val - 1 % 3 or i % 2
    // goal row = floor(val - 1/ 3) or floor(val - 1/ 3)
    // https://stackoverflow.com/questions/39759721/calculating-the-manhattan-distance-in-the-eight-puzzle
    if(heuristic == "Manhattan")
    {
        // cout << "+++++++Manhattan+++++++" << endl;
        // this->printStatePuzzle();
        for(int i = 0; i < goalPuzzle.size(); ++i)
        {
            if((goalPuzzle.at(i) != nodePuzzle.at(i)) && (nodePuzzle.at(i) != 0))
            {
                // cout << "val: " << nodePuzzle.at(i) << endl;
                // cout << "x: " << (nodePuzzle.at(i)-1)%2 << " y: " << floor((nodePuzzle.at(i)-1)/2) << endl;
                cost += abs((nodePuzzle.at(i)-1)%3 - (i%3)) + abs(floor((nodePuzzle.at(i)-1)/3) - floor(i/3));
            }
        }
    }

    else if(heuristic == "Misplaced Tile")
    {
        for(int i = 0; i < goalPuzzle.size(); ++i)
        {
            if((goalPuzzle.at(i) != nodePuzzle.at(i)) && (nodePuzzle.at(i) != 0))
            {
                ++cost;
            }
        }
    }

    return cost;
}

// int Node::getUcsCost()
// {
//     return this->ucsCost;
// }

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

vector<Node*> Node::getChildren()
{
    vector<Node*> children;
    if(this->left != NULL)
    {
        children.push_back(this->left);
    }
    if(this->right != NULL)
    {
        children.push_back(this->right);
    }
    if(this->up != NULL)
    {
        children.push_back(this->up);
    }
    if(this->down != NULL)
    {
        children.push_back(this->down);
    }

    return children;
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
    // printStatePuzzle(this->nodeState.getPuzzle());
    return this->nodeState.getPuzzle();
}

// calc cost here
// could be simplified if using the children vector
void Node::expand()
{
    // print node being expanded

    vector<int> puzzle = this->getStatePuzzle();
    vector<int> tempPuzzle = puzzle; 
    int tempInt = 0;
    int zeroIndex = this->nodeState.getZeroPos();
    // cout << "zero: " << zeroIndex << endl;

    printStatePuzzle();
    cout << "---Expanding this node" << endl;

    // move blank down
    if(zeroIndex <= 5)
    {
        tempInt = tempPuzzle.at(zeroIndex);
        tempPuzzle.at(zeroIndex) = tempPuzzle.at(zeroIndex + 3);
        tempPuzzle.at(zeroIndex + 3) = tempInt;
        // for(int i = 1; i <= tempPuzzle.size(); ++i)
        // {
        //     cout << tempPuzzle.at(i - 1) << " ";
        //     if(i % 3 == 0)
        //     {
        //         cout << endl;
        //     }
        // }
        // cout << "down" << endl;
        this->down = new Node(tempPuzzle, this->g() + 1, this->heuristic);
    }

    // reset temp
    tempPuzzle = puzzle;

    // move blank to right 
    if((zeroIndex == 0) || (zeroIndex == 3) || (zeroIndex == 6) || (zeroIndex == 1) || (zeroIndex == 4) || (zeroIndex == 7))
    {
        tempInt = tempPuzzle.at(zeroIndex);
        tempPuzzle.at(zeroIndex) = tempPuzzle.at(zeroIndex + 1);
        tempPuzzle.at(zeroIndex + 1) = tempInt;
        // for(int i = 1; i <= tempPuzzle.size(); ++i)
        // {
        //     cout << tempPuzzle.at(i - 1) << " ";
        //     if(i % 3 == 0)
        //     {
        //         cout << endl;
        //     }
        // }
        // cout << "right" << endl;
        this->right = new Node(tempPuzzle, this->g() + 1, this->heuristic);
    }

    tempPuzzle = puzzle;

    // move blank to up
    if(zeroIndex >= (puzzle.size() / 3))
    {
        tempInt = tempPuzzle.at(zeroIndex);
        tempPuzzle.at(zeroIndex) = tempPuzzle.at(zeroIndex - 3);
        tempPuzzle.at(zeroIndex - 3) = tempInt;
        // for(int i = 1; i <= tempPuzzle.size(); ++i)
        // {
        //     cout << tempPuzzle.at(i - 1) << " ";
        //     if(i % 3 == 0)
        //     {
        //         cout << endl;
        //     }
        // }
        // cout << "up" << endl;
        this->up = new Node(tempPuzzle, this->g() + 1, this->heuristic);
    }

    tempPuzzle = puzzle;
    // move blank to left
    if((zeroIndex == 2) || (zeroIndex == 5) || (zeroIndex == 8) || (zeroIndex == 1) || (zeroIndex == 4) || (zeroIndex == 7))
    {
        tempInt = tempPuzzle.at(zeroIndex);
        tempPuzzle.at(zeroIndex) = tempPuzzle.at(zeroIndex - 1);
        tempPuzzle.at(zeroIndex - 1) = tempInt;
        // for(int i = 1; i <= tempPuzzle.size(); ++i)
        // {
        //     cout << tempPuzzle.at(i - 1) << " ";
        //     if(i % 3 == 0)
        //     {
        //         cout << endl;
        //     }
        // }
        // cout << "left" << endl;
        this->left = new Node(tempPuzzle, this->g() + 1, this->heuristic);
    }

    //add this node to visited
    // we do return them, then check if vistied, add non visited to frontier
}

bool Node::hasGoalState()
{
    return this->nodeState.isFinalState();
}

void Node::printStatePuzzle()
{
    vector<int> puzzle = this->getStatePuzzle();
    // bool endOfRow = false;
    for(int i = 1; i <= puzzle.size(); ++i)
    {
        cout << puzzle.at(i - 1) <<  " ";
        // end of row
        if((i % 3) == 0)
        {
            cout << endl;
        }
        // if(endOfRow)
        // {
        //     cout << endl;
        //     endOfRow = !endOfRow;
        // }
    }
}

int Node::g()
{
    return this->ucsCost;
}

int Node::h()
{
    // 0 for uniform
    // calculate for A*
    return this->heuristicCost;
}

// void Node::addChildren(Node* newChild)
// {

// }

// vector<Node*> Node::getChildren(Node* newChild)
// {
//     //add left...down
//     return 
// }