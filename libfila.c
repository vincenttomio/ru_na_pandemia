#include <stdio.h>
#include <stdlib.h>
#include "libfila.h"

/*
 * Cria uma fila vazia e a retorna, se falhar retorna NULL.
 */
fila_t * fila_cria() {
    fila_t * f = (fila_t * ) malloc(sizeof(fila_t));

    if (f == NULL) {
        return NULL;
    }

    f -> ini = NULL;
    f -> fim = NULL;
    f -> tamanho = 0;
    return f;
}

/*
 * Remove todos os elementos da fila, libera espaco e devolve NULL.
 */
fila_t * fila_destroi(fila_t * f) {
    nodo_f_t * no;

    if (!fila_vazia(f)) {
        no = f -> ini;
        while (no) {
            f -> ini = no -> prox;
            free(no);
            f -> tamanho--;
            no = f -> ini;
        }
    }
    free(f);
    f = NULL;
    return NULL;
}
/*
 * Retorna 1 se a fila esta vazia e 0 caso contrario.
 */
int fila_vazia(fila_t * f) {
    return f -> tamanho == 0;
}

/*
 * Retorna o tamanho da fila, isto eh, o numero de elementos presentes nela.
 */
int fila_tamanho(fila_t * f) {
    return f -> tamanho;
}

/*
 * Insere o chave no final da fila (politica FIFO).
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
 */
int queue(fila_t * f, int chave) {
    nodo_f_t * novo = (nodo_f_t * ) malloc(sizeof(nodo_f_t));

    if (novo == NULL) {
        return 0;
    }

    novo -> chave = chave;
    novo -> prox = NULL;

    if (fila_vazia(f)) {
        novo -> prox = NULL;
        f -> ini = novo;
    } else {
        f -> fim -> prox = novo;
    }
    f -> fim = novo;
    f -> tamanho++;
    return 1;
}

/*
 * Remove o chave do inicio da fila (politica FIFO) e o retorna.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
 */
int dequeue(fila_t * f, int * chave) {
    nodo_f_t * no;

    if (fila_vazia(f))
        return 0;

    no = f -> ini;
    * chave = no -> chave;
    if (f -> ini == f -> fim) {
        f -> ini = NULL;
        f -> fim = NULL;
    } else {
        f -> ini = no -> prox;
    }

    free(no);
    f -> tamanho--;
    return 1;
}

/*
 * Imprime a fila, do inicio ate o fim, este por ultimo, sem espaco no final.
 * Quando a fila estiver vazia, nao imprime nada, nem um \n.
 * Esta funcao eh somente para facilitar teus testes.
 * Normalmente ela nao existe nas implementacoes de um TAD fila.
*/
void fila_imprime (fila_t* f){
    nodo_f_t * ptr = f -> ini;

    printf("\nFila: ");

    while(ptr != NULL){
        printf("%d ", ptr -> chave);
        ptr = ptr -> prox;
    }

}

