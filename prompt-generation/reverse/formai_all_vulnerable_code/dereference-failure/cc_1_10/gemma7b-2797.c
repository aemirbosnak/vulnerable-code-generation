//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 16

typedef struct HexConverter {
  int numDigits;
  char **digits;
  char **hexdigits;
} HexConverter;

HexConverter *createHexConverter(int numDigits)
{
  HexConverter *converter = malloc(sizeof(HexConverter));
  converter->numDigits = numDigits;
  converter->digits = malloc(numDigits * sizeof(char *));
  converter->hexdigits = malloc(numDigits * sizeof(char *));

  for (int i = 0; i < numDigits; i++)
  {
    converter->digits[i] = malloc(MAX_DIGITS * sizeof(char));
    converter->hexdigits[i] = malloc(MAX_DIGITS * sizeof(char));
  }

  return converter;
}

void convertHex(HexConverter *converter, int num)
{
  int i = converter->numDigits - 1;

  for (; i >= 0 && num > 0; i--)
  {
    int digit = num % 16;
    num /= 16;

    converter->digits[i][0] = digit + 'a' - 1;
    converter->hexdigits[i][0] = digit + 'A' - 1;
  }

  converter->digits[i][0] = '\0';
  converter->hexdigits[i][0] = '\0';
}

int main()
{
  HexConverter *converter = createHexConverter(4);

  convertHex(converter, 15);

  printf("%s", converter->hexdigits[0]);
  printf("%s", converter->hexdigits[1]);
  printf("%s", converter->hexdigits[2]);
  printf("%s", converter->hexdigits[3]);

  free(converter);

  return 0;
}