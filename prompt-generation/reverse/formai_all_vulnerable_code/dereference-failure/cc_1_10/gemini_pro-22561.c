//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 1024

// Function to sanitize a URL
char *sanitize_url(char *url) {
  // Allocate memory for the sanitized URL
  char *sanitized_url = malloc(MAX_URL_LENGTH);
  if (sanitized_url == NULL) {
    fprintf(stderr, "Error allocating memory for sanitized URL\n");
    return NULL;
  }

  // Copy the original URL into the sanitized URL
  strcpy(sanitized_url, url);

  // Replace all occurrences of "%20" with " "
  char *ptr = sanitized_url;
  while ((ptr = strstr(ptr, "%20")) != NULL) {
    *ptr = ' ';
    ptr++;
  }

  // Replace all occurrences of "+" with " "
  ptr = sanitized_url;
  while ((ptr = strstr(ptr, "+")) != NULL) {
    *ptr = ' ';
    ptr++;
  }

  // Decode any URL-encoded characters
  CURL *curl = curl_easy_init();
  if (curl == NULL) {
    fprintf(stderr, "Error initializing CURL\n");
    free(sanitized_url);
    return NULL;
  }

  curl_easy_setopt(curl, CURLOPT_URL, sanitized_url);
  curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
  CURLcode res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    fprintf(stderr, "Error decoding URL: %s\n", curl_easy_strerror(res));
    curl_easy_cleanup(curl);
    free(sanitized_url);
    return NULL;
  }

  curl_easy_cleanup(curl);

  // Return the sanitized URL
  return sanitized_url;
}

// Main function
int main(int argc, char *argv[]) {
  // Check if a URL was provided
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Sanitize the URL
  char *sanitized_url = sanitize_url(argv[1]);
  if (sanitized_url == NULL) {
    return EXIT_FAILURE;
  }

  // Print the sanitized URL
  printf("Sanitized URL: %s\n", sanitized_url);

  // Free the memory allocated for the sanitized URL
  free(sanitized_url);

  return EXIT_SUCCESS;
}