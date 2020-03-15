#ifndef KNN_H
#define KNN_H

#include <vector>
using namespace std;
// maybe don't even have the dataset
class knn
{
    private:
        vector<double> dataset;
    public:
        knn();
        knn(vector<double>);
        double findNNClass();
};

#endif