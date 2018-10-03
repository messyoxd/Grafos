
/*
 * @Brief   : Essa função checa se o grafo na entrada e uma floresta
 *
 * @Entrada : Um GrafoLA g
 *
 * @Saida   : Retorna 1, caso g e floresta; 0, caso contrario
*/
int floresta(GrafoLA *g){

	if(g->arestas >= g->vertices)
		return 0;
	int visitado[g->vertices];
	int anterior[g->vertices];
	int i;
	int j = 0;
	Node *aux = NULL;
	Node *u = NULL;
	Node *w = NULL;
	Fila *f = criaFila();
	for(i = 0; i < g->vertices; i++){

		visitado[i] = 0;
		anterior[i] = -1;

	}

	while(visitado[j] == 0){

		visitado[j] = 1;
		aux = criarNo(j,0);
		insereFila(f, aux);
		while(f->l->n > 0){

			u = retiraFila(f);

			w = g->a[u->conteudo].h;
			
			while(w){
	            if(anterior[u->conteudo] != w->conteudo){

	            	if(visitado[w->conteudo] == 1){
	            		
	            		return 0;

	            	}
	            	else{
	            		visitado[w->conteudo] = 1;
	            		anterior[w->conteudo] = u->conteudo;
	            		insereFila(f, criarNo(w->conteudo,0));
	            	}

	            }
	            w = w->p;
	            
	        }


		}
		while(visitado[j] == 1)
			j++;

	}
	return 1;

}