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
        pq->heapArray=(heapElem*)realloc(pq->heapArray, (((pq->capac)*2)+1)*sizeof(heapElem));
        if (pq->heapArray==NULL) 
        {
            free(pq);
            return;
        }
        pq->capac=(pq->capac*2)+1;
    }
    bool entro=false;
    pq->heapArray[pq->size].data=data;
    pq->heapArray[pq->size].priority=priority;
    int ultiK=pq->size;
    for (int k=pq->size;k>0 || entro==false;k=(k-1)/2)
    {
        if (pq->heapArray[k].priority<pq->heapArray[ultiK].priority)
        {
            int aux=pq->heapArray[k].priority;
            pq->heapArray[k].priority=pq->heapArray[ultiK].priority;
            pq->heapArray[ultiK].priority=aux;
            
            void* data=pq->heapArray[k].data;
            pq->heapArray[k].data=pq->heapArray[ultiK].data;
            pq->heapArray[ultiK].data=data;
        }
        ultiK=k;
        if (k==0)entro=true;
    }
    pq->size++;
}
/*Implemente la función `void heap_pop(Heap* pq)`. Esta función elimina el mayor elemento del montículo (la raíz). Si no recuerda el procedimiento puede ver las [diapositivas](https://docs.google.com/presentation/d/1ZjXWMf6g05WdICqvno_oyRvorjAThABgbRGbEqc7mYU/edit#slide=id.g10c6e3d52b_0_98).*/

void heap_pop(Heap* pq){
    if (pq->size==0)return;
    printf("%i",pq->heapArray[pq->size-1].priority);
    pq->heapArray[0].data=pq->heapArray[pq->size-1].data;
    pq->heapArray[0].priority=pq->heapArray[pq->size-1].priority;
    pq->size--;
    for (size_t k=0;k<pq->size;k=(k*2)+1)
    {
        if (pq->heapArray[k].priority<pq->heapArray[k+1].priority)
        {
            int aux=pq->heapArray[k].priority;
            pq->heapArray[k].priority=pq->heapArray[k+1].priority;
            pq->heapArray[k+1].priority=aux;
            
            void* data=pq->heapArray[k].data;
            pq->heapArray[k].data=pq->heapArray[k+1].data;
            pq->heapArray[k+1].data=data;
            
        }
    }
    
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
