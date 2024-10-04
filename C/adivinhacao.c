#include <stdio.h>

int main() {

    // imprime cabeçalho do jogo
    printf("===============================\n");
    printf("Bem vindo ao jogo de adivinhação\n");
    printf("===============================\n");

    int numero_secreto = 42;

    int chute;

    printf("Qual é o seu chute? ");
    scanf("%d", &chute);


    if (chute == numero_secreto) {
        printf("Parabéns, você acertou\n");
    }else{
        if (chute > numero_secreto) {
            printf("Seu chute é maior que o número secreto");
        }
        if (chute < numero_secreto) {
            printf("Seu chute foi menor que o número secreto");
        }
        printf("Você errou\n");
        printf("Tente de novo\n");
    }

}