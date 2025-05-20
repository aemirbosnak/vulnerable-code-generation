//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <regex.h>

// Define the maximum length of the URL
#define MAX_URL_LENGTH 2048

// Define the regular expression pattern for matching valid URLs
#define URL_REGEX "^(http|https)://\\S+$"

// Define the error message for invalid URLs
#define INVALID_URL "Error: Invalid URL provided."

// Function to sanitize the URL
char* sanitize_url(char* url) {
  // Check if the URL is valid
  regex_t regex;
  int reti;

  // Compile the regular expression
  reti = regcomp(&regex, URL_REGEX, REG_EXTENDED);
  if (reti != 0) {
    fprintf(stderr, "Error: Could not compile regular expression.\n");
    return NULL;
  }

  // Match the URL against the regular expression
  reti = regexec(&regex, url, 0, NULL, 0);
  if (reti != 0) {
    fprintf(stderr, "%s\n", INVALID_URL);
    return NULL;
  }

  // URL is valid, so sanitize it by removing any leading or trailing whitespace
  char* sanitized_url = strdup(url);
  if (sanitized_url == NULL) {
    fprintf(stderr, "Error: Could not allocate memory for sanitized URL.\n");
    return NULL;
  }

  // Trim leading whitespace
  while (*sanitized_url == ' ') {
    sanitized_url++;
  }

  // Trim trailing whitespace
  int len = strlen(sanitized_url);
  while (len > 0 && sanitized_url[len - 1] == ' ') {
    len--;
  }
  sanitized_url[len] = '\0';

  // Return the sanitized URL
  return sanitized_url;
}

int main(int argc, char* argv[]) {
  // Check if the user has provided a URL
  if (argc != 2) {
    fprintf(stderr, "Error: Please provide a URL as an argument.\n");
    return EXIT_FAILURE;
  }

  // Get the URL from the user
  char* url = argv[1];

  // Sanitize the URL
  char* sanitized_url = sanitize_url(url);
  if (sanitized_url == NULL) {
    return EXIT_FAILURE;
  }

  // Print the sanitized URL
  printf("Sanitized URL: %s\n", sanitized_url);

  // Free the memory allocated for the sanitized URL
  free(sanitized_url);

  return EXIT_SUCCESS;
}