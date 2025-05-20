//FormAI DATASET v1.0 Category: Searching algorithm ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define NUM_THREADS 4

int arr[] = { 10, 2, 45, 67, 23, 56, 7, 9, 2, 55, 76 };

bool found = false;
int search_key = 23;

void *search(void *arg) {
  int start = *(int*)arg * (sizeof(arr) / NUM_THREADS);
  int end = start + (sizeof(arr) / NUM_THREADS);

  for (int i = start; i < end; i++) {
    if (arr[i] == search_key) {
      found = true;
      break;
    }
  }

  return NULL;
}

int main() {
  pthread_t threads[NUM_THREADS];

  for (int i = 0; i < NUM_THREADS; i++) {
    int *thread_id = malloc(sizeof(int));
    *thread_id = i;

    if (pthread_create(&threads[i], NULL, search, (void *)thread_id) != 0) {
      printf("Failed to create thread %d\n", i);
      exit(EXIT_FAILURE);
    }
  }

  for (int i = 0; i < NUM_THREADS; i++) {
    if (pthread_join(threads[i], NULL) != 0) {
      printf("Failed to join thread %d\n", i);
      exit(EXIT_FAILURE);
    }
  }

  if (found) {
    printf("%d found in the array\n", search_key);
  } else {
    printf("%d not found in the array\n", search_key);
  }

  return 0;
}