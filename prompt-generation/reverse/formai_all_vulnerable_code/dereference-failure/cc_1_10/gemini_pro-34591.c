//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A verily cunning function that converts a humble string of characters representing a hexadecimal number into its integer equivalent.
int HexToInteger(char *hex)
{
  int i = 0, j = 0, len = strlen(hex), value = 0;
  char digit;

  while (i < len)
  {
    digit = hex[i++];
    if (digit >= '0' && digit <= '9')
    {
      value = value * 16 + (digit - '0');
    }
    else if (digit >= 'A' && digit <= 'F')
    {
      value = value * 16 + (digit - 'A' + 10);
    }
    else if (digit >= 'a' && digit <= 'f')
    {
      value = value * 16 + (digit - 'a' + 10);
    }
    else
    {
      printf("Invalid hexadecimal digit: %c\n", digit);
      return -1;
    }
  }

  return value;
}

int main(int argc, char *argv[])
{
  // Behold, the valiant command-line arguments!
  if (argc < 2)
  {
    printf("Usage: %s <hexadecimal number>\n", argv[0]);
    return 1;
  }

  // A string of characters, as enchanting as a minstrel's song.
  char *hex = argv[1];

  // The integer equivalent of the hexadecimal number, a treasure of knowledge.
  int value = HexToInteger(hex);

  if (value >= 0)
  {
    printf("Lo! The integer equivalent of '%s' is: %d\n", hex, value);
  }
  else
  {
    printf("Alas! An error befell the conversion of '%s'.\n", hex);
  }

  return 0;
}