//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the binary to decimal conversion function
int binary_to_decimal(char *binary) {
  int decimal = 0;
  int length = strlen(binary);

  // Iterate over the binary digits from right to left
  for (int i = 0; i < length; i++) {
    // Check if the current digit is '1'
    if (binary[i] == '1') {
      // Add 2^(length - 1 - i) to the decimal value
      decimal += (1 << (length - 1 - i));
    }
  }

  // Return the decimal value
  return decimal;
}

// Define the decimal to binary conversion function
char *decimal_to_binary(int decimal) {
  char *binary = malloc(33);  // Allocate memory for the binary representation (32 bits + null-terminator)

  // Initialize the binary string to all '0's
  memset(binary, '0', 32);

  // Iterate over the binary digits from right to left
  for (int i = 0; i < 32; i++) {
    // Check if the current bit is set
    if (decimal & (1 << i)) {
      // Set the corresponding binary digit to '1'
      binary[i] = '1';
    }
  }

  // Add the null-terminator
  binary[32] = '\0';

  // Return the binary string
  return binary;
}

// Define the main function
int main() {
  // Get the binary number from the user
  char binary[] = "10110101";

  // Convert the binary number to decimal
  int decimal = binary_to_decimal(binary);

  // Print the decimal number
  printf("Decimal: %d\n", decimal);

  // Convert the decimal number back to binary
  char *binary_result = decimal_to_binary(decimal);

  // Print the binary representation
  printf("Binary: %s\n", binary_result);

  // Free the allocated memory
  free(binary_result);

  return 0;
}