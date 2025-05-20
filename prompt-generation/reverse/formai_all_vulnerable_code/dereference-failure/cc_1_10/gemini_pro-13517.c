//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to summarize a text
char *summarize(char *text, int num_sentences) {
  // Split the text into sentences
  char **sentences = malloc(sizeof(char *) * num_sentences);
  int num_tokens = 0;
  char *token = strtok(text, ".");
  while (token != NULL) {
    sentences[num_tokens++] = strdup(token);
    token = strtok(NULL, ".");
  }

  // Calculate the score of each sentence
  int *scores = malloc(sizeof(int) * num_sentences);
  for (int i = 0; i < num_sentences; i++) {
    scores[i] = 0;
    char *word = strtok(sentences[i], " ");
    while (word != NULL) {
      if (strlen(word) > 3) {
        scores[i]++;
      }
      word = strtok(NULL, " ");
    }
  }

  // Sort the sentences by score
  for (int i = 0; i < num_sentences - 1; i++) {
    for (int j = i + 1; j < num_sentences; j++) {
      if (scores[i] < scores[j]) {
        int temp = scores[i];
        scores[i] = scores[j];
        scores[j] = temp;
        char *temp_sentence = sentences[i];
        sentences[i] = sentences[j];
        sentences[j] = temp_sentence;
      }
    }
  }

  // Generate the summary
  char *summary = malloc(sizeof(char) * 1024);
  summary[0] = '\0';
  for (int i = 0; i < num_sentences; i++) {
    strcat(summary, sentences[i]);
    strcat(summary, ". ");
  }

  // Free the allocated memory
  for (int i = 0; i < num_sentences; i++) {
    free(sentences[i]);
  }
  free(sentences);
  free(scores);

  return summary;
}

// Main function
int main() {
  // Get the input text
  char *text = malloc(sizeof(char) * 1024);
  printf("Enter the text to summarize: ");
  fgets(text, 1024, stdin);

  // Get the number of sentences in the summary
  int num_sentences;
  printf("Enter the number of sentences in the summary: ");
  scanf("%d", &num_sentences);

  // Summarize the text
  char *summary = summarize(text, num_sentences);

  // Print the summary
  printf("Summary: %s", summary);

  // Free the allocated memory
  free(text);
  free(summary);

  return 0;
}