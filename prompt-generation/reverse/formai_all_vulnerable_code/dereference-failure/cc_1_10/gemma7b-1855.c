//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define WORDS_PER_PAGE 20

typedef struct Word {
  char *word;
  struct Word *next;
} Word;

void initializeWordList(Word **head) {
  *head = NULL;
}

void addWordToList(Word **head, char *word) {
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->next = NULL;

  if (*head == NULL) {
    *head = newWord;
  } else {
    (*head)->next = newWord;
  }
}

void displayWords(Word *head) {
  while (head) {
    printf("%s ", head->word);
    head = head->next;
  }
}

int main() {
  Word *head = NULL;
  initializeWordList(&head);

  // Add some words to the list
  addWordToList(&head, "apple");
  addWordToList(&head, "banana");
  addWordToList(&head, "orange");
  addWordToList(&head, "grapefruit");

  // Display the words in the list
  displayWords(head);

  return 0;
}