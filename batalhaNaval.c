#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // 1. Declarar e inicializar o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // 2. Coordenadas iniciais (pré-definidas) dos navios
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 7;

    // 3. Validar posições horizontais e verticais
    // Verifica se os navios estão dentro dos limites
    if (coluna_horizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO || linha_vertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Um dos navios sairia do tabuleiro.\n");
        return 1;
    }

    // 4. Verificar sobreposição
    int sobreposicao = 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha_horizontal][coluna_horizontal + i] != 0 ||
            tabuleiro[linha_vertical + i][coluna_vertical] != 0) {
            sobreposicao = 1;
            break;
        }
    }

    if (sobreposicao) {
        printf("Erro: Os navios se sobrepõem.\n");
        return 1;
    }

    // 5. Posicionar navio horizontal
    printf("Navio horizontal nas coordenadas:\n");
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
        printf("(%d, %d)\n", linha_horizontal, coluna_horizontal + i);
    }

    // 6. Posicionar navio vertical
    printf("Navio vertical nas coordenadas:\n");
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = 3;
        printf("(%d, %d)\n", linha_vertical + i, coluna_vertical);
    }

    // 7. Exibir o tabuleiro
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
