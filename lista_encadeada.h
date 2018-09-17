#ifndef LISTA_ENCADEADA_H_INCLUDED
#define LISTA_ENCADEADA_H_INCLUDED
#include "node.h"
/*Lista encadeada simples*/
typedef struct lista_encadeada{

    Node* h; /*ponteiro pra cabeça*/
    int n; /* numero de nos*/

} ListaEncadeada;

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

#endif // LISTA_ENCADEADA_H_INCLUDED
