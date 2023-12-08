#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 500

void calcularLocacoesGratuitas(const int vetorRetiradas[], int vetorLocacoes[], int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        vetorLocacoes[i] = vetorRetiradas[i] / 15;
    }
}

int main() {
    int vetorRetiradas[TAMANHO];
    int vetorLocacoes[TAMANHO];

    // Solicitar ao usuário inserir os dados
    for (int i = 0; i < TAMANHO; ++i) {
        printf("Digite a quantidade de filmes retirados pelo cliente %d: ", i + 1);
        scanf("%d", &vetorRetiradas[i]);
    }

    // Calcular a quantidade de locações gratuitas
    calcularLocacoesGratuitas(vetorRetiradas, vetorLocacoes, TAMANHO);

    // Exibir os resultados
    printf("\nResultados:\n");
    for (int i = 0; i < TAMANHO; ++i) {
        printf("Cliente %d: %d locações gratuitas\n", i + 1, vetorLocacoes[i]);
    }

    return 0;
}
