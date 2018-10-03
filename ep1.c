#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Celula simples*/
typedef struct node{

    struct node* p; /*ponteiro para o proximo no*/
    int conteudo; /*conteudo do no*/
    int custo; //custo de um no ate outro

} Node;
/*
 * @Brief: struct para representar uma aresta
 *
*/
typedef struct aresta{

	int u;    // vertice u
	int v;    // vertice v
	int custo; // custo da aresta

}Aresta;
/*Lista encadeada simples*/
typedef struct lista_encadeada{

    Node* h; /*ponteiro pra cabeça*/
    int n; /* numero de nos*/

} ListaEncadeada;
/*Fila*/
typedef struct{
	
	ListaEncadeada *l;
	Node *primeiro;
	/*A lista encadeada ja tem um ponteiro para o ultimo da fila e o numero de elementos na fila*/

}Fila;
/*representação de grafo nao direcionado por lista de adjacencias*/
typedef struct Grafo_LA{
    ListaEncadeada* a;
    int vertices;
    int arestas;
}GrafoLA;
/***********************************************************/
/*Recebe um inteiro, cria um no com o conteudo do inteiro  */
/*e o devolve. Devolve NULL caso não haja espaço na memoria*/
/***********************************************************/
Node* criarNo(int conteudo, int custo){
    Node* a = (Node*) malloc(sizeof(Node)); /*instancia de no*/
    if(a == NULL)
        return NULL;
    a->conteudo = conteudo; /*conteudo do no*/
    a->custo = custo; //custo do no
    a->p = NULL; /*ponteiro vazio deve apontar para null*/
    return a;
}
/***************************************************************/
/*Recebe um ponteiro para Node que deve ser liberado e o libera*/
/***************************************************************/
void removeNo(Node* no){
    no->p = NULL;
    free(no);
}
/************************************************/
/*Devolve ponteiro para uma ListaEncadeada vazia*/
/*Devolve NULL caso não haja espaço na memoria  */
/************************************************/
ListaEncadeada* criaLista(){
    ListaEncadeada* l = (ListaEncadeada*) malloc(sizeof(ListaEncadeada));
    if(l == NULL)
        return NULL;
    l->h = NULL;
    l->n = 0;
    return l;
}
/***********************************************************/
/*Recebe ponteiro para uma ListaEncadeada e um No não vazio*/
/*e insere o no no inicio da lista encadeada.              */
/***********************************************************/
void insereLista(ListaEncadeada* l,Node* no){
    Node* aux = l->h;
    l->h = no;
    l->h->p = aux;
    l->n++;
}
/*************************************************************/
/*Recebe ponteiro para uma ListaEncadeada e remove o primeiro*/
/*No da lista encadeada e o devolve*/
/*************************************************************/
Node* removePrimeiroDaLista(ListaEncadeada* l){
    Node* no = l->h;
    l->h = l->h->p;
    no->p = NULL;
    l->n--;
    return no;
}
/*
 * @Brief    : Essa funcao procura um node com conteudo e custo igual ao recebido e o remove
 *
 * @Entrada  : ListaEncadeada l e conteudo e custo do node
 *
 * @Saida    : Retorna 1, caso consiga excluir com sucesso; 0, caso contrario
*/
 int removeLista(ListaEncadeada *l, int conteudo, int custo){
    Node *aux = l->h;
    if(l->h->conteudo == conteudo && l->h->custo == custo){
        l->h = aux->p;
        aux->p =NULL;
        free(aux);
    }
    else{
        Node *aux2 = aux->p;
        while(aux2){
            if(aux2->conteudo == conteudo && aux2->custo == custo){
                aux->p = aux2->p;
                aux2->p = NULL;
                free(aux2);
                return 1;
            }
            else{
                aux = aux2;
                aux2 = aux2->p;
            }                
        }
    }
    return 0;
 }
 /*******************************************************/
