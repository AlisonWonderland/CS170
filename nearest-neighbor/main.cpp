#include <iostream>
#include <string>
#include <vector>
#include "knn.h"
#include "Validator.h"
using namespace std;

void testKNN()
{
    knn test;
    cout << test.findNNClass() << endl;
    exit(0);
}

void testValidator()
{
    Validator test("cs_170_small80.txt");
    // cout << test.printData() << endl;
    exit(0);
}

int main()
{
    int userChoice = 0;
    int number = 0;
    int algoChoice = 0;
    string testFile;
    vector<int> userPuzzle;

    // remove when done;
    // testKNN();
    testValidator();

    cout << "Welcome to Marcos Leandro's Feature Selection Algorithm.\n"
        << "Type in the name of the file to test:  ";
    
    cin >> testFile;

    // read in file data.

    cout << "Type the number of the algorithm you want to run." 
        << endl
        << "    1) Forward Selection"
        << endl
        << "    2) Backward Elimination"
        << endl;

    cin >> userChoice;

    cout << "This dataset has " 
        << " features (not including the class attribute), with " 
        << "instances" << endl;

    cout << "Please wait while I normalize the data...     ";
    // normalize data
    cout << "";

    if(userChoice == 1) 
    {
        // use forward
    }

    else if(userChoice == 2) 
    {
        // use backward
    }

    
    return 0;
}