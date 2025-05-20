//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEX_DIGITS "0123456789ABCDEF"

// Function to convert a hexadecimal string to an integer
int hex_to_int(const char *hex) {
  int len = strlen(hex);
  int value = 0;

  for (int i = 0; i < len; i++) {
    char digit = hex[i];
    int val = strchr(HEX_DIGITS, digit) - HEX_DIGITS;

    if (val < 0 || val > 15) {
      fprintf(stderr, "Invalid hexadecimal digit '%c'\n", digit);
      exit(EXIT_FAILURE);
    }

    value = (value << 4) | val;
  }

  return value;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int value, int min_len) {
  char *hex = malloc(min_len + 1);

  if (hex == NULL) {
    fprintf(stderr, "Failed to allocate memory for hexadecimal string\n");
    exit(EXIT_FAILURE);
  }

  for (int i = min_len - 1; i >= 0; i--) {
    int digit = value & 0xF;
    hex[i] = HEX_DIGITS[digit];
    value >>= 4;
  }

  hex[min_len] = '\0';

  return hex;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <hexadecimal string>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *hex = argv[1];
  int value = hex_to_int(hex);

  printf("Hexadecimal string: %s\n", hex);
  printf("Integer value: %d\n", value);

  char *hex_out = int_to_hex(value, strlen(hex));
  printf("Decimal string: %s\n", hex_out);

  free(hex_out);

  return 0;
}