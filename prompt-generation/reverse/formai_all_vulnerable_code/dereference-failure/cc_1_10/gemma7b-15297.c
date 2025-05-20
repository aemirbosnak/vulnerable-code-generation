//Gemma-7B DATASET v1.0 Category: Table Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

typedef struct Word {
  char **words;
  int numWords;
} Word;

Word *createWordList() {
  Word *wordList = malloc(sizeof(Word));
  wordList->words = malloc(MAX_WORDS * sizeof(char *));
  wordList->numWords = 0;
  return wordList;
}

void addWordToWordList(Word *wordList, char *word) {
  if (wordList->numWords >= MAX_WORDS) {
    return;
  }
  wordList->words[wordList->numWords++] = strdup(word);
}

void playGame(Word *wordList) {
  char guessWord[MAX_WORD_LENGTH];
  int guesses = 0;
  int found = 0;

  printf("Welcome to the game, guess a word:\n");

  while (!found && guesses < MAX_WORDS) {
    printf("Enter your guess:");
    scanf("%s", guessWord);

    for (int i = 0; i < wordList->numWords; i++) {
      if (strcmp(guessWord, wordList->words[i]) == 0) {
        found = 1;
        break;
      }
    }

    guesses++;

    if (!found) {
      printf("Incorrect guess, try again.\n");
    }
  }

  if (found) {
    printf("Congratulations, you guessed the word!\n");
  } else {
    printf("Sorry, you ran out of guesses.\n");
  }
}

int main() {
  Word *wordList = createWordList();
  addWordToWordList(wordList, "apple");
  addWordToWordList(wordList, "banana");
  addWordToWordList(wordList, "orange");
  addWordToWordList(wordList, "grape");

  playGame(wordList);

  return 0;
}