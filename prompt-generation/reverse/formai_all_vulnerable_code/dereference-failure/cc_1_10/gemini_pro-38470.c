//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to summarize a text
char *summarize(char *text, int length) {
  // Check if the text is valid
  if (text == NULL || length <= 0) {
    return NULL;
  }

  // Create a buffer to store the summary
  char *summary = malloc(length / 2 + 1);
  if (summary == NULL) {
    return NULL;
  }

  // Initialize the summary
  summary[0] = '\0';

  // Split the text into sentences
  char **sentences = malloc(sizeof(char *) * length);
  if (sentences == NULL) {
    free(summary);
    return NULL;
  }

  int num_sentences = 0;
  char *sentence = strtok(text, ".");
  while (sentence != NULL) {
    sentences[num_sentences++] = sentence;
    sentence = strtok(NULL, ".");
  }

  // Find the most important sentences
  int *importance = malloc(sizeof(int) * num_sentences);
  if (importance == NULL) {
    free(summary);
    free(sentences);
    return NULL;
  }

  for (int i = 0; i < num_sentences; i++) {
    importance[i] = 0;
  }

  // Count the number of occurrences of each word in the text
  char **words = malloc(sizeof(char *) * length);
  if (words == NULL) {
    free(summary);
    free(sentences);
    free(importance);
    return NULL;
  }

  int num_words = 0;
  char *word = strtok(text, " ");
  while (word != NULL) {
    words[num_words++] = word;
    word = strtok(NULL, " ");
  }

  for (int i = 0; i < num_words; i++) {
    for (int j = 0; j < num_sentences; j++) {
      if (strstr(sentences[j], words[i]) != NULL) {
        importance[j]++;
      }
    }
  }

  // Sort the sentences by importance
  for (int i = 0; i < num_sentences - 1; i++) {
    for (int j = i + 1; j < num_sentences; j++) {
      if (importance[i] < importance[j]) {
        int temp = importance[i];
        importance[i] = importance[j];
        importance[j] = temp;

        char *temp2 = sentences[i];
        sentences[i] = sentences[j];
        sentences[j] = temp2;
      }
    }
  }

  // Create the summary
  for (int i = 0; i < num_sentences / 2; i++) {
    strcat(summary, sentences[i]);
    strcat(summary, ". ");
  }

  // Free the allocated memory
  free(sentences);
  free(importance);
  free(words);

  return summary;
}

// Main function
int main() {
  // Get the text from the user
  char *text = malloc(1000);
  printf("Enter the text to be summarized: ");
  fgets(text, 1000, stdin);

  // Summarize the text
  char *summary = summarize(text, strlen(text));

  // Print the summary
  printf("Summary: %s\n", summary);

  // Free the allocated memory
  free(text);
  free(summary);

  return 0;
}