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
    return NULL;
}



void heap_push(Heap* pq, void* data, int priority){

}

/*Implemente la función `void* heap_top(Heap* pq)`. Esta función retorna el dato con mayor prioridad del montículo. 
    > Recuerde que este dato se encuentra en la raíz el montículo, es decir, en la primera casilla del arreglo.
*/
void heap_pop(Heap* pq){
    //if (pq->size==0)return;
    printf("%p\n",pq->heapArray[0].data);
    //pq->heapArray->data[0];
    return (void)pq->heapArray[0].data;
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
