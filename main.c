#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "kruskal.h"

int main()
{
    
    //GrafoLA* a = criaGrafoLA(5);
    //GrafoLA *gl = NULL;
    /*
    insereArestaLA(a,0,1,5);
    insereArestaLA(a,0,4,10);
    insereArestaLA(a,1,2,4);
    insereArestaLA(a,1,3,13);
    insereArestaLA(a,1,4,2);
    insereArestaLA(a,2,3,7);
    insereArestaLA(a,4,3,6);
    */
    char arquivo[256];
    int vertices;
    int arestas;
    printf("Digite o nome do arquivo:\n");
    scanf(" %s",arquivo);
    strcat(arquivo, ".txt");
    FILE *fp;
    fp = fopen(arquivo, "r");
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
    /*
    if(floresta(a))
        printf("uhu!\n");
    else{
        printf("droga!\n");
    }
    */  
    /*
    gl = kruskal(a);

    printf("custo do grafo : %d\n", custoGrafoLA(gl));
    */

    //printGrafoLA(gl);

    /*
    Aresta *exemplo = getLowerCostEdge(a);

    if(exemplo)
        printf("custo da aresta de menor custo: %d\n", exemplo->custo);

    else
        printf("deu ruim\n");
    */
    
    /*
    Fila* f = criaFila();
    
    insereFila(f, criarNo(1,1));
    insereFila(f, criarNo(2,2));
    insereFila(f, criarNo(3,3));
    insereFila(f, criarNo(4,4));
    insereFila(f, criarNo(5,5));
    insereFila(f, criarNo(6,6));
    insereFila(f, criarNo(7,7));
    */
    
    /*
    printf("f->primeiro: %d\n", f->primeiro->conteudo);
    printListaEncadeada(f->l);
    
    retiraFila(f);
    printf("f->primeiro: %d\n", f->primeiro->conteudo);
    printListaEncadeada(f->l);
    */
    
	//GrafoMA* b = criaGrafoMA(5);
    /*
    if(a != NULL)
        printf("Sucesso: criacao\n");
    else{
        printf("Fracasso: criacao\n");
    }
    */
    /*
	insereArestaMA(b,0,1);
    insereArestaMA(b,0,3);
    insereArestaMA(b,1,3);
    insereArestaMA(b,1,2);
    insereArestaMA(b,2,3);
    insereArestaMA(b,2,4);
    insereArestaMA(b,3,4);
    */

   
    
    //insereVerticeLA(a);
    //insereVerticeMA(b);
    //insereArestaLA(a,5,1, "y");
    //insereArestaMA(b,5,1);

    //printGrafoLA(a);
    //printMA(b);

    /*
    if(conexo(a) == 1)
        printf("G e conexo\n");
    else
        printf("G nao e conexo\n");
    */
    return 0;
}
