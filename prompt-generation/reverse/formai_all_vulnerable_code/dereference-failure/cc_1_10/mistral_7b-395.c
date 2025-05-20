//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

// Function to convert a single hexadecimal digit to its decimal value
int hex_digit_to_decimal(char c) {
  if (isdigit(c))
    return c - '0';
  else if (isalpha(c))
    return (isupper(c) ? 10 + (c - 'A') : 14 + (c - 'a'));
  else
    return -1; // Invalid character
}

// Function to convert a hexadecimal string to decimal
unsigned long long hex_string_to_decimal(char *hex_string) {
  unsigned long long result = 0;
  int length = strlen(hex_string);

  // Iterate through each character in the string and convert to decimal
  for (int i = 0; i < length; i++) {
    int digit = hex_digit_to_decimal(hex_string[i]);
    if (digit == -1) {
      fprintf(stderr, "Invalid hexadecimal character '%c' in string '%s'\n", hex_string[i], hex_string);
      exit(EXIT_FAILURE);
    }

    // Multiply the current digit by 16 raised to the power of its position
    result = result * 16 + digit;
  }

  return result;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <hexadecimal_string>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Convert the hexadecimal string to decimal
  unsigned long long decimal = hex_string_to_decimal(argv[1]);

  // Print the result in a introspective style
  printf("You have given me a hexadecimal string: '%s'\n", argv[1]);
  printf("I have pondered its meaning, delved into its depths,\n");
  printf("Explored each character, deciphered its code,\n");
  printf("And now I bring you the result of my labor:\n");
  printf("%llx\n", decimal);
  printf("Isn't it fascinating how we can convert\n");
  printf("From one base to another, revealing hidden patterns,\n");
  printf("Unveiling the secrets that lie beneath the surface?\n");
  printf("Well, I'm just a simple program, but isn't it amazing?\n");

  return EXIT_SUCCESS;
}