#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>
#include <limits.h>

using namespace std;

//Functions
extern void Merge(vector<long int> &inputVector, int p, int q, int r);
extern void MergeSort(vector<long int> &inputVector, int p, int r);

#endif