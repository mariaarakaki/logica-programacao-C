#include <stdio.h>
#include <string.h>

#define TAM_ALFABETO 62 //! Definindo o tamanho máximo do alfabeto
#define MAX_PALAVRA 100 //! Definindo o tamanho máximo da palavra

//* Alfabeto completo
char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"; 

//* Os 62 primeiros numeros primos 
int primos[TAM_ALFABETO] = {
  2,   3,   5,   7,   11,  13,  17,  19,  23,  29,
  31,  37,  41,  43,  47,  53,  59,  61,  67,  71,
  73,  79,  83,  89,  97,  101, 103, 107, 109, 113,
  127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
  179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
  233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
  283, 293
};

//* Vai passar pelo alfabeto, e procurar a letra que o usuário colocou (shift)
int indice_no_alfabeto(char c) { //! O "char c" irá dizer a letra que o usuário quer procurar
  for (int k = 0; k < 62; k++) {
    if (alfabeto[k] == c) {
      return k;
    }
  }
  return -1; //? O "return -1" seria ele passar por todo oalfabeto retornar falando "não encontrei"
}

//* Garante que o valor fique entre 0 e 61 (funciona com negativos também)
int normaliza(int valor) {
  return ((valor % TAM_ALFABETO) + TAM_ALFABETO) % TAM_ALFABETO;
}

  //* Sequência de auxiliares (PG, Fibonacci, etc)
  int termo_pg(int n, int a1, int razao) {
  int termo = normaliza(a1);
  for (int k = 0; k < n; k++) {
    termo = normaliza(termo * razao);
  }
  return termo;
}

//* Sequência Fibonacci  
//* Devolve o shift da letra na posição i: 1, 1, 2, 3, 5, 8, 13, 21... 
//* “% TAM_ALFABETO" evita estourar 
//*  o long long em palavras longas. O resultado final da cifra continua sendo o mesmo. 
int termo_fibonacci(int i) { 
  long long shift_anterior = 0; 
  long long shift_atual = 1; 

  for (int k = 0; k <= i; k++) { 
    long long resultado = (shift_anterior + shift_atual) % TAM_ALFABETO; 
    shift_anterior = shift_atual; shift_atual = resultado; 
  } 
  return (int)(shift_anterior % TAM_ALFABETO); 
} 

//* Incremento em progressão  
//* Devolve o incremento da letra na posição i: começa em 1 e aumenta 2 a cada letra (1, 3, 5, 7, 9...) 
//* No código havia "% 26" (alfabeto de 26 letras); aqui o "normaliza" da aplica_cifra já cuida do alfabeto de 62 caracteres. 
int termo_incremento(int i) { 
  int a1 = 1;      //! primeiro termo 
  int razao = 2;   //! quanto o incremento aumenta a cada letra return 
  a1 + i * razao; 
} 

//* Cifras que são baseadas no shift (PA, PG, Fibonacci...)
int calcula_shift(int tipo, int i, int shift_inicial, int razao) {
  switch (tipo) {
    case 1: return shift_inicial;                       //! Cesar (sempre terá)
    case 2: return shift_inicial + i * razao;           //! PA
    case 3: return termo_pg(i, shift_inicial, razao);   //! PG
    case 5: return shift_inicial + termo_fibonacci(i);  //!Fibonacci 
    case 6: return shift_inicial + termo_incremento(i); //!Incremento em progressão 
    default: return 0;
  }
}

//* Declarando sentido para cifrar
void aplica_cifra(char *palavra, char *resultado, int tipo, int shift_inicial, int razao) {
  int i;

  for (i = 0; palavra[i] != '\0'; i++) {
    int idx = indice_no_alfabeto(palavra[i]);

    if (idx != -1) {
      int shift = calcula_shift(tipo, i, shift_inicial, razao);
      resultado[i] = alfabeto[normaliza(idx + shift)];
    } else {
      resultado[i] = palavra[i];
    }
  }

  resultado[i] = '\0';
}

//* Para cifrar em primos
void cifra_primos(const char *entrada, char *saida) {
  int tam = strlen(entrada);

  for (int i = 0; i < tam; i++) {
    int idx = indice_no_alfabeto(entrada[i]);

    if (idx != -1) {
      saida[i] = alfabeto[primos[idx] % TAM_ALFABETO];
    } else {
      saida[i] = entrada[i];
    }
  }
  saida[tam] = '\0';
}

int main() {

  char palavra[MAX_PALAVRA];
  char resultado[MAX_PALAVRA];
  int tipo, shift_inicial = 0, razao = 0;

  printf("Digite a palavra: "); //! Para o usuário inserir a palavra que irá ser cifrada
  fgets(palavra, MAX_PALAVRA, stdin);
  palavra[strcspn(palavra, "\n")] = '\0';

  //* Para o usuário escolher qual cifra ela quer usar
  printf("\nEscolha a cifra:\n");
  printf("1 - Cesar (shift fixo)\n");
  printf("2 - PA\n");
  printf("3 - PG\n");
  printf("4 - Numeros primos\n");
  printf("5 - Fibonacci\n");
  printf("6 - Incremento em progressão\n"); 
  printf("Opcao: ");
  if (scanf("%d", &tipo) != 1 || tipo < 1 || tipo > 6) {
    printf("Opcao invalida.\n");
    return 1;
  }

  if (tipo == 7) {
    //*Somente para Primos (sem shift e sem razão)
    cifra_primos(palavra, resultado);

    printf("\nEntrada:   %s\n", palavra);
    printf("Resultado: %s\n", resultado);

    printf("Primos usados: ");
    for (int i = 0; palavra[i] != '\0'; i++) {
      int idx = indice_no_alfabeto(palavra[i]);
      if (idx != -1) printf("%d ", primos[idx]);
    }
    printf("\n");
    return 0;
  }

  printf("Digite o shift inicial: ");
  if (scanf("%d", &shift_inicial) != 1) {
    printf("Valor invalido.\n");
    return 1;
  }

  if (tipo == 2 || tipo == 3) {
    printf("Digite a razao: ");
    if (scanf("%d", &razao) != 1) {
      printf("Valor invalido.\n");
      return 1;
    }
  }

  aplica_cifra(palavra, resultado, tipo, shift_inicial, razao);

  printf("\nEntrada:   %s\n", palavra);
  printf("Resultado: %s\n", resultado);

  return 0;
}
