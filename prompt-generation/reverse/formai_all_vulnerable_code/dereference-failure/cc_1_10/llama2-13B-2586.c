//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: mathematical
#include <stdio.h>
#include <stdint.h>
#include <math.h>

// Define the base and number systems
#define BASE 2
#define N_SYSTEMS 3

// Define the number of bits in each system
#define BITS_PER_SYSTEM [N_SYSTEMS] = {8, 16, 32}

// Define the number of possible values in each system
#define VALUE_RANGE [N_SYSTEMS] = {1, 2^8, 2^16, 2^32}

// Define the conversion functions
void binary_to_decimal(uint32_t binary, int32_t *decimal) {
  int32_t temp = 0;
  for (int i = 0; i < 32; i++) {
    temp *= BASE;
    temp += (binary >> i) & 1;
  }
  *decimal = temp;
}

void decimal_to_binary(int32_t decimal, uint32_t *binary) {
  uint32_t temp = 0;
  while (decimal != 0) {
    temp *= BASE;
    temp += (decimal % BASE);
    decimal /= BASE;
    binary[2] = (temp >> 32) & 1;
    binary[1] = (temp >> 16) & 1;
    binary[0] = (temp >> 0) & 1;
  }
}

int main() {
  int32_t decimal;
  uint32_t binary;

  // Test cases
  decimal = 5;
  binary = 0;
  binary_to_decimal(binary, &decimal);
  printf("5 in decimal is %d\n", decimal);

  decimal = 10;
  binary = 0;
  binary_to_decimal(binary, &decimal);
  printf("10 in decimal is %d\n", decimal);

  decimal = 15;
  binary = 0;
  binary_to_decimal(binary, &decimal);
  printf("15 in decimal is %d\n", decimal);

  // Convert binary to decimal
  binary = 0b101010;
  decimal = 0;
  binary_to_decimal(binary, &decimal);
  printf("0b101010 in binary is %d in decimal\n", decimal);

  // Convert decimal to binary
  decimal = 17;
  binary = 0;
  decimal_to_binary(decimal, &binary);
  printf("17 in decimal is %0b\n", binary);

  return 0;
}