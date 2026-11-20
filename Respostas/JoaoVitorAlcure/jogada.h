#ifndef _JOGADA_H
#define _JOGADA_H

#include "jogador.h"

typedef struct Jogada Jogada;

/**
 * @brief Aloca dinamicamente um Jogada.
 * @param j Jogador responsável pela jogada
 * @param quantidade Quantidade retirada no dado
 * @return Ponteiro para a Jogada criada
 */
Jogada *criaJogada(Jogador *j, int quantidade);

/**
 * @brief Converte o dado genérico para Jogada e executa a jogada
 * @param dado Ponteiro genérico para o Jogada
 */
void executaJogada(void *dado);

/**
 * @brief Converte o dado genérico para Jogada e libera a memória alocada para ele
 * @param dado Ponteiro genérico para o Jogada
 */
void desalocaJogada(void *dado);

#endif // _JOGADA_H
