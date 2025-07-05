#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para verificar se há sobreposição nas posições
int verificarSobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int posicoes[3][2]) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linha = posicoes[i][0];
        int coluna = posicoes[i][1];
        if (tabuleiro[linha][coluna] != 0) {
            return 1; // Há sobreposição
        }
    }
    return 0;
}

// Função para posicionar o navio
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int posicoes[3][2]) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linha = posicoes[i][0];
        int coluna = posicoes[i][1];
        tabuleiro[linha][coluna] = 3;
        printf("(%d, %d)\n", linha, coluna);
    }
}


int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // ----- Navio 1: Horizontal -----
    int navio1[3][2] = {
        {2, 2}, {2, 3}, {2, 4}
    };

    // ----- Navio 2: Vertical -----
    int navio2[3][2] = {
        {5, 5}, {6, 5}, {7, 5}
    };

    // ----- Navio 3: Diagonal Principal ↘ -----
    int navio3[3][2] = {
        {4, 0}, {5, 1}, {6, 2}
    };

    // ----- Navio 4: Diagonal Secundária ↙ -----
    int navio4[3][2] = {
        {0, 9}, {1, 8}, {2, 7}
    };

    // Verificar e posicionar cada navio
    if (verificarSobreposicao(tabuleiro, navio1)) {
        printf("Erro: Sobreposição no navio 1 (horizontal).\n");
        return 1;
    }
    printf("Navio 1 (horizontal) nas coordenadas:\n");
    posicionarNavio(tabuleiro, navio1);

    if (verificarSobreposicao(tabuleiro, navio2)) {
        printf("Erro: Sobreposição no navio 2 (vertical).\n");
        return 1;
    }
    printf("Navio 2 (vertical) nas coordenadas:\n");
    posicionarNavio(tabuleiro, navio2);

    if (verificarSobreposicao(tabuleiro, navio3)) {
        printf("Erro: Sobreposição no navio 3 (diagonal ↘).\n");
        return 1;
    }
    printf("Navio 3 (diagonal ↘) nas coordenadas:\n");
    posicionarNavio(tabuleiro, navio3);

    if (verificarSobreposicao(tabuleiro, navio4)) {
        printf("Erro: Sobreposição no navio 4 (diagonal ↙).\n");
        return 1;
    }
    printf("Navio 4 (diagonal ↙) nas coordenadas:\n");
    posicionarNavio(tabuleiro, navio4);

    // Exibir o tabuleiro final
    printf("\nTabuleiro Final:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}