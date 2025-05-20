//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of bits in a binary number
#define MAX_BITS 32

// Define the base of the binary number
#define BASE 2

// Define the number of digits in a binary number
#define NUM_DIGITS 8

// Define the string representation of the binary number
char binary_string[MAX_BITS + 1];

// Define the array of binary digits
int binary_digits[MAX_BITS];

// Define the function to convert a binary number to a decimal number
int binary_to_decimal(char *binary_string) {
  int decimal_number = 0;
  int i;

  // Loop through the binary digits
  for (i = 0; i < MAX_BITS; i++) {
    // If the binary digit is 1, then add the corresponding power of 2 to the decimal number
    if (binary_digits[i] == 1) {
      decimal_number += 1 << i;
    }
  }

  // Return the decimal number
  return decimal_number;
}

// Define the main function
int main(int argc, char *argv[]) {
  // Check if the user has provided a binary number
  if (argc != 2) {
    printf("Usage: %s <binary_number>\n", argv[0]);
    return 1;
  }

  // Get the binary number from the user
  strcpy(binary_string, argv[1]);

  // Check if the binary number is valid
  if (!binary_string_is_valid(binary_string)) {
    printf("Error: Invalid binary number\n");
    return 1;
  }

  // Convert the binary number to a decimal number
  int decimal_number = binary_to_decimal(binary_string);

  // Print the decimal number
  printf("Decimal number: %d\n", decimal_number);

  return 0;
}

// Define the function to check if a binary number is valid
int binary_string_is_valid(char *binary_string) {
  int i;

  // Loop through the binary digits
  for (i = 0; i < MAX_BITS; i++) {
    // Check if the binary digit is not 0 or 1
    if (binary_digits[i] != 0 && binary_digits[i] != 1) {
      return 0;
    }
  }

  // Return 1 if the binary number is valid
  return 1;
}