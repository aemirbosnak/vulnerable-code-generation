//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_BINARY_LENGTH 1024

// Function to convert a binary string to an integer
int binary_to_integer(char *binary_string) {
  int integer = 0;
  int length = strlen(binary_string);

  for (int i = 0; i < length; i++) {
    if (binary_string[i] == '1') {
      integer += pow(2, length - i - 1);
    }
  }

  return integer;
}

// Function to convert an integer to a binary string
char *integer_to_binary(int integer) {
  char *binary_string = malloc(MAX_BINARY_LENGTH * sizeof(char));

  int i = 0;
  while (integer > 0) {
    if (integer % 2 == 1) {
      binary_string[i] = '1';
    } else {
      binary_string[i] = '0';
    }
    integer /= 2;
    i++;
  }

  binary_string[i] = '\0';

  return binary_string;
}

int main() {
  // Get the binary string from the user
  char binary_string[MAX_BINARY_LENGTH];
  printf("Enter a binary string: ");
  scanf("%s", binary_string);

  // Convert the binary string to an integer
  int integer = binary_to_integer(binary_string);

  // Print the integer
  printf("The integer is: %d\n", integer);

  // Convert the integer to a binary string
  char *new_binary_string = integer_to_binary(integer);

  // Print the binary string
  printf("The binary string is: %s\n", new_binary_string);

  return 0;
}