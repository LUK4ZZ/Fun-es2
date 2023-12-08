#include <stdio.h>
#include <time.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

int isBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int diasNoMes(int mes, int ano) {
    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mes == 2 && isBissexto(ano))
        return 29;
    else
        return diasNoMes[mes];
}

void calcularIdade(Data nascimento, Data hoje, int *anos, int *meses, int *dias) {
    if (hoje.dia < nascimento.dia) {
        hoje.mes -= 1;
        hoje.dia += diasNoMes(nascimento.mes, hoje.ano);
    }
    if (hoje.mes < nascimento.mes) {
        hoje.ano -= 1;
        hoje.mes += 12;
    }

    *anos = hoje.ano - nascimento.ano;
    *meses = hoje.mes - nascimento.mes;
    *dias = hoje.dia - nascimento.dia;
}

int main() {
    Data nascimento = {1, 1, 2000}; // Substitua pelos valores reais de nascimento
    Data hoje;
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    hoje.dia = tm_info->tm_mday;
    hoje.mes = tm_info->tm_mon + 1;
    hoje.ano = tm_info->tm_year + 1900;

    int anos, meses, dias;
    calcularIdade(nascimento, hoje, &anos, &meses, &dias);

    printf("Idade: %d anos, %d meses, %d dias\n", anos, meses, dias);

    return 0;
}
