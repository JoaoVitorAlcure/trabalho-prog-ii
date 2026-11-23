#include "acao_avanca.h"
#include <stdlib.h>
#include <stdio.h>


struct Avanca{
    int quantidade;
};

/**
 * @brief Aloca dinamicamente uma ação do tipo avanca e guarda nela a quantidade
 * @param quantidade Bonus que o Avanca da na forca
 * @return Ponteiro para o Avanca criado
 */
Avanca *criaAvanca(int quantidade){
    Avanca* avanca = malloc(sizeof(struct Avanca));
    avanca->quantidade = quantidade;
    return avanca;
}

/**
 * @brief Lê da entrada padrão, na mesma linha, a quantidade (a palavra AVANCA
 * já deve ter sido lida) e cria o Avanca com criaAvanca.
 * @return Ponteiro para o Avanca criado
 */
Avanca *leAvanca(){
    int quantidade;
    scanf(" %d", &quantidade);
    return criaAvanca(quantidade);
}

/**
 * @brief Converte o dado genérico para Avanca e realiza a ação de avancar. Não verifica a casa atual 
 * @param dado Ponteiro genérico para o Avanca
 * @param j Jogador que parou na célula
 */
int executaAvanca(void *dado, Jogador *j){
    Avanca* avanca = (Avanca*)dado;
    return avanca->quantidade;
}

/**
 * @brief Converte o dado genérico para Avanca e imprime, sem quebra de linha:
 * "AVANCA <quantidade>". Ex: "AVANCA 2"
 * @param dado Ponteiro genérico para o Avanca
 */
void imprimeAvanca(void *dado){
    Avanca* avanca = (Avanca*)dado;
    printf("AVANCA %d", avanca->quantidade);
}

/**
 * @brief Converte o dado genérico para Avanca e libera a memória alocada para ele
 * @param dado Ponteiro genérico para o Avanca
 */
void desalocaAvanca(void *dado){
    Avanca* avanca = (Avanca*)dado;
    free(avanca);
}