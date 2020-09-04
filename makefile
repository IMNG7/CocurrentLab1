
#Makefile for the Lab0 for ECEN 5033

DEPS = main.o util.o quicksort.o mergesort.o
CC = g++

mysort: ${DEPS}
	${CC} ${DEPS} -o $@

*.o: *.cpp *.h
	${CC} -c *.cpp

clean :
	rm mysort *.o
