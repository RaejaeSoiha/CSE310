all: encoder

encoder: main.o hash.o
	g++ -o encoder main.o hash.o

main.o: main.cpp hash.h
	g++ -c main.cpp

hash.o: hash.cpp hash.h
	g++ -c hash.cpp

clean:
	rm -rf *.o encoder
