#ifndef _ACAO_VAZIA_H
#define _ACAO_VAZIA_H

#include "jogador.h"

/**
 * @brief Converte o dado genérico para Vazia e não executa nada
 * @param dado Ponteiro genérico para o Vazia
 * @param j Jogador que parou na célula
 */
int executaVazia(void *dado, Jogador *j);

/**
 * @brief Converte o dado genérico para Vazia e imprime, sem quebra de linha:
 * "VAZIA".
 * @param dado Ponteiro genérico para o Vazia
 */
void imprimeVazia(void *dado);

/**
 * @brief Converte o dado genérico para Vazia e libera a memória alocada para ele
 * @param dado Ponteiro genérico para o Vazia
 */
void desalocaVazia(void *dado);

#endif // _ACAO_VAZIA_H
