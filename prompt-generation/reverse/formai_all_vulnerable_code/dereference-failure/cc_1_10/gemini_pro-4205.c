//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Converts a binary number to its decimal equivalent
int binary_to_decimal(char *binary) {
  int decimal = 0;
  int i = 0;
  int length = strlen(binary);

  // Iterate over the binary number from right to left
  while (i < length) {
    // Get the current digit
    int digit = binary[length - i - 1] - '0';

    // Multiply the digit by the appropriate power of 2
    decimal += digit * (1 << i);

    i++;
  }

  return decimal;
}

// Converts a decimal number to its binary equivalent
char *decimal_to_binary(int decimal) {
  int size = 32;
  char *binary = malloc(size);
  int i = 0;

  // Iterate over the binary number from right to left
  while (decimal > 0) {
    // Get the current digit
    int digit = decimal % 2;

    // Convert the digit to a character
    binary[size - i - 1] = digit + '0';

    // Divide the decimal number by 2
    decimal /= 2;

    i++;
  }

  // Add the null terminator
  binary[size] = '\0';

  return binary;
}

int main() {
  char *binary = "101010";
  int decimal = binary_to_decimal(binary);
  printf("%s in binary is %d in decimal\n", binary, decimal);

  char *new_binary = decimal_to_binary(decimal);
  printf("%d in decimal is %s in binary\n", decimal, new_binary);

  free(new_binary);

  return 0;
}