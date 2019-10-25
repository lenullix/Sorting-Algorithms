all: tp
tp: array.o sort.o main.o
	gcc -o tp array.o sort.o main.o
array.o: array.c array.h
	gcc -o array.o -c array.c
sort.o: sort.c sort.h array.h
	gcc -o sort.o -c sort.c
main.o: main.c sort.h
	gcc -o main.o -c main.c

clean:
	rm -rf *.o
