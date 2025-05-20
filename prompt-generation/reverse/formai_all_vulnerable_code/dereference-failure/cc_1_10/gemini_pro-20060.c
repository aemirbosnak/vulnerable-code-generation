//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <regex.h>

// Define the maximum length of a URL
#define MAX_URL_LENGTH 2048

// Define the regular expression pattern for a valid URL
#define URL_PATTERN "^(https?|ftp|file)://[-a-zA-Z0-9+&@#/%?=~_|!:,.;]*[-a-zA-Z0-9+&@#/%=~_|]"

// Function to sanitize a URL
char *sanitize_url(char *url) {
  // Check if the URL is valid
  regex_t regex;
  int reti;
  if (regcomp(&regex, URL_PATTERN, REG_EXTENDED) != 0) {
    fprintf(stderr, "Could not compile the regular expression.\n");
    return NULL;
  }
  reti = regexec(&regex, url, 0, NULL, 0);
  regfree(&regex);
  if (reti != 0) {
    fprintf(stderr, "The URL is not valid.\n");
    return NULL;
  }

  // Create a new buffer to store the sanitized URL
  char *sanitized_url = malloc(MAX_URL_LENGTH);
  if (sanitized_url == NULL) {
    fprintf(stderr, "Could not allocate memory for the sanitized URL.\n");
    return NULL;
  }

  // Copy the valid characters from the URL to the sanitized URL
  int i = 0;
  int j = 0;
  while (url[i] != '\0') {
    if (isalnum(url[i]) || strchr(".-_~", url[i]) != NULL) {
      sanitized_url[j++] = url[i];
    }
    i++;
  }

  // Terminate the sanitized URL
  sanitized_url[j] = '\0';

  // Return the sanitized URL
  return sanitized_url;
}

// Main function
int main(int argc, char **argv) {
  // Check if the user has provided a URL
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <url>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Sanitize the URL
  char *sanitized_url = sanitize_url(argv[1]);
  if (sanitized_url == NULL) {
    return EXIT_FAILURE;
  }

  // Print the sanitized URL
  printf("%s\n", sanitized_url);

  // Free the memory allocated for the sanitized URL
  free(sanitized_url);

  return EXIT_SUCCESS;
}