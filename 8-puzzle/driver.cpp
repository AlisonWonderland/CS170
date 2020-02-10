#include <iostream>
#include <vector>
using namespace std;

vector<int> getDefaultPuzzle()
{
    vector<int> defaultPuzzle = {
        1,2,3,
        4,5,6,
        0,7,8
    };

    return defaultPuzzle;
}

int main()
{
    int userChoice = 0;
    int number = 0;
    int algoChoice = 0;
    vector<int> userPuzzle;

    cout << "Welcome to mlean002s 8-puzzle solver.\n"
        << "Type \"1\" to use a default puzzle or \"2\" to enter your own puzzle." 
        << endl;

    cin >> userChoice;

    if(userChoice == 1) 
    {
        userPuzzle = getDefaultPuzzle();
        // cout << userPuzzle[0] << endl;
    }

    else if(userChoice == 2) 
    {
        cout << "Enter your puzzle, use a zero to represent the blank" << endl;
        cout << "Enter the first row, use space or tabs between numbers:" << endl;
        for(int i = 0; i < 3; ++i)
        {
            cin >> number;
            userPuzzle.push_back(number);
        }
        cout << "Enter the second row, use space or tabs between numbers:" << endl;
        for(int i = 0; i < 3; ++i)
        {
            cin >> number;
            userPuzzle.push_back(number);
        }
        cout << "Enter the third row, use space or tabs between numbers:" << endl;
        for(int i = 0; i < 3; ++i)
        {
            cin >> number;
            userPuzzle.push_back(number);
        }

        int len = 0;
        cout << "Confirming your puzzle: " << endl;
        for(int i = 0; i < userPuzzle.size(); ++i)
        {
            cout << userPuzzle[i] << " ";
            ++len;
            if((len % 3 == 0) && (len != 0))
            {
                cout << endl;
            }
        }
    }

    cout << endl;
    // Set the game up
    cout << "Enter your choice of algorithm\n"
        << "1) Uniform Cost Search\n"
        << "2) A* with the Misplaced Tile heuristic.\n"
        << "3) A* with the Manhattan distance heuristic\n" << endl;

	cin >> algoChoice;

    cout << endl;

    return 0;
}