#ifndef _ACAO_AVANCA_H
#define _ACAO_AVANCA_H

#include "jogador.h"
#include "mapa.h"

typedef struct Avanca Avanca;

/**
 * @brief Aloca dinamicamente uma ação do tipo avanca e guarda nela a quantidade
 * @param quantidade Bonus que o Avanca da na forca
 * @return Ponteiro para o Avanca criado
 */
Avanca *criaAvanca(int quantidade);

/**
 * @brief Lê da entrada padrão, na mesma linha, a quantidade (a palavra Avanca
 * já deve ter sido lida) e cria o Avanca com criaAvanca.
 * @return Ponteiro para o Avanca criado
 */
Avanca *leAvanca();

/**
 * @brief Converte o dado genérico para Avanca e realiza a ação de avancar. Não verifica a casa atual 
 * @param dado Ponteiro genérico para o Avanca
 * @param j Jogador que parou na célula
 */
void executaAvanca(Mapa *m, void *dado, Jogador *j);

/**
 * @brief Converte o dado genérico para Avanca e imprime, sem quebra de linha:
 * "AVANCA <quantidade>". Ex: "AVANCA 2"
 * @param dado Ponteiro genérico para o Avanca
 */
void imprimeAvanca(void *dado);

/**
 * @brief Converte o dado genérico para Avanca e libera a memória alocada para ele
 * @param dado Ponteiro genérico para o Avanca
 */
void desalocaAvanca(void *dado);

#endif // _ACAO_AVANCA_H
