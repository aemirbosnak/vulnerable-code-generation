//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

static size_t write_data(char *ptr, size_t size, size_t nmemb, void *stream) {
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}

static int sanitize_url(char *url) {
  // Check for any invalid characters in the URL
  for (int i = 0; i < strlen(url); i++) {
    if (!isalnum(url[i]) && url[i] != '.' && url[i] != '-' && url[i] != '_') {
      return -1;
    }
  }

  // Check for any leading or trailing whitespace
  if (isspace(url[0]) || isspace(url[strlen(url) - 1])) {
    return -1;
  }

  // Check for any double slashes
  if (strstr(url, "//")) {
    return -1;
  }

  // Check for any invalid port numbers
  if (strstr(url, ":") && atoi(strstr(url, ":") + 1) < 0) {
    return -1;
  }

  // Check for any invalid schemes
  if (!strstr(url, "http://") && !strstr(url, "https://")) {
    return -1;
  }

  // Check for any invalid path characters
  for (int i = 0; i < strlen(url); i++) {
    if (url[i] == '/' && url[i + 1] == '/') {
      return -1;
    }
  }

  // Check for any invalid query string characters
  if (strstr(url, "?") && strstr(url, "=") && strstr(url, "&")) {
    return -1;
  }

  // Check for any invalid fragment characters
  if (strstr(url, "#") && strstr(url, "%")) {
    return -1;
  }

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <URL>\n", argv[0]);
    return 1;
  }

  // Sanitize the URL
  if (sanitize_url(argv[1]) == 0) {
    // URL is valid, proceed with the request
    CURL *curl = curl_easy_init();
    if (curl) {
      curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
      curl_easy_perform(curl);
      curl_easy_cleanup(curl);
    }
  } else {
    printf("Invalid URL: %s\n", argv[1]);
    return 1;
  }

  return 0;
}