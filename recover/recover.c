#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define CARD_RAW 512

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: ./recover FILE\n");
    return 1;
  }

  FILE *card = fopen(argv[1], "r");

  if (card == NULL)
  {
    printf("This file was not opened properly.\n");
    return 1;
  }

  uint8_t buffer[CARD_RAW];
  int imgfound = 0;
  FILE *img = NULL;

  while (fread(buffer, 1, CARD_RAW, card) == CARD_RAW)
  {
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
      if (img != NULL)
      {
        fclose(img);
      }

      char *filename = malloc(8);
      sprintf(filename, "%03i.jpg", imgfound++);
      img = fopen(filename, "w");

      if (img == NULL)
      {
        printf("This file was not opened properly: %s\n", filename);
        free(filename);
        return 1;
      }

      free(filename);
    }

    if (img != NULL)
    {
      fwrite(buffer, 1, CARD_RAW, img);
    }
  }

  if (img != NULL)
  {
    fclose(img);
  }

  fclose(card);
}
