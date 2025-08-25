#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

int main() {
    // Declaração da matriz do tabuleiro 10x10
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa todas as posições com água (valor 0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }

    // Coordenadas iniciais do navio horizontal
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    // Coordenadas iniciais do navio vertical
    int linhaVertical = 5;
    int colunaVertical = 7;

    // Validação simples: garantir que os navios estão dentro dos limites
    if (colunaHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        linhaVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {

        // Posiciona navio horizontal (linha fixa, coluna variável)
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = VALOR_NAVIO;
        }

        // Posiciona navio vertical (coluna fixa, linha variável)
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se há sobreposição
            if (tabuleiro[linhaVertical + i][colunaVertical] == VALOR_NAVIO) {
                printf("Erro: sobreposição de navios detectada!\n");
                return 1;
            }
            tabuleiro[linhaVertical + i][colunaVertical] = VALOR_NAVIO;
        }

        // Exibe o tabuleiro no console
        printf("Tabuleiro de Batalha Naval:\n\n");
        for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
            for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }

    } else {
        printf("Erro: coordenadas inválidas para posicionar os navios.\n");
    }

    return 0;
}
