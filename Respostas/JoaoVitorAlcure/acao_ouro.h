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
int executaOuro(void *dado, Jogador *j);

/**
 * @brief Converte o dado genérico para ouro e imprime, sem quebra de linha:
 * "OURO <quantidade>". Ex: "OURO 10"
 * @param dado Ponteiro genérico para o ouro
 */
void imprimeOuro(void *dado);

/**
 * @brief Converte o dado genérico para ouro e libera a memória alocada para ele
 * @param dado Ponteiro genérico para o ouro
 */
void desalocaOuro(void *dado);

#endif // _ACAO_OURO_H
