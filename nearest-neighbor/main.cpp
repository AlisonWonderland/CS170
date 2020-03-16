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
    Validator test("cs_170_large16.txt");
    test.validate("forwards");
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
    // testValidator();
    // Validator vali("cs_170_large16.txt");

    cout << "Welcome to Marcos Leandro's Feature Selection Algorithm.\n"
        << "Type in the name of the file to test(\"cs_170_\" will be appended to the front of name):  ";
    
    cin >> testFile;

    Validator validator("cs_170_" + testFile);
    // read in file data.

    cout << "Type the number of the algorithm you want to run." 
        << endl
        << "    1) Forward Selection"
        << endl
        << "    2) Backward Elimination"
        << endl;

    cin >> userChoice;

    cout << endl << "This dataset has " << validator.getFeatures()
        << " features (not including the class attribute), with " 
        << validator.getInstances() << " instances" << endl;

    cout << "Please wait while I normalize the data...    Done" << endl;
    // normalize data

    cout << "Running nearest neighbor will all " <<  validator.getFeatures() 
        << " features, I get an accuracy of " << validator.fullSetAccuracy() << "%" << endl;

    cout << endl;
    
    if(userChoice == 1) 
    {
        // use forward
        validator.validate("forwards");
    }

    else if(userChoice == 2) 
    {
        // use backward
        validator.validate("backwards");
    }

    
    return 0;
}