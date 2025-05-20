//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LEN 100

char *sanitize_input(char *input) {
  // Trim leading and trailing whitespace
  size_t input_len = strlen(input);
  while (input_len > 0 && isspace(input[input_len - 1])) {
    input[input_len - 1] = '\0';
    input_len--;
  }
  while (input_len > 0 && isspace(input[0])) {
    input++;
    input_len--;
  }

  // Convert to lowercase
  for (size_t i = 0; i < input_len; i++) {
    input[i] = tolower(input[i]);
  }

  // Remove non-alphanumeric characters
  char *sanitized_input = malloc(input_len + 1);
  size_t sanitized_len = 0;
  for (size_t i = 0; i < input_len; i++) {
    if (isalnum(input[i])) {
      sanitized_input[sanitized_len++] = input[i];
    }
  }
  sanitized_input[sanitized_len] = '\0';

  return sanitized_input;
}

int main() {
  char input[MAX_INPUT_LEN + 1];

  printf("In the irradiated wasteland, enter your tainted words: ");
  fgets(input, MAX_INPUT_LEN + 1, stdin);

  char *sanitized_input = sanitize_input(input);

  printf("Your purified message: %s\n", sanitized_input);
  free(sanitized_input);

  return 0;
}