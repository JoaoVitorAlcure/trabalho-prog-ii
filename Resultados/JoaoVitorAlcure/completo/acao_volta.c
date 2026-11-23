#include "acao_volta.h"
#include <stdlib.h>
#include <stdio.h>


struct Volta{
    int quantidade;
};

/**
 * @brief Aloca dinamicamente uma ação do tipo Volta e guarda nela a quantidade
 * @param quantidade Bonus que o Volta da na forca
 * @return Ponteiro para o Volta criado
 */
Volta *criaVolta(int quantidade){
    Volta* volta = malloc(sizeof(struct Volta));
    volta->quantidade = quantidade;
    return volta;
}

/**
 * @brief Lê da entrada padrão, na mesma linha, a quantidade (a palavra VOLTA
 * já deve ter sido lida) e cria o Volta com criaVolta.
 * @return Ponteiro para o Volta criado
 */
Volta *leVolta(){
    int quantidade;
    scanf(" %d", &quantidade);
    return criaVolta(quantidade);
}

/**
 * @brief Converte o dado genérico para Volta e realiza a ação de Voltar. Não verifica a casa atual 
 * @param dado Ponteiro genérico para o Volta
 * @param j Jogador que parou na célula
 */
int executaVolta(void *dado, Jogador *j){
    Volta* volta = (Volta*)dado;
    return volta->quantidade*-1;
}

/**
 * @brief Converte o dado genérico para Volta e imprime, sem quebra de linha:
 * "VOLTA <quantidade>". Ex: "VOLTA 3"
 * @param dado Ponteiro genérico para o Volta
 */
void imprimeVolta(void *dado){
    Volta* volta = (Volta*)dado;
    printf("VOLTA %d", volta->quantidade);
}

/**
 * @brief Converte o dado genérico para Volta e libera a memória alocada para ele
 * @param dado Ponteiro genérico para o Volta
 */
void desalocaVolta(void *dado){
    Volta* volta = (Volta*)dado;
    free(volta);
}