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
}

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
    int row = 0; 
    int col = 0; 

    // https://stackoverflow.com/questions/39759721/calculating-the-manhattan-distance-in-the-eight-puzzle
    if(heuristic == "Manhattan")
    {
        for(int i = 0; i < goalPuzzle.size(); ++i)
        {
            if((goalPuzzle.at(i) != nodePuzzle.at(i)) && (nodePuzzle.at(i) != 0))
            {
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


vector<int> Node::getStatePuzzle()
{
    return this->nodeState.getPuzzle();
}

// could be simplified if using the children vector
void Node::expand()
{
    vector<int> puzzle = this->getStatePuzzle();
    vector<int> tempPuzzle = puzzle; 
    int tempInt = 0;
    int zeroIndex = this->nodeState.getZeroPos();

    printStatePuzzle();
    cout << "---Expanding this node" << endl;

    // move blank down
    if(zeroIndex <= 5)
    {
        tempInt = tempPuzzle.at(zeroIndex);
        tempPuzzle.at(zeroIndex) = tempPuzzle.at(zeroIndex + 3);
        tempPuzzle.at(zeroIndex + 3) = tempInt;
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
        this->right = new Node(tempPuzzle, this->g() + 1, this->heuristic);
    }

    tempPuzzle = puzzle;

    // move blank to up
    if(zeroIndex >= (puzzle.size() / 3))
    {
        tempInt = tempPuzzle.at(zeroIndex);
        tempPuzzle.at(zeroIndex) = tempPuzzle.at(zeroIndex - 3);
        tempPuzzle.at(zeroIndex - 3) = tempInt;
        this->up = new Node(tempPuzzle, this->g() + 1, this->heuristic);
    }

    tempPuzzle = puzzle;
    // move blank to left
    if((zeroIndex == 2) || (zeroIndex == 5) || (zeroIndex == 8) || (zeroIndex == 1) || (zeroIndex == 4) || (zeroIndex == 7))
    {
        tempInt = tempPuzzle.at(zeroIndex);
        tempPuzzle.at(zeroIndex) = tempPuzzle.at(zeroIndex - 1);
        tempPuzzle.at(zeroIndex - 1) = tempInt;
        this->left = new Node(tempPuzzle, this->g() + 1, this->heuristic);
    }
}

bool Node::hasGoalState()
{
    return this->nodeState.isFinalState();
}

void Node::printStatePuzzle()
{
    vector<int> puzzle = this->getStatePuzzle();
    for(int i = 1; i <= puzzle.size(); ++i)
    {
        cout << puzzle.at(i - 1) <<  " ";
        // end of row
        if((i % 3) == 0)
        {
            cout << endl;
        }
    }
}

int Node::g()
{
    return this->ucsCost;
}

int Node::h()
{
    return this->heuristicCost;
}