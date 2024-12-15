/*
 * TAD Estudante
 * Autor: Vincent
 *
 * May 6, 2022
*/

#ifndef _LIBestudante_t_H
#define _LIBestudante_t_H

struct nodo_e {
    int ticket;            /* fila de numeros inteiros, ticket do estudante */
    int vacina;            /* contem 0 e 1 para vacinacao */
    int mascara;           /* contem 0 e 1 para uso de mascara */
    float dinheiro;        /* fila de numeros float contendo dinheiro */
    struct nodo_e *prox;   /* ponteiro para o proximo  */
};
typedef struct nodo_e nodo_e_t;

struct fila_estudante {
    nodo_e_t* ini;        /* ponteiro para o inicio da fila */
    nodo_e_t* fim;        /* ponteiro para o fim da fila    */
    int tamanho;          /* numero de elementos na fila    */
};
typedef struct fila_estudante fila_e;

/*
 * Cria uma fila vazia e a retorna, se falhar retorna NULL.
*/
fila_e* fila_estudante_cria ();

/*
 * Remove todos os elementos da fila, libera espaco e devolve NULL.
*/
fila_e* fila_estudante_destroi (fila_e* f);

/*
 * Retorna 1 se a fila esta vazia e 0 caso contrario.
*/
int fila_estudante_vazia (fila_e* f);

/*
 * Retorna o tamanho da fila, isto eh, o numero de elementos presentes nela.
*/
int fila_estudante_tamanho (fila_e* f);

/*
 * Insere o elemento no final da fila (politica FIFO).
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
*/
int estudante_insere (fila_e * f, int num_ticket, int vac, int mas, float din);

/*
 * Remove elemento do inicio da fila (politica FIFO) e o retorna.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
*/
int estudante_remove (fila_e* f, int* elemento);

/*
 * Retorna 1 se estudante vacinado e 0 caso contrario.
*/
int estudante_vacina (fila_e* f);

/*
 * Retorna 1 se estudante tem mascara e 0 caso contrario.
*/
int estudante_mascara(fila_e* f);

/*
 * Retorna 1 se estudante tem 3.8 e 0 caso contrario.
*/
int estudante_dinheiro_suficiente(fila_e* f);

/*
 * Retira 2.5 do valor do Estudante
 * Mascara passa a ser 1
 * Coloca seu ticket no final da fila
*/
void estudante_final_fila(fila_e* f);


/*
 * Imprime a fila, do inicio ate o fim, este por ultimo, sem espaco no final.
 * Quando a fila estiver vazia, nao imprime nada, nem um \n.
 * Esta funcao eh somente para facilitar teus testes.
 * Normalmente ela nao existe nas implementacoes de um TAD fila.
*/
void fila_estudante_imprime (fila_e* f);

#endif
