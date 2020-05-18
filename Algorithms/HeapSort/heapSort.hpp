#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <vector>

using namespace std;

//Functions
extern void MaxHeapify(vector<long int> &inputVector, int index, int heapSize);
extern void BuildMaxHeap(vector<long int> &inputVector, int heapSize);
extern void HeapSort(vector<long int> &inputVector);

#endif