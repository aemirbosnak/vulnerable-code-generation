//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

// Function to convert a decimal number to binary
uint8_t *decimalToBinary(int num) {
  // Allocate memory for the binary representation
  uint8_t *binary = malloc(sizeof(uint8_t) * 32);

  // Initialize the binary representation to 0
  for (int i = 0; i < 32; i++) {
    binary[i] = 0;
  }

  // Iterate through the bits of the decimal number
  int index = 31;
  while (num > 0) {
    // Get the least significant bit of the decimal number
    binary[index--] = num % 2;

    // Divide the decimal number by 2 to get the next bit
    num /= 2;
  }

  // Return the binary representation
  return binary;
}

// Function to convert a binary number to decimal
int binaryToDecimal(uint8_t *binary) {
  // Initialize the decimal representation to 0
  int decimal = 0;

  // Iterate through the bits of the binary number
  for (int i = 0; i < 32; i++) {
    // Multiply the decimal representation by 2
    decimal *= 2;

    // Add the current bit to the decimal representation
    decimal += binary[i];
  }

  // Return the decimal representation
  return decimal;
}

// Main function
int main() {
  // Get the decimal number from the user
  printf("Enter a decimal number: ");
  int num;
  scanf("%d", &num);

  // Convert the decimal number to binary
  uint8_t *binary = decimalToBinary(num);

  // Print the binary representation of the decimal number
  printf("Binary representation: ");
  for (int i = 0; i < 32; i++) {
    printf("%d", binary[i]);
  }
  printf("\n");

  // Convert the binary number back to decimal
  int decimal2 = binaryToDecimal(binary);

  // Print the decimal representation of the binary number
  printf("Decimal representation: %d\n", decimal2);

  // Free the memory allocated for the binary representation
  free(binary);

  return 0;
}