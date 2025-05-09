#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number[5];

    number[0] = 1;
    printf("%i\n", number[0]);

    for (int i = 1; i < 5; i++)
    {
        number[i] = number[i - 1] * 2;
        printf("%i\n", number[i]);
    }
}
