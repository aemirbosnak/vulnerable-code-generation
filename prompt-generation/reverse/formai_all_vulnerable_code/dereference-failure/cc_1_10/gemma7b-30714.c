//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 20

typedef struct WordNode {
  char *word;
  struct WordNode *next;
} WordNode;

WordNode *insertWord(WordNode *head, char *word) {
  WordNode *newNode = malloc(sizeof(WordNode));
  newNode->word = strdup(word);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = insertWord(head->next, word);
  }

  return head;
}

void playMemoryGame(WordNode *head) {
  char *guessWord;
  int guessWordLength;
  WordNode *currentWordNode = head;

  guessWordLength = rand() % MAX_WORDS + 1;
  guessWord = malloc(guessWordLength);

  printf("Guess the word: ");
  scanf("%s", guessWord);

  for (int i = 0; i < guessWordLength; i++) {
    if (guessWord[i] == currentWordNode->word[i]) {
      currentWordNode->word[i] = '_';
    }
  }

  printf("Your guess: %s\n", guessWord);

  free(guessWord);
  free(currentWordNode);
}

int main() {
  WordNode *head = NULL;
  insertWord(head, "apple");
  insertWord(head, "banana");
  insertWord(head, "orange");
  insertWord(head, "grape");

  playMemoryGame(head);

  return 0;
}