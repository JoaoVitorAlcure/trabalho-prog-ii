#ifndef _ACAO_ITEM_H
#define _ACAO_ITEM_H

#include "jogador.h"

#define MAX_TAM_NOME_ITEM 21

typedef struct Item Item;

/**
 * @brief Aloca dinamicamente uma ação do tipo Item e guarda nela o nome (copiado), o preço e o bônus
 * @param nome Nome do Item
 * @param preco Preço do Item
 * @param bonus Bonus que o item da na forca
 * @return Ponteiro para o Item criado
 */
Item *criaItem(char *nome, int preco, int bonus);

/**
 * @brief Lê da entrada padrão, na mesma linha, o nome, a força e a XP do Item (a palavra Item
 * já deve ter sido lida) e cria o Item com criaItem.
 * @return Ponteiro para o Item criado
 */
Item *leItem();

/**
 * @brief Converte o dado genérico para item e realiza a compra. Se o jogador tiver ouro suficiente automaticamente
 * o jogador compra, o ouro é descontado e o bonus do item é somado a sua força. Caso contrário nada acontece.
 * @param dado Ponteiro genérico para o Item
 * @param j Jogador que parou na célula
 * @return 0 se o jogador vencer ou RECUO_CELULA se perder
 */
int executaItem(void *dado, Jogador *j);

/**
 * @brief Converte o dado genérico para Item e imprime, sem quebra de linha:
 * "ITEM <nome> (P:<preco> F:<bonus>)". Ex: "ITEM ESPADA (P:10 F:+2)"
 * @param dado Ponteiro genérico para o Item
 */
void imprimeItem(void *dado);

/**
 * @brief Converte o dado genérico para Item e libera a memória alocada para ele
 * @param dado Ponteiro genérico para o Item
 */
void desalocaItem(void *dado);

#endif // _ACAO_ITEM_H
