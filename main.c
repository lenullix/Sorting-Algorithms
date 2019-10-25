#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strcmp
#include <time.h>   //clock
#include "sort.h"


int main(int argc, char* argv[]){
	//lendo parametros de linha de comando.
	char* ALG = argv[1];
	int   NUM = atoi(argv[2]);
	char* SIT = argv[3];
	int PRINT = (argc == 5);
	if(NUM == 0){
		printf("ERRO: NUM DE ELEMENTOS DESCONHECIDO\n");
		exit(1);
	}

	TArray A;
	allocateArray(&A, NUM);

	//gerando o vetor
	printf("gerando o vetor...\n");
	if(strcmp(SIT, "ordc") == 0)
		generateSorted(&A, A.n);
	else if(strcmp(SIT, "ordi") == 0)
		generateInvert(&A, A.n);
	else if(strcmp(SIT, "ale") == 0)
		generateRandomNoRep(&A, A.n);
	else if(strcmp(SIT, "qord") == 0)
		generateAlmostSortedNoRep(&A, A.n);
	else{
		printf("ERRO: SITUACAO DO VETOR DESCONHECIDA\n");
		freeArray(&A);
		exit(1);
	}

	if(PRINT) printArray(&A);
       // printArray(&A);
	long att = 0, comp = 0;
	long time = 0;

	//ordenando o vetor
	printf("ordenando o vetor...\n");
	// Caso seja para executar Bubble-sort
	if(strcmp(ALG, "bub") == 0){
		time = clock();
		bubbleSort(&A, &att, &comp);
		time = clock() - time;
	}else if(strcmp(ALG, "bubo") == 0){ // Caso seja para executar Bubble-sort otimizado
		time = clock();
		bubbleSortO(&A, &att, &comp);
		time = clock() - time;
	}else if(strcmp(ALG, "sel") == 0){// Caso seja para executar Selection-sort
		time = clock();
		selectSort(&A, &att, &comp);
		time = clock() - time;
	}else if(strcmp(ALG, "selo") == 0){ // Caso seja para executar Selection-sort otimizado
		time = clock();
		selectSortO(&A, &att, &comp);
		time = clock() - time;
	}else if(strcmp(ALG, "ins") == 0){// Caso seja para executar Insertion-sort
		time = clock();
		insertionSort(&A, &att, &comp);
		time = clock() - time;
	}else if(strcmp(ALG, "inso") == 0){// Caso seja para executar Insertion-sort otimizado
		time = clock();
		insertionSortO(&A, &att, &comp);
		time = clock() - time;
	}else if(strcmp(ALG, "shell") == 0){// Caso seja para executar Shell-sort
		time = clock();
		shellSort(&A, &att, &comp);
		time = clock() - time;
	}else if(strcmp(ALG, "qui") == 0){// Caso seja para executar Quick-sort
		time = clock();
		int left = 0;
		int right = (A.n -1) - left;
		quickSort(&A, &att, &comp, left, right);
		time = clock() - time;
	}else if(strcmp(ALG, "heap") == 0){// Caso seja para executar Heap-sort
		time = clock();
		heapSort(&A, &att, &comp);
		time = clock() - time;
	}else if(strcmp(ALG, "merge") == 0){// Caso seja para executar Merge-sort
		time = clock();
		int l = 0;
		int r = 0;
		r = (A.n-1)-l;
		mergeSort(&A, &att, &comp, l, r);
		time = clock() - time;
	}else{
		printf("ERRO: ALGORITMO DE ORDENACAO DESCONHECIDO\n");
		freeArray(&A);
		exit(1);
	}

	// imprimindo resultados de execucao
	if(!isSorted(&A))
		printf("ERRO: VETOR NAO FOI COMPLETAMENTE ORDENADO!\n");
	if(PRINT) printArray(&A);
	printf("%*s: %s\n",   5, "ALG", ALG);
	printf("%*s: %d\n",   5, "NUM", NUM);
	printf("%*s: %ld\n",  5, "comp", comp);
	printf("%*s: %ld\n",  5, "att", att);
	printf("%*s: %lfs\n", 5, "tempo", (double)time/1000000);

	//printArray(&A);

	freeArray(&A);
	return 0;
}
