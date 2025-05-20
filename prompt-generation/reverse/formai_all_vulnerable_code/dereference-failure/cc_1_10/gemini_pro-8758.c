//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to summarize a text
char *summarize_text(char *text, int num_sentences) {
  // Allocate memory for the summary
  char *summary = malloc(sizeof(char) * 1000);

  // Tokenize the text into sentences
  char **sentences = malloc(sizeof(char *) * 1000);
  int num_tokens = 0;
  char *token = strtok(text, ".");
  while (token != NULL) {
    sentences[num_tokens++] = token;
    token = strtok(NULL, ".");
  }

  // Calculate the importance of each sentence
  int *sentence_importance = malloc(sizeof(int) * num_tokens);
  for (int i = 0; i < num_tokens; i++) {
    sentence_importance[i] = 0;
    char *word = strtok(sentences[i], " ");
    while (word != NULL) {
      if (strcmp(word, "the") == 0 || strcmp(word, "a") == 0 || strcmp(word, "an") == 0) {
        sentence_importance[i] -= 1;
      } else {
        sentence_importance[i] += 1;
      }
      word = strtok(NULL, " ");
    }
  }

  // Sort the sentences by importance
  for (int i = 0; i < num_tokens; i++) {
    for (int j = i + 1; j < num_tokens; j++) {
      if (sentence_importance[i] < sentence_importance[j]) {
        int temp = sentence_importance[i];
        sentence_importance[i] = sentence_importance[j];
        sentence_importance[j] = temp;
        char *temp_sentence = sentences[i];
        sentences[i] = sentences[j];
        sentences[j] = temp_sentence;
      }
    }
  }

  // Generate the summary
  for (int i = 0; i < num_sentences; i++) {
    strcat(summary, sentences[i]);
    strcat(summary, ". ");
  }

  // Free the allocated memory
  free(sentences);
  free(sentence_importance);

  // Return the summary
  return summary;
}

// Main function
int main() {
  // Get the text from the user
  char text[1000];
  printf("Enter the text to be summarized: ");
  gets(text);

  // Get the number of sentences in the summary
  int num_sentences;
  printf("Enter the number of sentences in the summary: ");
  scanf("%d", &num_sentences);

  // Summarize the text
  char *summary = summarize_text(text, num_sentences);

  // Print the summary
  printf("Summary: %s\n", summary);

  // Free the allocated memory
  free(summary);

  return 0;
}