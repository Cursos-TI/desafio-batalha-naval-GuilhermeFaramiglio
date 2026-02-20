#include <stdio.h>
#include <stdbool.h>

#define TAM 10      // Tamanho do tabuleiro 10x10
#define NAVIO 3    // Valor que representa o navio
#define AGUA 0     // Valor que representa a água

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("=== TABULEIRO BATALHA NAVAL ===\n");
    printf("Legenda: 0=Água, 3=Navio\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d  ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio no tabuleiro
bool posicionarNavio(int tabuleiro[TAM][TAM], int linhaInicial, int colunaInicial, int dirVertical, int dirHorizontal) {
    int tamanho = 3;

    // Verifica se o navio cabe nos limites e se não sobrepõe outro
    for (int i = 0; i < tamanho; i++) {
        int novaL = linhaInicial + (i * dirVertical);
        int novaC = colunaInicial + (i * dirHorizontal);

        // Verifica limites do tabuleiro (0 a 9)
        if (novaL < 0 || novaL >= TAM || novaC < 0 || novaC >= TAM) return false;

        // Verifica se já existe um navio (valor 3) naquela posição
        if (tabuleiro[novaL][novaC] == NAVIO) return false;
    }

    // Se validou tudo, agora preenche com 3
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linhaInicial + (i * dirVertical)][colunaInicial + (i * dirHorizontal)] = NAVIO;
    }

    return true;
}

int main() {
    // Inicializa o tabuleiro com 0 (água)
    int tabuleiro[TAM][TAM] = {0};

    // POSICIONAMENTO DOS NAVIOS
    posicionarNavio(tabuleiro, 1, 1, 0, 1);
    posicionarNavio(tabuleiro, 5, 8, 1, 0);
    posicionarNavio(tabuleiro, 2, 5, 1, 1);
    posicionarNavio(tabuleiro, 8, 2, -1, 1);

    // Exibe o resultado final
    exibirTabuleiro(tabuleiro);

    return 0;
}