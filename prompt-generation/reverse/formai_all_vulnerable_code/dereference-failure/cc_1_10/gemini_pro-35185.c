//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Colors for ANSI escape codes
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"

// Function to sanitize user input
char *sanitize_input(char *input) {
  char *sanitized_input = malloc(strlen(input) + 1);
  int i = 0;
  int j = 0;

  while (input[i]) {
    if (input[i] == '<' || input[i] == '>' || input[i] == '&' || input[i] == '"') {
      sanitized_input[j++] = '&';
      sanitized_input[j++] = 'a';
      sanitized_input[j++] = 'm';
      sanitized_input[j++] = 'p';
      sanitized_input[j++] = ';';
    } else {
      sanitized_input[j++] = input[i];
    }
    i++;
  }

  sanitized_input[j] = '\0';

  return sanitized_input;
}

// Main function
int main() {
  char input[100];

  printf(YELLOW "Enter your input: " RESET);
  scanf(" %[^\n]%*c", input);

  char *sanitized_input = sanitize_input(input);

  printf(GREEN "Sanitized input: " RESET);
  printf("%s\n", sanitized_input);

  free(sanitized_input);

  return 0;
}