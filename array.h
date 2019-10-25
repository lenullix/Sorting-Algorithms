#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct para uma variavel inteiro
typedef struct{
	int key;
}TItem;

// Struct para o array utilizando a struct anterior
typedef struct{
	TItem* item;
	int n;
}TArray;

// Declarações das funções de alocamento, liberamento e geramento do array
void allocateArray(TArray*, int);
void freeArray(TArray*);
void printArray(TArray*);
int isSorted(TArray*);
void generateSorted(TArray*, int);
void generateInvert(TArray*,int);
void generateRandom(TArray*, int);
void generateRandomNoRep(TArray*, int);
void generateAlmostSorted(TArray*,int);
void generateAlmostSortedNoRep(TArray*,int);
