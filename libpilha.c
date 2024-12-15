#include <stdio.h>
#include <stdlib.h>
#include "libpilha.h"

/* 
 * Cria e retorna uma nova pilha com capacidade de nelem elementos. 
 * Retorna NULL em caso de erro de alocação 
*/
pilha_t* pilha_cria (int nelem){

    if (nelem <= 0)
      return NULL;  

    pilha_t * p = (pilha_t *) malloc(sizeof(pilha_t));
    if (p == NULL)
      return NULL;

    p -> elems = malloc(nelem * sizeof(int));
    if (p == NULL){
        free(p);
        return NULL;
    }

    p -> nelem = nelem;
    p -> topo = 0;
 
    return p;
}

/* 
 * Insere elem na pilha (politica LIFO). Retorna o número de elementos na pilha 
 * em caso de sucesso e -1 em caso de pilha cheia 
*/
int push (pilha_t* pilha, int elem){

    if (pilha -> nelem == pilha -> topo){
        return -1;
    } else {
        pilha -> elems[pilha -> topo] = elem;
        pilha -> topo++;
    }
    return pilha -> topo;
}

/* 
 * Remove (politica LIFO) e retorna um elemento da pilha. 
 * Em caso de pilha vazia retorna 0 
*/
int pop (pilha_t* pilha){

    if (pilha_vazia(pilha)){
        return 0;
    } else {
       return pilha -> topo--;
    }  
}
 
/* Similar ao Pop, mas retorna sem remover */
int pilha_topo (pilha_t* pilha){
    if(pilha_vazia(pilha)){
        return 0;
    } else {
        return pilha -> elems[pilha -> topo - 1];
    }
}  

/* Retorna o numero de elementos da pilha, que pode ser 0 */
int pilha_tamanho (pilha_t* pilha){
    return pilha -> nelem;
}
/* Retorna 1 se pilha vazia, 0 em caso contrario */ 
int pilha_vazia (pilha_t* pilha){
    return pilha -> topo == 0;
}

/* Desaloca memoria de pilha_t e retorna NULL */
pilha_t* pilha_destroi (pilha_t* pilha){
    free(pilha -> elems);
    pilha -> elems = NULL;
    free(pilha);
    return NULL;
}

/* 
 * Imprime a pilha, da base ate o topo, este por ultimo, sem espaco no final.
 * Quando a pilha estiver vazia, nao imprime nada, nem um \n.
 * Esta funcao eh somente para facilitar teus testes.
 * Normalmente ela nao existe nas implementacoes de um TAD pilha.
*/
void pilha_imprime (pilha_t* pilha){
    int i;

    if(!pilha_vazia(pilha)){
        printf("\n");
        for (i = 1; i <= pilha -> topo; i++){
            printf("%d ",pilha -> elems[pilha -> topo - i]);
        }
        printf("\n");
    } else {
        printf("\nPilha Vazia");
    }
}