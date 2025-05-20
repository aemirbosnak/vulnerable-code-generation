//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// Maximum number of threads
#define MAX_THREADS 8

// Thread data structure
typedef struct {
  char *file_name;
  int file_size;
} thread_data;

// Mutex to protect shared data
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// List of known viruses
char *viruses[] = {"virus1", "virus2", "virus3", "virus4", "virus5"};

// Function to check if a file is infected with a virus
int is_infected(char *file_name) {
  // Open the file
  FILE *file = fopen(file_name, "rb");
  if (file == NULL) {
    return -1;
  }

  // Get the file size
  struct stat st;
  if (stat(file_name, &st) != 0) {
    fclose(file);
    return -1;
  }
  int file_size = st.st_size;

  // Read the file into memory
  char *file_data = malloc(file_size);
  if (file_data == NULL) {
    fclose(file);
    return -1;
  }
  fread(file_data, 1, file_size, file);
  fclose(file);

  // Check for each virus
  for (int i = 0; i < sizeof(viruses) / sizeof(viruses[0]); i++) {
    if (strstr(file_data, viruses[i]) != NULL) {
      free(file_data);
      return 1;
    }
  }

  // No virus found
  free(file_data);
  return 0;
}

// Function to scan a file for viruses
void *scan_file(void *arg) {
  thread_data *data = (thread_data *)arg;

  // Check if the file is infected with a virus
  int infected = is_infected(data->file_name);

  // Lock the mutex
  pthread_mutex_lock(&mutex);

  // Print the results
  if (infected == 1) {
    printf("%s is infected with a virus.\n", data->file_name);
  } else if (infected == -1) {
    printf("Error scanning %s.\n", data->file_name);
  } else {
    printf("%s is clean.\n", data->file_name);
  }

  // Unlock the mutex
  pthread_mutex_unlock(&mutex);

  // Free the thread data
  free(data);

  return NULL;
}

// Main function
int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <file1> <file2> ...\n", argv[0]);
    return 1;
  }

  // Create a thread pool
  pthread_t threads[MAX_THREADS];

  // Create a thread for each file
  for (int i = 1; i < argc; i++) {
    // Get the file name and size
    char *file_name = argv[i];
    struct stat st;
    if (stat(file_name, &st) != 0) {
      printf("Error getting file size for %s.\n", file_name);
      continue;
    }
    int file_size = st.st_size;

    // Create a thread data structure
    thread_data *data = malloc(sizeof(thread_data));
    data->file_name = file_name;
    data->file_size = file_size;

    // Create a thread to scan the file
    if (pthread_create(&threads[i - 1], NULL, scan_file, data) != 0) {
      printf("Error creating thread for %s.\n", file_name);
      free(data);
      continue;
    }
  }

  // Join all the threads
  for (int i = 1; i < argc; i++) {
    if (pthread_join(threads[i - 1], NULL) != 0) {
      printf("Error joining thread for %s.\n", argv[i]);
    }
  }

  // Destroy the mutex
  pthread_mutex_destroy(&mutex);

  return 0;
}