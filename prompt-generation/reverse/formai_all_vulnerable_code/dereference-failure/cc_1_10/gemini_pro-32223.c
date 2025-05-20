//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: asynchronous
#include <curl/curl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048

typedef struct {
  char *url;
  bool valid;
} URL_INFO;

static void free_url_info(URL_INFO *info) {
  if (info->url) {
    free(info->url);
  }
  free(info);
}

static size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp) {
  URL_INFO *info = (URL_INFO *)userp;
  size_t realsize = size * nmemb;

  if (info->valid) {
    return realsize;
  }

  if (realsize > MAX_URL_LENGTH) {
    info->valid = false;
    return realsize;
  }

  memcpy(info->url, buffer, realsize);
  info->url[realsize] = '\0';

  return realsize;
}

static void sanitize_url(const char *url, URL_INFO *info) {
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if (!curl) {
    info->valid = false;
    return;
  }

  info->url = malloc(MAX_URL_LENGTH + 1);
  if (!info->url) {
    curl_easy_cleanup(curl);
    info->valid = false;
    return;
  }
  info->valid = true;

  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, info);

  res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    info->valid = false;
  }

  curl_easy_cleanup(curl);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <url>\n", argv[0]);
    return EXIT_FAILURE;
  }

  URL_INFO info = {0};
  sanitize_url(argv[1], &info);

  if (info.valid) {
    printf("Sanitized URL: %s\n", info.url);
  } else {
    printf("Invalid URL: %s\n", argv[1]);
  }

  free_url_info(&info);

  return EXIT_SUCCESS;
}