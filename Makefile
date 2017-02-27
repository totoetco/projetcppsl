CFLAGS=-std=c++11

all: main

main: main.o Environment.o Gap.o Cell.o Cell_A.o Cell_B.o
	g++ $(CFLAGS) -g main.o Environment.o Ĝap.o Cell.o Cell_A.o Cell_B.o -o main
main.o: main.cpp Environment.h Gap.h Cell.h cell_A.h cell_B.h
	g++ $(CFLAGS) -c main.cpp -g -o main.o
Environment.o: Environment.cpp Environment.h
	g++ $(CFLAGS) -c Environment.cpp -g -o Environment.o
Gap.o: Gap.cpp Gap.h
	g++ $(CFLAGS) -c Gap.cpp -g -o Gap.o
Cell.o: Cell.cpp Cell.h
	g++ $(CFLAGS) -c Cell.cpp -g -o Cell.o
Cell_A.o: Cell_A.cpp Cell_A.h
	g++ $(CFLAGS) -c Cell_A.cpp -g -o Cell_A.o
Cell_B.o: Cell_B.cpp Cell_B.h
	g++ $(CFLAGS) -c Cell_B.cpp -g -o Cell_B.o

clean:
	rm -f *.o