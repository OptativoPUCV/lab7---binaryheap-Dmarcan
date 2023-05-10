#include <stdio.h>
#include <stdlib.h>
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
    if (pq->heapArray==NULL)return NULL;
    return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){

}

void heap_pop(Heap* pq){
    return;
}
/*Implemente la función `Heap* createHeap()`. Esta función crea un nuevo dato de tipo Heap inicializando sus variables. Considere que la capacidad incial es de 3 casillas para el arreglo.
   > Recuerde reservar memoria para el Heap y también para el arreglo `heapArray`.
*/
Heap* createHeap(){
    Heap* nuevoHeap=(Heap*)malloc(sizeof(Heap));
    if (nuevoHeap==NULL)return NULL;
    nuevoHeap->heapArray=(heapElem*)malloc(3*sizeof(heapElem));
    if (nuevoHeap->heapArray==NULL)
    {
        free(nuevoHeap);
        return NULL;
    }
    nuevoHeap->capac=3;
    nuevoHeap->size=0;
    return nuevoHeap;
}
