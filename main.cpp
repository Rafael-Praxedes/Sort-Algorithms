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
#include "Algorithms/InsertionSort/insertionSort.hpp"

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
    string numberStr;

    while (data.size() == 0){
        
        dataFile.open("In/" + fileName);
        
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
    dataFile.close();    
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
    dataFile.close();
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
    cout << ">>>>>>>>>>>>>>>>>>>> " << string(argv[2]) << " <<<<<<<<<<<<<<<<<<<<" << endl;

    //Read input file
    cout << "Read input file..." << endl;
    vector<long int> data;
    ReadDataFile(argv[2], data);

    //Print the input data
    //PrintVector(data);

    //Sort
    cout << "Sorting the data..." << endl;
    
    if(argv[1] == string("selection") || argv[1] == string("Selection")){
        auto start = high_resolution_clock::now();
        SelectionSort(data);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\t >>> Selection Sort time: " << duration.count() << " us" << endl;
    }
    else if(argv[1] == string("insertion") || argv[1] == string("Insertion")){
        auto start = high_resolution_clock::now();
        InsertionSort(data);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\t >>> Insertion Sort time: " << duration.count() << " us" << endl;
    }
    else{
        cout << "Invalid method! Please try again, inserting one of below options on correspondent method argument: " << endl;
        cout << "\t >>> <selection> or <Selection> " << endl;
        cout << "\t >>> <insertion> or <Insertion> " << endl;

        return -1;
    }

    //Write output file
    cout << "Write output file..." << endl;
    WriteDataFile(argv[3], data);

    //Print the output data
    //PrintVector(data);

    cout << "Finishing...\n" << endl;

    return 0;
}