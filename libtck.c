#include <stdio.h>
#include <stdlib.h>
#include "libtck.h"

/*
 * Cria uma lista vazia e a retorna, se falhar retorna NULL.
 */
lista_r * lista_tck_cria() {
    lista_r * l = (lista_r * ) malloc(sizeof(lista_r));

    if (l == NULL) {
        return NULL;
    }

    l -> ini = NULL;
    l -> tamanho = 0;
    return l;
}

/*
 * Remove todos os elementos da lista, libera espaco e retorna NULL.
 */
lista_r * lista_tck_destroi(lista_r * l) {
    nodo_tck_t * no;

    if (!lista_tck_vazia(l)) {
        no = l -> ini;
        while (no) {
            l -> ini = no -> prox;
            free(no);
            l -> tamanho--;
            no = l -> ini;
        }
    }
    free(l);
    l = NULL;

    return NULL;
}

/*
 * Retorna 1 se a lista esta vazia e 0 caso contrario.
 */
int lista_tck_vazia(lista_r * l) {
    return l -> tamanho == 0;
}

/*
 * Retorna o tamanho da lista, isto eh, o numero de elementos presentes nela.
 */
int lista_tck_tamanho(lista_r * l) {
    return l -> tamanho;
}

/*
 * Insere o Ticket e Motivo no inicio da lista.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
 */
int lista_tck_insere_inicio(lista_r * l, int ticket, int motivo) {
    nodo_tck_t * novo = (nodo_tck_t * ) malloc(sizeof(nodo_tck_t));
    if (novo == NULL) {
        return 0;
    }
    novo -> ticketna = ticket;
    novo -> motivo = motivo;

    if (lista_tck_vazia(l)) { 
        novo -> prox = NULL;
        l -> ini = novo;
    } else {
        novo -> prox = l -> ini;
        l -> ini = novo;
    }

    l -> tamanho++;
    return 1;
}

/*
 * Insere o Ticket e Motivo no final da lista.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
 * Uso ptr dentro do laca, para percorrer ate localizar o fim da lista
 */
int lista_tck_insere_fim(lista_r * l, int ticket, int motivo) {
    nodo_tck_t * novo = (nodo_tck_t * ) malloc(sizeof(nodo_tck_t));
    nodo_tck_t * ptr = l -> ini;
    
    if (novo == NULL)
        return 0;

    novo -> ticketna = ticket;
    novo -> motivo = motivo;
    novo -> prox = NULL;

    if (lista_tck_vazia(l)) {
        novo -> prox = NULL;
        l -> ini = novo;
    } else {
        while (ptr -> prox != NULL){
            ptr = ptr -> prox;
        }
        ptr -> prox = novo;
    }

    l -> tamanho++;
    return 1;
}



/*
 * Remove o elemento do inicio da lista e o retorna em 'elemento'.
 * Retorna o elemento.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
 */
int lista_tck_retira_inicio(lista_r * l, int * elemento) {
    nodo_tck_t * ptr = l -> ini;

    if (!lista_tck_vazia(l)) {
        l -> ini = ptr -> prox;
        free(ptr);
        l -> tamanho--;
        return 1;
    }
    return 0;
}

/*
 * Remove o elemento do final da lista e o retorna em 'elemento'.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
 * Uso ptr e ant, para percorrer lista em laco, localizando local para retirar
 * Testo para caso seja o primeiro elemento
 */
int lista_tck_retira_fim(lista_r * l, int * elemento) {
    nodo_tck_t * ptr = l -> ini;
    nodo_tck_t * ant = NULL;

    if (lista_tck_vazia(l)) {
        return 0;
    } else {
        while (ptr -> prox != NULL){
            ant = ptr;
            ptr = ptr -> prox;
        }
        if (ant == NULL){
            free(ptr);
            l -> ini = NULL;
        } else {
            free(ptr);
            ant -> prox = NULL;
        }
    }

    l -> tamanho--;
    return 1;
}


/*
 * Imprime a lista, do inicio ate o fim, este por ultimo, sem espaco no final.
 * Quando a lista estiver vazia, nao imprime nada, nem um \n.
 * Esta funcao eh somente para facilitar teus testes.
 * Normalmente ela nao existe nas implementacoes de um TAD lista.
*/
void lista_tck_imprime (lista_r* l){
    nodo_tck_t * ptr = l -> ini;

    printf("\nLista:\n");

	while(ptr != NULL){
		printf("Ticket: %d | Motivo: %d\n", ptr -> ticketna, ptr -> motivo);
		ptr = ptr -> prox;
	}
	printf("\n");

}