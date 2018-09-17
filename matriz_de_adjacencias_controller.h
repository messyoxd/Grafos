#include "matriz_de_adjacencias.h"

/********************************************/
/*Funcao que printa as arestas de um GrafoMA*/
/********************************************/
void printMA(GrafoMA* g){

	for(int i = 0; i < g->vertices; i++){

		for(int j = 0; j < g->vertices; j++){

			printf("%d ", g->m[i][j]);

		}
		printf("\n");

	}

}