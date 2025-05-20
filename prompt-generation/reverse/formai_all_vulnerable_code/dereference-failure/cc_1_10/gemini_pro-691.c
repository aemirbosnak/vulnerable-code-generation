//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: statistical
#include <stdlib.h>
#include <stdio.h>

// Function to convert a binary number to its decimal equivalent
int binaryToDecimal(char *binary) {
  int decimal = 0;
  int length = strlen(binary);

  for (int i = 0; i < length; i++) {
    if (binary[i] == '1') {
      decimal += (1 << (length - i - 1));
    }
  }

  return decimal;
}

// Function to convert a decimal number to its binary equivalent
char *decimalToBinary(int decimal) {
  char *binary = malloc(sizeof(char) * 33);
  int i = 0;

  while (decimal > 0) {
    binary[i++] = (decimal % 2) + '0';
    decimal /= 2;
  }

  binary[i] = '\0';

  // Reverse the string
  char temp;
  int length = strlen(binary);
  for (int j = 0; j < length / 2; j++) {
    temp = binary[j];
    binary[j] = binary[length - j - 1];
    binary[length - j - 1] = temp;
  }

  return binary;
}

// Driver code
int main() {
  // Test the binaryToDecimal function
  char *binary1 = "101010";
  int decimal1 = binaryToDecimal(binary1);
  printf("Binary number: %s\n", binary1);
  printf("Decimal equivalent: %d\n\n", decimal1);

  // Test the decimalToBinary function
  int decimal2 = 1234;
  char *binary2 = decimalToBinary(decimal2);
  printf("Decimal number: %d\n", decimal2);
  printf("Binary equivalent: %s\n", binary2);

  return 0;
}