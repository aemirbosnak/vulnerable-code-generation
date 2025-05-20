//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sherlock's URL Sanitizer
char *sanitize_url(char *url) {
  // Remove any potential anchor tags
  char *anchor_pos = strchr(url, '#');
  if (anchor_pos) *anchor_pos = '\0';

  // Remove any potential query strings
  char *query_pos = strchr(url, '?');
  if (query_pos) *query_pos = '\0';

  // Escape any potentially dangerous characters
  char *escaped_url = malloc(strlen(url) * 3 + 1); // +3 for % encoding
  int escaped_len = 0;
  for (int i = 0; i < strlen(url); i++) {
    char c = url[i];
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') ||
        c == '/' || c == '.' || c == '-' || c == '_') {
      escaped_url[escaped_len++] = c;
    } else {
      escaped_len += sprintf(escaped_url + escaped_len, "%%%02X", c);
    }
  }
  escaped_url[escaped_len++] = '\0'; // Null-terminate

  return escaped_url;
}

// Demonstrate Sherlock's URL Sanitizer
int main() {
  // Example URLs with potential vulnerabilities
  char *vulnerable_urls[] = {
    "https://www.example.com/malicious.php?param=1#anchor",
    "https://www.example.com/insecure&query=string",
    "https://www.example.com/%3Cscript%3Ealert('xss')%3C/script%3E"
  };

  for (int i = 0; i < 3; i++) {
    char *url = vulnerable_urls[i];
    printf("Original URL: %s\n", url);

    // Sanitize the URL
    char *sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);

    // Free the allocated memory
    free(sanitized_url);
  }

  return 0;
}