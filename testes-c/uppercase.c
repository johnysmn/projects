#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main()
{
    string s = get_string("Name: ");
    printf("Name: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper (s[i]));
    }
    printf("\n");
}
