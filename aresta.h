/*
 * @Brief: struct para representar uma aresta
 *
*/
typedef struct aresta{

	int u;    // vertice u
	int v;    // vertice v
	int custo; // custo da aresta

}Aresta;

/*
 *	@Brief   : Essa função cria uma instancia de uma Aresta
 *	
 *	@Entrada : inteiros u e v, para representar os vertices,
 *			   e inteiro custo para representar o custo da aresta
 *
 *	@Saida   : Ponteiro para uma instancia de Aresta
*/
Aresta* criaAresta(int u, int v, int custo){

	Aresta *a = (Aresta*)malloc(sizeof(Aresta));

	a->u = u;
	a->v = v;
	a->custo = custo;

	return a;

}