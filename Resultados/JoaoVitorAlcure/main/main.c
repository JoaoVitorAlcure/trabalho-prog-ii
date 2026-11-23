#include "jogo.h"
#include <stdio.h>
#include <string.h>


int main(){
    Jogo* jogo = criaJogo();
    char comando[TAM_COMANDO];
    cadastraMapaJogo(jogo);
    scanf("%s\n", comando);
    while (strcmp(comando, "J") == 0){
        cadastraJogadoresJogo(jogo);
        scanf("%s\n", comando);
    }
    executaJogo(jogo, comando);    
    desalocaJogo(jogo);
    return 0;
}