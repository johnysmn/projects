#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main()
{
    string name[] = {"Johny","Camila","James"};
    string s = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(name[i],s) == 0)
        {
            printf("Done!\n");
            return 0;
        }
    }
    printf("Wrong!\n");
    return 1;
}
