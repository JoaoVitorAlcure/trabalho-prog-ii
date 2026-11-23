#include "acao_vazia.h"
#include <stdio.h>


/**
 * @brief Converte o dado genérico para Vazia e não executa nada
 * @param dado Ponteiro genérico para o Vazia
 * @param j Jogador que parou na célula
 */
int executaVazia(void *dado, Jogador *j){
    return 0;
}

/**
 * @brief Converte o dado genérico para Vazia e imprime, sem quebra de linha:
 * "VAZIA".
 * @param dado Ponteiro genérico para o Vazia
 */
void imprimeVazia(void *dado){
    printf("VAZIA");
}

/**
 * @brief Converte o dado genérico para Vazia e libera a memória alocada para ele
 * @param dado Ponteiro genérico para o Vazia
 */
void desalocaVazia(void *dado){
}