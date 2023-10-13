#include <stdio.h>
#include <stdlib.h>

double multiplicacao(double a, double b) {
    double resultado = a * b;
    return resultado;
}

double divisao(double a, double b) {
    if (b == 0) {
        printf("Não é possível dividir por zero.\n");
        return 0.0;
    }
    
    double resultado = a / b;
    return resultado;
}

double soma(double a, double b) {
    double resultado = a + b;
    return resultado;
}

double subtracao(double a, double b) {
    double resultado = a - b;
    return resultado;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Uso: %s <num1> <operacao> <num2>\n", argv[0]);
        return 1;
    }

    double num1 = atof(argv[1]);
    int operacao = atoi(argv[2]);
    double num2 = atof(argv[3]);

    double resultado;

    switch (operacao) {
        case 1:
            resultado = multiplicacao(num1, num2);
            break;
        case 2:
            resultado = divisao(num1, num2);
            break;
        case 3:
            resultado = soma(num1, num2);
            break;
        case 4:
            resultado = subtracao(num1, num2);
            break;
        default:
            printf("Opção inválida\n");
            return 1;
    }

    printf("Resultado: %.2f\n", resultado);

    return 0;
}
