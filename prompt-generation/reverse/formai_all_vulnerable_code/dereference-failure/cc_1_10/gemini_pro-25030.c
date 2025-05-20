//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the number of threads to use
#define NUM_THREADS 4

// Define the mutex to protect the diary
pthread_mutex_t diary_mutex = PTHREAD_MUTEX_INITIALIZER;

// Define the condition variable to signal when a thread has finished writing to the diary
pthread_cond_t diary_cond = PTHREAD_COND_INITIALIZER;

// Define the diary file
FILE *diary_file;

// Define the thread data structure
typedef struct thread_data_t {
  int thread_id;
  char *entry;
} thread_data_t;

// Define the thread function
void *thread_function(void *arg) {
  // Get the thread data
  thread_data_t *data = (thread_data_t *)arg;

  // Lock the diary
  pthread_mutex_lock(&diary_mutex);

  // Write the entry to the diary
  fprintf(diary_file, "%s\n", data->entry);

  // Unlock the diary
  pthread_mutex_unlock(&diary_mutex);

  // Signal that the thread has finished writing to the diary
  pthread_cond_signal(&diary_cond);

  // Exit the thread
  pthread_exit(NULL);
}

int main() {
  // Open the diary file
  diary_file = fopen("diary.txt", "w");
  if (diary_file == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  // Create the threads
  pthread_t threads[NUM_THREADS];
  for (int i = 0; i < NUM_THREADS; i++) {
    // Allocate memory for the thread data
    thread_data_t *data = (thread_data_t *)malloc(sizeof(thread_data_t));
    if (data == NULL) {
      perror("malloc");
      return EXIT_FAILURE;
    }

    // Initialize the thread data
    data->thread_id = i;
    data->entry = (char *)malloc(MAX_ENTRY_LENGTH);
    if (data->entry == NULL) {
      perror("malloc");
      return EXIT_FAILURE;
    }

    // Create the thread
    if (pthread_create(&threads[i], NULL, thread_function, (void *)data) != 0) {
      perror("pthread_create");
      return EXIT_FAILURE;
    }
  }

  // Wait for the threads to finish writing to the diary
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Close the diary file
  fclose(diary_file);

  // Exit the program
  return EXIT_SUCCESS;
}