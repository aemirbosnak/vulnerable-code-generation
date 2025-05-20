//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: detailed
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

struct Word {
  char *word;
  int length;
  struct Word *next;
};

void insertWord(struct Word **head, char *word) {
  struct Word *newWord = malloc(sizeof(struct Word));
  newWord->word = strdup(word);
  newWord->length = strlen(word);
  newWord->next = NULL;

  if (*head == NULL) {
    *head = newWord;
  } else {
    (*head)->next = newWord;
  }
}

int countWords(struct Word *head) {
  int count = 0;
  struct Word *currentWord = head;

  while (currentWord) {
    count++;
    currentWord = currentWord->next;
  }

  return count;
}

int main() {
  struct Word *head = NULL;

  insertWord(&head, "apple");
  insertWord(&head, "banana");
  insertWord(&head, "cherry");
  insertWord(&head, "orange");

  int wordCount = countWords(head);

  printf("Number of words: %d\n", wordCount);

  return 0;
}