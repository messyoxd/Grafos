#ifndef LISTA_ENCADEADA_CONTROLLER_H_INCLUDED
#define LISTA_ENCADEADA_CONTROLLER_H_INCLUDED
#include "lista_encadeada.h"

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

Node* getLastNode(ListaEncadeada* l){

    if(l->h){
        Node* aux = l->h;
        while(aux->p){
            aux = aux->p;
        }
        return aux;
    }
    return l->h;

}

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


#endif // LISTA_ENCADEADA_CONTROLLER_H_INCLUDED
