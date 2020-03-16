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
        int datasetCols;
        int datasetRows;
    public:
        Validator();
        Validator(string);
        void normalize();
        // create forwards/backwards()
        // create outputstream test function.
        void validate(string);
        // returns accuracy percentage of features used
        double findNNClass(vector<int>, int, int);
        vector<vector<int>> backwards(vector<int>);
        vector<vector<int>> forwards(vector<int>);
        void printFeatures(vector<int>);
        void printFeaturesSet(vector<vector<int>>);
        double fullSetAccuracy();
        int getFeatures(); // cols
        int getInstances(); // rows
};
#endif