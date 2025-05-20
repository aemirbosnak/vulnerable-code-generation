//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to binary
int *decimalToBinary(int decimalNumber) {
  int *binaryNumber = malloc(sizeof(int) * 32);
  int index = 0;
  while (decimalNumber > 0) {
    binaryNumber[index] = decimalNumber % 2;
    decimalNumber /= 2;
    index++;
  }
  return binaryNumber;
}

// Function to convert a binary number to decimal
int binaryToDecimal(int *binaryNumber, int size) {
  int decimalNumber = 0;
  for (int i = 0; i < size; i++) {
    decimalNumber += binaryNumber[i] * (1 << i);
  }
  return decimalNumber;
}

// Function to print a binary number
void printBinaryNumber(int *binaryNumber, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d", binaryNumber[i]);
  }
  printf("\n");
}

// Main function
int main() {
  int decimalNumber;
  int *binaryNumber;

  // Get the decimal number from the user
  printf("Enter a decimal number: ");
  scanf("%d", &decimalNumber);

  // Convert the decimal number to binary
  binaryNumber = decimalToBinary(decimalNumber);

  // Print the binary number
  printf("The binary representation of %d is: ", decimalNumber);
  printBinaryNumber(binaryNumber, 32);

  // Convert the binary number back to decimal
  int decimalNumberFromBinary = binaryToDecimal(binaryNumber, 32);

  // Print the decimal number converted from binary
  printf("The decimal number converted from binary is: %d\n", decimalNumberFromBinary);

  return 0;
}