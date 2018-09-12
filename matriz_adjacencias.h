#include "lista_encadeada_controller.h"

typedef struct matriz_adjacencias{
	int** m;
	int vertices;
	int arestas;
} GrafoMA;

int** alocaMatrizAdjacencias(int vertices){

	int** aux = malloc(sizeof(int)*vertices);
	if(aux == NULL)
		return NULL;
	for(int i = 0; i < vertices; i++){

		aux[i] = malloc(sizeof(int)*vertices);
		if(aux[i] == NULL){

			for(int j = 0; j < i; j++)
				free(aux[j]);
			free(aux);
			return NULL;

		}

	}
	return aux;
}


GrafoMA* criaGrafoMA(int vertices){

	GrafoMA* m = malloc(sizeof(GrafoMA));
	if(m == NULL)
		return NULL;
	m->m = alocaMatrizAdjacencias(vertices);
	if(m->m == NULL)
		return NULL;
	/*
	for(int i = 0; i < vertices; i++){
		for(int j = 0; j < vertices; j++)
			m->m[i][j] = 0;
	}*/
	m->vertices = vertices;
	m->arestas = 0;
}

GrafoMA* insereVerticeMA(GrafoMA* g){

	int** aux = alocaMatrizAdjacencias(g->vertices+1);
	if(aux == NULL)
		return NULL;
	for(int i = 0; i < g->vertices; i++){

		for(int j = 0; j < g->vertices; j++){

			aux[i][j] = g->m[i][j];
			free(&g->m[i][j]);

		}
		free(&g->m[i]);

	}
	g->m = aux;
	g->vertices++;

}

GrafoMA* insereArestaMA(GrafoMA* g, int u, int v){

	g->m[u][v] = 1;
	g->m[v][u] = 1;
	g->arestas++;
}

void printMA(GrafoMA* g){

	for(int i = 0; i < g->vertices; i++){

		for(int j = 0; j < g->vertices; j++){

			printf("%d ", g->m[i][j]);

		}
		printf("\n");

	}

}









