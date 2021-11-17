main: main.o time.o
	g++ -o main main.o time.o

#tests: tests.o time.o
#	g++ -o tests tests.o time.o

time.o: time.cpp time.h
	g++ -c time.cpp

main.o: main.cpp time.h
	g++ -c main.cpp

#tests.o: tests.cpp doctest.h time.h
#	g++ -c tests.cpp -std=c++11

clean:
	rm -f *.o