//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert a hexadecimal number to an integer
int hex_to_int(char *hex) {
  int len = strlen(hex);
  int base = 1;
  int dec = 0;
  for (int i = len - 1; i >= 0; i--) {
    if (isdigit(hex[i]))
      dec += (hex[i] - '0') * base;
    else if (isupper(hex[i]))
      dec += (hex[i] - 'A' + 10) * base;
    else
      dec += (hex[i] - 'a' + 10) * base;
    base *= 16;
  }
  return dec;
}

// Function to convert an integer to a hexadecimal number
char *int_to_hex(int num) {
  char *hex = (char *)malloc(50);
  int i = 0;
  while (num != 0) {
    int temp = num % 16;
    if (temp < 10)
      hex[i++] = temp + '0';
    else
      hex[i++] = temp + 'A' - 10;
    num /= 16;
  }
  hex[i] = '\0';
  return hex;
}

int main() {
  // Get the hexadecimal number from the user
  char hex[50];
  printf("Enter a hexadecimal number: ");
  gets(hex);

  // Convert the hexadecimal number to an integer
  int dec = hex_to_int(hex);

  // Print the integer
  printf("Integer: %d\n", dec);

  // Convert the integer to a hexadecimal number
  char *new_hex = int_to_hex(dec);

  // Print the hexadecimal number
  printf("Hexadecimal: %s\n", new_hex);

  return 0;
}