//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_DIGITS 16
#define MAX_HEX_STRING_LENGTH (MAX_HEX_DIGITS + 1)

static const char *HEX_DIGITS = "0123456789ABCDEF";

// Converts a single hexadecimal digit to its corresponding integer value.
// Returns -1 if the digit is invalid.
int hex_digit_to_int(char digit) {
  for (int i = 0; i < MAX_HEX_DIGITS; i++) {
    if (digit == HEX_DIGITS[i]) {
      return i;
    }
  }
  return -1;
}

// Converts a hexadecimal string to its corresponding integer value.
// Returns -1 if the string is invalid.
int hex_string_to_int(const char *hex_string) {
  int value = 0;
  int length = strlen(hex_string);
  if (length > MAX_HEX_STRING_LENGTH) {
    return -1;
  }
  for (int i = 0; i < length; i++) {
    int digit_value = hex_digit_to_int(hex_string[i]);
    if (digit_value == -1) {
      return -1;
    }
    value = value * 16 + digit_value;
  }
  return value;
}

// Prints the usage information for the program.
void print_usage(const char *program_name) {
  printf("Usage: %s <hexadecimal_string>\n", program_name);
  printf("Converts a hexadecimal string to its corresponding integer value.\n");
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    print_usage(argv[0]);
    return EXIT_FAILURE;
  }

  const char *hex_string = argv[1];
  int value = hex_string_to_int(hex_string);
  if (value == -1) {
    printf("Invalid hexadecimal string: %s\n", hex_string);
    return EXIT_FAILURE;
  }

  printf("Hexadecimal string: %s\n", hex_string);
  printf("Integer value: %d\n", value);

  return EXIT_SUCCESS;
}