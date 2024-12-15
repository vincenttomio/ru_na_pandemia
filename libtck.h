/*
 * TAD Estudante
 * Autor: Vincent
 *
 * May 6, 2022
*/

#ifndef _LIBru_t_H
#define _LIBru_t_H

struct nodo_tck {
    int ticketna;           /* Numeros inteiros tickets n atendidos */
    int motivo;             /* Motivo do ticket nao ser atendido   */
    struct nodo_tck* prox;   /* ponteiro para o proximo   */
};
typedef struct nodo_tck nodo_tck_t;

struct lista_tna {
    nodo_tck_t* ini;      /* ponteiro para o inicio da lista */
    int tamanho;        /* numero de elementos na lista    */
};
typedef struct lista_tna lista_r;

/*
 * Cria uma lista vazia e a retorna, se falhar retorna NULL.
*/
lista_r* lista_tck_cria ();

/*
 * Remove todos os elementos da lista, libera espaco e retorna NULL.
*/
lista_r* lista_tck_destroi (lista_r* l);

/*
 * Retorna 1 se a lista esta vazia e 0 caso contrario.
*/
int lista_tck_vazia (lista_r* l);

/*
 * Retorna o tamanho da lista, isto eh, o numero de elementos presentes nela.
*/
int lista_tck_tamanho (lista_r* l);

/*
 * Insere o Ticket e Motivo no inicio da lista.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
*/
int lista_tck_insere_inicio (lista_r * l, int ticket, int motivo);

/*
 * Insere o Ticket e Motivo no final da lista.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
*/
int lista_tck_insere_fim (lista_r * l, int ticket, int motivo);

/*
 * Remove o Ticket e Motivo do inicio da lista e o retorna em 'elemento'.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
*/
int lista_tck_retira_inicio (lista_r* l, int* elemento);

/*
 * Remove o Ticket e Motivo do final da lista e o retorna em 'elemento'.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
*/
int lista_tck_retira_fim (lista_r* l, int* elemento);


/*
 * Imprime a lista, do inicio ate o fim, este por ultimo, sem espaco no final.
 * Quando a lista estiver vazia, nao imprime nada, nem um \n.
 * Esta funcao eh somente para facilitar teus testes.
 * Normalmente ela nao existe nas implementacoes de um TAD lista.
*/
void lista_tck_imprime (lista_r* l);

#endif