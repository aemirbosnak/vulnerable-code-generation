//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Shared data structure for word frequencies
typedef struct {
  char* word;
  int count;
} WordFrequency;

// Global variables
WordFrequency* word_frequencies;
int num_word_frequencies;
int num_threads;

// Mutex for protecting shared data
pthread_mutex_t mutex;

// Function to compare WordFrequency structures by count
int compare_word_frequencies(const void* a, const void* b) {
  WordFrequency* wa = (WordFrequency*)a;
  WordFrequency* wb = (WordFrequency*)b;
  return wb->count - wa->count;
}

// Thread function to count word frequencies
void* count_word_frequencies(void* arg) {
  FILE* fp = (FILE*)arg;
  char word[1024];
  int found;

  // Lock the mutex
  pthread_mutex_lock(&mutex);

  // Read words from the file and update word frequencies
  while (fscanf(fp, "%s", word) != EOF) {
    found = 0;
    for (int i = 0; i < num_word_frequencies; i++) {
      if (strcmp(word_frequencies[i].word, word) == 0) {
        word_frequencies[i].count++;
        found = 1;
        break;
      }
    }
    if (!found) {
      word_frequencies = realloc(word_frequencies, (num_word_frequencies + 1) * sizeof(WordFrequency));
      word_frequencies[num_word_frequencies].word = strdup(word);
      word_frequencies[num_word_frequencies].count = 1;
      num_word_frequencies++;
    }
  }

  // Unlock the mutex
  pthread_mutex_unlock(&mutex);

  return NULL;
}

// Main function
int main(int argc, char* argv[]) {
  if (argc < 3) {
    printf("Usage: %s <num_threads> <filenames>\n", argv[0]);
    return 1;
  }

  num_threads = atoi(argv[1]);

  // Initialize word frequencies and mutex
  word_frequencies = NULL;
  num_word_frequencies = 0;
  pthread_mutex_init(&mutex, NULL);

  // Create threads and pass file names as arguments
  pthread_t* threads = malloc(num_threads * sizeof(pthread_t));
  for (int i = 0; i < num_threads; i++) {
    pthread_create(&threads[i], NULL, count_word_frequencies, (void*)argv[i + 2]);
  }

  // Wait for threads to finish
  for (int i = 0; i < num_threads; i++) {
    pthread_join(threads[i], NULL);
  }

  // Sort word frequencies by count
  qsort(word_frequencies, num_word_frequencies, sizeof(WordFrequency), compare_word_frequencies);

  // Print word frequencies
  for (int i = 0; i < num_word_frequencies; i++) {
    printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].count);
  }

  // Free allocated memory
  for (int i = 0; i < num_word_frequencies; i++) {
    free(word_frequencies[i].word);
  }
  free(word_frequencies);
  free(threads);
  pthread_mutex_destroy(&mutex);

  return 0;
}