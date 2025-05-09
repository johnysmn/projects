#include <stdint.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Por favor coloque 1 nome de arquivo.\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");

    uint8_t buffer[4];

    uint8_t signature[] = {0x25, 0x50, 0x44, 0x46};

    fread(buffer, sizeof(uint8_t), 4, input);

    for (int i = 0; i < 4; i++)
    {
        if (signature[i] != buffer[i])
        {
            printf("Não é um PDF!\n");
            return 0;
        }
    }

    printf("É um pdf!\n");

    fclose(input);
    return 0;
}
