#include <stdio.h>
#include <cs50.h>

int N = 3;

float average(int lenght, int array[]);

int main(void)
{
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }
    printf("Average: %.2f\n", average(N, scores));
}

float average(int lenght, int array[])
{
    int sum = 0;
    for (int i = 0, l = lenght; i < l; i++)
    {
        sum += array[i];
    }
    return sum / (float) lenght;
}
