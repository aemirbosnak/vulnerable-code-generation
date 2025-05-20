//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Mutex to protect shared data
pthread_mutex_t mutex;

// Condition variable to signal when data is ready
pthread_cond_t cond;

// Shared data
char *text;
int text_len;

// Function to read text from a file
void *read_text(void *arg) {
  FILE *fp;
  char *filename = (char *)arg;

  // Open the file
  if ((fp = fopen(filename, "r")) == NULL) {
    perror("fopen");
    exit(1);
  }

  // Determine the length of the text
  fseek(fp, 0, SEEK_END);
  text_len = ftell(fp);
  rewind(fp);

  // Allocate memory for the text
  text = malloc(text_len + 1);

  // Read the text from the file
  fread(text, 1, text_len, fp);
  text[text_len] = '\0';

  // Close the file
  fclose(fp);

  // Signal that the data is ready
  pthread_mutex_lock(&mutex);
  pthread_cond_signal(&cond);
  pthread_mutex_unlock(&mutex);

  return NULL;
}

// Function to process text
void *process_text(void *arg) {
  char *word;

  // Wait for the data to be ready
  pthread_mutex_lock(&mutex);
  while (text == NULL) {
    pthread_cond_wait(&cond, &mutex);
  }
  pthread_mutex_unlock(&mutex);

  // Process the text
  for (word = strtok(text, " "); word != NULL; word = strtok(NULL, " ")) {
    // Do something with the word
    printf("%s\n", word);
  }

  return NULL;
}

int main(int argc, char **argv) {
  pthread_t read_thread, process_thread;

  // Initialize the mutex and condition variable
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&cond, NULL);

  // Create the threads
  pthread_create(&read_thread, NULL, read_text, argv[1]);
  pthread_create(&process_thread, NULL, process_text, NULL);

  // Join the threads
  pthread_join(read_thread, NULL);
  pthread_join(process_thread, NULL);

  // Destroy the mutex and condition variable
  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cond);

  // Free the memory allocated for the text
  free(text);

  return 0;
}