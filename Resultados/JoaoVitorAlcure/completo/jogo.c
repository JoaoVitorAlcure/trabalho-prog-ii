#include "jogo.h"
#include "mapa.h"
#include "acao_monstro.h"
#include "acao_ouro.h"
#include "acao_avanca.h"
#include "acao_volta.h"
#include "acao_item.h"
#include "acao_vazia.h"
#include "jogador.h"
#include "dado.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Jogo{
    Mapa* mapa;
    Jogador** jogadores;
    int qtdJogadores, jogoAcabou, jogadorAtual, jogadorVencedor;
};

/**
 * @brief Aloca dinamicamente um jogo, sem mapa (mapa = NULL) e sem jogadores (jogadores = NULL)
 * @return Ponteiro para o Jogo criado
 */
Jogo *criaJogo(){
    Jogo* jogo = malloc(sizeof(struct Jogo));
    jogo->mapa = NULL;
    jogo->jogadores = NULL;
    jogo->qtdJogadores = 0;
    jogo->jogoAcabou = 0;
    jogo->jogadorAtual = 0;
    jogo->jogadorVencedor = 0;
    return jogo;
}

/**
 * @brief Cria e cadastra o mapa
 * @param j Jogo
 */
void cadastraMapaJogo(Jogo *j){
    j->mapa = criaMapa();
    char comando[TAM_COMANDO];
    scanf("%[^\n]\n", comando);
    scanf("%s", comando);
    while (strcmp(comando, "FIM") != 0){
        if (strcmp(comando, "MONSTRO") == 0){
            Monstro* monstro = leMonstro();
            insereCelulaMapa(j->mapa, monstro, executaMonstro, imprimeMonstro, desalocaMonstro);
        } else if (strcmp(comando, "AVANCA") == 0){
            Avanca* avanca = leAvanca();
            insereCelulaMapa(j->mapa, avanca, executaAvanca, imprimeAvanca, desalocaAvanca);
        } else if (strcmp(comando, "VAZIA") == 0){
            insereCelulaMapa(j->mapa, NULL, executaVazia, imprimeVazia, desalocaVazia);
        } else if (strcmp(comando, "ITEM") == 0){
            Item* item = leItem();
            insereCelulaMapa(j->mapa, item, executaItem, imprimeItem, desalocaItem);
        } else if (strcmp(comando, "VOLTA") == 0){
            Volta* volta = leVolta();
            insereCelulaMapa(j->mapa, volta, executaVolta, imprimeVolta, desalocaVolta);
        } else if (strcmp(comando, "OURO") == 0){
            Ouro* ouro = leOuro();
            insereCelulaMapa(j->mapa, ouro, executaOuro, imprimeOuro, desalocaOuro);
        }
        scanf("%s", comando);
    }
    scanf("%s", comando);
}

/**
 * @brief Cadastra os jogadores
 * @param j Jogo
 */
void cadastraJogadoresJogo(Jogo *j){
    Jogador* jogadorASerCadastrado = leJogador();
    int i=0, jogadorJaExiste=0;
    for(i;i<j->qtdJogadores;i++){
        Jogador* jogador = j->jogadores[i];
        if (comparaNomeJogador(jogadorASerCadastrado, obtemNomeJogador(jogador))){
            jogadorJaExiste = 1;
            break;
        }
    }

    if (jogadorJaExiste){
        free(jogadorASerCadastrado);
        return;
    }

    j->jogadores = realloc(j->jogadores, (j->qtdJogadores+1)*sizeof(Jogador*));
    j->jogadores[j->qtdJogadores] = jogadorASerCadastrado;
    j->qtdJogadores++;
}

/**
 * @brief Simula onde o jogador vai se mover e verifica se na casa destinada tem uma disputa, se houver
 * ocorre a disputa normalmente
 * 
 * @return 1 se a casa esta livre ou houve disputa e o desafiante venceu, 0 se houve disputa e ele perdeu
 * @param j Jogo
 */
int moveEVerificaDisputaJogador(Jogo *j, Jogador *jogador, int posicao){
    Jogador* ocupante = obtemOcupanteMapa(j->mapa, posicao);
    
    if (ocupante != NULL && ocupante != jogador){
        if (venceDisputaJogador(jogador, ocupante) == 0){
            incrementaDisputasVencidasJogador(ocupante);
            retiraJogadorMapa(j->mapa, jogador);
            recuaJogadorMapa(j->mapa, jogador, posicao);
            return 0;
        } else {
            incrementaDisputasVencidasJogador(jogador);
            retiraJogadorMapa(j->mapa, jogador);
            retiraJogadorMapa(j->mapa, ocupante);
            recuaJogadorMapa(j->mapa, ocupante, posicao);
            moveJogadorMapa(j->mapa, jogador, posicao);
            return 1;
        }
    } else {
        moveJogadorMapa(j->mapa, jogador, posicao);
        return 1;
    }
}


