#include "insertionSort.hpp"

void InsertionSort(vector<long int> &inputVector)
{
    long int aux;
    size_t j;

    for (size_t i = 1; i < inputVector.size(); i++){
        j = i;

        while (j > 0 && inputVector[j-1] > inputVector[j]){
            aux = inputVector[j-1];
            inputVector[j-1] = inputVector[j];
            inputVector[j] = aux;

            j--;
        }
    }
}