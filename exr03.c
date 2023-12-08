#include <stdio.h>

// Tamanho da matriz
#define N 10

// Procedimento para realizar as trocas na matriz
void realizarTrocas(int matriz[N][N]) {
    // Trocar a linha 2 com a linha 8
    for (int i = 0; i < N; ++i) {
        int temp = matriz[1][i];
        matriz[1][i] = matriz[7][i];
        matriz[7][i] = temp;
    }

    // Trocar a coluna 4 com a coluna 10
    for (int i = 0; i < N; ++i) {
        int temp = matriz[i][3];
        matriz[i][3] = matriz[i][9];
        matriz[i][9] = temp;
    }

    // Trocar a diagonal principal com a secundária
    for (int i = 0; i < N; ++i) {
        int temp = matriz[i][i];
        matriz[i][i] = matriz[i][N - 1 - i];
        matriz[i][N - 1 - i] = temp;
    }

    // Trocar a linha 5 com a coluna 10
    for (int i = 0; i < N; ++i) {
        int temp = matriz[4][i];
        matriz[4][i] = matriz[i][9];
        matriz[i][9] = temp;
    }
}

// Função para exibir a matriz
void exibirMatriz(int matriz[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Criar e preencher uma matriz 10x10 com números fictícios (você pode substituir por seus próprios dados)
    int matriz[N][N];
    int contador = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matriz[i][j] = contador++;
        }
    }

    // Exibir a matriz original
    printf("Matriz Original:\n");
    exibirMatriz(matriz);

    // Chamar o procedimento para realizar as trocas
    realizarTrocas(matriz);

    // Exibir a matriz após as trocas
    printf("\nMatriz Após as Trocas:\n");
    exibirMatriz(matriz);

    return 0;
}
