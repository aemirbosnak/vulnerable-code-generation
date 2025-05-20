//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Welcome message
void welcome() {
  printf("-----------------------------------------------------------\n");
  printf("Welcome to the Wasteland Binary Converter, survivor!\n");
  printf("-----------------------------------------------------------\n");
}

// Get input from the user
char *get_input() {
  char *input = NULL;
  size_t len = 0;
  printf("Enter a binary number to convert to decimal: ");
  getline(&input, &len, stdin);
  return input;
}

// Convert binary to decimal
int binary_to_decimal(char *binary) {
  int decimal = 0;
  int length = strlen(binary);
  for (int i = 0; i < length; i++) {
    if (binary[i] == '0') {
      continue;
    } else if (binary[i] == '1') {
      decimal += (1 << (length - i - 1));
    } else {
      printf("Invalid binary number. Please enter a valid binary number.\n");
      return -1;
    }
  }
  return decimal;
}

// Print the result
void print_result(int decimal) {
  if (decimal == -1) {
    return;
  }
  printf("The decimal equivalent of the binary number is: %d\n", decimal);
}

// Main function
int main() {
  welcome();
  char *input = get_input();
  int decimal = binary_to_decimal(input);
  print_result(decimal);
  return 0;
}