//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: Linus Torvalds
// Linus Torvalds style C Binary Converter

#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of bits in a binary number
#define MAX_BITS 32

// Function to convert a binary number to an integer
int binary_to_int(char *binary) {
  int i, num = 0;

  // Iterate over the binary number from right to left
  for (i = 0; binary[i] != '\0'; i++) {
    // If the current bit is a '1', add 2^(i) to the integer
    if (binary[i] == '1') {
      num += (1 << i);
    }
  }

  // Return the integer
  return num;
}

// Function to convert an integer to a binary number
char *int_to_binary(int num) {
  int i, j, temp;
  char *binary = malloc(MAX_BITS + 1);

  // Initialize the binary number to 0
  for (i = 0; i < MAX_BITS; i++) {
    binary[i] = '0';
  }
  binary[MAX_BITS] = '\0';

  // Iterate over the bits in the integer from right to left
  for (i = 0; num > 0; i++) {
    // If the current bit is a '1', set the corresponding bit in the binary number to '1'
    if (num & 1) {
      binary[i] = '1';
    }

    // Shift the integer right by 1 bit
    num >>= 1;
  }

  // Return the binary number
  return binary;
}

// Main function
int main(int argc, char *argv[]) {
  char *binary;
  int num;

  // Check if the user has provided a binary number or an integer
  if (argc == 2) {
    // Convert the binary number to an integer
    num = binary_to_int(argv[1]);

    // Print the integer
    printf("%d\n", num);
  } else if (argc == 3) {
    // Convert the integer to a binary number
    binary = int_to_binary(atoi(argv[1]));

    // Print the binary number
    printf("%s\n", binary);
  } else {
    // Print an error message
    printf("Usage: %s <binary number> or %s <integer>\n", argv[0], argv[0]);
  }

  return 0;
}