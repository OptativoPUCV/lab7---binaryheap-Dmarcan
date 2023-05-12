#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
    if (pq->size == 0)return NULL;
    return pq->heapArray[0].data;
}

void heap_push(Heap* pq, void* data, int priority){
    if (pq->size == pq->capac)
    {
        pq->heapArray = (heapElem*) realloc(pq->heapArray,((pq->capac * 2) + 1) * sizeof(heapElem));
        if (pq->heapArray == NULL) 
        {
            free(pq);
            return;
        }
        pq->capac = (pq->capac * 2) +1;
    }
    
    bool entro = false;
    pq->heapArray[pq->size].data = data;
    pq->heapArray[pq->size].priority = priority;
    int anteriorK = pq->size;
    for (int k = pq->size;k > 0 || entro == false;k = (k-1)/2)
    {
        if (pq->heapArray[k].priority < pq->heapArray[anteriorK].priority)
        {
            int aux = pq->heapArray[k].priority;
            pq->heapArray[k].priority = pq->heapArray[anteriorK].priority;
            pq->heapArray[anteriorK].priority = aux;
            
            void* data = pq->heapArray[k].data;
            pq->heapArray[k].data = pq->heapArray[anteriorK].data;
            pq->heapArray[anteriorK].data = data;
        }
        anteriorK = k;
        if (k == 0) entro = true;
    }
    pq->size++;
}

void heap_pop(Heap* pq){
    if (pq->size==0)return;
    pq->heapArray[0].data=pq->heapArray[pq->size-1].data;
    pq->heapArray[0].priority=pq->heapArray[pq->size-1].priority;
    pq->size--;
    
    size_t k=0;
    size_t anteriorK=k;
    while (k<pq->size)
    {
        anteriorK=k;
        if (pq->heapArray[k+1].priority<pq->heapArray[k+2].priority)k=(2*k)+2;
        else k=(2*k)+1;
        
        int aux=pq->heapArray[k].priority;
        pq->heapArray[k].priority=pq->heapArray[anteriorK].priority;
        pq->heapArray[anteriorK].priority=aux;
            
        void* data=pq->heapArray[k].data;
        pq->heapArray[k].data=pq->heapArray[anteriorK].data;
        pq->heapArray[anteriorK].data=data;
    }
    return;
}

Heap* createHeap(){
    Heap* nuevoHeap = (Heap*) malloc(sizeof(Heap));
    if (nuevoHeap==NULL) return NULL;
    nuevoHeap->heapArray = (heapElem*) malloc(3 * sizeof(heapElem));
    if (nuevoHeap->heapArray == NULL)
    {
        free(nuevoHeap);
        return NULL;
    }
    nuevoHeap->capac = 3;
    nuevoHeap->size = 0;
    return nuevoHeap;
}
