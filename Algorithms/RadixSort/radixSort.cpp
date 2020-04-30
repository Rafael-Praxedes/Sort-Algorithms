#include "radixSort.hpp"
#include "../CountingSort/countingSort.hpp"

void RadixCountSort(vector<long int> &inputVector, vector<long int> &outputVector, int exp)
{
    vector<int> auxVector(DECIMAL_SET_SIZE, 0);
    
    for (int j = 0; j < inputVector.size(); j++){
        auxVector[(inputVector[j]/exp) % DECIMAL_SET_SIZE] += 1;
    }

    for (int i = 1; i < DECIMAL_SET_SIZE; i++){
        auxVector[i] += auxVector[i-1];
    }

    for (int j = inputVector.size() - 1; j >= 0; j--){
        outputVector[auxVector[(inputVector[j]/exp) % DECIMAL_SET_SIZE] - 1] = inputVector[j];
        
        auxVector[(inputVector[j]/exp) % DECIMAL_SET_SIZE] += -1; 
    }
}

void RadixSort(vector<long int> &inputVector, vector<long int> &outputVector, long int maxElement)
{
    for (int exp = 1; maxElement/exp > 0; exp *= 10){
        RadixCountSort(inputVector, outputVector, exp);

        for (int i = 0; i < inputVector.size(); i++){
            inputVector[i] = outputVector[i];
        }
    }
}