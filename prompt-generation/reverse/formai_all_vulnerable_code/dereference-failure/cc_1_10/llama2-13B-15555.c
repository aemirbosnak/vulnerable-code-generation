//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 1024

// Declare a function to convert binary to decimal
int binaryToDecimal(char binary[MAX_LENGTH]) {
  int decimal = 0;
  for (int i = 0; i < strlen(binary); i++) {
    if (binary[i] == '1') {
      decimal += pow(2, i);
    }
  }
  return decimal;
}

// Declare a function to convert decimal to binary
char* decimalToBinary(int decimal) {
  char binary[MAX_LENGTH];
  int i = 0;
  while (decimal != 0) {
    binary[i] = decimal % 2 == 0 ? '0' : '1';
    decimal /= 2;
    i++;
  }
  return binary;
}

int main() {
  // Declare a string to store the binary input
  char binary[MAX_LENGTH];
  gets(binary);

  // Convert binary to decimal
  int decimal = binaryToDecimal(binary);

  // Print the decimal output
  printf("Decimal: %d\n", decimal);

  // Convert decimal to binary
  char* binaryOutput = decimalToBinary(decimal);
  printf("Binary: %s\n", binaryOutput);

  // Free the memory allocated for the binary output
  free(binaryOutput);

  return 0;
}