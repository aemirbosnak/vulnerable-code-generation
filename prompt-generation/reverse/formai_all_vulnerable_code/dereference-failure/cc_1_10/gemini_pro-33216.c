//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BINARY_LENGTH 100

// Function to convert a binary number to a decimal number
int binary_to_decimal(char *binary) {
  int decimal = 0;
  int length = strlen(binary);

  for (int i = 0; i < length; i++) {
    if (binary[i] == '0') {
      decimal *= 2;
    } else if (binary[i] == '1') {
      decimal *= 2;
      decimal += 1;
    } else {
      return -1;  // Invalid binary number
    }
  }

  return decimal;
}

// Function to convert a decimal number to a binary number
char *decimal_to_binary(int decimal) {
  char *binary = malloc(MAX_BINARY_LENGTH * sizeof(char));
  int index = 0;

  while (decimal > 0) {
    if (decimal % 2 == 0) {
      binary[index] = '0';
    } else {
      binary[index] = '1';
    }
    decimal /= 2;
    index++;
  }

  binary[index] = '\0';  // Null-terminate the string

  // Reverse the binary string
  char *temp = malloc(MAX_BINARY_LENGTH * sizeof(char));
  int j = 0;
  for (int i = strlen(binary) - 1; i >= 0; i--) {
    temp[j] = binary[i];
    j++;
  }
  temp[j] = '\0';

  free(binary);
  return temp;
}

int main() {
  // Get the input binary number
  char binary[MAX_BINARY_LENGTH];
  printf("Enter a binary number: ");
  scanf("%s", binary);

  // Convert the binary number to a decimal number
  int decimal = binary_to_decimal(binary);

  // Check if the input was a valid binary number
  if (decimal == -1) {
    printf("Invalid binary number\n");
    return 1;
  }

  // Print the decimal number
  printf("The decimal equivalent of %s is %d\n", binary, decimal);

  // Get the input decimal number
  int number;
  printf("Enter a decimal number: ");
  scanf("%d", &number);

  // Convert the decimal number to a binary number
  char *binary_result = decimal_to_binary(number);

  // Print the binary number
  printf("The binary equivalent of %d is %s\n", number, binary_result);

  free(binary_result);
  return 0;
}