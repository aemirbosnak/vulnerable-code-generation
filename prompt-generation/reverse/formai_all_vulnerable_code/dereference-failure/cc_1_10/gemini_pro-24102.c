//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>

// Global variables
pthread_mutex_t lock;
char *url;
int size;

// Function to be executed by each thread
void *sanitize_url(void *arg) {
  char *local_url = malloc(size);
  strcpy(local_url, url);

  // Lock the mutex
  pthread_mutex_lock(&lock);

  // Sanitize the URL
  char *sanitized_url = curl_easy_escape(NULL, local_url, 0);
  free(local_url);

  // Unlock the mutex
  pthread_mutex_unlock(&lock);

  // Print the sanitized URL
  printf("%s\n", sanitized_url);
  curl_free(sanitized_url);

  return NULL;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <URL>\n", argv[0]);
    return 1;
  }

  // Initialize the mutex
  pthread_mutex_init(&lock, NULL);

  // Store the URL and its size
  url = argv[1];
  size = strlen(url);

  // Create a thread pool
  pthread_t *threads = malloc(sizeof(pthread_t) * 4);

  // Create threads and pass the URL to each thread
  for (int i = 0; i < 4; i++) {
    pthread_create(&threads[i], NULL, sanitize_url, NULL);
  }

  // Join threads
  for (int i = 0; i < 4; i++) {
    pthread_join(threads[i], NULL);
  }

  // Destroy the mutex
  pthread_mutex_destroy(&lock);

  // Free the thread pool
  free(threads);

  return 0;
}