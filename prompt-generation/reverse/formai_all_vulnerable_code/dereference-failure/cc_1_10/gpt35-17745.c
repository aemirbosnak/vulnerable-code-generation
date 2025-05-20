//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LENGTH 256
#define SLEEP_INTERVAL 30

void check_website(char* url) {
  CURL* curl = curl_easy_init();
  CURLcode response_code;

  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    response_code = curl_easy_perform(curl);

    if(response_code != CURLE_OK) {
      fprintf(stderr, "Error fetching %s: %s\n", url, curl_easy_strerror(response_code));
    }
    else {
      printf("%s is up and running!\n", url);
    }

    curl_easy_cleanup(curl);
  }
}

int main() {
  char urls[][MAX_URL_LENGTH] = {
    "https://www.google.com/",
    "https://www.facebook.com/",
    "https://www.twitter.com/",
    "https://www.instagram.com/"
  };

  int num_urls = sizeof(urls) / sizeof(urls[0]);

  while(1) {
    time_t current_time;
    char* time_string;

    time(&current_time);
    time_string = ctime(&current_time);
    time_string[strlen(time_string) - 1] = '\0';

    printf("[%s] Checking websites\n", time_string);

    for(int i = 0; i < num_urls; i++) {
      check_website(urls[i]);
    }

    printf("Sleeping for %d seconds\n\n", SLEEP_INTERVAL);
    sleep(SLEEP_INTERVAL);
  }

  return 0;
}