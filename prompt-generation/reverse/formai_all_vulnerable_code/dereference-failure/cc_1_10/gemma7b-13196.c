//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: interoperable
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 1024

char sanitize_input(char **input) {
  char *ptr = *input;
  char output[MAX_LEN];
  int i = 0;
  int flag = 0;

  // Remove leading and trailing whitespace
  while (isspace(*ptr)) {
    ptr++;
  }

  // Convert to uppercase and remove non-alphanumeric characters
  while (*ptr) {
    if (isalnum(*ptr)) {
      output[i++] = toupper(*ptr);
    } else if (!flag) {
      flag = 1;
      printf("Invalid characters detected. Please try again:\n");
      *input = NULL;
      return NULL;
    }
    ptr++;
  }

  // Null terminate the output
  output[i] = '\0';

  // Return the sanitized input
  *input = strdup(output);

  return output;
}

int main() {
  char *input = NULL;
  char *sanitized_input = NULL;

  printf("Enter a string: ");
  getline(&input, MAX_LEN, stdin);

  sanitized_input = sanitize_input(&input);

  if (sanitized_input) {
    printf("Sanitized input: %s\n", sanitized_input);
  }

  return 0;
}