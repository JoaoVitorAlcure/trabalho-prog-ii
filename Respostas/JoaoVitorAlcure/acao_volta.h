#ifndef _ACAO_VOLTA_H
#define _ACAO_VOLTA_H

#include "jogador.h"
#include "mapa.h"

typedef struct Volta Volta;

/**
 * @brief Aloca dinamicamente uma ação do tipo Volta e guarda nela a quantidade
 * @param quantidade Bonus que o Volta da na forca
 * @return Ponteiro para o Volta criado
 */
Volta *criaVolta(int quantidade);

/**
 * @brief Lê da entrada padrão, na mesma linha, a quantidade (a palavra VOLTA
 * já deve ter sido lida) e cria o Volta com criaVolta.
 * @return Ponteiro para o Volta criado
 */
Volta *leVolta();

/**
 * @brief Converte o dado genérico para Volta e realiza a ação de Voltar. Não verifica a casa atual 
 * @param dado Ponteiro genérico para o Volta
 * @param j Jogador que parou na célula
 */
void executaVolta(Mapa *m, void *dado, Jogador *j);

/**
 * @brief Converte o dado genérico para Volta e imprime, sem quebra de linha:
 * "Volta <quantidade>". Ex: "Volta 2"
 * @param dado Ponteiro genérico para o Volta
 */
void imprimeVolta(void *dado);

/**
 * @brief Converte o dado genérico para Volta e libera a memória alocada para ele
 * @param dado Ponteiro genérico para o Volta
 */
void desalocaVolta(void *dado);

#endif // _ACAO_VOLTA_H
