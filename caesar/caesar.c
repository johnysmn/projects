#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);

char rotate(char c, int n);

int main(int argc, string argv[])
{
   if (argc != 2)
   {
      printf("Usage: ./caesar key\n");
      return 1;
   }
   if (!only_digits(argv[1]))
   {
      printf("Usage: ./caesar key\n");
      return 1;
   }
   int num_argv = atoi(argv[1]);
   string text_argv = get_string("plaintext: ");
   for (int i = 0, len = strlen(text_argv); i < len; i++)
   {
      text_argv[i] = rotate(text_argv[i], num_argv);
   }
   printf("ciphertext: %s\n", text_argv);
}

bool only_digits(string s)
{
   int length = strlen(s);

   for (int i = 0; i < length; i++)
   {
      if (!isdigit(s[i]))
      {
         return false;
      }
   }
   return true;
}

char rotate(char c, int n)
{
    if (isupper(c))
    {
        return 'A' + (c - 'A' + n) % 26;
    }
    if (islower(c))
    {
        return 'a' + (c - 'a' + n) % 26;
    }
    return c;
}
