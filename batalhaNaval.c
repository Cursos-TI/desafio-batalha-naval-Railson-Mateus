#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5
#define ALTURA_HABILIDADE 3
#define LARGURA_HABILIDADE 5
#define VAL_NAVIO 3
#define VAL_AGUA 0
#define VAL_HABILIDADE 5

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VAL_AGUA;
        }
    }
}

// Função para imprimir o tabuleiro com legenda
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n=== TABULEIRO ===\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio com 3 coordenadas
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int navio[3][2]) {
    for (int i = 0; i < 3; i++) {
        int linha = navio[i][0];
        int coluna = navio[i][1];

        if (tabuleiro[linha][coluna] != VAL_HABILIDADE) {
            tabuleiro[linha][coluna] = VAL_NAVIO;
        }
    }
}

// Função para aplicar matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[ALTURA_HABILIDADE][LARGURA_HABILIDADE], int origemLinha, int origemColuna) {
    int offsetLinha = ALTURA_HABILIDADE / 2;
    int offsetColuna = LARGURA_HABILIDADE / 2;

    for (int i = 0; i < ALTURA_HABILIDADE; i++) {
        for (int j = 0; j < LARGURA_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int linha = origemLinha + (i - offsetLinha);
                int coluna = origemColuna + (j - offsetColuna);

                if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
                    if (tabuleiro[linha][coluna] != VAL_NAVIO) {
                        tabuleiro[linha][coluna] = VAL_HABILIDADE;
                    }
                }
            }
        }
    }
}


// Função para construir uma matriz de habilidade em cone (⬇)
void construirCone(int cone[ALTURA_HABILIDADE][LARGURA_HABILIDADE]) {
    int meio = LARGURA_HABILIDADE / 2;
    for (int i = 0; i < ALTURA_HABILIDADE; i++) {
        for (int j = 0; j < LARGURA_HABILIDADE; j++) {
            cone[i][j] = (j >= meio - i && j <= meio + i) ? 1 : 0;
        }
    }
}

// Função para construir uma matriz de habilidade em cruz (+)
void construirCruz(int cruz[ALTURA_HABILIDADE][LARGURA_HABILIDADE]) {
    int centroX = ALTURA_HABILIDADE / 2;
    int centroY = LARGURA_HABILIDADE / 2;

    for (int i = 0; i < ALTURA_HABILIDADE; i++) {
        for (int j = 0; j < LARGURA_HABILIDADE; j++) {
            cruz[i][j] = (i == centroX || j == centroY) ? 1 : 0;
        }
    }
}

// Função para construir uma matriz de habilidade em octaedro (losango)
void construirOctaedro(int octaedro[ALTURA_HABILIDADE][LARGURA_HABILIDADE]) {
    int centroX = ALTURA_HABILIDADE / 2;
    int centroY = LARGURA_HABILIDADE / 2;

    for (int i = 0; i < ALTURA_HABILIDADE; i++) {
        for (int j = 0; j < LARGURA_HABILIDADE; j++) {
            octaedro[i][j] = (abs(i - centroX) + abs(j - centroY) <= 1) ? 1 : 0;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // NAVIOS
    int navio1[3][2] = { {2, 2}, {2, 3}, {2, 4} };         // Horizontal
    int navio2[3][2] = { {1, 5}, {2, 5}, {3, 5} };         // Vertical
    int navio3[3][2] = { {4, 0}, {5, 1}, {6, 2} };         // Diagonal ↘
    int navio4[3][2] = { {0, 9}, {1, 8}, {2, 7} };         // Diagonal ↙

    posicionarNavio(tabuleiro, navio1);
    posicionarNavio(tabuleiro, navio2);
    posicionarNavio(tabuleiro, navio3);
    posicionarNavio(tabuleiro, navio4);

    // MATRIZES DE HABILIDADES
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    // APLICAR HABILIDADES NO TABULEIRO
    aplicarHabilidade(tabuleiro, cone, 6, 6);        // Cone com origem em (6,6)
    aplicarHabilidade(tabuleiro, cruz, 4, 4);        // Cruz com origem em (4,4)
    aplicarHabilidade(tabuleiro, octaedro, 1, 1);    // Octaedro com origem em (1,1)

    // IMPRIMIR RESULTADO FINAL
    imprimirTabuleiro(tabuleiro);

    return 0;
}