/**
 * @brief Executa as jogadas
 * @param j Jogo
 */
void executaJogada(Jogo *j){
    Jogador* jogadorAtual = j->jogadores[j->jogadorAtual];
    int valor = RolaDado();
    int posicao = valor+obtemPosicaoJogador(jogadorAtual);

    incrementaJogadasJogador(jogadorAtual);

    if (posicao >= obtemPosicaoFimMapa(j->mapa)){
        posicao = obtemPosicaoFimMapa(j->mapa);
    }

    if (moveEVerificaDisputaJogador(j, jogadorAtual, posicao) == 0){
        return;
    }

    Celula *celula = obtemCelulaMapa(j->mapa, posicao);

    if (celula == NULL){
        return;
    }

    int deslocamento = executaAcaoCelula(celula, jogadorAtual);
    if (deslocamento == RECUO_CELULA){
        recuaJogadorMapa(j->mapa, jogadorAtual, posicao);
    } else if (deslocamento != 0){
        int novaPosicao = posicao+deslocamento;
        if (novaPosicao < 0){
            novaPosicao = 0;
        } else if (novaPosicao >= obtemPosicaoFimMapa(j->mapa)){
            novaPosicao = obtemPosicaoFimMapa(j->mapa);
        }
        moveEVerificaDisputaJogador(j, jogadorAtual, novaPosicao);
    }
}

/**
 * @brief Executa o jogo
 * @param j Jogo
 */
void executaJogo(Jogo *j, char* comando){
    while (strcmp(comando, "F") != 0){
        
        if (strcmp(comando, "ROLAGEM") == 0){
            int tamRolagem=0;
            scanf(" %d\n", &tamRolagem);

            while(tamRolagem>0 && j->jogoAcabou != 1){
                executaJogada(j);
                verificaEstadoJogo(j);

                if (j->jogoAcabou == 1){
                    break;
                }

                if (j->jogadorAtual == (j->qtdJogadores-1)){
                    j->jogadorAtual = 0;
                } else {
                    j->jogadorAtual++;
                }

                tamRolagem--;
            }
        } else if (strcmp(comando, "E") == 0){
            scanf(" %s", comando);
            if (strcmp(comando, "ESTADO") == 0){
                imprimeEstadoJogo(j);
            } else if (strcmp(comando, "RANKING") == 0){
                imprimeRankingJogo(j);
            } else if (strcmp(comando, "RELATORIO") == 0){
                imprimeRelatorioJogo(j);
            }
        } 
        scanf("%s", comando);
    }
}

/**
 * @brief Verifica o estado do jogo para saber se ele está em andamento ou foi finalizado
 * (Altera o jogoAcabou dentro de jogo)
 * @param j Jogo
 */
void verificaEstadoJogo(Jogo *j){
    int i=0;
    for(i;i<j->qtdJogadores;i++){
        Jogador* jogador = j->jogadores[i];
        if (obtemPosicaoJogador(jogador) == obtemPosicaoFimMapa(j->mapa)){
            j->jogadorVencedor = i;
            j->jogoAcabou = 1;
            break;
        }
    }
}

/**
 * @brief Imprime os jogadores que estão em certa posição
 * @param j Jogo
 * @param posicao Posição que se deseja imprimir
 */
void imprimeJogadoresPosicao(Jogo *j, int posicao){
    int i=0, encontrou=0;
    for(i;i<j->qtdJogadores;i++){
        Jogador* jogador = j->jogadores[i];

        if (obtemPosicaoJogador(jogador) == posicao){
            if (encontrou){
                printf(", ");
            } else {
                printf(" <- ");
                encontrou = 1;
            }

            printf("%s", obtemNomeJogador(jogador));
        }
    }
    printf("\n");
}


/**
 * @brief Imprime o estado do jogo
 * 
 * FORMA DE SAÍDA:
 * =========== ESTADO ============
   [INICIO]
   [1] OURO 10
   [2] MONSTRO GOBLIN (F:3 XP:10) <- CARLA
   [3] AVANCA 2
   [4] VAZIA <- ANA
   [5] ITEM ESPADA (P:10 F:+2) <- BRUNO
   [6] MONSTRO ORC (F:6 XP:25)
   [7] VOLTA 3
   [8] OURO 20
   [9] VAZIA
   [10] MONSTRO DRAGAO (F:9 XP:50)
   [11] OURO 5
   [12] VAZIA
   [FIM]
   -------------------------------
   - ANA: casa 4 | forca 5 | xp 0 | ouro 10
   - BRUNO: casa 5 | forca 5 | xp 0 | ouro 0
   - CARLA: casa 2 | forca 4 | xp 10 | ouro 0
   - Situacao: EM ANDAMENTO
   ===============================

 * 
 * @param j Jogo
 */
