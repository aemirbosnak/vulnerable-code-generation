//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our trusty assistant, the URL sanitizer
void sanitizeURL(char *url) {
  // Remove any leading or trailing whitespace
  while (*url == ' ') url++;
  while (url[strlen(url) - 1] == ' ') url[strlen(url) - 1] = '\0';

  // Replace any instances of " " with "%20"
  char *ptr = strstr(url, " ");
  while (ptr != NULL) {
    *ptr++ = '%';
    *ptr++ = '2';
    *ptr++ = '0';
  }

  // Replace any instances of "&" with "%26"
  ptr = strstr(url, "&");
  while (ptr != NULL) {
    *ptr++ = '%';
    *ptr++ = '2';
    *ptr++ = '6';
  }

  // Replace any instances of "=" with "%3D"
  ptr = strstr(url, "=");
  while (ptr != NULL) {
    *ptr++ = '%';
    *ptr++ = '3';
    *ptr++ = 'D';
  }

  // And finally, replace any instances of "?" with "%3F"
  ptr = strstr(url, "?");
  while (ptr != NULL) {
    *ptr++ = '%';
    *ptr++ = '3';
    *ptr++ = 'F';
  }
}

int main() {
  // Our suspect, the URL to be sanitized
  char *url = "http://www.example.com/path/to/file.html?param=value space";

  // Let us examine the URL and sanitize it
  printf("Unsanitized URL: %s\n", url);
  sanitizeURL(url);
  printf("Sanitized URL: %s\n", url);

  return 0;
}