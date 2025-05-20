//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SUMMARY_LENGTH 500

// Function to summarize a text
char *summarize(char *text) {
  // Split the text into sentences
  char *sentences[100];
  int num_sentences = 0;
  char *sentence = strtok(text, ".");
  while (sentence != NULL) {
    sentences[num_sentences++] = sentence;
    sentence = strtok(NULL, ".");
  }

  // Calculate the importance of each sentence
  int importance[100];
  for (int i = 0; i < num_sentences; i++) {
    importance[i] = 0;
    char *word = strtok(sentences[i], " ");
    while (word != NULL) {
      if (strlen(word) > 3) {
        importance[i]++;
      }
      word = strtok(NULL, " ");
    }
  }

  // Sort the sentences by importance
  for (int i = 0; i < num_sentences; i++) {
    for (int j = i + 1; j < num_sentences; j++) {
      if (importance[i] < importance[j]) {
        char *temp = sentences[i];
        sentences[i] = sentences[j];
        sentences[j] = temp;
        int temp_importance = importance[i];
        importance[i] = importance[j];
        importance[j] = temp_importance;
      }
    }
  }

  // Create the summary
  char *summary = malloc(MAX_SUMMARY_LENGTH);
  strcpy(summary, "");
  for (int i = 0; i < num_sentences; i++) {
    if (strlen(summary) + strlen(sentences[i]) + 1 < MAX_SUMMARY_LENGTH) {
      strcat(summary, sentences[i]);
      strcat(summary, ". ");
    }
  }

  return summary;
}

// Main function
int main() {
  // Get the text from the user
  char *text = malloc(1000);
  printf("Enter the text you want to summarize: ");
  scanf("%s", text);

  // Summarize the text
  char *summary = summarize(text);

  // Print the summary
  printf("Summary: %s\n", summary);

  return 0;
}