#include <stdio.h>
#include <cs50.h>

void draw(int n);

int main (void)
{
    int block = get_int("Blocks: ");
    draw(block);
}

void draw(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j= 0; j < n+1; j++)
        {
            printf("#");
        }
    printf("\n");

    }
}
