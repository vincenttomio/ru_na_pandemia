#include <stdio.h>
#include <stdlib.h>
#include "liblista.h"

/*
 * Cria uma lista vazia e a retorna, se falhar retorna NULL.
 */
lista_t * lista_cria() {
    lista_t * l = (lista_t * ) malloc(sizeof(lista_t));

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
lista_t * lista_destroi(lista_t * l) {
    nodo_l_t * no;

    if (!lista_vazia(l)) {
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
int lista_vazia(lista_t * l) {
    return l -> tamanho == 0;
}

/*
 * Retorna o tamanho da lista, isto eh, o numero de elementos presentes nela.
 */
int lista_tamanho(lista_t * l) {
    return l -> tamanho;
}

/*
 * Insere o elemento no inicio da lista.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
 */
int lista_insere_inicio(lista_t * l, int elemento) {
    nodo_l_t * novo = (nodo_l_t * ) malloc(sizeof(nodo_l_t));
    if (novo == NULL) {
        return 0;
    }
    novo -> elemento = elemento;

    if (lista_vazia(l)) { 
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
 * Insere o elemento no final da lista.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
 * Uso ptr dentro do laca, para percorrer ate localizar o fim da lista
 */
int lista_insere_fim(lista_t * l, int elemento) {
    nodo_l_t * novo = (nodo_l_t * ) malloc(sizeof(nodo_l_t));
    nodo_l_t * ptr = l -> ini;
    
    if (novo == NULL)
        return 0;

    novo -> elemento = elemento;
    novo -> prox = NULL;

    if (lista_vazia(l)) {
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
 * Insere o elemento na lista garantindo ordenacao em ordem crescente.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
 * Uso ptr e ant, para percorrer lista em laco, localizando local para inserir
 * Testo para caso seja o primeiro elemento
 */
int lista_insere_ordenado(lista_t * l, int elemento) {
    nodo_l_t * novo = (nodo_l_t * ) malloc(sizeof(nodo_l_t));
    nodo_l_t * ptr = l -> ini;
    nodo_l_t * ant = NULL;
    
    if (novo == NULL)
        return 0;

    novo -> elemento = elemento;
    novo -> prox = NULL;

    if (lista_vazia(l)) {
        novo -> prox = NULL;
        l -> ini = novo;
    } else {
        while (ptr != NULL && ptr -> elemento < elemento){
            ant = ptr;
            ptr = ptr -> prox;
        }
        if (ant == NULL){
            l -> ini = novo;
            novo -> prox = ptr;
        } else {
            ant -> prox = novo;
            novo -> prox = ptr;
        }   
    }
    
    l -> tamanho++;
    return 1;
}

/*
 * Remove o elemento do inicio da lista e o retorna em 'elemento'.
 * Retorna o elemento.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
 */
int lista_retira_inicio(lista_t * l, int * elemento) {
    nodo_l_t * ptr = l -> ini;

    if (!lista_vazia(l)) {
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
int lista_retira_fim(lista_t * l, int * elemento) {
    nodo_l_t * ptr = l -> ini;
    nodo_l_t * ant = NULL;

    if (lista_vazia(l)) {
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
 * Remove o elemento 'elemento' caso ele exista na lista.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
 * Se o elemento nao for encontrado na lista tambem retorna 0.
 */
int lista_retira_elemento(lista_t * l, int * elemento) {
    nodo_l_t * ptr = l -> ini;
    nodo_l_t * ant = NULL;

    if (lista_vazia(l)) 
        return 0;

    if(ptr -> elemento == * elemento) {
        l -> ini = ptr -> prox;
        free(ptr);
    } else {
        while (ptr != NULL && ptr -> elemento != * elemento){
            ant = ptr;
            ptr = ptr -> prox;
        }
        if (ptr == NULL){
            return 0;
        } else {
            ant -> prox = ptr -> prox;
            free(ptr);
        }
    }

    l -> tamanho--;
    return 1;
}

/*
 * Retorna 1 se o elemento existe na lista e 0 caso contrario.
 */
int lista_pertence(lista_t * l, int elemento) {
    nodo_l_t * ptr = l -> ini;

    while (ptr != NULL && ptr -> elemento != elemento) {
        ptr = ptr -> prox;
    }

    return (ptr != NULL);
}

/*
 * Imprime a lista, do inicio ate o fim, este por ultimo, sem espaco no final.
 * Quando a lista estiver vazia, nao imprime nada, nem um \n.
 * Esta funcao eh somente para facilitar teus testes.
 * Normalmente ela nao existe nas implementacoes de um TAD lista.
*/
void lista_imprime (lista_t* l){
    nodo_l_t * ptr = l -> ini;

    printf("\n\nLista: ");

	while(ptr != NULL){
		printf("%d ", ptr -> elemento);
		ptr = ptr -> prox;
	}
	printf("\n");

}