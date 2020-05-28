#The executable file will be output
all: output

output: main.o startgame.o Initialization.o 
	g++ main.o startgame.o Initialization.o -o output
	
main.o: main.o
	g++ -c main.cpp

startgame.o: startgame.o
	g++ -c startgame.cpp

Initialization.o: Initialization.o 
	g++ -c Initialization.cpp

clean:
	rm -rf *o output