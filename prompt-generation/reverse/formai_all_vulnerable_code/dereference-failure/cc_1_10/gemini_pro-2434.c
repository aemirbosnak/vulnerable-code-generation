//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal string to an integer
int hex_to_int(const char *hex) {
  int value = 0;
  int len = strlen(hex);
  for (int i = 0; i < len; i++) {
    char c = hex[i];
    int digit;
    if (c >= '0' && c <= '9') {
      digit = c - '0';
    } else if (c >= 'A' && c <= 'F') {
      digit = c - 'A' + 10;
    } else if (c >= 'a' && c <= 'f') {
      digit = c - 'a' + 10;
    } else {
      return -1;  // Invalid character
    }
    value = (value << 4) | digit;
  }
  return value;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int value) {
  char *hex = malloc(sizeof(char) * 9);  // 8 characters for the hex value, plus null terminator
  int i = 0;
  do {
    int digit = value % 16;
    if (digit < 10) {
      hex[i++] = digit + '0';
    } else {
      hex[i++] = digit - 10 + 'A';
    }
    value /= 16;
  } while (value != 0);
  hex[i] = '\0';
  return hex;
}

int main() {
  // Convert a hexadecimal string to an integer
  int value = hex_to_int("123456");
  printf("Hexadecimal string: 123456\n");
  printf("Integer value: %d\n", value);

  // Convert an integer to a hexadecimal string
  char *hex = int_to_hex(123456);
  printf("Integer value: 123456\n");
  printf("Hexadecimal string: %s\n", hex);

  free(hex);  // Free the memory allocated for the hexadecimal string
  return 0;
}