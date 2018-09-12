#ifndef LISTA_DE_ADJACENCIA_H_INCLUDED
#define LISTA_DE_ADJACENCIA_H_INCLUDED
#include "lista_encadeada_controller.h"
/*representação de grafo nao direcionado por lista de adjacencias*/
typedef struct Grafo_LA{
    ListaEncadeada* a;
    int vertices;
    int arestas;
}GrafoLA;
/******************************************************************/
/*Devolve uma Lista Encadeada, em que cada indice possui uma Lista*/
/*Encadeada, de tamanho v. Retorna NULL caso não haja memoria     */
/*suficiente                                                      */
/******************************************************************/
ListaEncadeada* alocaListaAdjacente(int v){

    ListaEncadeada* LA = malloc(sizeof(ListaEncadeada)*v);
    if(LA == NULL)
        return NULL;
    for(int i = 0; i < v; i++){

        LA[i].h = NULL;
        LA[i].n = 0;

    }
    return LA;
}
/************************************************************/
/*retorna um Grafo representado com listas adjacentes       */
/*de v vertices. Devolve NULL caso não haja memoria sufiente*/
/************************************************************/
GrafoLA* criaGrafoLA(int v){
    GrafoLA* GLA = (GrafoLA*) malloc(sizeof(GrafoLA));
    if(GLA == NULL)
        return NULL;
    ListaEncadeada* LA = alocaListaAdjacente(v);
    if(LA == NULL)
        return NULL;
    GLA->a = LA;
    GLA->arestas = 0;
    GLA->vertices = v;
    return GLA;
}

GrafoLA* insereVerticeLA(GrafoLA* g){
    //desalocar toda a lista de adjacencias do grafo e criar uma maior?
    //g->a = (ListaEncadeada*) realloc(g->a, g->vertices+1);
    //g->vertices++;
    ListaEncadeada *nova = alocaListaAdjacente(g->vertices+1);
    if(nova == NULL)
        return NULL;
    for(int i = 0; i < g->vertices; i++){

        for(int j = 0; j < g->a[i].n; j++){

            insereLista(&nova[i],removePrimeiroDaLista(&g->a[i]));

        }

    }
    g->a = nova;
    g->vertices++;
}

GrafoLA* insereArestaLA(GrafoLA* g, int u, int v, char* nome){
    if(insereLista(&g->a[u], criarNo(v, nome)) == NULL)
        return NULL;
    if(insereLista(&g->a[v], criarNo(u, nome)) == NULL)
        return NULL;
    g->arestas++;
}

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

#endif // LISTA_DE_ADJACENCIA_H_INCLUDED
