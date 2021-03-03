CC=clang++
CFLAGS=-Wall -std=c++17
LFLAGS=-g

main: main.o
	$(CC) $(CFLAGS) -o main main.o $(LFLAGS)

main.o:
	$(CC) $(CFLAGS) -c -o main.o main.cpp $(LFLAGS)

clean:
	rm -f *.o main
