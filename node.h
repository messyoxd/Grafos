#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
/*Celula simples*/
typedef struct aresta{

    struct aresta* p; /*ponteiro para o proximo no*/
    int conteudo; /*conteudo do no*/
    char* a;/*nome do no*/

} Node;
/***********************************************************/
/*Recebe um inteiro, cria um no com o conteudo do inteiro  */
/*e o devolve. Devolve NULL caso não haja espaço na memoria*/
/***********************************************************/
Node* criarNo(int conteudo, char* nome){

    Node* a = (Node*) malloc(sizeof(Node)); /*instancia de no*/
    if(a == NULL)
        return NULL;
    a->conteudo = conteudo; /*conteudo do no*/
    a->a = nome;
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
void alteraNo(Node* no, int conteudo, char* nome){
    no->conteudo = conteudo;
    no->a = nome;
}
/**************************************************/
/*Recebe ponteiro para Node e retorna seu conteudo*/
/**************************************************/
int getConteudo(Node* no){
    return no->conteudo;
}

char* getCaractere(Node* no){
    return no->a;
}

#endif // NODE_H_INCLUDED
