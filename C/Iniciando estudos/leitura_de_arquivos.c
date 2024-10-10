#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "jogo_forca.c"

void escolhe_palavra()
{
    FILE *f;
    f = fopen("palavras.txt", "r");

    if (f == NULL)
    {
        printf("Banco de dados de palavas não disponível\n\n");
        exit(1); // Parâmetro 1 informa que o programa encerrou de maneira que ele não gostaria(erro);
    }
}

/**
 * Lê o arquivo de palavras e seleciona uma palavra aleatória
 */
int qtd_palavras()
{
    FILE *f;

    int qtd_palavras;
    fscanf(f, "%d", &qtd_palavras);

    srand(time(0));
    int randomico = rand() % qtd_palavras;

    for (int i = 0; i <= randomico; i++)
    {
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);

    return qtd_palavras;
}

void main()
{
    escolhe_palavra();

    char palavra[50];
    fscanf(f, "%s", palavra);

    printf("%s", palavra);

    return 0;
}