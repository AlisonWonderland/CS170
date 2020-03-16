#include "Validator.h"
#include <iostream> 
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

    for(int i = 0; i < tempDataset.size(); ++i)
    {
        stringstream ss(tempDataset.at(i));
        string item;
        while (ss >> item) {
           row.push_back(stod(item, &sz));
        }
        this->dataset.push_back(row);
        row.clear();
    }

    this->normalize();
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
            avg += this->dataset.at(j).at(i);
        }
        avg /= this->datasetRows;
        avgs.push_back(avg);
        avg = 0;
    }

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

    for(int i = 2; i < this->datasetCols; ++i)
    {
        for(int j = 0; j < this->datasetRows; ++j)
        {
            this->dataset.at(j).at(i) = (this->dataset.at(j).at(i) - avgs.at(i - 2)) / stds.at(i -2);
        }
    }
}

void Validator::validate(string algo)
{
    int correct = 0;
    double percentage = 0.0;
    double bestPercentage = 0.0;
    int bestFeatureIndex = 0.0;
    double previousFeatureSetPercentage = 0.0;

    vector<vector<int>> featuresSet;
    int maxCombos = 10; // 10 possible feature sets to test out.
    vector<int> bestFeatures;
    vector<int> selectedFeatures = {};

    if(algo == "backwards")
    {
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
        for(int k = 0; k < featuresSet.size(); ++k)
        {
            cout << "   Using feature(s) ";
            printFeatures(featuresSet.at(k));
            for(int i = 0; i < this->datasetRows; ++i)
            {
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
        bestFeatureIndex = 0;
    }
}


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
    return;
}

// create feature combination sets
vector<vector<int>> Validator::forwards(vector<int> selectedFeatures)
{
    vector<vector<int>> featuresSet;

    for(int i = 0; i < this->datasetCols - 2; ++i)
    {
        vector<int> temp = selectedFeatures;
        if(!count(selectedFeatures.begin(), selectedFeatures.end(), i + 1))
        {
            temp.push_back(i + 1);
            featuresSet.push_back(temp);
        }
    }

    return featuresSet;
}

// create feature combination sets
vector<vector<int>> Validator::backwards(vector<int> selectedFeatures)
{
    vector<vector<int>> featuresSet;

    for(int i = 0; i < selectedFeatures.size(); ++i)
    {
        vector<int> temp = selectedFeatures;
        temp.erase(temp.begin() + i);
        featuresSet.push_back(temp);
    }

    return featuresSet;
}


double Validator::findNNClass(vector<int> features, int numFeatures, int instanceID)
{
    double minDistance = 10000000.0;
    double nnClass = -1.0;
    double distance = 0.0;

    for(int i = 0; i < this->datasetRows; ++i)
    {
        if(i == instanceID)
        {
            // don't do nn on the row that we're trying to classify
            continue;
        }
        for(int j = 0; j < numFeatures; ++j)
        {
            distance += pow(dataset.at(i).at(features[j] + 1) - dataset.at(instanceID).at(features[j] + 1), 2.0);
        }

        distance = sqrt(distance);
        
        if(distance < minDistance)
        {
            minDistance = distance;
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

    return static_cast<double>(correct) / this->datasetRows;
}