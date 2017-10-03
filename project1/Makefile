project1: main.o State.o
	g++ -g -Wall -std=c++11 -o project1 main.o
main.o: main.cpp
	g++ -g -Wall -std=c++11 -c main.cpp
State.o: State.cpp State.h
	g++ -g -Wall -std=c++11 -c State.cpp
clean:
	rm *.o project1
