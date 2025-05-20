//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to sanitize a URL
char *sanitize_url(char *url) {
  // Allocate memory for the sanitized URL
  char *sanitized_url = malloc(strlen(url) + 1);

  // Copy the URL into the sanitized URL
  strcpy(sanitized_url, url);

  // Replace any characters that are not allowed in a URL with an underscore
  for (int i = 0; i < strlen(sanitized_url); i++) {
    if (sanitized_url[i] < 'a' || sanitized_url[i] > 'z' &&
        sanitized_url[i] < 'A' || sanitized_url[i] > 'Z' &&
        sanitized_url[i] < '0' || sanitized_url[i] > '9' &&
        sanitized_url[i] != '-' && sanitized_url[i] != '_' &&
        sanitized_url[i] != '.' && sanitized_url[i] != '/') {
      sanitized_url[i] = '_';
    }
  }

  // Return the sanitized URL
  return sanitized_url;
}

int main() {
  // Romeo's URL
  char *romeo_url = "https://www.example.com/romeo.html";

  // Juliet's URL
  char *juliet_url = "https://www.example.com/juliet.html";

  // Sanitize Romeo's URL
  char *sanitized_romeo_url = sanitize_url(romeo_url);

  // Sanitize Juliet's URL
  char *sanitized_juliet_url = sanitize_url(juliet_url);

  // Print the sanitized URLs
  printf("Romeo's sanitized URL: %s\n", sanitized_romeo_url);
  printf("Juliet's sanitized URL: %s\n", sanitized_juliet_url);

  // Free the memory allocated for the sanitized URLs
  free(sanitized_romeo_url);
  free(sanitized_juliet_url);

  return 0;
}