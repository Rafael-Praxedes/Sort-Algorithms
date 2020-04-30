#include "countingSort.hpp"

long int MaxElement(vector<long int> &inputVector)
{
    long int maxElement = inputVector[0];

    for (size_t i = 1; i < inputVector.size(); i++){
        if (inputVector[i] > maxElement){
            maxElement = inputVector[i];
        }
    }
    return maxElement;
}

long int MinElement(vector<long int> &inputVector)
{
    long int minElement = inputVector[0];

    for (size_t i = 1; i < inputVector.size(); i++){
        if (inputVector[i] < minElement){
            minElement = inputVector[i];
        }
    }
    return minElement;
}

void InputEditor(vector<long int> &inputVector, bool normalize, long int minElement)
{
    for (size_t i = 0; i < inputVector.size(); i++){
       inputVector[i] += (normalize == 1) ? abs(minElement) : -1*abs(minElement);  
    }    
}

void CountingSort(vector<long int> &inputVector, vector<long int> &outputVector, long int k)
{
    vector<int> auxVector(k + 1, 0);
    
    for (int j = 0; j < inputVector.size(); j++){
        auxVector[inputVector[j]] += 1;
    }

    for (int i = 1; i < k + 1; i++){
        auxVector[i] += auxVector[i-1];
    }

    for (int j = inputVector.size() - 1; j >= 0; j--){
        outputVector[auxVector[inputVector[j]] - 1] = inputVector[j];
        
        auxVector[inputVector[j]] += -1; 
    }
}