#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

#include <vector>
#include <string>

using namespace std;

//Functions
extern long int MaxElement(vector<long int> &inputVector);
extern long int MinElement(vector<long int> &inputVector);
extern void InputEditor(vector<long int> &inputVector, bool normalize, long int minElement);
extern void CountingSort(vector<long int> &inputVector, vector<long int> &outputVector, long int k);

#endif