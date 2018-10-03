#include "lista_de_adjacencia_controller.h"
#include "fila.h"
/*******************************************************/
/*Recebe um grafo implementado com lista de adjacencias*/
/*Retorna 1 caso for conexo;Caso contrario 0           */
/*******************************************************/
int conexo(GrafoLA* g){
	int visitado[g->vertices];
	int i;
	Node *u, *aux;
	/*preencher o vetor de vertices visitados com 0*/
	for(i = 1; i < g->vertices; i++){
		visitado[i] = 0;
	}
	visitado[0] = 1;
	/*Cria fila*/
	Fila* f = criaFila();
	/*Insere vertice 1 na fila*/
	insereFila(f, criaNo(0, 0));
	/*enquanto a fila não estiver vazia*/
	while(f->l->n > 0){

		u = retiraFila(f);
		/*para cada vertice v adjacente a u*/
		aux = g->a[u->conteudo].h;
		
		//printf("d\n");

		while(aux){


			if(visitado[aux->conteudo] == 0){
				visitado[aux->conteudo] = 1;
				insereFila(f, criarNo(aux->conteudo,0));
			}
			/*aux->p ta ficando vazio quando não deveria*/
			/*era na insercao na fila, consertado criando um novo node*/
			aux = aux->p;
			
		}

	}
	/*Se houver i tal que visitado[i] e falso retorna 0*/
	//printf("f\n");
	for(i = 0; i < g->vertices; i++){
		if(visitado[i] == 0)
			return 0;
	}
	//printf("g\n");
	return 1;
}
