
#Makefile for the Lab0 for ECEN 5033

mysort: main.o util.o quicksort.o mergesort.o
	g++ main.o util.o quicksort.o mergesort.o -o mysort

*.o: *.cpp *.h
	g++ -c *.cpp

clean :
	rm mysort *.o