//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum length of a sentence
#define MAX_SENTENCE_LENGTH 100

// Maximum number of sentences in a summary
#define MAX_SUMMARY_SENTENCES 5

// Function to summarize a text
char *summarize_text(char *text) {
  // Split the text into sentences
  char **sentences = malloc(sizeof(char *) * MAX_SUMMARY_SENTENCES);
  int num_sentences = 0;
  char *sentence = strtok(text, ".");
  while (sentence != NULL) {
    sentences[num_sentences++] = sentence;
    sentence = strtok(NULL, ".");
  }

  // Remove duplicate sentences
  for (int i = 0; i < num_sentences; i++) {
    for (int j = i + 1; j < num_sentences; j++) {
      if (strcmp(sentences[i], sentences[j]) == 0) {
        sentences[j] = NULL;
      }
    }
  }

  // Sort the sentences by length
  for (int i = 0; i < num_sentences; i++) {
    for (int j = i + 1; j < num_sentences; j++) {
      if (strlen(sentences[i]) > strlen(sentences[j])) {
        char *temp = sentences[i];
        sentences[i] = sentences[j];
        sentences[j] = temp;
      }
    }
  }

  // Create the summary
  char *summary = malloc(sizeof(char) * MAX_SUMMARY_SENTENCES * MAX_SENTENCE_LENGTH);
  int summary_length = 0;
  for (int i = 0; i < num_sentences; i++) {
    if (summary_length + strlen(sentences[i]) + 1 <= MAX_SUMMARY_SENTENCES * MAX_SENTENCE_LENGTH) {
      strcat(summary, sentences[i]);
      strcat(summary, ". ");
      summary_length += strlen(sentences[i]) + 1;
    } else {
      break;
    }
  }

  // Free the memory allocated for the sentences
  free(sentences);

  // Return the summary
  return summary;
}

// Main function
int main() {
  // Get the text to be summarized from the user
  char *text = malloc(sizeof(char) * 1000);
  printf("Enter the text to be summarized: ");
  gets(text);

  // Summarize the text
  char *summary = summarize_text(text);

  // Print the summary
  printf("Summary: %s", summary);

  // Free the memory allocated for the summary
  free(summary);

  return 0;
}