//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct Word {
  char *word;
  int frequency;
};

int main() {
  int numPlayers = 2;
  char **words = NULL;
  struct Word *wordList = NULL;
  int i, j, k, wordCount = 0, totalWords = 0;

  // Allocate memory for words and word list
  words = malloc(numPlayers * MAX_WORDS * sizeof(char *));
  wordList = malloc(MAX_WORDS * sizeof(struct Word));

  // Initialize the word list
  for (i = 0; i < MAX_WORDS; i++) {
    wordList[i].word = NULL;
    wordList[i].frequency = 0;
  }

  // Start the game
  for (i = 0; i < numPlayers; i++) {
    printf("Player %d, enter a word: ", i + 1);
    words[i] = malloc(MAX_WORD_LENGTH * sizeof(char));
    scanf("%s", words[i]);
  }

  // Count the words
  for (i = 0; i < numPlayers; i++) {
    char *word = words[i];
    for (j = 0; word[j] != '\0'; j++) {
      word[j] = tolower(word[j]);
    }

    for (k = 0; k < wordCount; k++) {
      if (strcmp(wordList[k].word, word) == 0) {
        wordList[k].frequency++;
        break;
      }
    }

    if (wordList[k].word == NULL) {
      wordList[wordCount].word = strdup(word);
      wordList[wordCount].frequency = 1;
      wordCount++;
    }
  }

  // Print the results
  printf("Word frequency:\n");
  for (i = 0; i < wordCount; i++) {
    printf("%s: %d\n", wordList[i].word, wordList[i].frequency);
  }

  // Free the memory
  for (i = 0; i < numPlayers; i++) {
    free(words[i]);
  }
  free(words);
  free(wordList);

  return 0;
}