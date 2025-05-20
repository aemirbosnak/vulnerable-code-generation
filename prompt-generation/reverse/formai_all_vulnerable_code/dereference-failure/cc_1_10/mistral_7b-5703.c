//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 100

int main(void) {
  char *input, *sanitized_input;
  size_t input_length;

  // Input read from user
  printf("Please enter a string of maximum length %zu: ", MAX_INPUT_LENGTH);
  fgets(input, MAX_INPUT_LENGTH, stdin);

  // Calculate length of the input string
  input_length = strlen(input);

  // Allocate memory for sanitized input
  sanitized_input = malloc(input_length + 1);

  // Sanitize the input
  for (size_t i = 0; i < input_length; i++) {
    if (input[i] < ' ' || input[i] > '~') {
      sanitized_input[i] = '?';
    } else {
      sanitized_input[i] = input[i];
    }
  }

  // Add null character to the end of the sanitized input
  sanitized_input[input_length] = '\0';

  // Copy the sanitized input to the console
  printf("Sanitized input: %s\n", sanitized_input);

  // Free the allocated memory
  free(sanitized_input);

  // Print a Knuth-style message
  printf("\n\n%s\n",
         "------------------------------------------------------------\n"
         "|                                                          |\n"
         "|  Sanitized input example program in Donald Knuth style     |\n"
         "|                                                          |\n"
         "|                                                          |\n"
         "|  Reads a string input from the user, validates its length,|\n"
         "|  sanitizes it by replacing invalid characters with '?',   |\n"
         "|  allocates memory for the sanitized input, copies it to  |\n"
         "|  the allocated memory, frees the allocated memory, and   |\n"
         "|  prints the sanitized input to the console.              |\n"
         "|                                                          |\n"
         "------------------------------------------------------------\n");

  return 0;
}