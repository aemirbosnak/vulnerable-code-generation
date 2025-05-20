//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 200

int main() {
  char **words = NULL;
  char **sentences = NULL;
  int num_words = 0;
  int num_sentences = 0;
  char input_sentence[MAX_SENTENCE_LENGTH];

  // Allocate memory for words and sentences
  words = malloc(MAX_WORDS * sizeof(char *));
  sentences = malloc(MAX_SENTENCE_LENGTH * sizeof(char *));

  // Get the input sentence
  printf("Enter a sentence: ");
  fgets(input_sentence, MAX_SENTENCE_LENGTH, stdin);

  // Tokenize the input sentence into words
  char *word = strtok(input_sentence, " ");
  while (word) {
    words[num_words++] = strdup(word);
    word = strtok(NULL, " ");
  }

  // Create a hash table to store the words and their frequencies
  int word_frequency[num_words];
  for (int i = 0; i < num_words; i++) {
    word_frequency[i] = 1;
  }

  // Iterate over the words and count their frequencies
  for (int i = 0; i < num_words; i++) {
    for (int j = i + 1; j < num_words && words[i] == words[j]; j++) {
      word_frequency[i]++;
    }
  }

  // Identify the words with the highest frequency
  int top_words[MAX_WORDS];
  int num_top_words = 0;
  for (int i = 0; i < num_words; i++) {
    if (word_frequency[i] > top_words[num_top_words]) {
      top_words[num_top_words++] = word_frequency[i];
    }
  }

  // Print the top words
  printf("The top words in the sentence are:\n");
  for (int i = 0; i < num_top_words; i++) {
    printf("%s (%d)  ", words[top_words[i]], top_words[i]);
  }

  // Free the memory allocated for words and sentences
  free(words);
  free(sentences);

  return 0;
}