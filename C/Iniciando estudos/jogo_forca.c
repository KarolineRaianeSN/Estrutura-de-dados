#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "forca.h"

char palavrasecreta[20];
char chutes[26];
int chutes_dados = 0;

void limpar_tela()
{
#ifdef _WIN32
    system("cls"); // Para Windows
#else
    system("clear"); // Para Linux ou macOS
#endif
}

void abertura()
{
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta()
{
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[chutes_dados] = chute;
    chutes_dados++;
}

/**
 * Verifica se o jogador já chutou uma letra.
 *
 * @param letra A letra que sera verificada.
 * @return 1 se o jogador ja chutou a letra, 0 caso contrário.
 */
int jachutou(char letra)
{
    int achou = 0;
    for (int j = 0; j < chutes_dados; j++)
    {
        if (chutes[j] == letra)
        {
            achou = 1;
            break;
        }
    }

    return achou;
}

/**
 * Desenha a palavra secreta com as letras ja chutadas ou nao.
 *
 * Para cada letra da palavra secreta, verifica se o jogador ja chutou
 * aquela letra. Se sim, imprime a letra. Se nao, imprime um underline.
 */
void desenhaforca()
{

    printf("Você já deu %d chutes\n", chutes_dados);

    for (int i = 0; i < strlen(palavrasecreta); i++)
    {

        if (jachutou(palavrasecreta[i]))
        {
            printf("%c ", palavrasecreta[i]);
        }
        else
        {
            printf("_ ");
        }
    }
    printf("\n");
}

void escolhepalavra()
{
    sprintf(palavrasecreta, "MELANCIA");
}

int enforcou() 
{
    int erros = 0;

    // Todos os chutes
    for(int i = 0; i < chutes_dados; i++) {

        int existe = 0;

        // Verifica letra por letra da palavra a existência do chute
        for(int j = 0; j < strlen(palavrasecreta); j++) {
            if(chutes[i] == palavrasecreta[j]) {

                existe = 1;
                break;
        }
    }
    if (!existe) erros++;
}

    return erros >= 5;
}

int ganhou()
{
    for (int i = 0; i < strlen(palavrasecreta); i++) {
        if (!jachutou(palavrasecreta[i])) {
            return 0;
        }
    }

    return 1;
}

int main()
{

    escolhepalavra();

    do
    {

        limpar_tela();
        abertura();
        desenhaforca();
        chuta();

    } while (!ganhou() && !enforcou());
}