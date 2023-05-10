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
    if (pq->size==0)return NULL;
    return pq->heapArray[0].data;
}
/*Implemente la función `void heap_push(Heap* pq, void* data, int p)`. Esta función inserta un nuevo dato con prioridad `p` en el montículo. Si no recuerda como insertar datos en el montículo puede ver las [diapositivas](https://docs.google.com/presentation/d/1ZjXWMf6g05WdICqvno_oyRvorjAThABgbRGbEqc7mYU/edit#slide=id.g55ac49ed61_0_167).

    > Si el arreglo está lleno aumente la capacidad al **doble + 1** usando la función `realloc` así:
    > `arreglo = realloc(arreglo, nueva_capacidad)`
*/
void heap_push(Heap* pq, void* data, int priority){
    if (pq->size==pq->capac)
    {
        pq->heapArray=(heapElem*)realloc(pq->heapArray, ((pq->capac)*2)*sizeof(heapElem));
        if (pq->heapArray==NULL) 
        {
            free(pq);
            return;
        }
        pq->capac*=2;
    }
    pq->heapArray[pq->size].data=data;
    pq->heapArray[pq->size].priority=priority;
    size_t cont=0;
    for (int k=pq->size;k>=0;k=(k-1)/2)
    {
        printf("LOL %i\n",k);
        cont++;
        if (cont==10)return;
    }
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