/*Recebe ponteiro para ListaEncadeada e um inteiro e   */
/*busca um no da lista tal que o conteudo seja igual ao*/
/*inteiro                                              */
/*******************************************************/
Node* getNode(ListaEncadeada* l, int conteudo){
    if(l->h){
        Node* aux = l->h;
        while(aux){
            if(aux->conteudo == conteudo)
                return aux;
            else
                aux = aux->p;
        }
    }
    return l->h;
}
/*******************************************************/
/*Recebe um ponteiro para ListaEncadeada e printa todos*/
/*os nos da lista encadeada                            */
/*******************************************************/
void printListaEncadeada(ListaEncadeada* l){
    if(l->h){
        Node* aux = l->h;
        while(aux){
            printf("conteudo = %d custo = %d\n", aux->conteudo, aux->custo);
            aux = aux->p;
        }
    }
    else
        printf("lista vazia!\n");
}
/*
 * @Brief   : Essa funcao retorna o ultimo node da lista encadeada
 *
 * @Entrada : ListaEncadeada l
 *
 * @Saida   : Node aux, ou l->h caso a lista esteja vazia
*/
Node* getLastNode(ListaEncadeada* l){
    if(l->h){
        Node* aux = l->h;
        while(aux->p)
            aux = aux->p;
        return aux;
    }
    return l->h;
}
/*
 * @Brief   : Essa funcao remove o ultimo node da lista encadeada, retornando-o
 *
 * @Entrada : ListaEncadeada l
 *
 * @Saida   : Node aux ou NULL caso a lista tivesse apenas um no ou nenhum
*/
Node* removeLastNode(ListaEncadeada* l){
    if(l->h){
        Node* aux = l->h;
        Node* aux2 = aux->p;
        if(!aux2){
            l->h = NULL;
            l->n--;
            return aux;
        }
        else{
            while(aux2->p){
                aux = aux2;
                aux2 = aux2->p;                
            }    
        }
        free(aux2);
        aux->p = NULL;
        l->n--;
        return NULL;
    }
    return l->h;
}
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
/******************************************************************/
/*Devolve uma Lista Encadeada, em que cada indice possui uma Lista*/
/*Encadeada, de tamanho v. Retorna NULL caso não haja memoria     */
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
        for(int j = 0; j < g->a[i].n; j++)
            insereLista(&nova[i],removePrimeiroDaLista(&g->a[i]));
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
    removeLista(&g->a[u], v, custo);
    removeLista(&g->a[v], u, custo);
    g->arestas -= 1;
    return 1;
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
 	if(a->custo >= 0)
 		return a;
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
/*
 * @Brief : Essa funcao retorna um ponteiro para uma fila
*/
Fila* criaFila(){
	Fila* f;
	f = (Fila*) malloc(sizeof(Fila));
	if(f == NULL)
		return NULL;
	f->l = criaLista();
	f->primeiro = NULL;
	f->l->n = 0;
	return f;
}
/*
 * @Brief   : Essa funcao insere um node numa fila
 *
 * @Entrada : Fila f e Node no
*/
void insereFila(Fila* f, Node* no){
	insereLista(f->l, no);
	if(f->l->n == 1)
		f->primeiro = f->l->h;
}
/*
 * @Brief   : Essa funcao retira o primeiro da fila e o retorna
 *
 * @Entrada : Fila f
 *
 * @Saida   : Node aux
*/
Node* retiraFila(Fila* f){
	Node* aux = f->primeiro;
	removeLastNode(f->l);
	f->primeiro = getLastNode(f->l);
	return aux;
}
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

	            	if(visitado[w->conteudo] == 1)
	            		return 0;
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
	//enquanto Gl tiver menos arestas que o número de vertices
	while(gl->arestas < g->vertices-1){
		//selecione a aresta de menor custo em aux que Gl já não a possua e a adicione em Gl, tal que não haja ciclos
		aresta_aux = getLowerCostEdge(aux);
		insereArestaLA(gl, aresta_aux->u, aresta_aux->v, aresta_aux->custo);
		//checar se gl tem ciclos com o floresta
		if(!floresta(gl)){
			//se ha ciclos, entao deve-se tentar a proxima aresta de menor custo
			retiraArestaLA(gl, aresta_aux->u, aresta_aux->v, aresta_aux->custo);
		}
		else{
			//se nao ha ciclos, entao deve-se tirar de aux a aresta que colocou-se em gl
			retiraArestaLA(aux, aresta_aux->u, aresta_aux->v, aresta_aux->custo);
		}
	}
	//devolva Gl
	return gl;
}
int main()
{
    char arquivo[256];
    int vertices;
    int arestas;
    printf("Digite o nome do arquivo:\n");
    scanf("%s",arquivo);
    strcat(arquivo, ".txt");
    FILE *fp;
    fp = fopen(arquivo, "r");
    if(fp == NULL){
        printf("Arquivo nao encontrado!");
	return 0;
    }
    fscanf(fp, "%d", &vertices);
    fscanf(fp, "%d", &arestas);
    GrafoLA *a = criaGrafoLA(vertices);
    int u,v,custo;
    for(int i = 0; i < arestas; i++){
        fscanf(fp, "%d", &u);
        fscanf(fp, "%d", &v);
        fscanf(fp, "%d", &custo);
        insereArestaLA(a,u-1,v-1,custo);
    }
    fclose(fp);
    GrafoLA *gl = kruskal(a);
    printAGM(gl);
    printf("\n");
    printf("Custo: %d\n", custoGrafoLA(gl));
    return 0;
}
