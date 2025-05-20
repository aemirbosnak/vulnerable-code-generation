//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LEN 100

// A simple struct to store a word and its frequency
typedef struct {
  char word[MAX_LEN];
  int freq;
} Word;

// A simple function to compare two words
int cmp(const void *a, const void *b) {
  Word *w1 = (Word *)a;
  Word *w2 = (Word *)b;
  return strcmp(w1->word, w2->word);
}

int main() {
  // Get the input string
  char *input = malloc(100000);
  scanf("%s", input);

  // Create an array of words
  Word words[MAX_WORDS];
  int num_words = 0;

  // Tokenize the input string
  char *token = strtok(input, " ");
  while (token != NULL) {
    // Check if the word is already in the array
    int found = 0;
    for (int i = 0; i < num_words; i++) {
      if (strcmp(token, words[i].word) == 0) {
        words[i].freq++;
        found = 1;
        break;
      }
    }

    // If the word is not in the array, add it
    if (!found) {
      strcpy(words[num_words].word, token);
      words[num_words].freq = 1;
      num_words++;
    }

    // Get the next token
    token = strtok(NULL, " ");
  }

  // Sort the array of words
  qsort(words, num_words, sizeof(Word), cmp);

  // Print the array of words
  for (int i = 0; i < num_words; i++) {
    printf("%s: %d\n", words[i].word, words[i].freq);
  }

  return 0;
}