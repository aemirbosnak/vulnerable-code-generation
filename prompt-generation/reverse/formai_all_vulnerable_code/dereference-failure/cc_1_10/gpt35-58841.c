//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* to_hex(int decimal);

int main() {
  int decimalNumber;

  printf("Enter the decimal number to convert to hexadecimal: ");
  scanf("%d", &decimalNumber);

  char* hexNumber = to_hex(decimalNumber);

  printf("The hexadecimal number is: %s\n", hexNumber);

  free(hexNumber);

  return 0;
}

char* to_hex(int decimal) {
  char* hex = (char*) malloc(100);
  char* digits = "0123456789ABCDEF";

  if(decimal == 0) {
    strcpy(hex, "0");
    return hex;
  }

  int remainder, quotient = decimal;
  int index = 0;

  while(quotient > 0) {
    remainder = quotient % 16;
    hex[index++] = digits[remainder];
    quotient /= 16;
  }

  hex[index] = '\0';

  char* reversedHex = (char*) malloc(strlen(hex) + 1);

  for(int i = 0; i < strlen(hex); i++) {
    reversedHex[i] = hex[strlen(hex) - i - 1];
  }

  reversedHex[strlen(hex)] = '\0';

  free(hex);

  return reversedHex;
}