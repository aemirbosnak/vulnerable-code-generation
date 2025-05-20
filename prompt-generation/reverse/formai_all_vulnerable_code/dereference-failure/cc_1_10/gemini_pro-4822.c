//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: asynchronous
#include <curl/curl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_URL_LENGTH 2048

typedef struct {
  CURL *curl;
  char *data;
  size_t data_len;
  bool done;
} curl_async_data;

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
  curl_async_data *data = (curl_async_data *)userp;
  size_t new_len = data->data_len + size * nmemb;
  data->data = realloc(data->data, new_len + 1);
  if (!data->data) {
    return 0;
  }
  memcpy(data->data + data->data_len, ptr, size * nmemb);
  data->data_len = new_len;
  data->data[data->data_len] = '\0';
  return size * nmemb;
}

static void cleanup_curl_async_data(curl_async_data *data) {
  curl_easy_cleanup(data->curl);
  free(data->data);
  free(data);
}

static void *curl_async(void *arg) {
  curl_async_data *data = (curl_async_data *)arg;

  curl_easy_setopt(data->curl, CURLOPT_URL, data->data);
  curl_easy_setopt(data->curl, CURLOPT_WRITEFUNCTION, write_data);
  curl_easy_setopt(data->curl, CURLOPT_WRITEDATA, data);
  curl_easy_setopt(data->curl, CURLOPT_NOSIGNAL, 1L);

  CURLcode res = curl_easy_perform(data->curl);
  if (res != CURLE_OK) {
    fprintf(stderr, "curl_easy_perform failed: %s\n", curl_easy_strerror(res));
  }
  data->done = true;

  return NULL;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
    return EXIT_FAILURE;
  }

  if (strlen(argv[1]) > MAX_URL_LENGTH) {
    fprintf(stderr, "URL is too long\n");
    return EXIT_FAILURE;
  }

  curl_global_init(CURL_GLOBAL_ALL);

  curl_async_data *data = malloc(sizeof(curl_async_data));
  if (!data) {
    fprintf(stderr, "malloc failed\n");
    return EXIT_FAILURE;
  }
  data->curl = curl_easy_init();
  if (!data->curl) {
    fprintf(stderr, "curl_easy_init failed\n");
    cleanup_curl_async_data(data);
    return EXIT_FAILURE;
  }
  data->data = malloc(1);
  if (!data->data) {
    fprintf(stderr, "malloc failed\n");
    cleanup_curl_async_data(data);
    return EXIT_FAILURE;
  }
  data->data_len = 0;
  data->done = false;

  pthread_t thread;
  if (pthread_create(&thread, NULL, curl_async, data) != 0) {
    fprintf(stderr, "pthread_create failed\n");
    cleanup_curl_async_data(data);
    return EXIT_FAILURE;
  }

  while (!data->done) {
    sleep(1);
  }

  pthread_join(thread, NULL);

  if (data->data_len > 0) {
    printf("%s", data->data);
  }

  cleanup_curl_async_data(data);
  curl_global_cleanup();

  return EXIT_SUCCESS;
}