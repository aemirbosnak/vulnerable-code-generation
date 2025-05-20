//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal string to an integer
int hex_to_int(char *hex) {
  int len = strlen(hex);
  int base = 1;
  int dec = 0;

  for (int i = len - 1; i >= 0; i--) {
    if (hex[i] >= '0' && hex[i] <= '9') {
      dec += (hex[i] - '0') * base;
    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
      dec += (hex[i] - 'A' + 10) * base;
    } else if (hex[i] >= 'a' && hex[i] <= 'f') {
      dec += (hex[i] - 'a' + 10) * base;
    }
    base *= 16;
  }

  return dec;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int num) {
  int temp = num;
  int len = 0;

  // Count the number of digits in the hexadecimal representation
  while (temp > 0) {
    len++;
    temp /= 16;
  }

  // Allocate memory for the hexadecimal string
  char *hex = malloc(len + 1);

  // Convert the integer to a hexadecimal string
  hex[len] = '\0';
  while (num > 0) {
    int digit = num % 16;
    if (digit < 10) {
      hex[len - 1] = digit + '0';
    } else {
      hex[len - 1] = digit - 10 + 'A';
    }
    num /= 16;
    len--;
  }

  return hex;
}

int main() {
  // Get the hexadecimal string from the user
  char hex[100];
  printf("Enter a hexadecimal string: ");
  scanf("%s", hex);

  // Convert the hexadecimal string to an integer
  int dec = hex_to_int(hex);

  // Print the integer
  printf("The integer representation of %s is %d\n", hex, dec);

  // Convert the integer back to a hexadecimal string
  char *new_hex = int_to_hex(dec);

  // Print the hexadecimal string
  printf("The hexadecimal representation of %d is %s\n", dec, new_hex);

  // Free the allocated memory
  free(new_hex);

  return 0;
}