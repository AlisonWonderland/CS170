#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <vector>
using namespace std;
// maybe don't even have the dataset
class Validator
{
    private:
        vector<vector<double>> dataset; // maybe use this
        // vector<string> dataset;
        // vector<double> 
        // int cols;
        // int rows;
    public:
        Validator();
        Validator(string);
        // double findNNClass();
};
#endif