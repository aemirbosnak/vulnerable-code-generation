//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

// Function to encode a URL
char *url_encode(const char *url) {
  char *encoded_url = NULL;
  CURL *curl = curl_easy_init();
  if (curl) {
    encoded_url = curl_easy_escape(curl, url, 0);
    curl_easy_cleanup(curl);
  }
  return encoded_url;
}

// Function to decode a URL
char *url_decode(const char *url) {
  char *decoded_url = NULL;
  CURL *curl = curl_easy_init();
  if (curl) {
    decoded_url = curl_easy_unescape(curl, url, 0, NULL);
    curl_easy_cleanup(curl);
  }
  return decoded_url;
}

// Function to check if a character is valid in a URL
int is_valid_url_char(char c) {
  return isalpha(c) || isdigit(c) || c == '-' || c == '_' || c == '.' || c == '~';
}

// Function to sanitize a URL
char *url_sanitize(const char *url) {
  char *sanitized_url = malloc(strlen(url) + 1);
  int i, j;
  for (i = 0, j = 0; i < strlen(url); i++) {
    if (is_valid_url_char(url[i])) {
      sanitized_url[j++] = url[i];
    } else {
      char encoded_char[4];
      sprintf(encoded_char, "%%%02X", url[i]);
      strcpy(&sanitized_url[j], encoded_char);
      j += 3;
    }
  }
  sanitized_url[j] = '\0';
  return sanitized_url;
}

int main() {
  // URL to be sanitized
  const char *url = "https://www.example.com/path/to/file?query=string#fragment";

  // Sanitize the URL
  char *sanitized_url = url_sanitize(url);

  // Print the sanitized URL
  printf("Sanitized URL: %s\n", sanitized_url);

  // Free the allocated memory
  free(sanitized_url);

  return 0;
}