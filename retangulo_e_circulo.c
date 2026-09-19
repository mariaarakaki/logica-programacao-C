#include <stdio.h>
#define PI 3.14159

float areaRetangulo (float base, float altura) {
    return base * altura;
}

float areaCirculo (float raio) {
    return PI * raio * raio;
}

int main () {
    float base, altura;
    float raio;
     //! a variável "base", "altura" e "raio" não foram declaradas dentro da main, logo ela não consegue encontra-las.
     //* para resolver, só repetir o "float exemplo, exemplo"

    printf("Digite a base do retangulo: ");
    scanf("%f", &base);
    printf("Digite a altura do retangulo: ");
    scanf("%f", &altura);
    printf("Area do retangulo = %.2f\n", areaRetangulo (base, altura));

    printf("Digite o raio do circulo: ");
    scanf("%f", &raio);
    printf("Area do circulo = %.2f\n", areaCirculo (raio));
    return 0;
}
