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

| Instruction  | Cost | Number of executions |
| ------------- | ------------- | ------------- |
| 1  | C1  |	1	|
| 2  | C2  |	1	|
| 3  | C3  |	n	|
| 4  | C4  |	n-1	|
| 5  | C5  |	(n(n+1))/2 - 1 	|
| 6  | C6  |	(n(n-1))/2	|
| 7  | C7  |	(n(n-1))/2	|
| 8  | C8  |	n-1	|
| 9  | C9  |	n-1	|
| 10  | C10  |	n-1	|
| 11  | C11  |	n-1	|


![equation](https://latex.codecogs.com/gif.latex?T%28n%29%20%3D%20a%20n%5E2%20&plus;%20b%20n%20&plus;%20c)

![a](https://latex.codecogs.com/gif.latex?a%20%3D%20%5Cfrac%7BC5%20&plus;%20C6%20&plus;%20C7%7D%7B2%7D)
![b](https://latex.codecogs.com/gif.latex?b%20%3D%20C3%20&plus;%20C4%20&plus;%20%5Cfrac%7BC5%7D%7B2%7D%20-%20%5Cfrac%7BC6%7D%7B2%7D%20-%20%5Cfrac%7BC7%7D%7B2%7D%20&plus;%20C8%20&plus;%20C9%20&plus;%20C10%20&plus;%20C11)
![c](https://latex.codecogs.com/gif.latex?c%20%3D%20C1%20&plus;%20C2%20-%20C4%20-%20C5%20-%20C9%20-%20C10%20-%20C11)

### Insertion Sort 


