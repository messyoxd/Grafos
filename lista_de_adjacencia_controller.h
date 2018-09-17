#include "lista_de_adjacencia.h"
/************************************************/
/*Recebe um ponteiro para GrafoLA e printa todas*/
/*as arestas dos vertices do grafo              */
/************************************************/
void printGrafoLA(GrafoLA* g){

    for(int i = 0; i < g->vertices; i++){

        printf("Arestas do vertice %d\n", i);

        printListaEncadeada(&g->a[i]);

    }

}