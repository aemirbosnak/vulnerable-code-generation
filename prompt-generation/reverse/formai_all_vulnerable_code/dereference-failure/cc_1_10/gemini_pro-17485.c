//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define SAFE_CHAR_SET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_.~"
#define MAX_URL_LENGTH 2048

char *sanitize_url(const char *url) {
  if (url == NULL) {
    return NULL;
  }

  char *sanitized_url = malloc(MAX_URL_LENGTH);
  if (sanitized_url == NULL) {
    return NULL;
  }

  int i = 0;
  int j = 0;
  while (url[i] != '\0') {
    if (strchr(SAFE_CHAR_SET, url[i]) != NULL) {
      sanitized_url[j++] = url[i];
    } else {
      sanitized_url[j++] = '%';
      char hex[3];
      snprintf(hex, sizeof(hex), "%02X", (unsigned char)url[i]);
      sanitized_url[j++] = hex[0];
      sanitized_url[j++] = hex[1];
    }
    i++;
  }
  sanitized_url[j] = '\0';

  return sanitized_url;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
    return EXIT_FAILURE;
  }

  const char *url = argv[1];

  CURL *curl = curl_easy_init();
  if (curl == NULL) {
    fprintf(stderr, "Error: curl_easy_init() failed\n");
    return EXIT_FAILURE;
  }

  char *sanitized_url = sanitize_url(url);
  if (sanitized_url == NULL) {
    fprintf(stderr, "Error: sanitize_url() failed\n");
    curl_easy_cleanup(curl);
    return EXIT_FAILURE;
  }

  curl_easy_setopt(curl, CURLOPT_URL, sanitized_url);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);

  CURLcode res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    fprintf(stderr, "Error: curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    curl_easy_cleanup(curl);
    free(sanitized_url);
    return EXIT_FAILURE;
  }

  curl_easy_cleanup(curl);
  free(sanitized_url);
  return EXIT_SUCCESS;
}