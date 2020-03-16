#include "Validator.h"
#include <iostream> // comment out later
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

Validator::Validator()
{
    return;
}

Validator::Validator(string filename)
{
    int id = 0;
    ifstream file(filename);
    vector<string> tempDataset;
    vector<double> row;
    size_t sz;
    vector<string> temp;

    // extract text
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            tempDataset.push_back(to_string(id) + line);
            ++id;
        }
        file.close();
    }
    
    this->datasetRows = id;

    // finding the number of columns, by finding values.
    stringstream ss(tempDataset.at(0));
    string item;
    while (ss >> item) {
        temp.push_back(item);
    }

    this->datasetCols = temp.size();

    // cout << this->datasetCols << " " << this->datasetRows << endl;

    for(int i = 0; i < tempDataset.size(); ++i)
    {
        stringstream ss(tempDataset.at(i));
        string item;
        while (ss >> item) {
           row.push_back(stod(item, &sz));
        }
        this->dataset.push_back(row);
        row.clear();
        // col = 0;
    }

    this->normalize();
    //  cout << this->dataset.at(99).at(11) << endl;
}

void Validator::normalize()
{
    vector<double> avgs;
    vector<double> stds;
    double avg = 0;
    double std = 0;

    // find avgs
    for(int i = 2; i < this->datasetCols; ++i)
    {
        for(int j = 0; j < this->datasetRows; ++j)
        {
            // if(i == this->datasetCols - 1)
            // {
            //     //  cout << this->dataset.at(j).at(i) << endl;
            // }
            avg += this->dataset.at(j).at(i);
        }
        avg /= this->datasetRows;
        avgs.push_back(avg);
        avg = 0;
    }

    // cout << avgs.at(0) << endl;

    // find standard deviations
    for(int i = 2; i < this->datasetCols; ++i)
    {
        for(int j = 0; j < this->datasetRows; ++j)
        {
            std += pow(this->dataset.at(j).at(i) - avgs.at(i - 2), 2.0);
        }
        std = sqrt(std / this->datasetRows);
        stds.push_back(std);
        std = 0;
    }

    // cout << stds.at(0) << endl;

    for(int i = 2; i < this->datasetCols; ++i)
    {
        for(int j = 0; j < this->datasetRows; ++j)
        {
            this->dataset.at(j).at(i) = (this->dataset.at(j).at(i) - avgs.at(i - 2)) / stds.at(i -2);
        }
    }

    // cout << this->dataset.at(0).at(2) << endl;
}

// pass in the features to validator and track accuracy, use one feature and then two.
// generate features

void Validator::validate(string algo)
{
    int correct = 0;
    double percentage = 0.0;
    double bestPercentage = 0.0;
    int bestFeatureIndex = 0.0;
    double previousFeatureSetPercentage = 0.0;

    vector<vector<int>> featuresSet;
    // initalize differently based on algo
    int maxCombos = 10; // 10 possible feature sets to test out.
    vector<int> bestFeatures;
    vector<int> selectedFeatures = {};

    if(algo == "backwards")
    {
        // backwardsElim();
        selectedFeatures = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    }
    
    cout << "Beginning search." << endl << endl;
    for(int j = 0; j < maxCombos; ++j)
    {
        if(algo == "backwards")
        {
            featuresSet = backwards(selectedFeatures);
        }
        else
        {
            featuresSet = forwards(selectedFeatures);
        }
        // cout << "here" << endl;
        for(int k = 0; k < featuresSet.size(); ++k)
        {
            // cout << "size2: " << featuresSet.at(k).size() << endl;
            // this->printFeatures(featuresSet.at(k));
            // ______
            cout << "   Using feature(s) ";
            printFeatures(featuresSet.at(k));
            for(int i = 0; i < this->datasetRows; ++i)
            {
                // cout << this->findNNClass(features, 2, i) << " " << this->dataset.at(i).at(1) << endl;
                // check if returned class matches the one in the class column for that row.
                if(this->findNNClass(featuresSet.at(k), featuresSet.at(k).size(), i) == this->dataset.at(i).at(1))
                {
                    ++correct;
                }
            }

            percentage = static_cast<double>(correct) / this->datasetRows;
            if(percentage > bestPercentage)
            {
                bestPercentage = percentage;
                bestFeatureIndex = k;
            }
            correct = 0;
            cout << " accuracy is " << percentage << "%" << endl;
        }

        cout << endl;
        if(bestPercentage > previousFeatureSetPercentage)
        {
            previousFeatureSetPercentage = bestPercentage;
            selectedFeatures = featuresSet.at(bestFeatureIndex);
            bestFeatures = featuresSet.at(bestFeatureIndex);
            cout << "Feature set: ";
            printFeatures(bestFeatures);
            cout << " was best, accuracy is " << bestPercentage << "%" << endl;
        }
        else
        {
            cout << "Finished Search!! The best feature subset is ";
            printFeatures(bestFeatures);
            cout << ", with an accuracy of " << bestPercentage << "%" << endl << endl;
            break;
        }
        // bestPercentage = 0;
        bestFeatureIndex = 0;
        // exit(0);
        // update selected features(highest accuracy)
        // print percentage
    }
    // cout << "cor " << correct << endl;
    // percentage = static_cast<double>(correct) / this->datasetRows;
    // cout << percentage << endl;
}

// void Validator::backwardsElim()
// {

// }

// void Validator::forwardsElim()
// {

// }

