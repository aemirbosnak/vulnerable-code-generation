//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal string to an integer
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
      return -1;  // Invalid character
    }

    // Add the digit value to the result
    val += digit * base;

    // Multiply the base by 16
    base *= 16;
  }

  return val;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int num) {
  char *hex = malloc(sizeof(char) * 11);  // Maximum 8 digits plus null terminator

  int i = 0;
  while (num != 0) {
    int digit = num % 16;
    if (digit < 10) {
      hex[i] = '0' + digit;
    } else {
      hex[i] = 'a' + digit - 10;
    }
    i++;
    num /= 16;
  }

  hex[i] = '\0';  // Null terminator

  // Reverse the string
  for (int j = 0; j < i / 2; j++) {
    char temp = hex[j];
    hex[j] = hex[i - j - 1];
    hex[i - j - 1] = temp;
  }

  return hex;
}

int main() {
  // Test the hex_to_int function
  char *hex = "12345678";
  int num = hex_to_int(hex);
  printf("Hexadecimal: %s\n", hex);
  printf("Integer: %d\n\n", num);

  // Test the int_to_hex function
  num = 12345678;
  hex = int_to_hex(num);
  printf("Integer: %d\n", num);
  printf("Hexadecimal: %s\n", hex);

  return 0;
}