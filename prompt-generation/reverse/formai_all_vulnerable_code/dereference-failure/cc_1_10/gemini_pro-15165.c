//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal string to an integer
int hex_to_int(char *hex) {
  int len = strlen(hex);
  int base = 1;
  int val = 0;

  // Iterate over the hexadecimal string in reverse order
  for (int i = len - 1; i >= 0; i--) {
    // Get the digit value of the current character
    int digit;
    if (hex[i] >= '0' && hex[i] <= '9') {
      digit = hex[i] - '0';
    } else if (hex[i] >= 'a' && hex[i] <= 'f') {
      digit = hex[i] - 'a' + 10;
    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
      digit = hex[i] - 'A' + 10;
    } else {
      return -1;  // Invalid hexadecimal character
    }

    // Multiply the digit value by the appropriate base and add it to the result
    val += digit * base;
    base *= 16;
  }

  return val;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int num) {
  // Allocate memory for the hexadecimal string
  char *hex = malloc(100);

  // Convert the integer to a hexadecimal string
  int i = 0;
  while (num != 0) {
    int digit = num % 16;
    if (digit < 10) {
      hex[i++] = digit + '0';
    } else {
      hex[i++] = digit - 10 + 'a';
    }
    num /= 16;
  }

  // Reverse the hexadecimal string
  for (int j = 0; j < i / 2; j++) {
    char temp = hex[j];
    hex[j] = hex[i - 1 - j];
    hex[i - 1 - j] = temp;
  }

  // Add the null-terminator to the hexadecimal string
  hex[i] = '\0';

  return hex;
}

// Main function
int main(int argc, char **argv) {
  // Check if the user has provided a hexadecimal string
  if (argc < 2) {
    printf("Usage: %s <hexadecimal string>\n", argv[0]);
    return 1;
  }

  // Convert the hexadecimal string to an integer
  int num = hex_to_int(argv[1]);

  // Check if the hexadecimal string is valid
  if (num == -1) {
    printf("Invalid hexadecimal string: %s\n", argv[1]);
    return 1;
  }

  // Convert the integer to a hexadecimal string
  char *hex = int_to_hex(num);

  // Print the hexadecimal string
  printf("Hexadecimal string: %s\n", hex);

  // Free the memory allocated for the hexadecimal string
  free(hex);

  return 0;
}