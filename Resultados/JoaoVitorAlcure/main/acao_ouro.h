#ifndef _ACAO_OURO_H
#define _ACAO_OURO_H

#include "jogador.h"

typedef struct Ouro Ouro;

/**
 * @brief Aloca dinamicamente uma ação do tipo OURO e guarda nela a quantidade
 * @param quantidade Quantidade de ouro
 * @return Ponteiro para o ouro criado
 */
Ouro *criaOuro(int quantidade);

/**
 * @brief Lê da entrada padrão, na mesma linha, a quantidade (a palavra OURO já deve ter sido lida)
 * e cria o ouro com criaOuro.
 * @return Ponteiro para o monstro criado
 */
Ouro *leOuro();

/**
 * @brief Converte o dado genérico para ouro e adiciona a quantidade para  o jogador.
 * @param dado Ponteiro genérico para o ouro
 * @param j Jogador que parou na célula
 */
void executaOuro(void *dado, Jogador *j);

#endif // _ACAO_OURO_H
