#include <stdio.h>

int main() {

    // imprime cabeçalho do jogo
    printf("===============================\n");
    printf("Bem vindo ao jogo de adivinhação\n");
    printf("===============================\n");

    int numero_secreto = 42;

    int chute;

    for (int i = 1; i <=3; i++) {
        printf("Tentativa %d de 3\n", i);
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);

        int acertou = (chute == numero_secreto);

        if (acertou) {
            printf("Parabéns, você acertou\n");
            break;
        }else{
            int maior = chute > numero_secreto;
            int menor = chute < numero_secreto;

            if (maior) {
                printf("Seu chute é maior que o número secreto\n");
            } else {
                printf("Seu chute foi menor que o número secreto\n");
            }
        }
    }
    printf("Fim de jogo\n");
}

