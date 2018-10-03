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
        //printf("yeaa\n");
       // printf("yeaa\n");
        l->h = aux->p;
        aux->p =NULL;
        free(aux);
    }
    else{
        Node *aux2 = aux->p;
        //printf("conteudo a ser excluido: %d\n", conteudo);
        while(aux2){
    /*
            printf("aux->conteudo : %d\n", aux->conteudo);
            printf("aux2->conteudo : %d\n", aux2->conteudo);
    */
            if(aux2->conteudo == conteudo && aux2->custo == custo){
               /*printf("yeaa\n");
                printf("aux->conteudo : %d\n", aux->conteudo);
                printf("aux2->conteudo : %d\n", aux2->conteudo);
                printf("yeaa\n");*/
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

#endif // LISTA_ENCADEADA_H_INCLUDED
