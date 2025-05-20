//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void summarize(char **text, int text_size) {
  int i, j, n_words = 0, n_sentences = 0, word_freq[MAX] = {0}, sentence_length[MAX] = {0};

  for (i = 0; i < text_size; i++) {
    char *word = strtok(text[i], " \t\n");
    while (word) {
      word_freq[n_words++]++;
      word = strtok(NULL, " \t\n");
    }
    sentence_length[n_sentences++] = text_size - i;
  }

  // Calculate summary statistics
  int average_sentence_length = (sentence_length[0] + sentence_length[1]) / 2;
  int average_word_length = (word_freq[0] * average_sentence_length) / n_words;

  // Print summary statistics
  printf("Summary statistics:\n");
  printf("  - Number of words: %d\n", n_words);
  printf("  - Number of sentences: %d\n", n_sentences);
  printf("  - Average sentence length: %d words\n", average_sentence_length);
  printf("  - Average word length: %d characters\n", average_word_length);
}

int main() {
  char **text = NULL;
  int text_size = 0;

  // Allocate memory for text
  text = malloc(MAX * sizeof(char *));
  text_size = MAX;

  // Get text from the user
  printf("Enter text: ");
  getline(text[0], text_size, stdin);

  // Summarize the text
  summarize(text, text_size);

  // Free memory
  free(text);

  return 0;
}