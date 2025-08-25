#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5
#define VALOR_AGUA 0
#define VALOR_NAVIO 3
#define VALOR_HABILIDADE 5

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar navios fixos
void posicionarNavios(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Navio horizontal
    for (int i = 0; i < 3; i++) {
        tabuleiro[2][3 + i] = VALOR_NAVIO;
    }

    // Navio vertical
    for (int i = 0; i < 3; i++) {
        tabuleiro[5 + i][6] = VALOR_NAVIO;
    }
}

// Função para construir matriz de habilidade Cone (forma triangular)
void construirCone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= TAMANHO_HABILIDADE / 2 - i && j <= TAMANHO_HABILIDADE / 2 + i) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para construir matriz de habilidade Cruz
void construirCruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == TAMANHO_HABILIDADE / 2 || j == TAMANHO_HABILIDADE / 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para construir matriz de habilidade Octaedro (losango)
void construirOctaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - TAMANHO_HABILIDADE / 2) + abs(j - TAMANHO_HABILIDADE / 2) <= TAMANHO_HABILIDADE / 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para aplicar matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                       int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                       int origemLinha, int origemColuna) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTab = origemLinha - TAMANHO_HABILIDADE / 2 + i;
            int colunaTab = origemColuna - TAMANHO_HABILIDADE / 2 + j;

            // Verifica se está dentro dos limites
            if (linhaTab >= 0 && linhaTab < TAMANHO_TABULEIRO &&
                colunaTab >= 0 && colunaTab < TAMANHO_TABULEIRO) {
                if (habilidade[i][j] == 1 && tabuleiro[linhaTab][colunaTab] != VALOR_NAVIO) {
                    tabuleiro[linhaTab][colunaTab] = VALOR_HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // Inicializa tabuleiro e posiciona navios
    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    // Constrói matrizes de habilidade
    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    // Aplica habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 1, 2);       // Cone com origem no topo
    aplicarHabilidade(tabuleiro, cruz, 5, 5);       // Cruz com origem no centro
    aplicarHabilidade(tabuleiro, octaedro, 7, 2);   // Octaedro com origem mais abaixo

    // Exibe tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
