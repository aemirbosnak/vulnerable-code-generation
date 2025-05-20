//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Get the binary representation of a decimal number
char *getBinary(int num) {
  // Allocate memory for the binary representation
  char *binary = malloc(33);
  memset(binary, '0', 32);
  binary[32] = '\0';

  // Convert the decimal number to binary
  int i = 31;
  while (num > 0) {
    if (num % 2 == 1) {
      binary[i] = '1';
    }
    num /= 2;
    i--;
  }

  // Return the binary representation
  return binary;
}

// Convert a binary number to decimal
int getDecimal(char *binary) {
  // Check if the binary number is valid
  for (int i = 0; i < strlen(binary); i++) {
    if (binary[i] != '0' && binary[i] != '1') {
      return -1;
    }
  }

  // Convert the binary number to decimal
  int decimal = 0;
  for (int i = 0; i < strlen(binary); i++) {
    if (binary[i] == '1') {
      decimal += (1 << (strlen(binary) - i - 1));
    }
  }

  // Return the decimal representation
  return decimal;
}

// Print the binary representation of a decimal number
void printBinary(int num) {
  // Get the binary representation of the decimal number
  char *binary = getBinary(num);

  // Print the binary representation
  printf("%s\n", binary);

  // Free the memory allocated for the binary representation
  free(binary);
}

// Print the decimal representation of a binary number
void printDecimal(char *binary) {
  // Convert the binary number to decimal
  int decimal = getDecimal(binary);

  // Print the decimal representation
  printf("%d\n", decimal);
}

// Main function
int main() {
  // Get the decimal number from the user
  int num;
  printf("Enter a decimal number: ");
  scanf("%d", &num);

  // Print the binary representation of the decimal number
  printf("Binary representation: ");
  printBinary(num);

  // Get the binary number from the user
  char binary[33];
  printf("Enter a binary number: ");
  scanf("%s", binary);

  // Print the decimal representation of the binary number
  printf("Decimal representation: ");
  printDecimal(binary);

  return 0;
}