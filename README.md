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
```sh
$ python3 run.py merge
```
```sh
$ python3 run.py quick <mode>
```
```sh
$ python3 run.py counting
```
```sh
$ python3 run.py radix
```
```sh
$ python3 run.py heap
```
- Obs.: 
	- If the selected method is quick sort, it is necessary specify the pivot selection mode "first", "median" or "random". 

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
```sh
$ ./sortingAlgorithms merge num.1000.1.in num.1000.1.out
```
```sh
$ ./sortingAlgorithms quick num.1000.1.in num.1000.1.out <mode>
```
```sh
$ ./sortingAlgorithms counting num.1000.1.in num.1000.1.out
```
```sh
$ ./sortingAlgorithms radix num.1000.1.in num.1000.1.out
```
```sh
$ ./sortingAlgorithms heap num.1000.1.in num.1000.1.out
```
- Obs.: 
	- If the selected method is quick sort, it is necessary specify the pivot selection mode "first", "median" or "random".
	- If specified input file does not exist, an another input file with 20 random elements that belonging to the range -100 to 100 is created

## Complexity functions

The complexity functions of sorting algorithms are described in file "ComplexidadeFuncoes.pdf". Thus, it is recommended to read this file, in folder "PDF", in order to obtain information about them.
