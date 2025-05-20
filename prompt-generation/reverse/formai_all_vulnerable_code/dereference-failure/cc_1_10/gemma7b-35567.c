//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct HexadecimalConverter
{
  char *buffer;
  int capacity;
  int used_size;
  int offset;
} HexadecimalConverter;

HexadecimalConverter *hex_converter_init(int capacity)
{
  HexadecimalConverter *converter = malloc(sizeof(HexadecimalConverter));

  converter->buffer = malloc(capacity * sizeof(char));
  converter->capacity = capacity;
  converter->used_size = 0;
  converter->offset = 0;

  return converter;
}

void hex_converter_append(HexadecimalConverter *converter, unsigned int value)
{
  char hex_chars[] = "0123456789abcdef";

  int num_digits = 0;
  while (value / 16)
  {
    num_digits++;
    value /= 16;
  }

  int offset = converter->offset;
  converter->offset += num_digits;

  if (converter->used_size >= converter->capacity)
  {
    converter->buffer = realloc(converter->buffer, converter->capacity * 2);
    converter->capacity *= 2;
  }

  for (int i = 0; i < num_digits; i++)
  {
    converter->buffer[offset++] = hex_chars[value % 16];
  }

  converter->used_size++;
}

void hex_converter_print(HexadecimalConverter *converter)
{
  for (int i = 0; i < converter->used_size; i++)
  {
    printf("%c", converter->buffer[i]);
  }

  printf("\n");
}

int main()
{
  HexadecimalConverter *converter = hex_converter_init(MAX_BUFFER_SIZE);

  hex_converter_append(converter, 0x12);
  hex_converter_append(converter, 0x34);
  hex_converter_append(converter, 0x56);

  hex_converter_print(converter);

  return 0;
}