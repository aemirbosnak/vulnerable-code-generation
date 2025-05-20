//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_THREADS 8

struct thread_args {
  char *text;
  int start;
  int end;
  char *summary;
};

void *summarize_text(void *args) {
  struct thread_args *thread_args = (struct thread_args *)args;

  // Process the text within the specified range
  char *summary = malloc(1024);  // Allocate memory for the summary
  memset(summary, 0, 1024);      // Initialize the summary with zeros
  int summary_length = 0;         // Initialize the summary length

  for (int i = thread_args->start; i < thread_args->end; i++) {
    if (thread_args->text[i] == '.' || thread_args->text[i] == '!' || thread_args->text[i] == '?') {
      // End of a sentence detected
      if (summary_length > 0) {
        strcat(summary, " ");  // Add a space between sentences
      }
      int sentence_length = i - thread_args->start + 1;
      char *sentence = malloc(sentence_length + 1);  // Allocate memory for the sentence
      memset(sentence, 0, sentence_length + 1);      // Initialize the sentence with zeros
      strncpy(sentence, thread_args->text + thread_args->start, sentence_length);  // Copy the sentence
      sentence[sentence_length] = '\0';  // Terminate the sentence with a null character
      strcat(summary, sentence);        // Add the sentence to the summary
      summary_length += sentence_length;  // Increment the summary length
      free(sentence);                   // Free the memory allocated for the sentence
      thread_args->start = i + 1;        // Update the start index for the next thread
    }
  }

  // Copy the summary to the thread's summary pointer
  strcpy(thread_args->summary, summary);

  // Free the memory allocated for the summary
  free(summary);

  return NULL;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <text file>\n", argv[0]);
    return 1;
  }

  // Read the text file
  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("Error opening file: %s\n", argv[1]);
    return 1;
  }
  fseek(file, 0, SEEK_END);
  int file_size = ftell(file);
  rewind(file);
  char *text = malloc(file_size + 1);  // Allocate memory for the text
  memset(text, 0, file_size + 1);      // Initialize the text with zeros
  fread(text, 1, file_size, file);  // Read the text from the file
  fclose(file);                     // Close the file

  // Create an array of thread arguments
  struct thread_args thread_args[MAX_THREADS];

  // Divide the text into chunks and assign them to the threads
  int chunk_size = file_size / MAX_THREADS;
  for (int i = 0; i < MAX_THREADS; i++) {
    thread_args[i].text = text;
    thread_args[i].start = i * chunk_size;
    thread_args[i].end = (i + 1) * chunk_size;
    thread_args[i].summary = malloc(1024);  // Allocate memory for the summary
    memset(thread_args[i].summary, 0, 1024);  // Initialize the summary with zeros
  }

  // Create the threads
  pthread_t threads[MAX_THREADS];
  for (int i = 0; i < MAX_THREADS; i++) {
    pthread_create(&threads[i], NULL, summarize_text, &thread_args[i]);
  }

  // Join the threads
  for (int i = 0; i < MAX_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Combine the summaries from each thread
  char *summary = malloc(1024);  // Allocate memory for the summary
  memset(summary, 0, 1024);      // Initialize the summary with zeros
  int summary_length = 0;         // Initialize the summary length
  for (int i = 0; i < MAX_THREADS; i++) {
    if (thread_args[i].summary[0] != '\0') {
      if (summary_length > 0) {
        strcat(summary, " ");  // Add a space between paragraphs
      }
      strcat(summary, thread_args[i].summary);  // Add the paragraph to the summary
      summary_length += strlen(thread_args[i].summary);  // Increment the summary length
    }
    free(thread_args[i].summary);  // Free the memory allocated for the summary
  }

  // Print the summary
  printf("Summary:\n%s\n", summary);

  // Free the memory allocated for the summary
  free(summary);

  // Free the memory allocated for the text
  free(text);

  return 0;
}