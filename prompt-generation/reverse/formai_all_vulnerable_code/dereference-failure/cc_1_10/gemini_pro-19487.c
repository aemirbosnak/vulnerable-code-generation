//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal string to an integer
int hex_to_int(char *hex) {
  int len = strlen(hex);
  int base = 1;
  int val = 0;

  for (int i = len - 1; i >= 0; i--) {
    // Get the digit value
    int digit;
    if (hex[i] >= '0' && hex[i] <= '9') {
      digit = hex[i] - '0';
    } else if (hex[i] >= 'a' && hex[i] <= 'f') {
      digit = hex[i] - 'a' + 10;
    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
      digit = hex[i] - 'A' + 10;
    } else {
      printf("Invalid hexadecimal digit: %c\n", hex[i]);
      return -1;
    }

    // Multiply the digit by the appropriate base and add it to the value
    val += digit * base;
    base *= 16;
  }

  return val;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int num) {
  char *hex = malloc(sizeof(char) * 100);
  int index = 0;

  while (num > 0) {
    // Get the remainder of the division by 16
    int rem = num % 16;

    // Convert the remainder to a hexadecimal digit
    char digit;
    if (rem < 10) {
      digit = rem + '0';
    } else {
      digit = rem - 10 + 'a';
    }

    // Add the digit to the hexadecimal string
    hex[index] = digit;
    index++;

    // Divide the number by 16
    num /= 16;
  }

  // Reverse the hexadecimal string
  char *temp = malloc(sizeof(char) * 100);
  int j = 0;
  for (int i = index - 1; i >= 0; i--) {
    temp[j] = hex[i];
    j++;
  }
  strcpy(hex, temp);
  free(temp);

  return hex;
}

// Main function
int main() {
  // Get the hexadecimal string from the user
  char hex[100];
  printf("Enter a hexadecimal string: ");
  scanf("%s", hex);

  // Convert the hexadecimal string to an integer
  int num = hex_to_int(hex);
  if (num == -1) {
    printf("Invalid hexadecimal string\n");
    return 1;
  }

  // Convert the integer to a hexadecimal string
  char *hex_result = int_to_hex(num);

  // Print the result
  printf("The integer value of the hexadecimal string is: %d\n", num);
  printf("The hexadecimal string of the integer is: %s\n", hex_result);

  free(hex_result);

  return 0;
}