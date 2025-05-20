//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

char *sanitize_url(char *url) {
  // Initialize the sanitization process.
  CURL *curl = curl_easy_init();
  if (!curl) {
    fprintf(stderr, "Error initializing CURL.\n");
    return NULL;
  }

  // Set the URL to be sanitized.
  curl_easy_setopt(curl, CURLOPT_URL, url);

  // Perform the sanitization process.
  CURLcode res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    fprintf(stderr, "Error sanitizing URL: %s\n", curl_easy_strerror(res));
    curl_easy_cleanup(curl);
    return NULL;
  }

  // Retrieve the sanitized URL.
  char *sanitized_url;
  curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &sanitized_url);

  // Clean up the CURL resources.
  curl_easy_cleanup(curl);

  // Return the sanitized URL.
  return sanitized_url;
}

int main() {
  // Define the input URL.
  char *url = "http://example.com/page.html?param=value";

  // Sanitize the input URL.
  char *sanitized_url = sanitize_url(url);
  if (!sanitized_url) {
    fprintf(stderr, "Error sanitizing URL.\n");
    return EXIT_FAILURE;
  }

  // Print the sanitized URL.
  printf("Sanitized URL: %s\n", sanitized_url);

  // Free the allocated memory.
  free(sanitized_url);

  return EXIT_SUCCESS;
}