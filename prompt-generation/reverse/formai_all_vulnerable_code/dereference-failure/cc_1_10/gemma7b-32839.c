//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT_SIZE 10

typedef struct BinaryConverter {
  int num_digits;
  int *digits;
  char *binary;
} BinaryConverter;

BinaryConverter *create_binary_converter(int num_digits) {
  BinaryConverter *converter = malloc(sizeof(BinaryConverter));
  converter->num_digits = num_digits;
  converter->digits = malloc(num_digits * sizeof(int));
  converter->binary = malloc((num_digits + 1) * sizeof(char));
  return converter;
}

void convert_number_to_binary(BinaryConverter *converter, int number) {
  int i = converter->num_digits - 1;
  converter->digits[i] = number % 2;
  number /= 2;
  while (number) {
    converter->digits[i - 1] = number % 2;
    number /= 2;
    i--;
  }
  converter->binary[0] = '0';
  for (i = 0; i < converter->num_digits; i++) {
    converter->binary[i + 1] = converter->digits[i] + '0';
  }
  converter->binary[converter->num_digits + 1] = '\0';
}

void print_binary(BinaryConverter *converter) {
  printf("%s", converter->binary);
}

int main() {
  BinaryConverter *converter = create_binary_converter(4);
  convert_number_to_binary(converter, 13);
  print_binary(converter);
  printf("\n");
  converter = create_binary_converter(3);
  convert_number_to_binary(converter, 10);
  print_binary(converter);

  return 0;
}