//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: interoperable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Function to check if a character is a valid URL character
bool is_valid_url_char(char c) {
  return (isalnum(c) || c == '.' || c == '/' || c == '-' || c == '_');
}

// Function to sanitize a URL
char *sanitize_url(const char *input) {
  // Allocate memory for the sanitized URL
  char *sanitized = malloc(strlen(input) + 1);

  // Copy the sanitized URL into the allocated memory
  int j = 0;
  for (int i = 0; i < strlen(input); i++) {
    if (is_valid_url_char(input[i])) {
      sanitized[j++] = input[i];
    }
  }
  sanitized[j] = '\0';

  // Return the sanitized URL
  return sanitized;
}

// Function to test the URL sanitizer
int main() {
  // Test case 1: Valid URL
  char *valid_url = "https://www.example.com";
  char *sanitized_url = sanitize_url(valid_url);
  printf("Original URL: %s\n", valid_url);
  printf("Sanitized URL: %s\n", sanitized_url);

  // Test case 2: Invalid URL with spaces
  char *invalid_url_with_spaces = "https://www.example.com with spaces";
  sanitized_url = sanitize_url(invalid_url_with_spaces);
  printf("Original URL: %s\n", invalid_url_with_spaces);
  printf("Sanitized URL: %s\n", sanitized_url);

  // Test case 3: Invalid URL with special characters
  char *invalid_url_with_special_chars = "https://www.example.com/&#$";
  sanitized_url = sanitize_url(invalid_url_with_special_chars);
  printf("Original URL: %s\n", invalid_url_with_special_chars);
  printf("Sanitized URL: %s\n", sanitized_url);

  // Free the allocated memory
  free(sanitized_url);

  return 0;
}