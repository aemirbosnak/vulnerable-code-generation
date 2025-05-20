//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Custom error handling function
void error_handler(CURLcode code, const char* func, const char* url) {
  printf("Error: %s (%d) while accessing %s\n", curl_easy_strerror(code), code, url);
  exit(1);
}

// Custom URL sanitizer function
char* sanitize_url(const char* url) {
  // Allocate memory for the sanitized URL
  char* sanitized_url = malloc(strlen(url) + 1);
  if (!sanitized_url) {
    error_handler(CURLE_OUT_OF_MEMORY, "malloc", url);
  }

  // Copy the URL into the sanitized buffer
  strcpy(sanitized_url, url);

  // Replace any invalid characters with underscores
  char* invalid_chars = "<>\"'";
  for (char* c = sanitized_url; *c != '\0'; c++) {
    if (strchr(invalid_chars, *c)) {
      *c = '_';
    }
  }

  // Return the sanitized URL
  return sanitized_url;
}

int main(int argc, char** argv) {
  // Initialize the CURL library
  curl_global_init(CURL_GLOBAL_ALL);

  // Get the URL from the user
  if (argc != 2) {
    printf("Usage: %s <url>\n", argv[0]);
    return 1;
  }
  const char* url = argv[1];

  // Sanitize the URL
  char* sanitized_url = sanitize_url(url);

  // Create a CURL handle
  CURL* handle = curl_easy_init();
  if (!handle) {
    error_handler(CURLE_FAILED_INIT, "curl_easy_init", url);
  }

  // Set the URL to fetch
  curl_easy_setopt(handle, CURLOPT_URL, sanitized_url);

  // Set the error handling function
  curl_easy_setopt(handle, CURLOPT_ERRORBUFFER, error_handler);

  // Perform the request
  CURLcode res = curl_easy_perform(handle);
  if (res != CURLE_OK) {
    error_handler(res, "curl_easy_perform", url);
  }

  // Cleanup the CURL handle
  curl_easy_cleanup(handle);

  // Free the sanitized URL
  free(sanitized_url);

  // Cleanup the CURL library
  curl_global_cleanup();

  return 0;
}