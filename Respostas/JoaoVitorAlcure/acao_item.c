#include "acao_item.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Item{
    char nome[MAX_TAM_NOME_ITEM];
    int preco, bonus;
};

/**
 * @brief Aloca dinamicamente uma ação do tipo Item e guarda nela o nome (copiado), o preço e o bônus
 * @param nome Nome do Item
 * @param preco Preço do Item
 * @param bonus Bonus que o item da na forca
 * @return Ponteiro para o Item criado
 */
Item *criaItem(char *nome, int preco, int bonus){
    Item* item = malloc(sizeof(struct Item));
    strcpy(item->nome, nome);
    item->preco = preco;
    item->bonus = bonus;
    return item;
}

/**
 * @brief Lê da entrada padrão, na mesma linha, o nome, o preço e o bonus do item (a palavra ITEM
 * já deve ter sido lida) e cria o item com criaItem.
 * @return Ponteiro para o Item criado
 */
Item *leItem(){
    char nome[MAX_TAM_NOME_ITEM];
    int preco, bonus;
    scanf("%20s %d %d", nome, &preco, &bonus);
    return criaItem(nome, preco, bonus);
}

/**
 * @brief Converte o dado genérico para item e realiza a compra. Se o jogador tiver ouro suficiente automaticamente
 * o jogador compra, o ouro é descontado e o bonus do item é somado a sua força. Caso contrário nada acontece.
 * @param dado Ponteiro genérico para o Item
 * @param j Jogador que parou na célula
 */
int executaItem(void *dado, Jogador *j){
    Item* item = (Item*)dado;
    if (obtemOuroJogador(j) >= item->preco){
        adicionaOuroJogador(j, (item->preco*-1));
        adicionaForcaJogador(j, item->bonus);
    }
    return 0;
}

/**
 * @brief Converte o dado genérico para Item e imprime, sem quebra de linha:
 * "ITEM <nome> (P:<preco> F:<bonus>)". Ex: "ITEM ESPADA (P:10 F:+2)"
 * @param dado Ponteiro genérico para o Item
 */
void imprimeItem(void *dado){
    Item* item = (Item*)dado;
    printf("ITEM %s (P:%d F:+%d)", item->nome, item->preco, item->bonus);
}

/**
 * @brief Converte o dado genérico para Item e libera a memória alocada para ele
 * @param dado Ponteiro genérico para o Item
 */
void desalocaItem(void *dado){
    Item* item = (Item*)dado;
    free(item);
}