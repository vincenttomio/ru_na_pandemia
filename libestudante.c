#include <stdio.h>
#include <stdlib.h>
#include "libestudante.h"

/*
 * Cria uma fila vazia e a retorna, se falhar retorna NULL.
 */
fila_e * fila_estudante_cria() {
    fila_e * f = (fila_e * ) malloc(sizeof(fila_e));

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
fila_e * fila_estudante_destroi(fila_e * f) {
    nodo_e_t * no;

    if (!fila_estudante_vazia(f)) {
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
int fila_estudante_vazia(fila_e * f) {
    return f -> tamanho == 0;
}

/*
 * Retorna o tamanho da fila, isto eh, o numero de elementos presentes nela.
 */
int fila_estudante_tamanho(fila_e * f) {
    return f -> tamanho;
}

/*
 * Insere o chave no final da fila (politica FIFO).
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
 */
int estudante_insere(fila_e * f, int num_ticket, int vac, int mas, float din) {
    nodo_e_t * novo = (nodo_e_t * ) malloc(sizeof(nodo_e_t));

    if (novo == NULL) {
        return 0;
    }

    novo -> ticket = num_ticket;
    novo -> vacina = vac;
    novo -> mascara = mas;
    novo -> dinheiro = din;
    novo -> prox = NULL;

    if (fila_estudante_vazia(f)) {
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
int estudante_remove(fila_e * f, int * chave) {
    nodo_e_t * no;

    if (fila_estudante_vazia(f))
        return 0;

    no = f -> ini;
    * chave = no -> ticket;
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
 * Retorna 1 se estudante vacinado e 0 caso contrario.
*/
int estudante_vacina(fila_e* f){
    nodo_e_t * ptr = f -> ini;

    if (ptr -> vacina == 0){
        return 0;
    } else {
        return 1;
    }
}

/*
 * Retorna 1 se estudante tem mascara e 0 caso contrario.
*/
int estudante_mascara(fila_e* f){
    nodo_e_t * ptr = f -> ini;

    if (ptr -> mascara == 0){
        return 0;
    } else {
        return 1;
    }
}

/*
 * Retorna 1 se estudante tem 3.8 e 0 caso contrario.
*/
int estudante_dinheiro_suficiente(fila_e* f){
    nodo_e_t * ptr = f -> ini;

    if (ptr -> dinheiro > 2){
        return 1;
    } else {
        return 0;
    }
}

/*
 * Retira 2.5 do valor do Estudante
 * Mascara passa a ser 1
 * Coloca seu ticket no final da fila
*/
void estudante_final_fila(fila_e* f){
    nodo_e_t * ptr = f -> ini;
    int tmp;

    estudante_insere(f, ptr -> ticket, ptr -> vacina, 1, 1.30);
    estudante_remove(f,&tmp);
}

/*
 * Imprime a fila, do inicio ate o fim, este por ultimo, sem espaco no final.
 * Quando a fila estiver vazia, nao imprime nada, nem um \n.
 * Esta funcao eh somente para facilitar teus testes.
 * Normalmente ela nao existe nas implementacoes de um TAD fila.
*/
void fila_estudante_imprime(fila_e* f){
    nodo_e_t * ptr = f -> ini;

    printf("\nFila de Estudantes:\n");

    while(ptr != NULL){
        printf("Ticket : %d | Vacina : %d | Mascara : %d | dinheiro : %0.2f\n", ptr -> ticket, ptr -> vacina, ptr -> mascara, ptr -> dinheiro);
        ptr = ptr -> prox;
    }
    printf("\n\n");
    }

