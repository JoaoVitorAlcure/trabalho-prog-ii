#include "acao_ouro.h"
#include <stdlib.h>

struct Ouro{
    int quantidade;
};

/**
 * @brief Aloca dinamicamente uma ação do tipo OURO e guarda nela a quantidade
 * @param quantidade Quantidade de ouro
 * @return Ponteiro para o ouro criado
 */
Ouro *criaOuro(int quantidade){
    Ouro* ouro = malloc(sizeof(struct Ouro));
    ouro->quantidade = quantidade;
    return ouro;
}

/**
 * @brief Lê da entrada padrão, na mesma linha, a quantidade (a palavra OURO já deve ter sido lida)
 * e cria o ouro com criaOuro.
 * @return Ponteiro para o monstro criado
 */
Ouro *leOuro(){
    int quantidade;
    scanf("%d\n", &quantidade);
    return criaOuro(quantidade);
}

/**
 * @brief Converte o dado genérico para ouro e adiciona a quantidade para  o jogador.
 * @param dado Ponteiro genérico para o ouro
 * @param j Jogador que parou na célula
 */
void executaOuro(void *dado, Jogador *j){
    Ouro* ouro = (Ouro*)dado;
    adicionaOuroJogador(j, ouro->quantidade);
}