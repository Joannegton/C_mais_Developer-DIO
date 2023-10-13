#include <stdio.h>

// Função para imprimir o tabuleiro
void imprimirTabuleiro(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

// Função para verificar se o jogo terminou (alguém venceu ou empate)
int verificarFimDoJogo(char tabuleiro[3][3]) {
    // Verificar linhas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            return 1;
        }
    }

    // Verificar colunas
    for (int j = 0; j < 3; j++) {
        if (tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j] && tabuleiro[0][j] != ' ') {
            return 1;
        }
    }

    // Verificar diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
        return 1;
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
        return 1;
    }

    // Verificar empate
    int empate = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                empate = 0;
                break;
            }
        }
    }
    if (empate) {
        return 2;
    }

    return 0;
}

int main() {
    char tabuleiro[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int jogador = 1; // Inicia com o jogador 1
    int linha, coluna;
    int fimDoJogo = 0;

    printf("Jogo da Velha\n");

    while (!fimDoJogo) {
        imprimirTabuleiro(tabuleiro);

        printf("Jogador %d (Digite a linha e coluna): ", jogador);
        scanf("%d %d", &linha, &coluna);

        if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == ' ') {
            tabuleiro[linha][coluna] = (jogador == 1) ? 'X' : 'O';
            jogador = (jogador == 1) ? 2 : 1;
            fimDoJogo = verificarFimDoJogo(tabuleiro);
        } else {
            printf("Jogada inválida. Tente novamente.\n");
        }
    }

    imprimirTabuleiro(tabuleiro);

    if (fimDoJogo == 1) {
        printf("Jogador %d venceu!\n", (jogador == 1) ? 2 : 1);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
