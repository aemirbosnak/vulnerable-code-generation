//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal number to an integer
int hex_to_int(char *hex) {
  int len = strlen(hex);
  int base = 1;
  int val = 0;

  for (int i = len - 1; i >= 0; i--) {
    // Get the value of the current digit
    int digit;
    if (hex[i] >= '0' && hex[i] <= '9') {
      digit = hex[i] - '0';
    } else if (hex[i] >= 'a' && hex[i] <= 'f') {
      digit = hex[i] - 'a' + 10;
    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
      digit = hex[i] - 'A' + 10;
    } else {
      return -1;  // Invalid hexadecimal digit
    }

    // Add the value of the current digit to the total
    val += digit * base;

    // Multiply the base by 16 to move to the next digit
    base *= 16;
  }

  return val;
}

// Function to convert an integer to a hexadecimal number
char *int_to_hex(int num) {
  int len = 0;

  // Count the number of digits in the hexadecimal representation
  while (num > 0) {
    num /= 16;
    len++;
  }

  // Allocate memory for the hexadecimal representation
  char *hex = malloc(len + 1);

  // Convert the integer to hexadecimal
  int i = len - 1;
  while (num > 0) {
    int digit = num % 16;

    if (digit < 10) {
      hex[i--] = digit + '0';
    } else {
      hex[i--] = digit - 10 + 'a';
    }

    num /= 16;
  }

  // Terminate the hexadecimal representation with a null character
  hex[len] = '\0';

  return hex;
}

// Driver code
int main() {
  // Test the hex_to_int function
  char *hex = "123a";
  int num = hex_to_int(hex);
  printf("Hexadecimal: %s\n", hex);
  printf("Integer: %d\n\n", num);

  // Test the int_to_hex function
  num = 45678;
  hex = int_to_hex(num);
  printf("Integer: %d\n", num);
  printf("Hexadecimal: %s\n", hex);

  return 0;
}