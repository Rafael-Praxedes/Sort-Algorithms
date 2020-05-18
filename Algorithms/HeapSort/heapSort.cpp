#include "heapSort.hpp"

void MaxHeapify(vector<long int> &inputVector, int index, int heapSize)
{
    int leftChild = 2*index + 1;
    int rightChild = 2*index + 2;

    int indexHigherElement = index; 

    if(leftChild < heapSize && inputVector[leftChild] > inputVector[index]){
        indexHigherElement = leftChild;
    }
    if (rightChild < heapSize && inputVector[rightChild] > inputVector[indexHigherElement]){
        indexHigherElement = rightChild;
    }
    
    if(indexHigherElement != index){
        long int aux = inputVector[index];
        inputVector[index] = inputVector[indexHigherElement];
        inputVector[indexHigherElement] = aux;

        MaxHeapify(inputVector, indexHigherElement, heapSize);   
    }
}

void BuildMaxHeap(vector<long int> &inputVector, int heapSize)
{
    for(int i = heapSize/2 - 1; i >= 0; i--){
        MaxHeapify(inputVector, i, heapSize);
    } 
}

void HeapSort(vector<long int> &inputVector)
{
    int heapSize = inputVector.size();
    long int aux;

    BuildMaxHeap(inputVector, heapSize);

    for (int i = inputVector.size()-1; i > 0; i--){
        
        aux = inputVector[0];
        inputVector[0] = inputVector[i];
        inputVector[i] = aux;

        heapSize -= 1;

        MaxHeapify(inputVector, 0, heapSize);
    }
}