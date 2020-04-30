#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include <vector>

#define DECIMAL_SET_SIZE 10

using namespace std;

//Functions
extern void RadixCountSort(vector<long int> &inputVector, vector<long int> &outputVector, int exp);
extern void RadixSort(vector<long int> &inputVector, vector<long int> &outputVector, long int maxElement);

#endif