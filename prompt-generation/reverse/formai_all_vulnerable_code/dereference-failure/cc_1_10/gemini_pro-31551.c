//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: light-weight
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Thread function
void *thread_function(void *arg) {
  // Get the thread ID
  int tid = *(int *)arg;

  // Print the thread ID
  printf("Thread %d says hello!\n", tid);

  // Free the allocated memory
  free(arg);

  // Return NULL
  return NULL;
}

int main(int argc, char *argv[]) {
  // Check if the number of arguments is correct
  if (argc != 2) {
    printf("Usage: %s <number of threads>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the number of threads from the command line
  int num_threads = atoi(argv[1]);

  // Create an array of thread IDs
  pthread_t *tids = malloc(num_threads * sizeof(pthread_t));

  // Create the threads
  for (int i = 0; i < num_threads; i++) {
    int *arg = malloc(sizeof(int));
    *arg = i;
    pthread_create(&tids[i], NULL, thread_function, arg);
  }

  // Join the threads
  for (int i = 0; i < num_threads; i++) {
    pthread_join(tids[i], NULL);
  }

  // Free the allocated memory
  free(tids);

  // Return success
  return EXIT_SUCCESS;
}