//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: configurable
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to sanitize a URL string
char *sanitize_url(char *url) {
  // Allocate memory for the sanitized URL
  char *sanitized_url = malloc(strlen(url) + 1);

  // Copy the original URL into the sanitized URL
  strcpy(sanitized_url, url);

  // Replace any unsafe characters with their escaped equivalents
  for (int i = 0; i < strlen(sanitized_url); i++) {
    switch (sanitized_url[i]) {
      case ' ':
        sanitized_url[i] = '%';
        sanitized_url[i + 1] = '2';
        sanitized_url[i + 2] = '0';
        i += 2;
        break;
      case '\'':
        sanitized_url[i] = '%';
        sanitized_url[i + 1] = '2';
        sanitized_url[i + 2] = '7';
        i += 2;
        break;
      case '"':
        sanitized_url[i] = '%';
        sanitized_url[i + 1] = '2';
        sanitized_url[i + 2] = '2';
        i += 2;
        break;
      case '<':
        sanitized_url[i] = '%';
        sanitized_url[i + 1] = '3';
        sanitized_url[i + 2] = 'C';
        i += 2;
        break;
      case '>':
        sanitized_url[i] = '%';
        sanitized_url[i + 1] = '3';
        sanitized_url[i + 2] = 'E';
        i += 2;
        break;
      case '&':
        sanitized_url[i] = '%';
        sanitized_url[i + 1] = '2';
        sanitized_url[i + 2] = '6';
        i += 2;
        break;
    }
  }

  // Return the sanitized URL
  return sanitized_url;
}

int main(int argc, char *argv[]) {
  // Check if the user has provided a URL
  if (argc < 2) {
    printf("Usage: %s <URL>\n", argv[0]);
    return 1;
  }

  // Sanitize the URL
  char *sanitized_url = sanitize_url(argv[1]);

  // Initialize the cURL session
  CURL *curl = curl_easy_init();

  // Set the URL to fetch
  curl_easy_setopt(curl, CURLOPT_URL, sanitized_url);

  // Perform the HTTP request
  CURLcode res = curl_easy_perform(curl);

  // Check if the request was successful
  if (res != CURLE_OK) {
    fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
    return 2;
  }

  // Get the response code
  long response_code;
  curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

  // Print the response code
  printf("Response code: %ld\n", response_code);

  // Cleanup the cURL session
  curl_easy_cleanup(curl);

  // Free the sanitized URL
  free(sanitized_url);

  return 0;
}