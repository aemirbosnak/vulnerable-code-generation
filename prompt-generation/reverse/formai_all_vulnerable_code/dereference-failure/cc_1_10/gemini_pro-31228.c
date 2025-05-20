//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string contains only alphanumeric characters
int is_alphanumeric(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isalnum(str[i])) {
      return 0;
    }
  }
  return 1;
}

// Function to check if a string is a valid integer
int is_integer(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isdigit(str[i])) {
      return 0;
    }
  }
  return 1;
}

// Function to check if a string is a valid float
int is_float(char *str) {
  int dot_count = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isdigit(str[i]) && str[i] != '.') {
      return 0;
    }
    if (str[i] == '.') {
      dot_count++;
    }
  }
  return dot_count == 1;
}

// Function to sanitize user input
char *sanitize_input(char *input) {
  // Trim leading and trailing whitespace
  while (isspace(*input)) {
    input++;
  }
  while (isspace(input[strlen(input) - 1])) {
    input[strlen(input) - 1] = '\0';
  }

  // Remove any non-alphanumeric characters
  char *sanitized_input = malloc(strlen(input) + 1);
  int j = 0;
  for (int i = 0; input[i] != '\0'; i++) {
    if (isalnum(input[i])) {
      sanitized_input[j] = input[i];
      j++;
    }
  }
  sanitized_input[j] = '\0';

  return sanitized_input;
}

int main() {
  char input[100];
  printf("Enter a string: ");
  fgets(input, sizeof(input), stdin);

  char *sanitized_input = sanitize_input(input);

  // Check if the sanitized input is alphanumeric
  if (is_alphanumeric(sanitized_input)) {
    printf("The sanitized input is alphanumeric.\n");
  } else {
    printf("The sanitized input is not alphanumeric.\n");
  }

  // Check if the sanitized input is an integer
  if (is_integer(sanitized_input)) {
    printf("The sanitized input is an integer.\n");
  } else {
    printf("The sanitized input is not an integer.\n");
  }

  // Check if the sanitized input is a float
  if (is_float(sanitized_input)) {
    printf("The sanitized input is a float.\n");
  } else {
    printf("The sanitized input is not a float.\n");
  }

  free(sanitized_input);

  return 0;
}