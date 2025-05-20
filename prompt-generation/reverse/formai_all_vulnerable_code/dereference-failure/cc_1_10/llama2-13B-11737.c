//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_BITS 32

// Function to convert a binary string to decimal
int binary_to_decimal(char *binary_str) {
  int decimal = 0;
  for (int i = 0; i < strlen(binary_str); i++) {
    if (binary_str[i] == '1') {
      decimal += pow(2, i);
    }
  }
  return decimal;
}

// Function to convert a decimal number to binary
char *decimal_to_binary(int decimal) {
  char *binary_str = malloc(sizeof(char) * (strlen(binary_str) + 1));
  int i = 0;
  while (decimal != 0) {
    binary_str[i] = (decimal % 2) == 1 ? '1' : '0';
    decimal /= 2;
    i++;
  }
  binary_str[i] = '\0';
  return binary_str;
}

int main() {
  char binary_str[MAX_INPUT_LENGTH] = "";
  int decimal = 0;

  // Ask the user for a binary string
  printf("Enter a binary string (up to 1024 bits long): ");
  fgets(binary_str, MAX_INPUT_LENGTH, stdin);

  // Convert the binary string to decimal
  decimal = binary_to_decimal(binary_str);

  // Print the decimal number
  printf("The decimal equivalent of the binary string is: %d\n", decimal);

  // Ask the user if they want to convert the decimal number back to binary
  printf("Would you like to convert the decimal number back to binary? (y/n): ");
  char input;
  scanf("%c", &input);
  if (input == 'y' || input == 'Y') {
    // Convert the decimal number back to binary
    char *binary_str = decimal_to_binary(decimal);
    printf("The binary equivalent of the decimal number is: %s\n", binary_str);
    free(binary_str);
  }

  return 0;
}