void imprimeEstadoJogo(Jogo *j){
    printf("=========== ESTADO ============\n");
    printf("[INICIO]");
    imprimeJogadoresPosicao(j, 0);
    imprimeCelulasMapa(j->mapa);
    printf("[FIM]");
    imprimeJogadoresPosicao(j, obtemPosicaoFimMapa(j->mapa));
    printf("-------------------------------\n");
    int i=0;
    for(i;i<j->qtdJogadores;i++){
        printEstadoJogador((void*)j->jogadores[i]);
    }
    if (j->jogoAcabou == 0){
        printf("- Situacao: EM ANDAMENTO\n");
    } else {
        printf("- Situacao: VENCEDOR %s\n", obtemNomeJogador(j->jogadores[j->jogadorVencedor]));
    }
    printf("===============================\n");
}

/**
 * @brief Imprime o ranking do jogo
 * FORMATO DE SAÍDA:
 * =========== RANKING ===========
1. CARLA (AMARELO) | casa 13 | forca 4 | xp 10
2. BRUNO (VERDE) | casa 12 | forca 5 | xp 0
3. ANA (VERMELHO) | casa 9 | forca 5 | xp 0
===============================
 * @param j Jogo
 */
void imprimeRankingJogo(Jogo *j){
    Jogador** jogadoresRanking = malloc(j->qtdJogadores*sizeof(Jogador*));
    int i=0;
    for(i;i<j->qtdJogadores;i++){
        jogadoresRanking[i] = copiaJogador(j->jogadores[i]);
    }

    qsort(jogadoresRanking, j->qtdJogadores, sizeof(Jogador*), comparaOrdJogador);

    printf("=========== RANKING ===========\n");
    i=0;
    for(i;i<j->qtdJogadores;i++){
        printRankingJogador(jogadoresRanking[i], i+1);
    }
    printf("===============================\n");
    

    i=0;
    for(i;i<j->qtdJogadores;i++){
        desalocaJogador(jogadoresRanking[i]);
    }
    free(jogadoresRanking);
}


/**
 * @brief Imprime o relatorio do jogo
 * 
 *  FORMATO DE SAÍDA:
 * ========= RELATORIO ===========
- Celulas do mapa: 12
- Jogadores: 3
- Jogadas totais: 12
- Disputas: 3
- Monstros derrotados: 1
- Situacao: VENCEDOR CARLA
-------------------------------
- ANA: jogadas 4 | disputas vencidas 1 | forca 5 | xp 0 | ouro 10
- BRUNO: jogadas 4 | disputas vencidas 2 | forca 5 | xp 0 | ouro 20
- CARLA: jogadas 4 | disputas vencidas 0 | forca 4 | xp 10 | ouro 0
===============================


 * 
 * @param j Jogo
 */
void imprimeRelatorioJogo(Jogo *j){
    int jogadasTotais=0, disputasTotais=0, monstrosDerrotadosTotais=0;
    printf("========= RELATORIO ===========\n");
    printf("- Celulas do mapa: %d\n", obtemQtdCelulasMapa(j->mapa));
    printf("- Jogadores: %d\n", j->qtdJogadores);
    int i=0;
    for(i;i<j->qtdJogadores;i++){
        Jogador* jogador = j->jogadores[i];
        jogadasTotais += obtemJogadasJogador(jogador);
        disputasTotais += obtemDisputasVencidasJogador(jogador);
        monstrosDerrotadosTotais += obtemMonstrosDerrotadosJogador(jogador);
    }
    printf("- Jogadas totais: %d\n", jogadasTotais);
    printf("- Disputas: %d\n", disputasTotais);
    printf("- Monstros derrotados: %d\n", monstrosDerrotadosTotais);
    if (j->jogoAcabou == 0){
        printf("- Situacao: EM ANDAMENTO\n");
    } else {
        printf("- Situacao: VENCEDOR %s\n", obtemNomeJogador(j->jogadores[j->jogadorVencedor]));
    }
    printf("-------------------------------\n");
    i=0;
    for(i;i<j->qtdJogadores;i++){
        Jogador* jogador = j->jogadores[i];
        printRelatorioJogador((void*)jogador);
    }
    printf("===============================\n");
}

/**
 * @brief Desaloca o mapa, o vetor de jogadores e o jogo
 * @param j Jogo
 */
void desalocaJogo(Jogo *j){
    desalocaMapa(j->mapa);
    int i=0;
    for(i;i<j->qtdJogadores;i++){
        Jogador* jogador = j->jogadores[i];
        desalocaJogador((void*)jogador);
    }
    free(j->jogadores);
    free(j);
}