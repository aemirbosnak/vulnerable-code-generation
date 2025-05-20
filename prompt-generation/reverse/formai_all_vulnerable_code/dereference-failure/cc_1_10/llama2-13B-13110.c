//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BINARY_BASE 2
#define BINARY_CHAR '0'
#define OCTAL_CHAR '0'
#define HEXADECIMAL_CHAR '0'

// Function to convert binary to decimal
int binary_to_decimal(char *binary_string) {
  int decimal = 0;
  for (int i = 0; binary_string[i] != '\0'; i++) {
    int digit = binary_string[i] - BINARY_CHAR;
    decimal += (digit * BINARY_BASE);
  }
  return decimal;
}

// Function to convert decimal to binary
char *decimal_to_binary(int decimal) {
  char *binary_string = malloc(sizeof(char) * (log10(decimal) + 1));
  int i = 0;
  while (decimal != 0) {
    binary_string[i] = (decimal % BINARY_BASE) + BINARY_CHAR;
    decimal /= BINARY_BASE;
    i++;
  }
  binary_string[i] = '\0';
  return binary_string;
}

// Function to convert octal to decimal
int octal_to_decimal(char *octal_string) {
  int decimal = 0;
  for (int i = 0; octal_string[i] != '\0'; i++) {
    int digit = octal_string[i] - OCTAL_CHAR;
    decimal += (digit * 8);
  }
  return decimal;
}

// Function to convert decimal to octal
char *decimal_to_octal(int decimal) {
  char *octal_string = malloc(sizeof(char) * (log10(decimal) + 1));
  int i = 0;
  while (decimal != 0) {
    octal_string[i] = (decimal % 8) + OCTAL_CHAR;
    decimal /= 8;
    i++;
  }
  octal_string[i] = '\0';
  return octal_string;
}

// Function to convert hexadecimal to decimal
int hexadecimal_to_decimal(char *hexadecimal_string) {
  int decimal = 0;
  for (int i = 0; hexadecimal_string[i] != '\0'; i++) {
    int digit = hexadecimal_string[i] - HEXADECIMAL_CHAR;
    decimal += (digit * 16);
  }
  return decimal;
}

// Function to convert decimal to hexadecimal
char *decimal_to_hexadecimal(int decimal) {
  char *hexadecimal_string = malloc(sizeof(char) * (log10(decimal) + 1));
  int i = 0;
  while (decimal != 0) {
    hexadecimal_string[i] = (decimal % 16) + HEXADECIMAL_CHAR;
    decimal /= 16;
    i++;
  }
  hexadecimal_string[i] = '\0';
  return hexadecimal_string;
}

int main() {
  char binary_string[] = "1101010";
  int decimal = binary_to_decimal(binary_string);
  char *hexadecimal_string = decimal_to_hexadecimal(decimal);
  printf("Binary: %s\n", binary_string);
  printf("Decimal: %d\n", decimal);
  printf("Hexadecimal: %s\n", hexadecimal_string);

  free(hexadecimal_string);

  return 0;
}