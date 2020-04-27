#include "quickSort.hpp"
#include "../InsertionSort/insertionSort.hpp"

int FindElement(vector<long int> &vector, int element, int start, int end)
{   
    for (size_t i = start; i <= end; i++){
        if(vector[i] == element)
            return i;
    }
}

int SelectPivot(vector<long int> &inputVector, string mode, int start, int end)
{
    long int aux;
    int pivot_pos;

    if(mode == "median" || mode == "Median"){
        if ((end - start + 1) >= SUBVECTOR_SIZE){
            vector<long int> subVector(SUBVECTOR_SIZE);
            copy(inputVector.begin() + start, inputVector.begin() + start + SUBVECTOR_LAST_POSITION + 1, subVector.begin());
            
            InsertionSort(subVector);

            aux = inputVector[start];
            inputVector[start] = subVector[SUBVECTOR_LAST_POSITION/2]; // (0 + 6)/2 = 3
            inputVector[FindElement(inputVector, subVector[SUBVECTOR_LAST_POSITION/2], start, start + SUBVECTOR_LAST_POSITION)] = aux;  
        }
    }
    else if(mode == "random" || mode == "Random"){
        
        srand((unsigned) time(0));
        pivot_pos = start + (rand() % (end - start + 1));
        
        aux = inputVector[start];
        inputVector[start] = inputVector[pivot_pos];
        inputVector[pivot_pos] = aux;
    }
    
    return start;    
}

int Partition(vector<long int> &inputVector, int start, int end, string mode)
{
    int pivot_pos = SelectPivot(inputVector, mode, start, end);
    long int pivot = inputVector[pivot_pos];

    int i = start - 1;
    int j = end + 1;

    long int aux; 

    while (true){
        
        do{
            ++i;
        } while(i <= end && inputVector[i] <= pivot);
        
        do{
            --j;
        } while (j >= start && inputVector[j] > pivot);
        
        if(i >= j)
            break;
        
        aux = inputVector[i];
        inputVector[i] = inputVector[j];
        inputVector[j] = aux;
    }

    inputVector[pivot_pos] = inputVector[j];
    inputVector[j] = pivot;

    return j;
}

void QuickSort(vector<long int> &inputVector, int l, int r, string mode)
{
    int q;

    if(l < r){
        q = Partition(inputVector, l, r, mode);

        QuickSort(inputVector, l, q-1, mode);
        QuickSort(inputVector, q+1, r, mode);
    }
}