#include <stdio.h>

int main() {
    float saldo = 1000.00;
    int saque;
    int n100, n50, n20, n10, n5;
    int resto;
    int valor;
    
    printf("Digite o valor do seu saque: ");
    scanf("%d", &saque);
    
    
    //! impõe a condição do valor do saque ser múltiplo de 5 com resto 0.
    while (!(saque % 5 == 0 && saque <= saldo)) { 
        if (saque > saldo) { //* se o valor do saque for maior que o saldo, aparece uma mensagem de erro
            printf("O valor de saque ultrapassa o saldo atual.\n"); 
            printf("Digite um valor válido para o saque: ");
            scanf("%d", &saque);
        } else {
            printf("Valor de saque inválido, digite um valor múltiplo de 5.\n"); 
            printf("Digite um valor válido para o saque: ");
            scanf("%d", &saque);
        }
    }
    
    if (saque % 5 == 0 && saque <= saldo) {
        valor = saldo - saque;
        printf("Saque aprovado!\n");
        printf("Seu saldo atual e de: %d\n", valor); //* quando o valor do saque for menor que o saldo, dá como saque aprovado e atualiza o valor do saldo atual.
        
        n100 = saque / 100;
        resto = saque % 100;
        if (n100 >= 1) { //? enquanto o número dividido por 100 for maior ou igual a 1, ele vai continuar contando para calcular quantas notas de 100 tem.
            printf("%d ""nota(s) de 100\n", n100); //* printa a quantidade de notas de 100 que a pessoa sacou.
        }
        
        n50 = resto / 50;
        resto = resto % 50;
        
        if (n50 >= 1) {
            printf("%d ""nota(s) de 50\n", n50);
        }
        
        n20 = resto / 20;
        resto = resto % 20;
        
        if (n20 >= 1) {
            printf("%d ""nota(s) de 20\n", n20);
        }
        
        n10 = resto / 10;
        resto = resto % 10;
        
        if (n10 >= 1) {
            printf("%d ""nota(s) de 10\n", n10);
        }
        
        n5 = resto / 5;
        resto = resto % 5;
        
        if (n5 >= 1) {
            printf("%d ""nota(s) de 5\n", n5);
        }
        
    return 0;
}
}