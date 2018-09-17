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
/*********************************************************************************************/
/*recebe um grafo LA, cria uma Lista de Listas encadeadas com um espaço a mais que a do grafo*/
/*original, copia todas as arestas da lista do grafo original e a substitui                  */
/*Caso suceda, retorna 1. Caso nao haja espaço para a lita nova, retorna 0                   */
/*********************************************************************************************/
int insereVerticeLA(GrafoLA* g){
    ListaEncadeada *nova = alocaListaAdjacente(g->vertices+1);
    if(nova == NULL)
        return 0;
    for(int i = 0; i < g->vertices; i++){

        for(int j = 0; j < g->a[i].n; j++){

            insereLista(&nova[i],removePrimeiroDaLista(&g->a[i]));

        }

    }
    g->a = nova;
    g->vertices++;
    return 1;
}

/****************************************************************************************/
/*Recebe um grafo LA, um par de vertices e o nome da aresta e insere uma aresta no grafo*/
/****************************************************************************************/
void insereArestaLA(GrafoLA* g, int u, int v, char* nome){
    insereLista(&g->a[u], criarNo(v, nome));
    insereLista(&g->a[v], criarNo(u, nome)); 
    g->arestas++;
}

#endif // LISTA_DE_ADJACENCIA_H_INCLUDED
