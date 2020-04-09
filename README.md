# Sort-Algorithms
A set of sorting algorithms, implemented in C++ Language.

## Running the program

### Running all input files (all instances)
Follow the below steps to running the program:
- Open a new treminal in folder "Sort-Algorithms"
- If exceutable file "sortingAlgorithms" does not exist, execute the command "make"
```sh
$ make
```
- Execute the python script "run.py", choosing the sorting method
```sh
$ python3 run.py selection
```
```sh
$ python3 run.py insertion
```
### Running specific input file (one instance)
Follow the below steps to running the program:
	
- Open a new treminal on folder "Sort-Algorithms"
- Execute the command "make" to compile source files
```sh
$ make
``` 
- Execute the command "./sortingAlgorithms 'method' 'inputFile' 'outputFile'"
```sh
$ ./sortingAlgorithms selection num.1000.1.in num.1000.1.out
```
```sh
$ ./sortingAlgorithms insertion num.1000.1.in num.1000.1.out
```
if specified input file does not exist, an another input file with 20 random elements that belonging to the range -100 to 100 is created

## Complexity functions

In this section, the complexity functions for the "Insertion sort" and "Selectuin Sort" methods will be presented. 

### Selection Sort

```c++
void SelectionSort(vector<long int> &inputVector)
{ 
    int min_pos;						   // (1)
    long int aux;						   // (2)

    for (size_t i = 0; i < inputVector.size() - 1; i++){	   // (3)
        
        min_pos = i;						   // (4)

        for (size_t j = i + 1; j < inputVector.size(); j++){	   // (5)
            if(inputVector[min_pos] > inputVector[j]){		   // (6)
                min_pos = j;					   // (7)
            }
        }
        if(min_pos != i){					   // (8)
            aux = inputVector[i];				   // (9)
            inputVector[i] = inputVector[min_pos];		   // (10)
            inputVector[min_pos] = aux;				   // (11)
        }
    }
}
```

### Insertion Sort 
