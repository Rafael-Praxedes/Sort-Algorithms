#include "selectionSort.hpp"

void SelectionSort(vector<long int> &inputVector)
{
    int min_pos;
    long int aux;

    for (size_t i = 0; i < inputVector.size() - 1; i++){
        
        min_pos = i;

        for (size_t j = i + 1; j < inputVector.size(); j++){
            if(inputVector[min_pos] > inputVector[j]){
                min_pos = j;
            }
        }
        if(min_pos != i){
            aux = inputVector[i];
            inputVector[i] = inputVector[min_pos];
            inputVector[min_pos] = aux;
        }
    }
}