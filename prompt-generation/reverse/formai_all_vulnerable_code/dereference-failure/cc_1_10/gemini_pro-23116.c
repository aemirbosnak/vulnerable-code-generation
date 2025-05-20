//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: expert-level
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
char *int_to_hex(int dec) {
  char *hex = malloc(100);
  int i = 0;

  while (dec != 0) {
    int rem = dec % 16;
    if (rem < 10) {
      hex[i++] = rem + '0';
    } else {
      hex[i++] = rem + 'A' - 10;
    }
    dec /= 16;
  }

  hex[i] = '\0';

  // Reverse the hexadecimal string
  char *rev_hex = malloc(100);
  int j = 0;
  for (int k = i - 1; k >= 0; k--) {
    rev_hex[j++] = hex[k];
  }

  free(hex);

  return rev_hex;
}

// Main function
int main() {
  // Test the hex_to_int function
  char *hex = "A1B2C3D4";
  int dec = hex_to_int(hex);
  printf("Hexadecimal: %s\n", hex);
  printf("Decimal: %d\n\n", dec);

  // Test the int_to_hex function
  int dec2 = 1023456789;
  char *hex2 = int_to_hex(dec2);
  printf("Decimal: %d\n", dec2);
  printf("Hexadecimal: %s\n", hex2);

  return 0;
}