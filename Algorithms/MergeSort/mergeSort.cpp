#include "mergeSort.hpp"

void Merge(vector<long int> &inputVector, int p, int q, int r)
{
    vector<long int> left(q - p + 1);
    copy(inputVector.begin() + p, inputVector.begin() + q + 1, left.begin());

    vector<long int> right(r - q); // r - (q + 1) + 1 = r - q
    copy(inputVector.begin() + q + 1, inputVector.begin() + r + 1, right.begin());
    
    left.push_back(INT_MAX);
    right.push_back(INT_MAX);

    size_t i = 0;
    size_t j = 0;

    for(int k = p; k < (r+1); k++){
        if(left[i] < right[j]){
            inputVector[k] = left[i];
            i++;
        }
        else{
            inputVector[k] = right[j];
            j++;
        }
    }
}

void MergeSort(vector<long int> &inputVector, int p, int r)
{
    int q;
    
    if(p < r){
        
        q = (p + r)/2;

        MergeSort(inputVector, p, q);
        MergeSort(inputVector, q + 1, r);
        Merge(inputVector, p, q, r);
    }
}