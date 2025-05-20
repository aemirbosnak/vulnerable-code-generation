//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert hexadecimal to decimal
int hex_to_decimal(char *hex) {
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

// Function to convert decimal to hexadecimal
char *decimal_to_hex(int dec) {
  int temp = dec;
  int len = 0;

  // Count the number of digits in the hexadecimal representation
  while (temp != 0) {
    len++;
    temp /= 16;
  }

  // Allocate memory for the hexadecimal representation
  char *hex = malloc(len + 1);

  // Convert the decimal number to hexadecimal
  int i = len - 1;
  while (dec != 0) {
    int remainder = dec % 16;
    if (remainder < 10) {
      hex[i] = remainder + '0';
    } else {
      hex[i] = remainder - 10 + 'A';
    }
    dec /= 16;
    i--;
  }

  hex[len] = '\0';

  return hex;
}

// Main function
int main() {
  // Get the hexadecimal number from the user
  char hex[100];
  printf("Enter a hexadecimal number: ");
  scanf("%s", hex);

  // Convert the hexadecimal number to decimal
  int dec = hex_to_decimal(hex);

  // Print the decimal number
  printf("Decimal: %d\n", dec);

  // Convert the decimal number back to hexadecimal
  char *hex2 = decimal_to_hex(dec);

  // Print the hexadecimal number
  printf("Hexadecimal: %s\n", hex2);

  return 0;
}