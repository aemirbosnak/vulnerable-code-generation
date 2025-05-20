//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string.
#define MAX_INPUT_LENGTH 100

// Convert a hexadecimal digit to its decimal equivalent.
int hex_to_dec(char hex_digit) {
  if (hex_digit >= '0' && hex_digit <= '9') {
    return hex_digit - '0';
  } else if (hex_digit >= 'A' && hex_digit <= 'F') {
    return hex_digit - 'A' + 10;
  } else if (hex_digit >= 'a' && hex_digit <= 'f') {
    return hex_digit - 'a' + 10;
  } else {
    return -1;
  }
}

// Convert a hexadecimal string to its decimal equivalent.
int hex_to_dec_str(char *hex_string) {
  int dec_value = 0;
  int len = strlen(hex_string);
  for (int i = 0; i < len; i++) {
    int hex_digit = hex_to_dec(hex_string[i]);
    if (hex_digit == -1) {
      return -1;
    }
    dec_value = dec_value * 16 + hex_digit;
  }
  return dec_value;
}

// Print the hexadecimal representation of a decimal number.
void dec_to_hex_str(int dec_number, char *hex_string) {
  int i = 0;
  while (dec_number != 0) {
    int hex_digit = dec_number % 16;
    if (hex_digit < 10) {
      hex_string[i++] = hex_digit + '0';
    } else {
      hex_string[i++] = hex_digit - 10 + 'A';
    }
    dec_number /= 16;
  }
  hex_string[i] = '\0';
}

// Get the hexadecimal representation of a decimal number.
char *dec_to_hex(int dec_number) {
  char *hex_string = malloc(100);
  dec_to_hex_str(dec_number, hex_string);
  return hex_string;
}

// The main function.
int main() {
  // Get the input string from the user.
  char input_string[MAX_INPUT_LENGTH];
  printf("Enter a hexadecimal string: ");
  scanf("%s", input_string);

  // Convert the hexadecimal string to its decimal equivalent.
  int dec_value = hex_to_dec_str(input_string);
  if (dec_value == -1) {
    printf("Invalid hexadecimal string.\n");
    return 1;
  }

  // Print the decimal equivalent.
  printf("Decimal equivalent: %d\n", dec_value);

  // Convert the decimal number back to its hexadecimal representation.
  char *hex_string = dec_to_hex(dec_value);

  // Print the hexadecimal representation.
  printf("Hexadecimal representation: %s\n", hex_string);

  // Free the memory allocated for the hexadecimal string.
  free(hex_string);

  return 0;
}