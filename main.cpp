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
#include "Algorithms/MergeSort/mergeSort.hpp"
#include "Algorithms/QuickSort/quickSort.hpp"
#include "Algorithms/CountingSort/countingSort.hpp"

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
    else if(argv[1] == string("merge") || argv[1] == string("Merge"))
    {
        auto start = high_resolution_clock::now();
        MergeSort(data, 0, data.size() - 1);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\t >>> Merge Sort time: " << duration.count() << " us" << endl;
    }
    else if(argv[1] == string("quick") || argv[1] == string("Quick"))
    {
        if(argc < 5){
            cout << "Error! Unspecified SelectPivot Function!" << endl;
            return -1;
        }

        if (argv[4] != string("median") && argv[4] != string("Median") && argv[4] != string("random") && argv[4] != string("Random") 
            && argv[4] != string("first") && argv[4] != string("First")){
            cout << ">> SelectPivot Function: Invalid mode! The pivot will be the first element of vector" << endl;
        }
        auto start = high_resolution_clock::now();
        QuickSort(data, 0, data.size() - 1, argv[4]);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\t >>> Quick Sort time: " << duration.count() << " us" << endl;
    }
    else if(argv[1] == string("counting") || argv[1] == string("Counting")){
        
        vector<long int> dataOut(data.size());
        int minElement = MinElement(data);
        
        InputEditor(data, 1, minElement);
        
        auto start = high_resolution_clock::now();
        CountingSort(data, dataOut, MaxElement(data));
        auto stop = high_resolution_clock::now();

        InputEditor(dataOut, 0, minElement);

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\t >>> Counting Sort time: " << duration.count() << " us" << endl;
        
        for (size_t i = 0; i < data.size(); i++){
            data[i] = dataOut[i];
        }
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