//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a decimal number to its binary representation
char *decimalToBinary(int decimalNumber) {
  // Allocate memory for the binary representation
  char *binaryRepresentation = malloc(33);

  // Initialize the binary representation to 0
  memset(binaryRepresentation, 0, 33);

  // Iterate through the bits of the decimal number
  int i = 31;
  while (decimalNumber > 0) {
    // If the bit is set, set the corresponding bit in the binary representation
    if (decimalNumber & 1) {
      binaryRepresentation[i] = '1';
    }

    // Shift the decimal number right by 1 bit
    decimalNumber >>= 1;

    // Move to the next bit in the binary representation
    i--;
  }

  // Return the binary representation
  return binaryRepresentation;
}

// Function to convert a binary number to its decimal representation
int binaryToDecimal(char *binaryNumber) {
  // Initialize the decimal representation to 0
  int decimalRepresentation = 0;

  // Iterate through the bits of the binary number
  int i = 0;
  while (binaryNumber[i] != '\0') {
    // If the bit is set, add the corresponding weight to the decimal representation
    if (binaryNumber[i] == '1') {
      decimalRepresentation += (1 << (31 - i));
    }

    // Move to the next bit in the binary number
    i++;
  }

  // Return the decimal representation
  return decimalRepresentation;
}

// Function to print the binary representation of a number
void printBinaryRepresentation(int number) {
  // Convert the number to its binary representation
  char *binaryRepresentation = decimalToBinary(number);

  // Print the binary representation
  printf("%s\n", binaryRepresentation);

  // Free the memory allocated for the binary representation
  free(binaryRepresentation);
}

// Function to print the decimal representation of a binary number
void printDecimalRepresentation(char *binaryNumber) {
  // Convert the binary number to its decimal representation
  int decimalRepresentation = binaryToDecimal(binaryNumber);

  // Print the decimal representation
  printf("%d\n", decimalRepresentation);
}

// Function to test the binary converter
void testBinaryConverter() {
  // Test the conversion of decimal numbers to binary representations
  printf("Decimal numbers to binary representations:\n");
  printBinaryRepresentation(0);
  printBinaryRepresentation(1);
  printBinaryRepresentation(10);
  printBinaryRepresentation(100);
  printBinaryRepresentation(1000);

  // Test the conversion of binary numbers to decimal representations
  printf("Binary numbers to decimal representations:\n");
  printDecimalRepresentation("0");
  printDecimalRepresentation("1");
  printDecimalRepresentation("10");
  printDecimalRepresentation("100");
  printDecimalRepresentation("1000");
}

// Main function
int main() {
  // Test the binary converter
  testBinaryConverter();

  return 0;
}