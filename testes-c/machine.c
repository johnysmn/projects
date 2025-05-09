#include<stdio.h>
#include<cs50.h>

int main(void)
{
    printf("Calculadora de subtração\n");
    int x = get_int("Digite o primeiro valor: ");
    int y = get_int("Digite o segundo valor: ");

    printf("O resultado será: %i\n",x - y);
}
