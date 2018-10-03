#include "lista_encadeada_controller.h"

typedef struct{
	
	ListaEncadeada *l;
	Node *primeiro;
	/*A lista encadeada ja tem um ponteiro para o ultimo da fila e o numero de elementos na fila*/

}Fila;

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

void insereFila(Fila* f, Node* no){
	
	insereLista(f->l, no);
	if(f->l->n == 1)
		f->primeiro = f->l->h;

}

Node* retiraFila(Fila* f){

	Node* aux = f->primeiro;
	removeLastNode(f->l);
	f->primeiro = getLastNode(f->l);
	return aux;
}
