//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 2048

#define SAFE_CHARACTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-._~:/?#[]@!$&'()*+,;="

static int is_safe_char(char c)
{
  return strchr(SAFE_CHARACTERS, c) != NULL;
}

static int sanitize_url(char *url)
{
  char *safe_url = malloc(MAX_URL_LENGTH);
  if (!safe_url) {
    return -1;
  }

  int safe_url_len = 0;
  for (char *c = url; *c != '\0'; c++) {
    if (is_safe_char(*c)) {
      safe_url[safe_url_len++] = *c;
    }
  }

  safe_url[safe_url_len] = '\0';

  strcpy(url, safe_url);
  free(safe_url);

  return 0;
}

int main(int argc, char *argv[])
{
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <url>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *url = argv[1];

  if (strlen(url) > MAX_URL_LENGTH) {
    fprintf(stderr, "Error: URL is too long\n");
    return EXIT_FAILURE;
  }

  if (sanitize_url(url) != 0) {
    fprintf(stderr, "Error: Sanitization failed\n");
    return EXIT_FAILURE;
  }

  printf("Sanitized URL: %s\n", url);

  CURL *curl = curl_easy_init();
  if (!curl) {
    fprintf(stderr, "Error: Couldn't initialize curl\n");
    return EXIT_FAILURE;
  }

  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);

  CURLcode res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    fprintf(stderr, "Error: Couldn't perform curl request: %s\n", curl_easy_strerror(res));
    return EXIT_FAILURE;
  }

  curl_easy_cleanup(curl);

  return EXIT_SUCCESS;
}