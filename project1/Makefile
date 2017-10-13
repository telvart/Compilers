project1: main.o State.o ConvertHelper.o DFAState.o
	g++ -g -Wall -std=c++11 -o project1 main.o State.o ConvertHelper.o DFAState.o
main.o: main.cpp
	g++ -g -Wall -std=c++11 -c main.cpp
State.o: State.cpp
	g++ -g -Wall -std=c++11 -c State.cpp
ConvertHelper.o: ConvertHelper.cpp
	g++ -g -Wall -std=c++11 -c ConvertHelper.cpp
DFAState.o: DFAState.cpp
	g++ -g -Wall -std=c++11 -c DFAState.cpp
clean:
	rm *.o project1
