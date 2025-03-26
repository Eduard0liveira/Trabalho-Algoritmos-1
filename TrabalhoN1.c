#include <stdio.h>
#include <stdlib.h>

// Função para calcular o MDC (Máximo Divisor Comum)
int mdc(int a, int b) {
    if (b == 0)
        return a;
    return mdc(b, a % b);
}

// Função para simplificar uma fração
void simplificar(int *numerador, int *denominador) {
    int divisor = mdc(*numerador, *denominador);
    *numerador = *numerador / divisor;
    *denominador = *denominador / divisor;
}

// Função para somar duas frações
void somarFractions(int n1, int d1, int n2, int d2, int *result_num, int *result_den) {
    *result_num = n1 * d2 + n2 * d1;
    *result_den = d1 * d2;
    simplificar(result_num, result_den);
}

// Função para subtrair duas frações
void subtrairFractions(int n1, int d1, int n2, int d2, int *result_num, int *result_den) {
    *result_num = n1 * d2 - n2 * d1;
    *result_den = d1 * d2;
    simplificar(result_num, result_den);
}

// Função para multiplicar duas frações
void multiplicarFractions(int n1, int d1, int n2, int d2, int *result_num, int *result_den) {
    *result_num = n1 * n2;
    *result_den = d1 * d2;
    simplificar(result_num, result_den);
}

// Função para dividir duas frações
void dividirFractions(int n1, int d1, int n2, int d2, int *result_num, int *result_den) {
    if (n2 == 0) {
        printf("Erro: Divisão por zero!\n");
        return;
    }
    *result_num = n1 * d2;
    *result_den = d1 * n2;
    simplificar(result_num, result_den);
}

// Função para exibir a fração
void exibirFração(int numerador, int denominador) {
    if (denominador == 1)
        printf("%d\n", numerador); // Exibe como número inteiro se o denominador for 1
    else
        printf("%d/%d\n", numerador, denominador); // Exibe como fração
}

int main() {
    int num1, den1, num2, den2;
    int resultado_num, resultado_den;
    int opcao;

    printf("Calculadora de Frações\n");

    // Entrada das frações
    printf("Digite o numerador e o denominador da primeira fração: ");
    scanf("%d %d", &num1, &den1);
    printf("Digite o numerador e o denominador da segunda fração: ");
    scanf("%d %d", &num2, &den2);

    // Menu de operações
    printf("\nEscolha a operação que deseja realizar:\n");
    printf("1 - Soma\n2 - Subtração\n3 - Multiplicação\n4 - Divisão\n");
    printf("Digite a opção (1/2/3/4): ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            somarFractions(num1, den1, num2, den2, &resultado_num, &resultado_den);
            printf("Resultado da soma: ");
            exibirFração(resultado_num, resultado_den);
            break;
        case 2:
            subtrairFractions(num1, den1, num2, den2, &resultado_num, &resultado_den);
            printf("Resultado da subtração: ");
            exibirFração(resultado_num, resultado_den);
            break;
        case 3:
            multiplicarFractions(num1, den1, num2, den2, &resultado_num, &resultado_den);
            printf("Resultado da multiplicação: ");
            exibirFração(resultado_num, resultado_den);
            break;
        case 4:
            dividirFractions(num1, den1, num2, den2, &resultado_num, &resultado_den);
            if (den2 != 0)
                printf("Resultado da divisão: ");
                exibirFração(resultado_num, resultado_den);
            break;
        default:
            printf("Opção inválida!\n");
    }

    return 0;
}
