//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of bits in a binary number
#define MAX_BITS 32

// Define the base of the binary number
#define BASE 2

// Define the maximum number of digits in a decimal number
#define MAX_DIGITS 10

// Define the base of the decimal number
#define DECIMAL_BASE 10

// Function to convert a binary number to a decimal number
int binary_to_decimal(char *binary) {
  int decimal = 0;
  int power = 1;
  int i;

  // Iterate over the binary number from right to left
  for (i = strlen(binary) - 1; i >= 0; i--) {
    // If the current bit is 1, add the corresponding power of 2 to the decimal number
    if (binary[i] == '1') {
      decimal += power;
    }

    // Multiply the power by 2 to move to the next bit
    power *= 2;
  }

  // Return the decimal number
  return decimal;
}

// Function to convert a decimal number to a binary number
char *decimal_to_binary(int decimal) {
  char *binary = malloc(MAX_BITS + 1);
  int i = 0;

  // Iterate over the decimal number from right to left
  while (decimal > 0) {
    // If the current digit is even, add 0 to the binary number
    if (decimal % 2 == 0) {
      binary[i] = '0';
    }
    // Otherwise, add 1 to the binary number
    else {
      binary[i] = '1';
    }

    // Divide the decimal number by 2 to move to the next digit
    decimal /= 2;

    // Increment the index of the binary number
    i++;
  }

  // Add the null terminator to the binary number
  binary[i] = '\0';

  // Reverse the binary number
  for (i = 0; i < strlen(binary) / 2; i++) {
    char temp = binary[i];
    binary[i] = binary[strlen(binary) - i - 1];
    binary[strlen(binary) - i - 1] = temp;
  }

  // Return the binary number
  return binary;
}

// Main function
int main() {
  // Get the binary number from the user
  char binary[MAX_BITS + 1];
  printf("Enter the binary number: ");
  scanf("%s", binary);

  // Convert the binary number to a decimal number
  int decimal = binary_to_decimal(binary);

  // Print the decimal number
  printf("The decimal number is: %d\n", decimal);

  // Convert the decimal number to a binary number
  char *binary_result = decimal_to_binary(decimal);

  // Print the binary number
  printf("The binary number is: %s\n", binary_result);

  // Free the memory allocated for the binary number
  free(binary_result);

  return 0;
}