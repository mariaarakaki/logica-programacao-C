#include <stdio.h>
#include <stdbool.h>

bool ehPar (int n) {
    return (n % 2 == 0);
}

int main () {
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);
    if (ehPar (numero))
        printf("%d é par.\n", numero);
    else
        printf("%d é impar.\n", numero);
    return 0;
}
