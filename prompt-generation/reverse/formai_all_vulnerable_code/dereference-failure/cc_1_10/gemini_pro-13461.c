//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to convert hexadecimal to decimal
int hex_to_dec(char *hex) {
  int len = strlen(hex);
  int base = 1;
  int dec = 0;

  for (int i = len - 1; i >= 0; i--) {
    if (hex[i] >= '0' && hex[i] <= '9') {
      dec += (hex[i] - '0') * base;
      base *= 16;
    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
      dec += (hex[i] - 'A' + 10) * base;
      base *= 16;
    } else if (hex[i] >= 'a' && hex[i] <= 'f') {
      dec += (hex[i] - 'a' + 10) * base;
      base *= 16;
    }
  }

  return dec;
}

// Function to convert decimal to hexadecimal
char *dec_to_hex(int dec) {
  char *hex = malloc(MAX_SIZE);
  int i = 0;

  while (dec != 0) {
    int remainder = dec % 16;
    if (remainder < 10) {
      hex[i++] = remainder + '0';
    } else {
      hex[i++] = remainder - 10 + 'A';
    }
    dec /= 16;
  }

  hex[i] = '\0';

  // Reverse the string
  int len = strlen(hex);
  for (int j = 0; j < len / 2; j++) {
    char temp = hex[j];
    hex[j] = hex[len - j - 1];
    hex[len - j - 1] = temp;
  }

  return hex;
}

int main() {
  char hex[MAX_SIZE];
  int dec;

  printf("Enter a hexadecimal number: ");
  scanf("%s", hex);

  dec = hex_to_dec(hex);

  printf("%s in decimal is %d\n", hex, dec);

  char *new_hex = dec_to_hex(dec);

  printf("%d in hexadecimal is %s\n", dec, new_hex);

  free(new_hex);

  return 0;
}