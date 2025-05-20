//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: scalable
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 1024

// Function to encode a URL
char *encode_url(char *url) {
  int len = strlen(url);
  char *encoded_url = malloc(len * 3);  // Allocate enough space for worst-case scenario
  CURL *curl = curl_easy_init();
  if (!curl) {
    return NULL;
  }
  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, encoded_url);
  curl_easy_perform(curl);
  curl_easy_cleanup(curl);

  return encoded_url;
}

// Function to sanitize a URL
char *sanitize_url(char *url) {
  // 1. Remove leading and trailing whitespace
  char *trimmed_url = strdup(url);  // Make a copy since we'll be modifying it
  int start = 0;
  int end = strlen(trimmed_url) - 1;
  while (trimmed_url[start] == ' ') {
    start++;
  }
  while (trimmed_url[end] == ' ') {
    end--;
  }
  trimmed_url[start] = '\0';
  trimmed_url = &trimmed_url[start];

  // 2. Encode any unsafe characters
  char *encoded_url = encode_url(trimmed_url);
  free(trimmed_url);

  // 3. Validate the URL
  CURL *curl = curl_easy_init();
  if (!curl) {
    free(encoded_url);
    return NULL;
  }
  curl_easy_setopt(curl, CURLOPT_URL, encoded_url);
  CURLcode res = curl_easy_perform(curl);
  curl_easy_cleanup(curl);

  if (res != CURLE_OK) {
    free(encoded_url);
    return NULL;
  }

  // 4. Return the sanitized URL
  return encoded_url;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *url = argv[1];
  if (strlen(url) > MAX_URL_LENGTH) {
    fprintf(stderr, "URL too long (max length: %d)\n", MAX_URL_LENGTH);
    return EXIT_FAILURE;
  }

  char *sanitized_url = sanitize_url(url);
  if (!sanitized_url) {
    fprintf(stderr, "Failed to sanitize URL\n");
    return EXIT_FAILURE;
  }

  printf("Sanitized URL: %s\n", sanitized_url);
  free(sanitized_url);

  return EXIT_SUCCESS;
}