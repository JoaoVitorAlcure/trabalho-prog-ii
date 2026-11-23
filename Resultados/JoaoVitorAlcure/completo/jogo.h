#ifndef _JOGO_H
#define _JOGO_H

#include "jogador.h"

#define TAM_COMANDO 51
/**
 * Estrutura do jogo (Com mapa, vetor de jogadores e informacoes da partida).
 * JogoAcabou = 0
 */
typedef struct Jogo Jogo;

/**
 * @brief Aloca dinamicamente um jogo, sem mapa (mapa = NULL) e sem jogadores (jogadores = NULL)
 * @return Ponteiro para o Jogo criado
 */
Jogo *criaJogo();

/**
 * @brief Cria e cadastra o mapa
 * @param j Jogo
 */
void cadastraMapaJogo(Jogo *j);

/**
 * @brief Cadastra os jogadores
 * @param j Jogo
 */
void cadastraJogadoresJogo(Jogo *j);

/**
 * @brief Simula onde o jogador vai se mover e verifica se na casa destinada tem uma disputa, se houver
 * ocorre a disputa normalmente
 * @param j Jogo
 */
int moveEVerificaDisputaJogador(Jogo *j, Jogador *jogador, int posicao);


/**
 * @brief Executa as jogadas
 * @param j Jogo
 */
void executaJogada(Jogo *j);

/**
 * @brief Executa o jogo
 * @param j Jogo
 * @param comando comando passado logo após o cadastro dos jogadores
 */
void executaJogo(Jogo *j, char* comando);

/**
 * @brief Verifica o estado do jogo para saber se ele está em andamento ou foi finalizado
 * (Altera o situacao dentro de jogo)
 * @param j Jogo
 */
void verificaEstadoJogo(Jogo *j);

/**
 * @brief Imprime os jogadores que estão em certa posição
 * @param j Jogo
 * @param posicao Posição que se deseja imprimir
 */
void imprimeJogadoresPosicao(Jogo *j, int posicao);

/**
 * @brief Imprime o estado do jogo
 * @param j Jogo
 */
void imprimeEstadoJogo(Jogo *j);

/**
 * @brief Imprime o ranking do jogo
 * @param j Jogo
 */
void imprimeRankingJogo(Jogo *j);

/**
 * @brief Imprime o relatorio do jogo
 * @param j Jogo
 */
void imprimeRelatorioJogo(Jogo *j);

/**
 * @brief Desaloca o mapa, o vetor de jogadores e o jogo
 * @param j Jogo
 */
void desalocaJogo(Jogo *j);

#endif // _JOGO_H
