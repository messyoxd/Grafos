#include "lista_de_adjacencia.h"
#include "aresta.h"

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

/*
 * @Brief  : Essa função vai retornar a aresta de menor custo do grafo
 *		     de lista de adjacencias
 *
 * @Entrada: GrafoLA g
 * 
 * @Saida  : Aresta a, tal que a é a aresta de menor custo do grafo;
 *			 Retorna NULL caso não haja arestas 				   ;
 *
*/
 Aresta* getLowerCostEdge(GrafoLA *g){

 	int i;

 	Aresta *a = criaAresta(0, 0, -1);

 	Node *aux = NULL;

 	for(i = 0; i < g->vertices; i++){

 		if(g->a[i].h){
	        aux = g->a[i].h;
	        if(a->custo == -1){
	           	a->custo = aux->custo;
	           	a->u = i;
	           	a->v = aux->conteudo;
	        }
	        while(aux){
	            if(aux->custo < a->custo){
	            	a->custo = aux->custo;
	            	a->u = i;
	            	a->v = aux->conteudo;
	            }	            	
	            aux = aux->p;
	        }
	    }
 	}
 	if(a->custo >= 0){
 		return a;
 	}
 	else{
 		free(a);
 		return NULL;
 	}

 }

/*
 * @Brief   : Essa função conta o custo das arestas do grafo
 *
 * @Entrada : GrafoLA g
 *
 * @Saida   : Custo do grafo
*/
int custoGrafoLA(GrafoLA *g){

    int i;
    int custo = 0;
    Node *aux = NULL;
    for(i = 0; i < g->vertices; i++){

        if(g->a[i].h){

            aux = g->a[i].h;

            while(aux){
                custo += aux->custo;
                aux = aux->p;
            }

        }

    }
    return custo/2;

}

/*
 * @Brief   : Essa funcao mostra as arestas do grafo
 *
 * @Entrada : GrafoLA g
 *
 * @Saida   : Mostra as arestas do grafo, sem repeti-las
 *
*/
void printAGM(GrafoLA* g){

	Node* aux = NULL;
    for(int y = 0; y < g->vertices; y++){

    	if(g->a[y].h){
	        aux = g->a[y].h;
	        while(aux){
	        	if(aux->conteudo > y)
            		printf("(%d, %d) ", y+1, aux->conteudo+1);
	            aux = aux->p;
	        }
	    }

    }

}

