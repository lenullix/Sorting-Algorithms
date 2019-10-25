#include "sort.h"
#include <stdbool.h>
//Bubble-sort
void bubbleSort(TArray* pA, long* att, long* comp)
{
    TItem aux;

    for(int i = 0; i < pA->n-1; i++)
    {
        for(int j = 0; j < pA->n-i-1; j++)
        {
            (*comp)++;
            if(pA->item[j].key > pA->item[j+1].key)
            {
                *att+=3;
                aux           = pA->item[j];
                pA->item[j]   = pA->item[j+1];
                pA->item[j+1] = aux;
            }
        }
    }
}

//Bubble-sort Otimizado
void bubbleSortO(TArray* pA, long* att, long* comp)
{
    TItem aux;
    bool isSorted;
    for(int i = 0; i < pA->n-1; i++)
    {
        isSorted = true;
        for(int j = 0; j < pA->n-i-1; j++)
        {
            (*comp)++;
            if(pA->item[j].key > pA->item[j+1].key)
            {
                *att+=3;
                aux           = pA->item[j];
                pA->item[j]   = pA->item[j+1];
                pA->item[j+1] = aux;
                isSorted = false;
            }
        }
        if (isSorted)
        {
            (*comp)++;
            break;
        }
    }
}

// Selection-sort Otimizado
void selectSort(TArray* pA,long* att,long*comp)
{
    int i, j, min;
    TItem aux;
    for (i = 0; i < pA->n-1; i++)
    {
        *att +=1;
        min = i;
        for (j = i+1; j < pA->n; j++)
        {
            *comp+=1;
            if (pA->item[j].key < pA->item[min].key)
            {
                *att +=1;
                min = j;
            }
        }
        *att+=3;
        aux = pA->item[min];
        pA->item[min] = pA->item[i];
        pA->item[i] = aux;
    }
}

//Selection-sort Otimizado
void selectSortO(TArray* pA,long* att,long* comp)
{
    int i, j, min;
    TItem aux;
    for (i = 0; i < pA->n-1; i++)
    {
        *att+=1;
        min = i;
        for (j = i+1; j < pA->n; j++)
        {
            *comp+=1;
            if (pA->item[j].key < pA->item[min].key)
            {
                *att+=1;
                min = j;
            }
        }
        if (min != i)
        {
            *att+=3;
            aux = pA->item[min];
            pA->item[min] = pA->item[i];
            pA->item[i] = aux;
        }
        else;
    }
}

// Insertion-sort
void insertionSort(TArray* pA,long* att,long* comp)
{
    int i, j;
    TItem key;
    for (i = 0; i< pA->n; i++)
    {
        *att += 2;
        key.key = pA->item[i].key;
        j = i - 1;
        while(j >= 0 && pA->item[j].key > key.key)
        {
            *comp += 1;
            *att += 2;
            pA->item[j+1].key = pA->item[j].key;
            j = j - 1;
        }
        *att += 1;
        pA->item[j+1].key = key.key;
    }
}

//Insertion-sort Otimizado
void insertionSortO(TArray* pA,long* att,long* comp)
{
    int i = 0;
    int j = 0;
    for (i = pA->n - 2; i >= 0; i--){
        *att += 2;
        pA->item[pA->n] = pA->item[i];
        j = i + 1;
    *comp += 1;
    while (pA->item[pA->n].key > pA->item[j].key){
        *att += 2;
        pA->item[j-1] = pA->item[j];
        j++;
    }
    *att += 1;
    pA->item[j - 1] = pA->item[pA->n];
    }
}

//Shell-sort
void shellSort(TArray* pA,long* att,long* comp)
{
    int i, j, value;
    int gap = 1;
    do
    {
        *comp += 1;
        *att +=1;
        gap = 3*gap+1;
    }
    while(gap < pA->n); *comp += 1;
    do
    {
        *comp += 1;
        *att += 1;
        gap/= 3;
        for(i = gap; i < pA->n; i++)
        {
            *att +=2;
            value = pA->item[i].key;
            j = i -gap;
            while (j>=0 && value < pA->item[j].key)
            {
                *comp += 1;
                *att += 2;
                pA->item[j+gap] = pA->item[j];
                j -= gap;
            }
            *att += 1;
            pA->item[j+gap].key = value;
        }
    }
    while(gap > 1); *comp += 1;
}

