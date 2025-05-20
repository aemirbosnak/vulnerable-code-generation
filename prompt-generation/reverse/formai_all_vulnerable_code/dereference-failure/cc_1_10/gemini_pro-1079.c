//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>

#define NUM_THREADS 4
#define MAX_URL_LENGTH 1024
#define MAX_RESPONSE_LENGTH 1024
#define MIN_WAIT_TIME 10
#define MAX_WAIT_TIME 60

typedef struct {
  char url[MAX_URL_LENGTH];
  char response[MAX_RESPONSE_LENGTH];
  bool is_up;
} website_status;

void *monitor_website(void *args) {
  website_status *status = (website_status *)args;
  CURL *curl;
  CURLcode res;
  char error_buffer[CURL_ERROR_SIZE];
  int wait_time;

  // Initialize curl
  curl = curl_easy_init();
  if (!curl) {
    perror("curl_easy_init");
    return NULL;
  }

  // Set curl options
  curl_easy_setopt(curl, CURLOPT_URL, status->url);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, status->response);
  curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, error_buffer);

  // Monitor website
  while (true) {
    // Send request
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform: %s\n", error_buffer);
      status->is_up = false;
    } else {
      status->is_up = true;
    }

    // Sleep for a random amount of time
    wait_time = rand() % (MAX_WAIT_TIME - MIN_WAIT_TIME) + MIN_WAIT_TIME;
    sleep(wait_time);
  }

  // Cleanup curl
  curl_easy_cleanup(curl);
  return NULL;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s <url1> <url2> ... <urln>\n", argv[0]);
    return 1;
  }

  // Create thread pool
  pthread_t threads[NUM_THREADS];

  // Create website status objects
  website_status statuses[argc - 1];
  for (int i = 1; i < argc; i++) {
    strcpy(statuses[i - 1].url, argv[i]);
    statuses[i - 1].is_up = false;
  }

  // Create threads
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threads[i], NULL, monitor_website, &statuses[i]);
  }

  // Wait for threads to finish
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Print results
  for (int i = 0; i < argc - 1; i++) {
    printf("%s: %s\n", statuses[i].url, statuses[i].is_up ? "Up" : "Down");
  }

  return 0;
}