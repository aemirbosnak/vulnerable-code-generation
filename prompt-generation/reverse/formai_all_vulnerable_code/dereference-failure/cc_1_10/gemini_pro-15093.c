//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: secure
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
      base *= 16;
    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
      dec += (hex[i] - 'A' + 10) * base;
      base *= 16;
    } else if (hex[i] >= 'a' && hex[i] <= 'f') {
      dec += (hex[i] - 'a' + 10) * base;
      base *= 16;
    }
  }

  return dec;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int num) {
  char *hex = malloc(sizeof(char) * 100);
  int i = 0;

  while (num != 0) {
    int temp = num % 16;

    if (temp < 10) {
      hex[i++] = temp + '0';
    } else {
      hex[i++] = temp + 'A' - 10;
    }

    num /= 16;
  }

  hex[i] = '\0';

  // Reverse the string
  int len = strlen(hex);
  for (int j = 0; j < len / 2; j++) {
    char temp = hex[j];
    hex[j] = hex[len - j - 1];
    hex[len - j - 1] = temp;
  }

  return hex;
}

int main() {
  // Example hexadecimal string
  char *hex = "ABCDE";

  // Convert hexadecimal string to integer
  int dec = hex_to_int(hex);

  printf("Hexadecimal string: %s\n", hex);
  printf("Decimal equivalent: %d\n", dec);

  // Convert integer back to hexadecimal string
  char *new_hex = int_to_hex(dec);

  printf("Hexadecimal string after conversion: %s\n", new_hex);

  return 0;
}