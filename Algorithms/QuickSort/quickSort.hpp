#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

#define SUBVECTOR_LAST_POSITION 6
#define SUBVECTOR_SIZE 7

using namespace std;

//Functions
extern int FindElement(vector<long int> &vector, int element, int start, int end);
extern int SelectPivot(vector<long int> &inputVector, string mode, int start, int end);
extern int Partition(vector<long int> &inputVector, int start, int finish, string mode);
extern void QuickSort(vector<long int> &inputVector, int l, int r, string mode);

#endif