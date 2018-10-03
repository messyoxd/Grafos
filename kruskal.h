#include "lista_de_adjacencia_controller.h"
#include "floresta.h"

/*
 * @Brief   : Essa funcao retorna uma Arvore Geradora Minima do grafo da entrada
 *
 * @Entrada : GrafoLA g
 *
 * @Saidad  : GrafoLA gl, tal que gl e uma AGM de g
 *
*/
GrafoLA* kruskal(GrafoLA* g){

	//crie um grafo Gl tal que Gl tem todos os vertices de g, mas nenhuma aresta de g
	GrafoLA *gl = criaGrafoLA(g->vertices);
	GrafoLA *aux = g;
	Aresta *aresta_aux = NULL;
	//int i = 0;
	//enquanto Gl tiver menos arestas que o número de vertices
	while(gl->arestas < g->vertices-1){
		//	selecione a aresta de menor custo em aux que Gl já não a possua e a adicione em Gl, tal que não haja ciclos
		aresta_aux = getLowerCostEdge(aux);
		//printf("aresta: %d %d %d\n", aresta_aux->u, aresta_aux->v, aresta_aux->custo);
		insereArestaLA(gl, aresta_aux->u, aresta_aux->v, aresta_aux->custo);
		//printGrafoLA(gl);
		//checar se gl tem ciclos com o floresta
		if(!floresta(gl)){
			//se ha ciclos, entao deve-se tentar a proxima aresta de menor custo
			//printf("ha ciclos\n");
			retiraArestaLA(gl, aresta_aux->u, aresta_aux->v, aresta_aux->custo);
			//printf("\n");
			//printGrafoLA(gl);
			//printf("\n");
		}
		else{
			//se nao ha ciclos, entao deve-se tirar de aux a aresta que colocou-se em gl
			//printf("nao ha ciclos\n");
			retiraArestaLA(aux, aresta_aux->u, aresta_aux->v, aresta_aux->custo);
			//printf("\n");
			//printGrafoLA(aux);
			//printf("\n");
		}
		/*
		if(i == 4)
			return NULL;
		else
			i++;
		*/			
	}
	//devolva Gl
	return gl;
}