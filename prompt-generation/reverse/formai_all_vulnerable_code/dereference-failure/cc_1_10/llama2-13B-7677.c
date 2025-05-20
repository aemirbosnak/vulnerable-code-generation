//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define BINARY_DIGITS 64
#define BINARY_CHARS 10

// Function to convert binary to text
void binary_to_text(uint64_t binary, char *text) {
  int i, j;
  char c;

  // Initialize text with leading 0s
  memset(text, '0', BINARY_CHARS);

  // Iterate over binary digits
  for (i = 0; i < BINARY_DIGITS; i++) {
    // Get the ith digit of binary
    c = (binary >> i) & 1;

    // If the digit is 1, append a corresponding character
    if (c == 1) {
      text[i] = '1';
    } else {
      text[i] = '0';
    }
  }

  // Append a null terminator
  text[BINARY_CHARS] = '\0';
}

// Function to convert text to binary
uint64_t text_to_binary(char *text) {
  int i, j;
  uint64_t binary = 0;

  // Iterate over text characters
  for (i = 0; i < BINARY_CHARS; i++) {
    // If the character is a 1, append a corresponding power of 2
    if (text[i] == '1') {
      binary |= (1 << (BINARY_DIGITS - i - 1));
    }
  }

  return binary;
}

int main() {
  // Example usage of the functions
  uint64_t binary = 0b101010101010101;
  char text[BINARY_CHARS];

  binary_to_text(binary, text);
  printf("Binary: %llx\n", binary);
  printf("Text: %s\n", text);

  binary = text_to_binary(text);
  printf("Text: %s\n", text);
  printf("Binary: %llx\n", binary);

  return 0;
}