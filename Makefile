main: main.o shared_memory.o
	g++ -Wall -o main main.o shared_memory.o -lrt
shared_memory.o: shared_memory.cpp
	g++ -Wall -c shared_memory.cpp
main.o: main.cpp
	g++ -Wall -c main.cpp
clean:
	rm -f *.o main

