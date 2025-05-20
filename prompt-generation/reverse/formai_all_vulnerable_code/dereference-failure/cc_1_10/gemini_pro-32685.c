//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to binary
char* decToBin(int n) {
  // Allocate memory for the binary string
  char* bin = malloc(sizeof(char) * 33);

  // Initialize the binary string to empty
  bin[0] = '\0';

  // Iterate through the bits of the decimal number
  int i = 0;
  while (n > 0) {
    // Append the least significant bit to the binary string
    bin[i++] = (n & 1) + '0';

    // Shift the decimal number right by 1 bit
    n >>= 1;
  }

  // Reverse the binary string
  int j = 0;
  int k = i - 1;
  while (j < k) {
    char temp = bin[j];
    bin[j++] = bin[k];
    bin[k--] = temp;
  }

  // Return the binary string
  return bin;
}

// Function to convert a binary number to decimal
int binToDec(char* bin) {
  // Initialize the decimal number to 0
  int dec = 0;

  // Iterate through the bits of the binary number
  int i = 0;
  int len = strlen(bin);
  while (i < len) {
    // Add the value of the bit to the decimal number
    dec += (bin[i++] - '0') << (len - i - 1);
  }

  // Return the decimal number
  return dec;
}

// Main function
int main() {
  // Get the decimal number from the user
  int n;
  printf("Enter a decimal number: ");
  scanf("%d", &n);

  // Convert the decimal number to binary
  char* bin = decToBin(n);

  // Print the binary number
  printf("The binary representation of %d is: %s\n", n, bin);

  // Convert the binary number back to decimal
  int dec2 = binToDec(bin);

  // Print the decimal number
  printf("The decimal representation of %s is: %d\n", bin, dec2);

  // Free the memory allocated for the binary string
  free(bin);

  return 0;
}