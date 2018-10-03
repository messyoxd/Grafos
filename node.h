#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
/*Celula simples*/
typedef struct node{

    struct node* p; /*ponteiro para o proximo no*/
    int conteudo; /*conteudo do no*/
    int custo; //custo de um no ate outro

} Node;
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
/****************************************************************/
/*Recebe ponteiro para Node e um inteiro e altera o conteudo do*/
/*no recebido                                                   */
/****************************************************************/
void alteraNo(Node* no, int conteudo, int custo){
    no->conteudo = conteudo;
    no->custo = custo;
}

#endif // NODE_H_INCLUDED
