//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare our trusty URL sanitizer function
char *sanitize(char *url);

int main() {
  // We're off on an adventure to sanitize URLs!

  // Let's prepare some URLs to test our sanitizer on
  char *urls[] = {
    "http://example.com/path/with/encoded%20spaces",
    "https://google.com?q=special+characters+%23&%24",
    "ftp://ftp.mozilla.org/pub/firefox/releases/latest/source/",
    "mailto:info@example.com",
    "tel:+1-555-123-4567"
  };

  // Let's embark on our sanitizing journey!
  for (int i = 0; i < sizeof(urls) / sizeof(char *); i++) {
    // Observe how we adorn our URL with a shield of safety
    char *sanitized_url = sanitize(urls[i]);

    // Behold the glory of our sanitized URL!
    printf("Sanitized URL: %s\n", sanitized_url);

    // We'll be kind and tidy up after ourselves
    free(sanitized_url);
  }

  // Mission accomplished! URL sanitation complete!
  return 0;
}

// The heart of our sanitization quest
char *sanitize(char *url) {
  // Get ready for some URL-scrubbing magic!

  // Start with a clean slate
  char *sanitized_url = malloc(strlen(url) + 1);
  strcpy(sanitized_url, url);

  // Now, let's remove any pesky spaces
  int new_len = 0;
  for (int i = 0; i < strlen(url); i++) {
    if (url[i] != ' ') {
      sanitized_url[new_len++] = url[i];
    }
  }
  sanitized_url[new_len] = '\0';

  // We're not done yet! Let's banish any lingering special characters
  for (int i = 0; i < strlen(sanitized_url); i++) {
    if (sanitized_url[i] == '%' || sanitized_url[i] == '+' || sanitized_url[i] == '#') {
      sanitized_url[i] = '_';
    }
  }

  // Return our cleansed and sanitized URL
  return sanitized_url;
}