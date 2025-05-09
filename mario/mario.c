#include <stdio.h>
#include <cs50.h>


//O primeiro código complicado que eu fiz sozinho >:D
int h;
int i;
void print_row(int spaces, int bricks);
int main()
//Loop para obedecer os inputs de 1 a 8
{
    do
    {
        h = get_int("Height: ");
    }
    while (h > 15 || h < 1);

    for (i = 0; i < h; i++)
    {
        print_row(i, i);
    }
}
//Minha função que funciona como um cálculo de adição e subtração ao mesmo tempo
void print_row(int spaces, int bricks)
{
    int k;
    int j;
    for (j = h; j > i + 1; j--)
    {
        printf(" ");
    }
    for (k = 0; k < j; k++)
    {
        printf("#");
    }
    printf("\n");
}
