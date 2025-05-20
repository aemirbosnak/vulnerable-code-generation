//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: shape shifting
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 4

typedef struct {
  int id;
  int *shared_data;
  pthread_mutex_t *mutex;
} thread_args_t;

void *thread_function(void *arg) {
  thread_args_t *args = (thread_args_t *) arg;
  int id = args->id;
  int *shared_data = args->shared_data;
  pthread_mutex_t *mutex = args->mutex;

  printf("Thread %d starting.\n", id);

  // Do some work...
  for (int i = 0; i < 1000000; i++) {
    pthread_mutex_lock(mutex);
    *shared_data += 1;
    pthread_mutex_unlock(mutex);
  }

  printf("Thread %d finished.\n", id);
  return NULL;
}

int main() {
  // Create shared data
  int shared_data = 0;

  // Create mutex
  pthread_mutex_t mutex;
  pthread_mutex_init(&mutex, NULL);

  // Create threads
  pthread_t threads[NUM_THREADS];
  for (int i = 0; i < NUM_THREADS; i++) {
    thread_args_t *args = malloc(sizeof(thread_args_t));
    args->id = i;
    args->shared_data = &shared_data;
    args->mutex = &mutex;
    pthread_create(&threads[i], NULL, thread_function, args);
  }

  // Join threads
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Destroy mutex
  pthread_mutex_destroy(&mutex);

  // Print the final value of shared_data
  printf("Final value of shared_data: %d\n", shared_data);
  return 0;
}