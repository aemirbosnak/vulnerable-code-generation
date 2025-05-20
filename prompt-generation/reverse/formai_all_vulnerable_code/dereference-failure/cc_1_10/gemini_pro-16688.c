//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#include <errno.h>

// Define the metadata struct
typedef struct {
  char *name;
  char *value;
} metadata_t;

// Define the thread data struct
typedef struct {
  FILE *fp;
  pthread_mutex_t *lock;
  metadata_t *metadata;
  int num_metadata;
} thread_data_t;

// Define the thread function
void *thread_function(void *arg) {
  thread_data_t *data = (thread_data_t *)arg;

  // Lock the mutex
  pthread_mutex_lock(data->lock);

  // Read the metadata from the file
  char line[1024];
  while (fgets(line, sizeof(line), data->fp) != NULL) {
    // Parse the line
    char *name = strtok(line, ":");
    char *value = strtok(NULL, "\n");

    // Allocate memory for the metadata
    data->metadata = realloc(data->metadata, (data->num_metadata + 1) * sizeof(metadata_t));

    // Store the metadata
    data->metadata[data->num_metadata].name = strdup(name);
    data->metadata[data->num_metadata].value = strdup(value);

    // Increment the number of metadata
    data->num_metadata++;
  }

  // Unlock the mutex
  pthread_mutex_unlock(data->lock);

  return NULL;
}

int main(int argc, char *argv[]) {
  // Check the number of arguments
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Open the file
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  // Create the thread data
  thread_data_t data;
  data.fp = fp;
  data.lock = malloc(sizeof(pthread_mutex_t));
  pthread_mutex_init(data.lock, NULL);
  data.metadata = NULL;
  data.num_metadata = 0;

  // Create the thread
  pthread_t thread;
  if (pthread_create(&thread, NULL, thread_function, &data) != 0) {
    perror("pthread_create");
    return EXIT_FAILURE;
  }

  // Wait for the thread to finish
  if (pthread_join(thread, NULL) != 0) {
    perror("pthread_join");
    return EXIT_FAILURE;
  }

  // Print the metadata
  for (int i = 0; i < data.num_metadata; i++) {
    printf("%s: %s\n", data.metadata[i].name, data.metadata[i].value);
  }

  // Free the memory
  for (int i = 0; i < data.num_metadata; i++) {
    free(data.metadata[i].name);
    free(data.metadata[i].value);
  }
  free(data.metadata);
  pthread_mutex_destroy(data.lock);
  free(data.lock);
  fclose(fp);

  return EXIT_SUCCESS;
}