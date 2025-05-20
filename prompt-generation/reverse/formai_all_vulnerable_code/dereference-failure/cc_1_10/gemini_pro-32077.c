//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Convert a binary number to its decimal equivalent
int binaryToDecimal(char *binary) {
  int decimal = 0;
  int length = strlen(binary);
  int power = 1;

  for (int i = length - 1; i >= 0; i--) {
    if (binary[i] == '1') {
      decimal += power;
    }
    power *= 2;
  }

  return decimal;
}

// Convert a decimal number to its binary equivalent
char *decimalToBinary(int decimal) {
  char *binary = malloc(33);
  int index = 0;

  while (decimal > 0) {
    binary[index++] = (decimal % 2) + '0';
    decimal /= 2;
  }

  binary[index] = '\0';

  // Reverse the binary string
  char temp;
  for (int i = 0, j = strlen(binary) - 1; i < j; i++, j--) {
    temp = binary[i];
    binary[i] = binary[j];
    binary[j] = temp;
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
  printf("Decimal equivalent: %d\n", decimal);

  // Convert the decimal number to its binary equivalent
  char *newBinary = decimalToBinary(decimal);

  // Print the binary equivalent
  printf("Binary equivalent: %s\n", newBinary);

  return 0;
}