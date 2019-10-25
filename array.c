#include "array.h"

// Função que aloca o array
void allocateArray(TArray *pA, int size){
	pA->n = size;
	pA->item = (TItem*)calloc(size,sizeof(TItem));
	
	if(!pA->item){
		printf("ERRO: NAO FOI POSSIVEL ALOCAR MEMORIA PARA VETOR\n");
		exit(1);
	}
}
// Libera a memória usada pelo array
void freeArray(TArray *pA){
	if (pA->item != NULL)
		free(pA->item);

	pA->item = NULL;
	pA->n    = 0;
}

// Imprime o array
void printArray(TArray *pA){
	int i;
	printf("Array:\n");
	for(i=0;i<pA->n;i++)
		printf("%d ",pA->item[i].key);
	printf("\n");
}

// Verifica se o array está ordenado
int isSorted(TArray *pA){
	int i;
	for(i=0;i<pA->n-1;i++)
		if (pA->item[i].key > pA->item[i+1].key)
			return 0;
	return 1;
}

// Gera um array ordenado
void generateSorted(TArray *pA, int max){
	int i;
	for(i=0; i < pA->n; i++)
		pA->item[i].key = (int) (((double)i/pA->n)*max);
}

// Gera um array ordenado em ordem decrescente
void generateInvert(TArray *pA,int max){
	int i;
	for(i=0; i < pA->n; i++)
		pA->item[i].key = (int) ( ( max - ( (double)i/pA->n ) * max ) -1 );
}

// Gera um array com elementos randômicos
void generateRandom(TArray *pA, int max){
	int i;
	srand(time(NULL));
	for(i=0; i<pA->n; i++)
		pA->item[i].key = rand()%max;
}

// Gera um array com elementos randômicos e sem repetição
void generateRandomNoRep(TArray *pA, int max){
	int i,aux;
	int pos1, pos2;
	generateSorted(pA, max);

	srand(time(NULL));
	for(i=0; i < pA->n; i++){
		pos1 = rand()%pA->n;
		pos2 = rand()%pA->n;
		aux                = pA->item[pos2].key;
		pA->item[pos2].key = pA->item[pos1].key;
		pA->item[pos1].key = aux;
	}
}

// Gera um array com 1% dos elementos ordenados
void generateAlmostSorted(TArray *pA,int max){
	int i;
	for(i=0; i < (99*pA->n/100); i++)
		pA->item[i].key = (int) (((double)i/pA->n)*max);

	srand(time(NULL));
	for(; i < pA->n; i++)
		pA->item[i].key = rand()%max;
}

// Gera um array com 1% dos elementos ordenados e sem repetição
void generateAlmostSortedNoRep(TArray *pA,int max){
	int i,aux;
	int pos1,pos2;
	generateSorted(pA, max);

	srand(time(NULL));
	for(i=0; i < pA->n/100; i++){
		pos1 = rand()%pA->n;
		pos2 = rand()%pA->n;
		aux                = pA->item[pos2].key;
		pA->item[pos2].key = pA->item[pos1].key;
		pA->item[pos1].key = aux;
	}
}