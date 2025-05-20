//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Converts a binary number to its decimal equivalent
int binary_to_decimal(char *binary) {
  int decimal = 0;
  int base = 1;
  int i;

  for (i = strlen(binary) - 1; i >= 0; i--) {
    if (binary[i] == '1') {
      decimal += base;
    }
    base *= 2;
  }

  return decimal;
}

// Converts a decimal number to its binary equivalent
char *decimal_to_binary(int decimal) {
  char *binary = malloc(sizeof(char) * 33);
  int i = 0;

  while (decimal > 0) {
    if (decimal % 2 == 0) {
      binary[i] = '0';
    } else {
      binary[i] = '1';
    }
    decimal /= 2;
    i++;
  }

  binary[i] = '\0';
  return binary;
}

int main() {
  char *binary = "101010";
  int decimal = 42;

  printf("Binary: %s\n", binary);
  printf("Decimal: %d\n", binary_to_decimal(binary));

  printf("Decimal: %d\n", decimal);
  printf("Binary: %s\n", decimal_to_binary(decimal));

  return 0;
}