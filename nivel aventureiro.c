#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

// Função para verificar se há sobreposição
int verificarSobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    return tabuleiro[linha][coluna] == VALOR_NAVIO;
}

int main() {
    // Declaração e inicialização do tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }

    // NAVIO 1 - Horizontal
    int linhaH = 1, colunaH = 2;
    if (colunaH + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (verificarSobreposicao(tabuleiro, linhaH, colunaH + i)) {
                printf("Erro: sobreposição detectada no navio horizontal.\n");
                return 1;
            }
            tabuleiro[linhaH][colunaH + i] = VALOR_NAVIO;
        }
    }

    // NAVIO 2 - Vertical
    int linhaV = 4, colunaV = 6;
    if (linhaV + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (verificarSobreposicao(tabuleiro, linhaV + i, colunaV)) {
                printf("Erro: sobreposição detectada no navio vertical.\n");
                return 1;
            }
            tabuleiro[linhaV + i][colunaV] = VALOR_NAVIO;
        }
    }

    // NAVIO 3 - Diagonal Principal (↘)
    int linhaD1 = 0, colunaD1 = 0;
    if (linhaD1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaD1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (verificarSobreposicao(tabuleiro, linhaD1 + i, colunaD1 + i)) {
                printf("Erro: sobreposição detectada no navio diagonal ↘.\n");
                return 1;
            }
            tabuleiro[linhaD1 + i][colunaD1 + i] = VALOR_NAVIO;
        }
    }

    // NAVIO 4 - Diagonal Secundária (↙)
    int linhaD2 = 2, colunaD2 = 7;
    if (linhaD2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaD2 - TAMANHO_NAVIO + 1 >= 0) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (verificarSobreposicao(tabuleiro, linhaD2 + i, colunaD2 - i)) {
                printf("Erro: sobreposição detectada no navio diagonal ↙.\n");
                return 1;
            }
            tabuleiro[linhaD2 + i][colunaD2 - i] = VALOR_NAVIO;
        }
    }

    // Exibição do tabuleiro
    printf("\nTabuleiro de Batalha Naval:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
