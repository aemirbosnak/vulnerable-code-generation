//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *word;
  int count;
} word_count_pair;

int compare_word_count_pairs(const void *a, const void *b) {
  word_count_pair *pair1 = (word_count_pair *)a;
  word_count_pair *pair2 = (word_count_pair *)b;
  return strcmp(pair1->word, pair2->word);
}

int main() {
  char *text = "This is a sample text with some repeated words like this and a.";
  char *words[100];
  int word_counts[100];
  int num_words = 0;

  // Tokenize the text into words
  char *token = strtok(text, " ");
  while (token != NULL) {
    words[num_words] = token;
    word_counts[num_words] = 1;
    num_words++;
    token = strtok(NULL, " ");
  }

  // Count the occurrences of each word
  for (int i = 0; i < num_words; i++) {
    for (int j = i + 1; j < num_words; j++) {
      if (strcmp(words[i], words[j]) == 0) {
        word_counts[i]++;
        words[j] = NULL;
      }
    }
  }

  // Remove duplicate words
  int num_unique_words = 0;
  for (int i = 0; i < num_words; i++) {
    if (words[i] != NULL) {
      words[num_unique_words] = words[i];
      word_counts[num_unique_words] = word_counts[i];
      num_unique_words++;
    }
  }

  // Sort the words in alphabetical order
  qsort(words, num_unique_words, sizeof(char *), compare_word_count_pairs);

  // Print the word frequencies
  for (int i = 0; i < num_unique_words; i++) {
    printf("%s: %d\n", words[i], word_counts[i]);
  }

  return 0;
}