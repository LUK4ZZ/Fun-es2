#include <stdio.h>

// Função para imprimir as opções, solicitar a opção desejada e retornar a opção escolhida
char menuPagamento() {
    char opcao;

    printf("Escolha a opcao de pagamento:\n");
    printf("a) A vista com 10%% de desconto\n");
    printf("b) Em duas vezes (preco da etiqueta)\n");
    printf("c) De 3 ate 10 vezes com 3%% de juros ao mes (somente para compras acima de R$ 100,00)\n");

    printf("Digite a opcao desejada: ");
    scanf(" %c", &opcao);  // Espaço antes de %c para consumir a quebra de linha pendente

    return opcao;
}

// Função para calcular e imprimir o valor total das prestações com desconto
void opcaoA(double total) {
    double desconto = total * 0.10;
    double totalComDesconto = total - desconto;

    printf("Opcao escolhida: A vista com 10%% de desconto\n");
    printf("Valor total com desconto: R$ %.2lf\n", totalComDesconto);
}

// Função para calcular e imprimir o valor total das prestações em duas vezes
void opcaoB(double total) {
    printf("Opcao escolhida: Em duas vezes (preco da etiqueta)\n");
    printf("Valor total em duas vezes: 2x R$ %.2lf\n", total / 2);
}

// Função para calcular e imprimir o valor total das prestações com juros
void opcaoC(double total) {
    if (total > 100.00) {
        printf("Opcao escolhida: De 3 ate 10 vezes com 3%% de juros ao mes\n");
        printf("Digite o numero de prestacoes (entre 3 e 10): ");

        int numPrestacoes;
        scanf("%d", &numPrestacoes);

        if (numPrestacoes >= 3 && numPrestacoes <= 10) {
            double juros = total * 0.03;
            double totalComJuros = total + juros;
            double valorParcela = totalComJuros / numPrestacoes;

            printf("Valor total com juros: R$ %.2lf\n", totalComJuros);
            printf("Valor de cada prestacao: %.2lf\n", valorParcela);
        } else {
            printf("Numero de prestacoes invalido.\n");
        }
    } else {
        printf("Opcao indisponivel para compras abaixo de R$ 100.00.\n");
    }
}

int main() {
    double total;

    printf("Digite o total gasto pelo cliente: R$ ");
    scanf("%lf", &total);

    char opcao = menuPagamento();

    switch (opcao) {
        case 'a':
            opcaoA(total);
            break;
        case 'b':
            opcaoB(total);
            break;
        case 'c':
            opcaoC(total);
            break;
        default:
            printf("Opcao invalida.\n");
    }

    return 0;
}
