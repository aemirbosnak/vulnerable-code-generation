//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: Claude Shannon
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BITS 64

static uint64_t binary_to_decimal(const char *binary) {
  uint64_t decimal = 0;
  for (int i = 0; binary[i] != '\0'; i++) {
    if (binary[i] == '1') {
      decimal |= (1ULL << (strlen(binary) - 1 - i));
    }
  }
  return decimal;
}

static char *decimal_to_binary(uint64_t decimal) {
  char *binary = malloc(MAX_BITS + 1);
  for (int i = 0; i < MAX_BITS; i++) {
    binary[i] = (decimal & (1ULL << (MAX_BITS - 1 - i))) ? '1' : '0';
  }
  binary[MAX_BITS] = '\0';
  return binary;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <binary or decimal number>\n", argv[0]);
    return EXIT_FAILURE;
  }

  bool is_binary = true;
  for (int i = 0; argv[1][i] != '\0'; i++) {
    if (argv[1][i] < '0' || argv[1][i] > '9') {
      is_binary = false;
      break;
    }
  }

  if (is_binary) {
    uint64_t decimal = binary_to_decimal(argv[1]);
    printf("%llu\n", decimal);
  } else {
    char *binary = decimal_to_binary(atoi(argv[1]));
    printf("%s\n", binary);
    free(binary);
  }

  return EXIT_SUCCESS;
}