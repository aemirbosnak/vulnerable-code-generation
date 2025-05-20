//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: Linus Torvalds
// Linus Torvalds style C URL Sanitizer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>

// Some definitions
#define MAX_URL_LEN 1024
#define SAFE_CHARACTERS "!~-._"

// Okay, let's get started.
// We want to make sure the URL is safe, so we'll
// start by checking if it contains any unsafe characters.
int is_url_safe(const char* url) {
  // Check each character in the URL.
  for (int i = 0; i < strlen(url); i++) {
    // If the character is not safe, return 0.
    if (strchr(SAFE_CHARACTERS, url[i]) == NULL) {
      return 0;
    }
  }

  // If all characters are safe, return 1.
  return 1;
}

// Now we need to sanitize the URL.
// We'll do this by replacing any unsafe characters with a safe character.
void sanitize_url(char* url) {
  // Check each character in the URL.
  for (int i = 0; i < strlen(url); i++) {
    // If the character is not safe, replace it with a safe character.
    if (strchr(SAFE_CHARACTERS, url[i]) == NULL) {
      url[i] = '_';
    }
  }
}

// Finally, let's test our code.
int main(int argc, char** argv) {
  // Check if the URL was provided.
  if (argc != 2) {
    printf("Usage: %s <url>\n", argv[0]);
    return 1;
  }

  // Get the URL from the command line.
  char* url = argv[1];

  // Check if the URL is safe.
  if (is_url_safe(url)) {
    printf("The URL is safe.\n");
  } else {
    printf("The URL is not safe.\n");

    // Sanitize the URL.
    sanitize_url(url);

    // Print the sanitized URL.
    printf("The sanitized URL is: %s\n", url);
  }

  return 0;
}