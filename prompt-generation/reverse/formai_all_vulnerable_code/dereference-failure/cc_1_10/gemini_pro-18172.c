//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a binary number to its decimal equivalent
int binaryToDecimal(char *binary) {
  int decimal = 0;
  int base = 1;
  int len = strlen(binary);

  for (int i = len - 1; i >= 0; i--) {
    if (binary[i] == '1') {
      decimal += base;
    }
    base *= 2;
  }

  return decimal;
}

// Function to convert a decimal number to its binary equivalent
char *decimalToBinary(int decimal) {
  char *binary = malloc(33 * sizeof(char));
  int i = 0;

  while (decimal > 0) {
    binary[i] = (decimal % 2) + '0';
    decimal /= 2;
    i++;
  }

  binary[i] = '\0';

  // Reverse the binary string
  char temp;
  for (int j = 0; j < i / 2; j++) {
    temp = binary[j];
    binary[j] = binary[i - j - 1];
    binary[i - j - 1] = temp;
  }

  return binary;
}

int main() {
  // Get the binary number from the user
  char binary[33];
  printf("Enter a binary number: ");
  scanf("%s", binary);

  // Convert the binary number to its decimal equivalent
  int decimal = binaryToDecimal(binary);

  // Print the decimal equivalent
  printf("The decimal equivalent of %s is %d\n", binary, decimal);

  // Convert the decimal number to its binary equivalent
  char *newBinary = decimalToBinary(decimal);

  // Print the binary equivalent
  printf("The binary equivalent of %d is %s\n", decimal, newBinary);

  // Free the allocated memory
  free(newBinary);

  return 0;
}