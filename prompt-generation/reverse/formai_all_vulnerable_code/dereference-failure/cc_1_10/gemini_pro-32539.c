//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <curl/curl.h>
#include <curl/easy.h>

#define HTTP_OK 200
#define HTTP_CREATED 201

#define MAX_URL_LENGTH 1024
#define MAX_BUFFER_LENGTH 1024

static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
  size_t len = size * nmemb;
  char *buffer = (char *)userp;

  if (buffer) {
    if (len < MAX_BUFFER_LENGTH) {
      memcpy(buffer, contents, len);
      buffer[len] = '\0';
    } else {
      printf("Buffer too small, truncating response");
      memcpy(buffer, contents, MAX_BUFFER_LENGTH - 1);
      buffer[MAX_BUFFER_LENGTH - 1] = '\0';
    }
  }

  return len;
}

int main(int argc, char *argv[]) {
  char url[MAX_URL_LENGTH];
  char buffer[MAX_BUFFER_LENGTH];
  CURL *curl;
  CURLcode res;

  if (argc < 2) {
    printf("Usage: %s <URL>\n", argv[0]);
    return EXIT_FAILURE;
  }

  strncpy(url, argv[1], MAX_URL_LENGTH - 1);

  curl = curl_easy_init();
  if (!curl) {
    printf("Failed to initialize CURL");
    return EXIT_FAILURE;
  }

  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer);

  res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    printf("Failed to send HTTP request: %s", curl_easy_strerror(res));
    curl_easy_cleanup(curl);
    return EXIT_FAILURE;
  }

  long http_code;
  curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
  if (http_code != HTTP_OK && http_code != HTTP_CREATED) {
    printf("HTTP error: %ld", http_code);
    curl_easy_cleanup(curl);
    return EXIT_FAILURE;
  }

  printf("HTTP response:\n%s", buffer);

  curl_easy_cleanup(curl);

  return EXIT_SUCCESS;
}