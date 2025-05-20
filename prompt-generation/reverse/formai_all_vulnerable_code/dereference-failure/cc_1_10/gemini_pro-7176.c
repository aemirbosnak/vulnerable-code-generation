//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal number to an integer
int hex_to_int(char *hex) {
  int len = strlen(hex);
  int base = 1;
  int val = 0;
  for (int i = len - 1; i >= 0; i--) {
    // Get the digit value
    int digit;
    if (hex[i] >= '0' && hex[i] <= '9') {
      digit = hex[i] - '0';
    } else if (hex[i] >= 'a' && hex[i] <= 'f') {
      digit = hex[i] - 'a' + 10;
    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
      digit = hex[i] - 'A' + 10;
    } else {
      printf("Invalid hexadecimal digit: %c\n", hex[i]);
      return -1;
    }

    // Multiply the digit by the base and add it to the value
    val += digit * base;
    base *= 16;
  }

  return val;
}

// Function to convert an integer to a hexadecimal number
char *int_to_hex(int num) {
  char *hex = malloc(sizeof(char) * 100);
  int i = 0;
  while (num > 0) {
    int digit = num % 16;
    if (digit < 10) {
      hex[i++] = digit + '0';
    } else {
      hex[i++] = digit - 10 + 'a';
    }
    num /= 16;
  }
  hex[i] = '\0';

  // Reverse the string
  char *reversed_hex = malloc(sizeof(char) * 100);
  int j = 0;
  for (i = strlen(hex) - 1; i >= 0; i--) {
    reversed_hex[j++] = hex[i];
  }
  reversed_hex[j] = '\0';

  free(hex);
  return reversed_hex;
}

int main() {
  // Convert a hexadecimal number to an integer
  char *hex = "1234";
  int num = hex_to_int(hex);
  printf("Hexadecimal: %s, Integer: %d\n", hex, num);

  // Convert an integer to a hexadecimal number
  num = 5678;
  hex = int_to_hex(num);
  printf("Integer: %d, Hexadecimal: %s\n", num, hex);

  return 0;
}