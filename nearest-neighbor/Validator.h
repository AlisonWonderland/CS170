#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <vector>
using namespace std;
class Validator
{
    private:
        vector<vector<double>> dataset;
        int datasetCols;
        int datasetRows;
    public:
        Validator();
        Validator(string);
        void normalize();
        void validate(string);
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