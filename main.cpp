/*****************************************/
/* Rafael Maranhão Rego Praxedes         */
/*                                       */
/* 04/04/2020                            */
/*                                       */
/* Sort Algorithms - Main Function       */
/*                                       */
/*****************************************/

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <chrono>

#include <stdlib.h>
#include "Algorithms/SelectionSort/selectionSort.hpp"

using namespace std;
using namespace std::chrono;

void GenerateDataFile(string fileName, int size, int limit)
{
    ofstream dataFile;
    dataFile.open("In/" + fileName);

    srand((unsigned) time(0));
    for(size_t i = 0; i < size; i++)
    {
        dataFile << -1*limit + rand() % (2*limit) << endl;
    }

    dataFile.close();
}

void ReadDataFile(string fileName, vector<long int> &data)
{
    ifstream dataFile;
    dataFile.open("In/" + fileName);

    string numberStr;

    if(dataFile.is_open()){
        while (getline(dataFile, numberStr)){
            data.push_back(stol(numberStr));
        }
    }
    else{
        //Generate data file
        cout << "The file " << fileName << " does not exist! Calling random file generate..." << endl;
        GenerateDataFile(fileName, 20, 100);
    }    
}

void WriteDataFile(string fileName, vector<long int> &data)
{
    ofstream dataFile;
    dataFile.open("Out/" + fileName);

    if(dataFile.is_open()){
        for (size_t i = 0; i < data.size(); i++){
            dataFile << data[i] << endl;
        }
    }
    else{
        cout << "Error on open output file" << endl;
    }
}

void PrintVector(vector<long int> &data)
{
    for(size_t i = 0; i < data.size(); i++){
        cout << data[i] << " ";
    }
    cout << endl;
}

int main(int argc, char** argv)
{
    //Read input file
    cout << "Read input file..." << endl;
    vector<long int> data;
    ReadDataFile(argv[1], data);

    //Print the input data
    //PrintVector(data);

    //Sort
    cout << "Sorting the data..." << endl;
    auto start = high_resolution_clock::now();
    SelectionSort(data);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\t >>> Sorting time: " << duration.count() << " us" << endl;

    //Write output file
    cout << "Write output file..." << endl;
    WriteDataFile(argv[2], data);

    //Print the output data
    //PrintVector(data);

    cout << "Finishing..." << endl;

    return 0;
}