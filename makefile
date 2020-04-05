#Rafael Maranhão Rego Praxedes

#Makefile

all:sort

sort:selectionSort.o main.o 
	g++ -std=c++11 selectionSort.o main.o -o sortingAlgorithms

selectionSort.o: Algorithms/SelectionSort/selectionSort.cpp
	g++ -std=c++11 -c Algorithms/SelectionSort/selectionSort.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

clean:
	rm -f *.o selectionSort *~
	rm -f *.o main *~