//Quick-sort
void quickSort(TArray* pA,long* att,long* comp, int left, int right)
{
    int i, j, pivo;
    TItem aux;
    i = left;
    j = right;
    *att += 3;
    pivo = pA->item[(left+right)/2].key;
    *comp += 1;
    while(i <= j)
    {
        while(pA->item[i].key < pivo && i < right)
        {
            *comp += 1;
            *att += 1;
            i++;
        }
        *comp += 1;
        while(pA->item[j].key > pivo && j > left)
        {
            *att += 1;
            j--;
        }
        *comp += 1;
        if (i<=j)
        {
            *att += 5;
            aux = pA->item[i];
            pA->item[i] = pA->item[j];
            pA->item[j] = aux;
            i++;
            j--;
        }
    }
    *comp += 1;
    if (j > left)
    {
        quickSort(pA,att,comp,left,j);
    }
    *comp += 1;
    if (i < right)
    {
        quickSort(pA,att,comp,i,right);
    }
}

//Heap-sort
void heapSort(TArray* pA,long* att,long* comp)
{
    int i;
    TItem aux;
    for (i = (pA->n / 2); i>= 0; i--)
    {
        heapfy(pA, i, pA->n-1, att, comp);
    }
    for (i = pA->n-1; i>=1; i--)
    {
        *att += 3;
        aux = pA->item[0];
        pA->item[0] = pA->item[i];
        pA->item[i] = aux;
        heapfy(pA, 0, i-1, att, comp);
    }
}

//Merge-sort
void mergeSort(TArray* pA,long* att,long* comp, int l, int r)
{
    *comp += 1;
    if (l < r)
    {
        *att += 1;
        int m = (l+r)/2;

        mergeSort(pA, att, comp, l, m);
        mergeSort(pA, att, comp, m+1, r);
        Merge(pA, l, m, r, att, comp);
    }
}
//Heapfy utilizada no Heap-sort
void heapfy(TArray* pA, int raiz, int fundo, long* att, long* comp)
{
    TItem aux;
    int pronto, filhoMax;

    *att += 1;
    pronto = 0;
    *comp += 1;
    while ((raiz*2 <= fundo)&& (!pronto))
    {
        *comp += 1;
        if (raiz*2 == fundo)
        {
            *att += 1;
            filhoMax = raiz * 2;
        }
        else if (pA->item[raiz*2].key > pA->item[raiz * 2 +1].key)
        {
            *comp += 1;
            *att += 1;
            filhoMax = raiz * 2;
        }
        else
        {
            filhoMax = raiz * 2 + 1;
        }
        *comp += 1;
        if (pA->item[raiz].key < pA->item[filhoMax].key)
        {
            *att += 4;
            aux = pA->item[raiz];
            pA->item[raiz] = pA->item[filhoMax];
            pA->item[filhoMax] = aux;
            raiz = filhoMax;
        }
        else
        {
            *att += 1;
            pronto = 1;
        }
    }
}

//Merge utilizada no Merge-sort
void Merge(TArray* pA, int l, int m, int r, long* att, long* comp)
{
    int i = l;
    int j = m+1;
    int k = 0;
    int tam = r - l+1;
    int *arrayAux;
    arrayAux = (int *)malloc(tam * sizeof(int));
    *comp += 1;
    while(i <= m && j<= r)
    {
        *comp += 1;
        if (pA->item[i].key < pA->item[j].key)
        {
            *att += 2;
            arrayAux[k] = pA->item[i].key;
            i++;
        }
        else
        {
            *att += 2;
            arrayAux[k] = pA->item[j].key;
            j++;
        }
        *att += 1;
        k++;
    }
    *comp += 1;
    while (i <= m)
    {
        *att += 3;
        arrayAux[k] = pA->item[i].key;
        k++;
        i++;
    }
    *comp += 1;
    while (j <= r)
    {
        *att += 3;
        arrayAux[k] = pA->item[j].key;
        k++;
        j++;
    }
    for (k = l; k<=r; k++)
    {
        *att += 1;
        pA->item[k].key = arrayAux[k-l];
    }
    free(arrayAux);
}
