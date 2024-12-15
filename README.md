# RU na Pandemia

Este projeto simula o funcionamento de um Restaurante Universitário (RU) durante a pandemia, utilizando estruturas de dados como filas e pilhas para gerenciar o fluxo de estudantes. Desenvolvido como projeto final para a matéria de Programação da Universidade Federal do Paraná.

## Funcionalidades
- **Controle de acesso ao RU:** Verificação de vacinação, uso de máscara e pagamento.
- **Simulação financeira:** Rastreamento de receitas do RU com base nos valores pagos.
- **Estruturas de dados:** Uso de filas, pilhas e listas para organizar os dados de forma eficiente.

## Estruturas de Dados Utilizadas
- **Filas:** Para gerenciar a entrada de estudantes.
- **Pilhas:** Para controle de pagamentos.
- **Listas:** Para manipulação de dados gerais.

## Arquitetura do Projeto
O projeto é modularizado em vários arquivos:

- **`ru_na_pandemia.c`:** Arquivo principal que implementa a lógica do programa.
- **`libfila.c` / `libfila.h`:** Implementação das filas.
- **`libpilha.c` / `libpilha.h`:** Implementação das pilhas.
- **`liblista.c` / `liblista.h`:** Implementação das listas.
- **`libestudante.c` / `libestudante.h`:** Manipulação dos dados de estudantes.
- **`libtck.c` / `libtck.h`:** Funções auxiliares.
- **`makefile`:** Automação do processo de compilação.

## Compilação e Execução
1. Certifique-se de ter o compilador GCC instalado.
2. Para compilar o projeto, execute o comando:
   ```bash
   make
   ```
3. Para executar o programa:
   ```bash
   ./ru_na_pandemia
   ```

## Requisitos
- Compilador GCC compatível com a norma C90.
- Sistema operacional Linux ou similar para uso do `make`.

## Notas sobre o Funcionamento
- **Vacinação:** 5% de chance de um estudante não estar vacinado.
- **Uso de máscara:** 10% de chance de um estudante não usar máscara.
- **Pagamento:** Probabilidade de pagar R$ 1,30 (60%) ou R$ 3,80 (40%).

## Informações
Desenvolvido como parte dos requisitos da disciplina de Programação na UFPR.


🎓 **Autor:** Vincent Tomio

📫 Entre em contato: [seu-email](mailto:vvsbt20@inf.ufpr.br)
