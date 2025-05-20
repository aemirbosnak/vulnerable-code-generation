//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A mind-bending array of characters
char* mind_bender = "((((())))))((((())(()()(()()()(()))()()()()))))()())()(((((()())(()()())())()()()(())())()()(()()()(()()(()()()()()(()())(()()(()(())())";

// A function to sanitize user input
char* sanitize(char* input) {
  char* sanitized = malloc(strlen(input) + 1);
  int i, j;
  for (i = 0, j = 0; input[i] != '\0'; i++) {
    if (input[i] >= 'a' && input[i] <= 'z') {
      sanitized[j++] = input[i];
    } else if (input[i] >= 'A' && input[i] <= 'Z') {
      sanitized[j++] = input[i];
    } else if (input[i] >= '0' && input[i] <= '9') {
      sanitized[j++] = input[i];
    } else if (input[i] == ' ') {
      sanitized[j++] = input[i];
    }
  }
  sanitized[j] = '\0';
  return sanitized;
}

// A function to demonstrate the sanitizer
void demonstrate(char* input) {
  printf("Input: %s\n", input);
  char* sanitized = sanitize(input);
  printf("Sanitized: %s\n", sanitized);
  free(sanitized);
}

// The main function
int main() {
  // Get user input
  char* input = malloc(1024);
  printf("Enter your input: ");
  scanf("%s", input);

  // Sanitize the input
  char* sanitized = sanitize(input);

  // Print the original and sanitized input
  printf("Original: %s\n", input);
  printf("Sanitized: %s\n", sanitized);

  // Free the allocated memory
  free(input);
  free(sanitized);

  return 0;
}