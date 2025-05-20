//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 10
#define MAX_URL_LENGTH 2048

sem_t sem;

typedef struct {
  char *url;
  char *sanitized_url;
} url_data;

void *sanitize_url(void *arg) {
  url_data *data = (url_data *)arg;

  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if (!curl) {
    sem_post(&sem);
    fprintf(stderr, "curl_easy_init() failed\n");
    pthread_exit(NULL);
  }

  curl_easy_setopt(curl, CURLOPT_URL, data->url);
  curl_easy_setopt(curl, CURLOPT_NOBODY, 1);

  res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    sem_post(&sem);
    fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    pthread_exit(NULL);
  }

  long response_code;
  curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

  if (response_code >= 400) {
    sem_post(&sem);
    fprintf(stderr, "URL %s is not valid\n", data->url);
    pthread_exit(NULL);
  }

  char *url;
  curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);

  data->sanitized_url = strdup(url);

  sem_post(&sem);
  pthread_exit(NULL);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <url>\n", argv[0]);
    return EXIT_FAILURE;
  }

  //  Initialize semaphore
  sem_init(&sem, 0, 0);

  // Initialize threads
  pthread_t threads[NUM_THREADS];

  for (int i = 0; i < NUM_THREADS; i++) {
    url_data *data = malloc(sizeof(url_data));
    data->url = argv[1];

    pthread_create(&threads[i], NULL, sanitize_url, data);
  }

  for (int i = 0; i < NUM_THREADS; i++) {
    sem_wait(&sem);
  }

  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  //  Cleanup semaphore
  sem_destroy(&sem);

  return EXIT_SUCCESS;
}