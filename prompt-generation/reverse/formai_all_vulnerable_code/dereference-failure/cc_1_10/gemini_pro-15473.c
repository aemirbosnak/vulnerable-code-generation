//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert binary to decimal
int binary_to_decimal(char *binary) {
  int decimal = 0;
  int len = strlen(binary);

  for (int i = 0; i < len; i++) {
    if (binary[i] == '1') {
      decimal += (1 << (len - i - 1));
    }
  }

  return decimal;
}

// Function to convert decimal to binary
char *decimal_to_binary(int decimal) {
  int len = 32;
  char *binary = (char *)malloc(len + 1);

  for (int i = 0; i < len; i++) {
    binary[i] = '0';
  }
  binary[len] = '\0';

  int index = len - 1;
  while (decimal > 0) {
    if (decimal % 2 == 1) {
      binary[index] = '1';
    }
    decimal /= 2;
    index--;
  }

  return binary;
}

// Main function
int main() {
  // Binary to decimal conversion
  char *binary = "10101010";
  int decimal = binary_to_decimal(binary);
  printf("Binary: %s, Decimal: %d\n", binary, decimal);

  // Decimal to binary conversion
  decimal = 12345;
  binary = decimal_to_binary(decimal);
  printf("Decimal: %d, Binary: %s\n", decimal, binary);

  return 0;
}