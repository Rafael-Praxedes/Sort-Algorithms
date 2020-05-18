#Rafael Maranhão Rego Praxedes

#Makefile

all:sort

sort:selectionSort.o insertionSort.o mergeSort.o quickSort.o countingSort.o radixSort.o heapSort.o main.o 
	g++ -std=c++11 selectionSort.o insertionSort.o mergeSort.o quickSort.o countingSort.o radixSort.o heapSort.o main.o -o sortingAlgorithms

selectionSort.o: Algorithms/SelectionSort/selectionSort.cpp
	g++ -std=c++11 -c Algorithms/SelectionSort/selectionSort.cpp

insertionSort.o: Algorithms/InsertionSort/insertionSort.cpp
	g++ -std=c++11 -c Algorithms/InsertionSort/insertionSort.cpp

mergeSort.o: Algorithms/MergeSort/mergeSort.cpp
	g++ -std=c++11 -c Algorithms/MergeSort/mergeSort.cpp

quickSort.o: Algorithms/QuickSort/quickSort.cpp
	g++ -std=c++11 -c Algorithms/QuickSort/quickSort.cpp

countingSort.o: Algorithms/CountingSort/countingSort.cpp
	g++ -std=c++11 -c Algorithms/CountingSort/countingSort.cpp

radixSort.o: Algorithms/RadixSort/radixSort.cpp
	g++ -std=c++11 -c Algorithms/RadixSort/radixSort.cpp

heapSort.o: Algorithms/HeapSort/heapSort.cpp
	g++ -std=c++11 -c Algorithms/HeapSort/heapSort.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

clean:
	rm -f *.o selectionSort *~
	rm -f *.o insertionSort *~
	rm -f *.o mergeSort *~
	rm -f *.o quickSort *~
	rm -f *.o coutingSort *~
	rm -f *.o radixSort *~
	rm -f *.o heapSort *~
	rm -f *.o main *~
