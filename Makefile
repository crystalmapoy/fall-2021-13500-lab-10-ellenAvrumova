# Author: Ellen Avrumova
# Course: CSCI-135
# Instructor: Tong Yi & Mike Zamansky
# Assignment: Lab 10 A-E
# 
# This is the Makefile file for all parts of Lab10.

main: main.o time.o
	g++ -o main main.o time.o

tests: tests.o time.o
	g++ -o tests tests.o time.o

time.o: time.cpp time.h movie.h timeslot.h
	g++ -c time.cpp

main.o: main.cpp time.h movie.h timeslot.h
	g++ -c main.cpp

tests.o: tests.cpp doctest.h time.h movie.h timeslot.h
	g++ -c tests.cpp -std=c++11

clean:
	rm -f *.o