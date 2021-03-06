#ifndef LISTA_DE_ADJACENCIA_H_INCLUDED
#define LISTA_DE_ADJACENCIA_H_INCLUDED
#include "lista_encadeada_controller.h"
/*representa��o de grafo nao direcionado por lista de adjacencias*/
typedef struct Grafo_LA{
    ListaEncadeada* a;
    int vertices;
    int arestas;
}GrafoLA;
/******************************************************************/
/*Devolve uma Lista Encadeada, em que cada indice possui uma Lista*/
/*Encadeada, de tamanho v. Retorna NULL caso n�o haja memoria     */
/*suficiente                                                      */
/******************************************************************/
ListaEncadeada* alocaListaAdjacente(int v){

    ListaEncadeada* LA = (ListaEncadeada*)malloc(sizeof(ListaEncadeada)*v);
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
/*de v vertices. Devolve NULL caso n�o haja memoria sufiente*/
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
/*recebe um grafo LA, cria uma Lista de Listas encadeadas com um espa�o a mais que a do grafo*/
/*original, copia todas as arestas da lista do grafo original e a substitui                  */
/*Caso suceda, retorna 1. Caso nao haja espa�o para a lita nova, retorna 0                   */
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
void insereArestaLA(GrafoLA* g, int u, int v, int custo){
    insereLista(&g->a[u], criarNo(v, custo));
    insereLista(&g->a[v], criarNo(u, custo)); 
    g->arestas++;
}

/*
 * @Brief    : Essa funcao retira um par de arestas
 *
 * @Entrada  : GrafoLA g, vertices u e v, que serao retirados
 *
 * @Saida    : Retorna 1, caso a remocao seja um sucesso; 0, caso contrario
*/
int retiraArestaLA(GrafoLA *g, int u, int v, int custo){
    /*
    if(!removeLista(&g->a[u], v, custo) == 0)
        return 0;
    if(!removeLista(&g->a[v], u, custo) == 0)
        return 0;
    else{
        g->arestas -= 1;
        return 1;
    }
      */  
    removeLista(&g->a[u], v, custo);
    removeLista(&g->a[v], u, custo);
    g->arestas -= 1;
    return 1;
}



#endif // LISTA_DE_ADJACENCIA_H_INCLUDED
