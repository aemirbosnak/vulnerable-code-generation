//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

#define MAX_URLS 100
#define TIMEOUT 10

char *urls[MAX_URLS];
int num_urls = 0;

void add_url(char *url) {
  if (num_urls >= MAX_URLS) {
    printf("Error: Too many URLs. Maximum is %d.\n", MAX_URLS);
    return;
  }

  urls[num_urls] = malloc(strlen(url) + 1);
  strcpy(urls[num_urls], url);
  num_urls++;
}

int check_url(char *url) {
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    if (res == CURLE_OK) {
      return 1;
    }
  }

  return 0;
}

int main() {
  int i;

  add_url("http://example.com");
  add_url("http://www.google.com");
  add_url("http://www.facebook.com");

  for (i = 0; i < num_urls; i++) {
    if (check_url(urls[i])) {
      printf("URL %s is up.\n", urls[i]);
    } else {
      printf("URL %s is down.\n", urls[i]);
    }
  }

  return 0;
}