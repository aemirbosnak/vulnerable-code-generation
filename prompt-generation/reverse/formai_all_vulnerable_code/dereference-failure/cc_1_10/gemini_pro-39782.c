//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal number to an integer
int hex_to_int(char *hex) {
  int len = strlen(hex);
  int base = 1;
  int dec = 0;

  for (int i = len - 1; i >= 0; i--) {
    if (hex[i] >= '0' && hex[i] <= '9') {
      dec += (hex[i] - '0') * base;
    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
      dec += (hex[i] - 'A' + 10) * base;
    } else if (hex[i] >= 'a' && hex[i] <= 'f') {
      dec += (hex[i] - 'a' + 10) * base;
    }
    base *= 16;
  }

  return dec;
}

// Function to convert an integer to a hexadecimal number
char *int_to_hex(int dec) {
  char *hex = malloc(sizeof(char) * 100);
  int i = 0;

  while (dec != 0) {
    int rem = dec % 16;
    if (rem < 10) {
      hex[i++] = rem + '0';
    } else {
      hex[i++] = rem - 10 + 'A';
    }
    dec /= 16;
  }

  hex[i] = '\0';

  // Reverse the string
  char *temp = malloc(sizeof(char) * 100);
  int j = 0;
  for (i = strlen(hex) - 1; i >= 0; i--) {
    temp[j++] = hex[i];
  }
  temp[j] = '\0';

  free(hex);
  return temp;
}

int main() {
  // Get the hexadecimal number from the user
  char hex[100];
  printf("Enter a hexadecimal number: ");
  scanf("%s", hex);

  // Convert the hexadecimal number to an integer
  int dec = hex_to_int(hex);

  // Print the integer
  printf("The integer equivalent of %s is %d\n", hex, dec);

  // Convert the integer back to a hexadecimal number
  char *new_hex = int_to_hex(dec);

  // Print the hexadecimal number
  printf("The hexadecimal equivalent of %d is %s\n", dec, new_hex);

  free(new_hex);
  return 0;
}