void Validator::printFeatures(vector<int> features)
{
    cout << "{";
    for(int j = 0; j < features.size(); ++j)
    {
        if(j == features.size() - 1)
        {
            cout << features.at(j);
        }
        else 
        {
            cout << features.at(j) << ",";
        }
    }
    cout << "}";
    // cout << endl;
    // cout << "+++++++++" << endl;
    return;
}

// void Validator::printFeaturesSet(vector<vector<int>> featuresSet)
// {
//     for(int i = 0; i < featuresSet.size(); ++i)
//     {
//         cout << "Using feature(s) {";
//         for(int j = 0; j < featuresSet.at(i).size(); ++j)
//         {
//             cout << featuresSet.at(i).at(j) << " ";
//         }
//         // cout << featuresSet.at(i) << " ";
//     }
//     cout << "}";
//     cout << endl;
//     cout << "+++++++++" << endl;
//     return;
// }

// maybe call forward and create a backwards function
vector<vector<int>> Validator::forwards(vector<int> selectedFeatures)
{
    vector<vector<int>> featuresSet;
    // exclude features in selectedFeatures

    for(int i = 0; i < this->datasetCols - 2; ++i)
    {
        vector<int> temp = selectedFeatures;
        if(!count(selectedFeatures.begin(), selectedFeatures.end(), i + 1))
        {
            temp.push_back(i + 1); // this was outside
            featuresSet.push_back(temp);
        }
    }

    // printFeaturesSet(featuresSet);

    return featuresSet;
}

// for backwards just create new sets by remvoing one
// ignore initial set
vector<vector<int>> Validator::backwards(vector<int> selectedFeatures)
{
    vector<vector<int>> featuresSet;
    // exclude features in selectedFeatures

    for(int i = 0; i < selectedFeatures.size(); ++i)
    {
        vector<int> temp = selectedFeatures;
        temp.erase(temp.begin() + i);
        featuresSet.push_back(temp);
    }

    for(int i = 0; i < featuresSet.size(); ++i)
    {
        for(int j = 0; j < featuresSet.at(i).size(); ++j)
        {
            // cout << featuresSet.at(i).at(j) << " ";
        }
        // cout << endl;
        // cout << "set " << i << " done." << "Size: " << featuresSet.at(i).size() << endl;
    }

    return featuresSet;
}


double Validator::findNNClass(vector<int> features, int numFeatures, int instanceID)
{
    // double class = 0;
    // index, class
    // tuple<int, double> min(0, 0);
    // vector<double> classes = {0, 1, 0, 1, 0}
    // vector<double> feature1 = {2, 3, 4, 5, 6};
    double minDistance = 10000000.0;
    double nnClass = -1.0;
    // double accuracy = 0.0;
    // double dataset[5][5] = {
    //     {0, 1, 0.01, 0.02, 0.02},
    //     {1, 2, 0.01, 0.01, 0.03},
    //     {2, 1, 0.02, 0.03, 0.02},
    //     {3, 1, 0.03, 0.02, 0.02},
    //     {4, 2, 0.05, 0.01, 0.05}
    // };
    // double arr[row][col]
    // double dataset[5][2] = {
    //     {0, 2},
    //     {1, 3},
    //     {0, 4},
    //     {1, 5},
    //     {0, 6}
    // };

    // int rows = 5;
    // int numFeatures = 2;

    // instance we're trying to classify, put in loop
    // int classifyingID = 0;
    // int features[] = {0, 1};
    double distance = 0.0;

    // if(instanceID == 0)
    // {
    //     cout << "row 1 col3 " << this->dataset.at(1).size() << endl;
    //     cout << "row 1 col5 " << this->dataset.at(1).at(0) << endl;
    //     cout << "row 1 col7 " << this->dataset.at(1).at(7) << endl;
    // }

    // nested ??
    // keep track of the one we're leaving out or have validator pass it in thru params
    for(int i = 0; i < this->datasetRows; ++i)
    {
        if(i == instanceID)
        {
            // don't do nn on the row that we're trying to classify
            continue;
        }
        // no need to look
        for(int j = 0; j < numFeatures; ++j)
        {
            // if(i == 1 && instanceID == 0)
            // {
            //     // cout << features[j] + 1 << endl;
            //     cout << "row 1/col3,5,7: " << dataset.at(i).at(features[j] + 1) << endl;
            // }
            // cout << "feature1" << endl;
            distance += pow(dataset.at(i).at(features[j] + 1) - dataset.at(instanceID).at(features[j] + 1), 2.0);
            // cout << "feature1" << endl;
        }

        distance = sqrt(distance);
        
        if(distance < minDistance)
        {
            minDistance = distance;
            // class is in the second column, that's why I have .at(1)
            nnClass = dataset.at(i).at(1);
        }
        distance = 0;
    }

    return nnClass;
}

int Validator::getFeatures()
{
    return this->datasetCols - 2;
}

int Validator::getInstances()
{
    return this->datasetRows;
}

double Validator::fullSetAccuracy()
{
    vector<int> fullset;
    int correct = 0;

    for(int i = 0; i < this->getFeatures(); ++i)
    {
        fullset.push_back(i + 1);
    }

    for(int i = 0; i < fullset.size(); ++i)
    {
        if(this->findNNClass(fullset, fullset.size(), i) == this->dataset.at(i).at(1))
        {
            ++correct;
        }
    }

    // percentage = static_cast<double>(correct) / this->datasetRows;
    return static_cast<double>(correct) / this->datasetRows;
}