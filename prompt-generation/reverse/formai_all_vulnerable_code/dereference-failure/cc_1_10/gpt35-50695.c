//FormAI DATASET v1.0 Category: Memory management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 2
#define BUFFER_SIZE 1024

char *buffer1;
char *buffer2;

void *thread_func(void *arg) {
  char *buffer = (char *) arg;

  printf("Thread ID: %ld\t Allocating memory\n", pthread_self());
  buffer = (char *) malloc(BUFFER_SIZE);

  printf("Thread ID: %ld\t Filling up memory\n", pthread_self());
  for (int i = 0; i < BUFFER_SIZE; i++) {
    buffer[i] = 'A';
  }

  printf("Thread ID: %ld\t Going to sleep for 3 seconds\n", pthread_self());
  sleep(3);

  printf("Thread ID: %ld\t Freeing memory\n", pthread_self());
  free(buffer);

  pthread_exit(NULL);
}

int main() {
  buffer1 = (char *) malloc(BUFFER_SIZE);
  buffer2 = (char *) malloc(BUFFER_SIZE);

  pthread_t threads[NUM_THREADS];
  int rc;
  long t;

  for (t = 0; t < NUM_THREADS; t++) {
    printf("Creating thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, thread_func, buffer1);
    if (rc) {
      printf("Error: return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }

  printf("Main thread ID: %ld\t Filling up memory for buffer2\n", pthread_self());
  for (int i = 0; i < BUFFER_SIZE; i++) {
    buffer2[i] = 'B';
  }

  sleep(5);

  printf("Main thread ID: %ld\t Freeing memory for buffer2\n", pthread_self());
  free(buffer2);

  pthread_exit(NULL);
}