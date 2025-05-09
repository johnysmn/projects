#include <stdio.h>
#include <cs50.h>
//Programa para contar quantos passos é necessário para um número chegar até 1;
int collatz(int n);

int main (void)
{
    int n = get_int("Choose a number: ");
    printf("Number of steps: %i\n", collatz(n));
}

int collatz(int n)
{
    if (n == 1)
        return 0;
    else if ((n % 2) == 0)
        return 1 + collatz(n/2);
    else
        return 1 + collatz(3*n + 1);
}
