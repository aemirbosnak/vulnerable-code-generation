//FormAI DATASET v1.0 Category: Error handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread1(void* args); // Function for thread 1
void* thread2(void* args); // Function for thread 2

int main(void) {
  pthread_t t1, t2; // Create threads
  int rc1, rc2; // Thread creation status
  int* status_t1; // For thread 1 exit status
  int* status_t2; // For thread 2 exit status

  rc1 = pthread_create(&t1, NULL, thread1, NULL); // Create thread 1
  if(rc1) { // Check if thread creation failed
    printf("Error - pthread_create() code %d\n", rc1);
    exit(EXIT_FAILURE);
  }

  rc2 = pthread_create(&t2, NULL, thread2, NULL); // Create thread 2
  if(rc2) { // Check if thread creation failed
    printf("Error - pthread_create() code %d\n", rc2);
    exit(EXIT_FAILURE);
  }

  rc1 = pthread_join(t1, (void**)&status_t1); // Wait for thread 1 to finish
  if(rc1) { // Check if thread join failed
    printf("Error - pthread_join() code %d\n", rc1);
    exit(EXIT_FAILURE);
  }

  rc2 = pthread_join(t2, (void**)&status_t2); // Wait for thread 2 to finish
  if(rc2) { // Check if thread join failed
    printf("Error - pthread_join() code %d\n", rc2);
    exit(EXIT_FAILURE);
  }

  printf("Thread 1 exit status: %d\n", *status_t1);
  printf("Thread 2 exit status: %d\n", *status_t2);

  free(status_t1); // Clean up malloc'd memory
  free(status_t2);

  return 0;
}

void* thread1(void* args) {
  int* status = malloc(sizeof(int)); // Allocate space for exit status
  if(status == NULL) { // Check if malloc failed
    printf("Error - malloc() failed\n");
    exit(EXIT_FAILURE);
  }

  // Do some work...

  *status = 0; // Set exit status to 0
  pthread_exit(status); // Exit thread and pass exit status
}

void* thread2(void* args) {
  int* status = malloc(sizeof(int)); // Allocate space for exit status
  if(status == NULL) { // Check if malloc failed
    printf("Error - malloc() failed\n");
    exit(EXIT_FAILURE);
  }

  // Do some work that may cause an error...
  int x = 10/0; // Division by zero, will cause an error

  *status = 1; // Set exit status to 1
  pthread_exit(status); // Exit thread and pass exit status
}