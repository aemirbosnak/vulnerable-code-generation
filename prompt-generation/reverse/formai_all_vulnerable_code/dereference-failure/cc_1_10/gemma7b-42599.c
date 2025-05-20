//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 200

typedef struct Word {
  char *word;
  struct Word *next;
} Word;

Word *createWord(char *word) {
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->next = NULL;
  return newWord;
}

void addWordToWordList(Word **head, char *word) {
  Word *newWord = createWord(word);
  if (*head == NULL) {
    *head = newWord;
  } else {
    (*head)->next = newWord;
  }
}

int main() {
  Word *wordList = NULL;
  char sentence[MAX_SENTENCE_LENGTH];

  printf("Enter a sentence: ");
  fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

  // Tokenize the sentence
  char *word = strtok(sentence, " ");
  while (word) {
    addWordToWordList(&wordList, word);
    word = strtok(NULL, " ");
  }

  // Analyze the word list
  for (Word *word = wordList; word; word = word->next) {
    // Check if the word is a spam word
    if (isSpamWord(word->word)) {
      printf("WARNING: The word '%s' is a spam word.\n", word->word);
    }
  }

  return 0;
}

int isSpamWord(char *word) {
  // Define a list of spam words
  char *spamWords[] = {"free", "lottery", "miracle", "prize", "guarantee"};

  // Iterate over the list of spam words
  for (int i = 0; i < 5; i++) {
    if (strcmp(word, spamWords[i]) == 0) {
      return 1;
    }
  }

  return 0;
}