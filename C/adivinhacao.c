#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Limpa a tela do terminal.
 *
 * Chama o comando "cls" em sistemas Windows e "clear" em sistemas Linux ou macOS.
 */
void limpar_tela()
{
#ifdef _WIN32
    system("cls"); // Para Windows
#else
    system("clear"); // Para Linux ou macOS
#endif
}

/**
 * Exibe o menu principal do jogo para o uusuário com os níveis disponíveis.
 */
void menu()
{
    printf("===============================\n");
    printf("Bem vindo ao jogo de adivinhação\n");
    printf("===============================\n");
    printf("- Nível 1: 20 tentativas\n - Nível 2: 15 tentativas\n - Nível 3: 6 tentativas\n Escolha um nível: ");
}

/**
 * Lê do teclado o nível escolhido pelo usuário.
 *
 * O nível deve ser um inteiro entre 1 e 3, representando os níveis de dificuldade
 * do jogo. Caso o usuário digite um valor inválido, o programa não faz tratamento
 * de erro algum.
 *
 * @return O nível escolhido pelo usuário.
 */
int escolher_nivel()
{
    int nivel;
    scanf("%d", &nivel);
    return nivel;
}

/**
 * Gera um número secreto aleatório entre 0 e 99.
 *
 * @return O número secreto gerado.
 */
int gerar_numero_secreto()
{
    srand(time(0));
    int numero_secreto = rand() % 100;
    return numero_secreto;
}

/**
 * Função principal do jogo.
 *
 * Recebe como parâmetro o nível escolhido pelo usuário e o número secreto gerado.
 * O jogo consiste em uma série de tentativas para acertar o número secreto, e
 * a cada tentativa, o usuário recebe um feedback se o seu chute foi maior ou
 * menor que o número secreto. Caso o usuário erre todas as tentativas, o jogo
 * termina e o usuário perde.
 *
 * A pontuação do usuário é calculada com base na distância entre o seu chute e o
 * número secreto. Quanto mais distante o chute, mais pontos o usuário perde.
 *
 * @param nivel O nível escolhido pelo usuário.
 * @param numero_secreto O número secreto gerado.
 *
 * @return A pontuação do usuário.
 */
double jogar(int nivel, int numero_secreto)
{
    int total_tentativas;
    int chute;
    int acertou = 0;
    int tentativa;

    switch (nivel)
    {
    case 1:
        total_tentativas = 20;
        break;
    case 2:
        total_tentativas = 15;
        break;
    case 3:
        total_tentativas = 6;
        break;
    default:
        printf("Nível inválido! Definindo para nível 1.\n");
        total_tentativas = 20;
        break;
    }

    double pontos = 1000;

    for (tentativa = 1; tentativa <= total_tentativas; tentativa++) {
        limpar_tela();

        printf("Tentativa %d de %d\n", tentativa, total_tentativas);
        printf("Qual é o seu %do. chute? ", tentativa);
        scanf("%d", &chute);

        if (chute < 0)
        {
            printf("Você não pode chutar números negativos!\n");
            tentativa--; // Não conta a tentativa
            continue;
        }

        acertou = (chute == numero_secreto);
        int maior = (chute > numero_secreto);

        if (acertou)
        {
            printf("Parabéns, você acertou!\n");
            break;
        }
        else
        {
            if (maior)
            {
                printf("Seu chute foi maior que o número secreto.\n");
            }
            else
            {
                printf("Seu chute foi menor que o número secreto.\n");
            }
        }

        double pontos_perdidos = abs(chute - numero_secreto) / 2.0;
        pontos -= pontos_perdidos;
    }

    if (!acertou)
    {
        printf("Você perdeu! Tente novamente!\n");
    }

    limpar_tela();
    printf("Fim de jogo!\n");
    printf("Você fez %.2f pontos\n", pontos);
    printf("O número secreto era: %d\n", numero_secreto);

    return pontos;
}

int main()
{
    limpar_tela();
    menu();

    int nivel_selecionado = escolher_nivel();
    int segredo = gerar_numero_secreto();

    double pontos = jogar(nivel_selecionado, segredo);

    return 0;
}