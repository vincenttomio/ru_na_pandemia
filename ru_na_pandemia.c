#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libfila.h"
#include "liblista.h"
#include "libpilha.h"
#include "libestudante.h"
#include "libtck.h"

/*
* Estrutura Criada para o Armazenamento da Contabilidade
*/
struct contabilidade_t{
    float din_ref;
    float din_mas;
};


/*
*Funcao que retorna 0 ou 1
*Com 5% de chance de ser 0
*Sendo (0=Nao | 1=Sim)
*/
int vacina(void){
    int n;
    
    n = (rand() % (1-100+1) + 1);
    if(n <= 5)
        return 0;
    else
        return 1;
    
}

/*
*Funcao que retorna 0 ou 1
*Com 10% de chance de ser 0
*Sendo (0=Nao | 1=Sim)
*/
int mascara(void){
    int n;
    
    n = (rand() % (1-10+1) + 1);
    if(n == 1)
        return 0;
    else
        return 1;
 
}

/*
*Funcao que retorna 1.30 ou 3.80
*Com 60% de chance de ser 1.30
*/
float dinheiro(void){
    int n;
    
    n = (rand() % (1-5+1) + 1);
    if(n % 2 == 0)
        return 3.80;
    else
        return 1.30;
        
}

/*
*Funcao que retorna numero aleatorio
*Entre Num Base e Num Teto
*/
int aleat(int base, int teto){
    int n;

    n = (rand() % (base-teto+ 1) + base);

    return n;
}




int main(void){
    int i,ticket;
    pilha_t * pmask;
    pilha_t * pmeal;
    fila_e  * fila_estudantes;
    lista_r * lista_tna;
    struct contabilidade_t ru;

/*
* Altera a semente padrao para nao repetir sempre os mesmos numeros
*/
    srand(time(NULL)); 


/*
* Inicializando struct que sera usada pra salvar dados da contabilidade
*/
    ru.din_ref = 0;
    ru.din_mas = 0;


/*
*Criado Pilha de Mascaras conforme enunciado entre 1 e 1000
*/
    pmask = pilha_cria(aleat(1,1000));
    if(pmask == NULL){
        printf("Erro ao criar Pilha. \n");
        return 1;
    } else {
        printf("\nPilha criada com: %d Mascaras \n",pilha_tamanho(pmask));
        for (i = 1; i <= pilha_tamanho(pmask); i++){
            if (push(pmask, i) == -1){
                printf("\nSem espaco na Pilha");
            }
        }
    }


/*
*Criado Pilha de Refeicoes conforme enunciado entre 500 e 1000
*/
    pmeal = pilha_cria(aleat(500,1000));
    if(pmeal == NULL){
        printf("Erro ao criar Pilha. \n");
        return 1;
    } else {
        printf("Pilha criada com: %d Refeicoes \n\n",pilha_tamanho(pmeal));
        for (i = 1; i <= pilha_tamanho(pmeal); i++){
            if (push(pmeal, i) == -1){
                printf("\nSem espaco na Pilha");
            }
        }
    }


/*
*Criado Fila de Estudantes
*Contendo: Ticket, Vacina, Mascara e dinheiro
*Fila contem 1000 Estudantes
*/
    fila_estudantes = fila_estudante_cria();
    if(fila_estudantes == NULL){
        printf("Erro ao criar Fila. \n");
        return 1;
    } else {
        printf("Preenchendo fila, com 1000 Estudantes\n");
        for(i = 1; i<=1000; i++){
            estudante_insere(fila_estudantes, i,vacina(),mascara(),dinheiro());
        }
    }


/*
*Criado Lista Ligada Simples de Tickets Nao Atendidos conforme enunciado
*/
    lista_tna = lista_tck_cria();
    if(lista_tna == NULL){
        printf("Erro ao criar Lista. \n");
        return 1;
    }


/*
* Criado um laco, que se mantem enquanto houver refeicoes ou pessoas
* O primeiro caso, IF, se da caso Pessoa NAO tenha vacina
* Sem Vacina se eh retirado e inserido na lista de tickets nao atendidos
* O segundo caso, IF, se da caso a pessoa tenha Mascara
* Dinheiro eh add ao ru, estudante sai da fila, pop pilha refeicao
* O terceiro caso, IF, se da caso o estudante tenha dinheiro suficiente e haja mascara na pilha pmask
* Dinheiro add ao ru, pop pmask, pessoa enviada ao final da fila
* Por ultimo sobra o caso Com vacina, Sem mascara e Sem din suficiente
* Eh add a lista de tickets nao atendidos
*/
    printf("\n-=FISCALIZACAO=-\n");


    while ((!pilha_vazia(pmeal)) && (!fila_estudante_vazia(fila_estudantes))){

        if((!estudante_vacina(fila_estudantes))){
            estudante_remove(fila_estudantes, &ticket);
            lista_tck_insere_fim(lista_tna,ticket,1);
        } else {
            if (estudante_mascara(fila_estudantes)) {
                pop(pmeal);
                ru.din_ref += 1.3;
                estudante_remove(fila_estudantes, &ticket);
            } else {
                if (estudante_dinheiro_suficiente(fila_estudantes) && (!pilha_vazia(pmask))){
                    pop(pmask);
                    ru.din_mas += 2.5;
                    estudante_final_fila(fila_estudantes);
                } else {
                    estudante_remove(fila_estudantes, &ticket);
                    lista_tck_insere_fim(lista_tna,ticket,2);
                }
            }
        } 
    }

/*
* Impressao da contabilidade
*/
    printf("\n-=Encerrado Restaurante=-\n");
    printf("Refeicoes  restantes: %d\n",pilha_topo(pmeal));
    printf("Mascaras   restantes: %d\n",pilha_topo(pmask));
    printf("Estudantes restantes: %d\n\n",fila_estudante_tamanho(fila_estudantes));


/*
* Caso as refeicoes tenham acabado
* Os estudantes que nao comeram
* Sao inseridos na Lista de Tickets nao atendidos
*/
    while (!fila_estudante_vazia(fila_estudantes)){    
        estudante_remove(fila_estudantes, &ticket);
        lista_tck_insere_fim(lista_tna,ticket,3);
    }

/*
* Impressao da contabilidade
*/
    printf("\n-=CONTABILIDADE=-\n");
    printf("Valor arrecadado no total      = R$%0.2f\n",ru.din_mas + ru.din_ref);
    printf("Valor arrecadado com refeicoes = R$%0.2f\n",ru.din_ref);
    printf("Valor arrecadado com mascaras  = R$%0.2f\n",ru.din_mas);


/*
* Impressao da quantidade de tickets nao atendidos
* Impressao dos tickts nao atendidos
*/
    printf("\n%d Tickets Nao Atendidos\n",lista_tck_tamanho(lista_tna));
    printf("Motivos dos tickets nao serem atendidos:\n");
    printf("1 Sem Vacina | 2 Sem Mascara e Dinheiro | 3 Acabou Refeicao\n");
    lista_tck_imprime(lista_tna);


/*
*Libera-se o espaco de memoria alocado dinamicamente
*Encerra-se o programa
*/
    printf("\nFREE - ESPACO DE MEMOMRIA LIBERADO \n");
    pilha_destroi(pmask);
    pilha_destroi(pmeal);
    fila_estudante_destroi(fila_estudantes);
    lista_tck_destroi(lista_tna);
    printf("\n|PROGRAMA SE ENCERRA|\n\n");

    return 0;
}