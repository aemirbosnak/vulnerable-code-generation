//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: peaceful
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
  int quotient;
  int remainder;
  char *binary = malloc(33); // Allocate enough space for 32-bit binary number plus null-terminator

  int index = 0;
  while (decimal > 0) {
    remainder = decimal % 2;
    binary[index++] = remainder + '0';
    decimal /= 2;
  }

  binary[index] = '\0'; // Add null-terminator to the end of the string

  // Reverse the string to get the correct binary representation
  int start = 0;
  int end = index - 1;
  while (start < end) {
    char temp = binary[start];
    binary[start] = binary[end];
    binary[end] = temp;
    start++;
    end--;
  }

  return binary;
}

int main() {
  // Get the binary number from the user
  char binary[33]; // Allocate enough space for a 32-bit binary number plus null-terminator
  printf("Enter a binary number: ");
  scanf("%s", binary);

  // Convert the binary number to its decimal equivalent
  int decimal = binaryToDecimal(binary);

  // Print the decimal equivalent
  printf("Decimal equivalent: %d\n", decimal);

  // Convert the decimal number back to its binary equivalent
  char *binary2 = decimalToBinary(decimal);

  // Print the binary equivalent
  printf("Binary equivalent: %s\n", binary2);

  free(binary2); // Free the allocated memory

  return 0;
}