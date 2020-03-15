// using namespace std;

// knn::knn()
// {

// }

#include <cmath>
// #include <tuple>  
#include "knn.h"
using namespace std;

knn::knn()
{
    this->dataset = {2};
}

// maybe don't even have the dataset
knn::knn(vector<double> dataset)
{
    this->dataset = dataset;
}

// maybe pass in a map
// pass in the list of features.
// features = [1, 2, 3], numFeatures, featureSize = rows, dataset
// can save rows as a variable in dataset object
// pass id we're trying to classify
double knn::findNNClass()
{
    // double class = 0;
    // index, class
    // tuple<int, double> min(0, 0);
    // vector<double> classes = {0, 1, 0, 1, 0}
    // vector<double> feature1 = {2, 3, 4, 5, 6};
    double minDistance = 10000000.0;
    double nnClass = -1.0;

    double dataset[5][5] = {
        {0, 1, 0.01, 0.02, 0.02},
        {1, 2, 0.01, 0.01, 0.03},
        {2, 1, 0.02, 0.03, 0.02},
        {3, 1, 0.03, 0.02, 0.02},
        {4, 2, 0.05, 0.01, 0.05}
    };
    // double arr[row][col]
    // double dataset[5][2] = {
    //     {0, 2},
    //     {1, 3},
    //     {0, 4},
    //     {1, 5},
    //     {0, 6}
    // };
    int rows = 5;
    int numFeatures = 1;

    // instance we're trying to classify
    int classifyingID = 0;
    int features[] = {0};
    double distance = 0.0;

    // keep track of the one we're leaving out or have validator pass it in thru params
    for(int i = 0; i < rows; ++i)
    {
        if(i == classifyingID)
        {
            // don't do nn on the row that we're trying to classify
            continue;
        }
        // no need to look
        for(int j = 0; j < numFeatures; ++j)
        {
            // same features different row
            // i is row and j is column
            // cout << 
            distance += pow(dataset[i][features[j] + 2] - dataset[classifyingID][features[j] + 2], 2.0);
        }

        distance = sqrt(distance);
        if(distance < minDistance)
        {
            minDistance = distance;
            nnClass = dataset[i][1];
        }
        distance = 0;
    }

    return nnClass;
}

// add id to dataset? YES
// after returning nnClass, in the validator we check if this is right, if not then we don't add
// it to the accurate ccount. in validator return the double correct percentage