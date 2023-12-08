#include <stdio.h>

#define LINHAS 61
#define COLUNAS 10

void somarColunasMatriz(int matriz[LINHAS][COLUNAS]) {
    for (int j = 0; j < COLUNAS; ++j) {
        int soma = 0;
        for (int i = 0; i < LINHAS - 1; ++i) {
            soma += matriz[i][j];
        }
        matriz[LINHAS - 1][j] = soma;
    }
}

void imprimirMatriz(int matriz[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; ++i) {
        for (int j = 0; j < COLUNAS; ++j) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz[LINHAS][COLUNAS];

    // Preencher a matriz com valores de exemplo (pode ser ajustado conforme necessário)
    for (int i = 0; i < LINHAS - 1; ++i) {
        for (int j = 0; j < COLUNAS; ++j) {
            matriz[i][j] = i + j;
        }
    }

    // Chamar o procedimento para somar as colunas
    somarColunasMatriz(matriz);

    // Imprimir a matriz original e a matriz alterada
    printf("Matriz Original:\n");
    imprimirMatriz(matriz);

    return 0;
}
