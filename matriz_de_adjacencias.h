
typedef struct matriz_adjacencias{
	int** m;
	int vertices;
	int arestas;
} GrafoMA;

/**********************************************************************************/
/*Recebe o numero de vertices que o grafo terá e devolve uma matriz de adjacencias*/
/*Caso não haja espaço, devolve NULL                                              */
/**********************************************************************************/
int **alocaMatrizAdjacencias(int vertices){
	int i, j;
	int **aux; 
	aux = malloc(sizeof(aux)*vertices);
	if(aux == NULL)

		return NULL;

	for(i = 0; i < vertices; i++){

		aux[i] = malloc(sizeof(int)*vertices);
		
		if(aux[i] == NULL){

			for(j = 0; j < i; j++)
				
				free(aux[j]);

			free(aux);
			return NULL;

		}

	}

	return aux;

}

/***********************************************************************************************/
/*Recebe o numero de vertices que o grafo terá e devolve um ponteiro para um grafo de matriz de*/
/*adjacencias. Caso não haja espaço, devolve NULL					                           */
/***********************************************************************************************/
GrafoMA* criaGrafoMA(int vertices){

	GrafoMA* m = malloc(sizeof(GrafoMA));
	if(m == NULL)

		return NULL;

	m->m = alocaMatrizAdjacencias(vertices);
	if(m->m == NULL)

		return NULL;

	m->vertices = vertices;
	m->arestas = 0;

	return m;

}
/*********************************************************************************************************/
/*Recebe um grafo de matriz de adjacencias e retorna 1 caso uma MA com um vertice a mais e               */
/*todos os outros vertices com suas arestas for criada com sucesso. caso não haja espaço, retorna 0      */
/*********************************************************************************************************/
int insereVerticeMA(GrafoMA* g){


	int **aux; 
	aux = alocaMatrizAdjacencias(g->vertices+1);
	if(aux == NULL)
		return 0;
	for(int i = 0; i < g->vertices; i++){

		for(int j = 0; j < g->vertices; j++){

			aux[i][j] = g->m[i][j];			

		}
		free(g->m[i]);

	}
	g->m = aux;
	g->vertices++;
	return 1;

}

/*********************************************************************/
/*Recebe um GrafoMA e um par de vertices e insere uma aresta no grafo*/
/*********************************************************************/
void insereArestaMA(GrafoMA* g, int u, int v){

	g->m[u][v] = 1;
	g->m[v][u] = 1;
	g->arestas++;

}










