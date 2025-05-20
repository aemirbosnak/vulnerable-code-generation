//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: asynchronous
#include <curl/curl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  CURL *curl;
  char *url;
} curl_thread_data;

void *curl_thread(void *arg) {
  curl_thread_data *data = (curl_thread_data *)arg;

  CURLcode res = curl_easy_perform(data->curl);
  if (res != CURLE_OK) {
    fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    return NULL;
  }

  curl_easy_cleanup(data->curl);
  free(data->url);
  free(data);

  return NULL;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
    return EXIT_FAILURE;
  }

  pthread_t tid;
  curl_thread_data *data = malloc(sizeof(curl_thread_data));
  if (!data) {
    perror("malloc() failed");
    return EXIT_FAILURE;
  }

  data->url = strdup(argv[1]);
  if (!data->url) {
    perror("strdup() failed");
    free(data);
    return EXIT_FAILURE;
  }

  data->curl = curl_easy_init();
  if (!data->curl) {
    fprintf(stderr, "curl_easy_init() failed\n");
    free(data->url);
    free(data);
    return EXIT_FAILURE;
  }

  curl_easy_setopt(data->curl, CURLOPT_URL, data->url);
  curl_easy_setopt(data->curl, CURLOPT_WRITEFUNCTION, NULL);

  int res = pthread_create(&tid, NULL, curl_thread, data);
  if (res != 0) {
    fprintf(stderr, "pthread_create() failed: %s\n", strerror(res));
    curl_easy_cleanup(data->curl);
    free(data->url);
    free(data);
    return EXIT_FAILURE;
  }

  pthread_join(tid, NULL);

  return EXIT_SUCCESS;
}