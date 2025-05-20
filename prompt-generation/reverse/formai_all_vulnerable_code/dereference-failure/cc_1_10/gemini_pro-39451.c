//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the hexadecimal digits
char hex_digits[] = "0123456789ABCDEF";

// Convert a hexadecimal digit to its decimal value
int hex_to_dec(char hex_digit) {
  for (int i = 0; i < 16; i++) {
    if (hex_digit == hex_digits[i]) {
      return i;
    }
  }
  return -1;
}

// Convert a hexadecimal string to its decimal value
int hex_to_dec_string(char *hex_string) {
  int dec_value = 0;
  int len = strlen(hex_string);
  for (int i = 0; i < len; i++) {
    int hex_digit = hex_string[i];
    int dec_digit = hex_to_dec(hex_digit);
    dec_value += dec_digit * pow(16, len - i - 1);
  }
  return dec_value;
}

// Convert a decimal value to its hexadecimal string
char *dec_to_hex_string(int dec_value) {
  char *hex_string = (char *)malloc(sizeof(char) * 100);
  int i = 0;
  while (dec_value > 0) {
    int hex_digit = dec_value % 16;
    hex_string[i++] = hex_digits[hex_digit];
    dec_value /= 16;
  }
  hex_string[i] = '\0';
  return hex_string;
}

// Main function
int main() {
  // Get the hexadecimal string from the user
  char hex_string[100];
  printf("Enter a hexadecimal string: ");
  scanf("%s", hex_string);

  // Convert the hexadecimal string to its decimal value
  int dec_value = hex_to_dec_string(hex_string);

  // Print the decimal value
  printf("The decimal value of %s is %d\n", hex_string, dec_value);

  // Convert the decimal value to its hexadecimal string
  char *hex_string_new = dec_to_hex_string(dec_value);

  // Print the hexadecimal string
  printf("The hexadecimal string of %d is %s\n", dec_value, hex_string_new);

  return 0;
}