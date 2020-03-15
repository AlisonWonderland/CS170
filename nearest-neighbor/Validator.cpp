#include "Validator.h"
#include <iostream> // comment out later
#include <sstream>
#include <fstream>
using namespace std;

Validator::Validator()
{
    return;
}

Validator::Validator(string filename)
{
    int id = 0;
    int cols = 0;
    int rows = 0;
    ifstream file(filename);
    vector<string> tempDataset;
    // double* test;
    // make a temp dataset with the strings to find rows and cols.

    // extract text
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            tempDataset.push_back(to_string(id) + line);
            ++id;
        }
        file.close();
    }

    rows = id;
    // cout << rows << " " << tempDataset.size() << endl;

    vector<string> temp;
    size_t sz;

    // finding the number of columns
    stringstream ss(tempDataset.at(0));
    string item;
    while (ss >> item) {
        // cout << stod(item,&sz) << endl;
        // if(item != " ")
        // {
        //     cout << item << endl;
            temp.push_back(item);
        // }
    }
    cols = temp.size();

    cout << cols << " " << rows << endl;

    // this->dataset = vector<vector<int>>(rows)
    double data[rows][cols];
    vector<double> temp2;

    int col = 0;
    int row = 0;

    for(int i = 0; i < tempDataset.size(); ++i)
    {
        stringstream ss(tempDataset.at(i));
        string item;
        while (ss >> item) {
            // data[0][0] = 0.0;
        //    cout << "here";
        //    data[i][col] = stod(item, &sz);
           temp2.push_back(stod(item, &sz));
           ++col;
        //    cout << "col: " << col << endl;
        }
        // cout << "i: " <<  i << endl;
        // cout << "col: " << col << endl;
        this->dataset.push_back(temp2);
        temp2.clear();
        col = 0;
    }
    // this->dataset = new double*[rows][cols];
    // this->dataset = data;

    for(int i = 99; i < rows; ++i)
    {
        for(int j = 11; j < cols; ++j)
        {
            cout << this->dataset.at(i).at(j) << endl;
        }
    }


    // looking for num cols.
    // cout << tempDataset.at(0) << endl;
    // string tempStr = tempDataset.at(0);
    // int start, end = 0;

    // for(int i = 0; i < tempStr.size(); ++i)
    // {
    //     if(tempStr.at(i) != ' ')
    //     {
    //         cout << tempStr.at(i) << endl;
    //         // temp.push_back(tempDataset.at(i));
    //     }
    // }
    // cout << temp.size() << endl;

    // for(int i = 0; i < tempDataset.size(); ++i)
    // {

    //     // stringstream ss(tempDataset.at(i));
    //     // string item;
    //     // while (getline(ss, item, ' ')) {
    //     //     elems.push_back(stod(item,&sz));
    //     // }
    // }
}

// void Validator::Validate()
// {

// }