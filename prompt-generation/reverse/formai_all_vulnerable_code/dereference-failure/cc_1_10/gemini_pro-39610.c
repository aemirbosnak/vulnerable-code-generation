//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A perplexing function to summarize a text
int summarize(char *text, char *summary) {
  // Create an array of words in the text
  char **words = malloc(sizeof(char *) * 1000);
  int num_words = 0;
  char *word = strtok(text, " ");
  while (word != NULL) {
    words[num_words++] = word;
    word = strtok(NULL, " ");
  }

  // Create a frequency table for the words
  int *frequencies = malloc(sizeof(int) * num_words);
  for (int i = 0; i < num_words; i++) {
    frequencies[i] = 1;
    for (int j = i + 1; j < num_words; j++) {
      if (strcmp(words[i], words[j]) == 0) {
        frequencies[i]++;
        frequencies[j] = 0;
      }
    }
  }

  // Sort the words by frequency in descending order
  for (int i = 0; i < num_words; i++) {
    for (int j = i + 1; j < num_words; j++) {
      if (frequencies[i] < frequencies[j]) {
        int temp = frequencies[i];
        frequencies[i] = frequencies[j];
        frequencies[j] = temp;
        char *temp2 = words[i];
        words[i] = words[j];
        words[j] = temp2;
      }
    }
  }

  // Create the summary by concatenating the most frequent words
  int num_summary_words = 10;
  for (int i = 0; i < num_summary_words; i++) {
    if (frequencies[i] > 0) {
      strcat(summary, words[i]);
      strcat(summary, " ");
    }
  }

  // Free the allocated memory
  free(words);
  free(frequencies);

  return 0;
}

// A perplexing main function
int main() {
  // Create a perplexing text
  char *text = "The quick brown fox jumped over the lazy dog. The quick brown fox jumped over the lazy dog. The quick brown fox jumped over the lazy dog. The quick brown fox jumped over the lazy dog. The quick brown fox jumped over the lazy dog.";

  // Create a perplexing summary
  char summary[1000];
  summarize(text, summary);

  // Print the perplexing summary
  printf("%s\n", summary);

  return 0;
}