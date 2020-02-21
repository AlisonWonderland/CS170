#include <iostream>
// #include <vector>
#include "Tree.h"
using namespace std;


void solutionFoundMsg(int nodesExpanded, int maxNodes)
{
    cout << "Goal!!!" << endl;
    cout << "Number of nodes expanded: " << nodesExpanded << " nodes."<< endl;
    cout << "Maximum number of nodes in queue at any one time was: " << maxNodes << endl;

}

void ucs(Tree test)
{
    cout << "Inital node: " << endl;

    if(test.rootIsGoal())
    {
        test.getRoot()->printStatePuzzle();
        solutionFoundMsg(0, 1);
    }
    // }
    // in Tree test.getFrontier() == this->frontier
    // queue<Node*> nodeFrontier = test.getFrontier();
    Node* tempNode = NULL;
    Node* child = NULL;
    vector<Node*> children;
    int nodesExpanded = 0;

    if(test.getFrontier().empty())
    {
        cout << "FAILURE, frontier empty/no root" << endl;
        return;
    }

    while(!test.getFrontier().empty())
    {
        tempNode = test.getFrontier().top();
        test.removeFromFrontier();
        test.updateExplored(tempNode);
        // check if goal if not then expand
        // if(tempNode->hasGoalState())
        // {
        //     if(nodesExpanded == 0)
        //     {
        //         tempNode->printStatePuzzle();
        //     }
        //     cout << "Goal!!!" << endl;
        //     cout << "Number of nodes expanded: " << nodesExpanded << " nodes."<< endl;
        //     cout << "Maximum number of nodes in queue at any one time was: " << test.getMaxNumNodes() << endl;
        //     break;
        // }
        // tempNode = test.getFrontier().front();
        // cout << tempNode->getStatePuzzle()[0] << endl;
        // break;
        if(nodesExpanded > 0)
        {
            cout << "The best state to expand with a g(n) = " << tempNode->g() 
                << " and h(n) = " << tempNode->h() <<  " is ..." << endl;
        }

        tempNode->expand();
        ++nodesExpanded;
        children = tempNode->getChildren();

        for(int i = 0; i < children.size(); ++i)
        {
            child = children.at(i);
            if(child->hasGoalState())
            {
                solutionFoundMsg(nodesExpanded, test.getMaxNumNodes());
                return;
            }
        }
        // test.updateExplored(tempNode);
        // adding all children here
        test.updateFrontier(tempNode);
    }
}

// create new tree class?
// for prio queue:   https://stackoverflow.com/questions/2439283/how-can-i-create-min-stl-priority-queue
// https://www.geeksforgeeks.org/a-search-algorithm/
void aStar(Tree test)
{
    Node* tempNode = NULL;
    int nodesExpanded = 0;

    // initalize to large value so that we can compare it with the actual smaller costs of the nodes
    int prevGoalCost = 1000000;
    int currGoalCost = 0;

    if(test.getFrontier().empty())
    {
        cout << "FAILURE, frontier empty/no root" << endl;
    }

    cout << "Inital node: " << endl;

    while(!test.getFrontier().empty())
    {
        tempNode = test.getFrontier().top();
        test.removeFromFrontier();
        // and if not greater than next node in frontier
        if(tempNode->hasGoalState())
        {
            // if()
            if(nodesExpanded == 0)
            {
                tempNode->printStatePuzzle();
            }
            cout << "Goal!!!" << endl;
            cout << "Number of nodes expanded: " << nodesExpanded << " nodes."<< endl;
            cout << "Maximum number of nodes in queue at any one time was: " << test.getMaxNumNodes() << endl;
            return;
        }
        // tempNode = test.getFrontier().front();
        // cout << tempNode->getStatePuzzle()[0] << endl;
        // break;
        if(nodesExpanded > 0)
        {
            cout << "The best state to expand with a g(n) = " << tempNode->g() 
                << " and h(n) = " << tempNode->h() <<  " is ..." << endl;
        }
        tempNode->expand();
        ++nodesExpanded;
        test.updateExplored(tempNode);
        test.updateFrontier(tempNode);
        // cout << "hello" << endl;
    }

    cout << endl;
    cout << "*****NO SOLUTION*****" << endl;
}

vector<int> getDefaultPuzzle()
{
    // vector<int> defaultPuzzle = {
    //     1,2,3,
    //     4,5,6,
    //     0,7,8
    // };

    vector<int> defaultPuzzle2 = {
        2, 0,
        1, 3
    };

    return defaultPuzzle2;
}

int main()
{
    int userChoice = 0;
    int number = 0;
    int algoChoice = 0;
    vector<int> userPuzzle;
    // int* userPuzzle;

    cout << "Welcome to mlean002s 8-puzzle solver.\n"
        << "Type \"1\" to use a default puzzle or \"2\" to enter your own puzzle." 
        << endl;

    cin >> userChoice;

    if(userChoice == 1) 
    {
        userPuzzle = getDefaultPuzzle();
        // cout << userPuzzle[0] << endl;
    }

    // else if(userChoice == 2) 
    // {
    //     cout << "Enter your puzzle, use a zero to represent the blank" << endl;
    //     cout << "Enter the first row, use space or tabs between numbers:" << endl;
    //     for(int i = 0; i < 3; ++i)
    //     {
    //         cin >> number;
    //         userPuzzle.push_back(number);
    //     }
    //     cout << "Enter the second row, use space or tabs between numbers:" << endl;
    //     for(int i = 0; i < 3; ++i)
    //     {
    //         cin >> number;
    //         userPuzzle.push_back(number);
    //     }
    //     cout << "Enter the third row, use space or tabs between numbers:" << endl;
    //     for(int i = 0; i < 3; ++i)
    //     {
    //         cin >> number;
    //         userPuzzle.push_back(number);
    //     }

    //     int len = 0;
    //     cout << "Confirming your puzzle: " << endl;
    //     for(int i = 0; i < userPuzzle.size(); ++i)
    //     {
    //         cout << userPuzzle[i] << " ";
    //         ++len;
    //         if((len % 3 == 0) && (len != 0))
    //         {
    //             cout << endl;
    //         }
    //     }
    // }

    cout << endl;
    // Set the game up
    cout << "Enter your choice of algorithm\n"
        << "1) Uniform Cost Search\n"
        << "2) A* with the Misplaced Tile heuristic.\n"
        << "3) A* with the Manhattan distance heuristic\n" << endl;

	cin >> algoChoice;
    cout << endl;

    if(algoChoice == 1)
    {
        Node* root = new Node(userPuzzle, 0, "Ucs");
        Tree testTree = Tree(root);
        ucs(testTree);
    }
    else if(algoChoice == 2)
    {
        Node* root = new Node(userPuzzle, 0, "Manhattan");
        Tree testTree = Tree(root);
        aStar(testTree);
    }
    else if(algoChoice == 3)
    {
        Node* root = new Node(userPuzzle, 0, "Misplaced Tile");
        Tree testTree = Tree(root);
        aStar(testTree);
    }

    return 0;
}