#Rafael Maranhão Rego Praxedes

#Makefile

all:sort

sort:selectionSort.o insertionSort.o mergeSort.o quickSort.o main.o 
	g++ -std=c++11 selectionSort.o insertionSort.o mergeSort.o quickSort.o main.o -o sortingAlgorithms

selectionSort.o: Algorithms/SelectionSort/selectionSort.cpp
	g++ -std=c++11 -c Algorithms/SelectionSort/selectionSort.cpp

insertionSort.o: Algorithms/InsertionSort/insertionSort.cpp
	g++ -std=c++11 -c Algorithms/InsertionSort/insertionSort.cpp

mergeSort.o: Algorithms/MergeSort/mergeSort.cpp
	g++ -std=c++11 -c Algorithms/MergeSort/mergeSort.cpp

quickSort.o: Algorithms/QuickSort/quickSort.cpp
	g++ -std=c++11 -c Algorithms/QuickSort/quickSort.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

clean:
	rm -f *.o selectionSort *~
	rm -f *.o insertionSort *~
	rm -f *.o mergeSort *~
	rm -f *.o main *~
