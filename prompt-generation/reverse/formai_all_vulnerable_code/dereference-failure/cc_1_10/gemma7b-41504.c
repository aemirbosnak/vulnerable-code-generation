//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WORDS 100000

typedef struct WordEntry {
  char *word;
  int count;
  struct WordEntry *next;
} WordEntry;

WordEntry *insertWord(WordEntry *head, char *word) {
  WordEntry *newEntry = malloc(sizeof(WordEntry));
  newEntry->word = strdup(word);
  newEntry->count = 1;
  newEntry->next = NULL;

  if (head == NULL) {
    return newEntry;
  }

  WordEntry *current = head;
  WordEntry *previous = NULL;

  while (current) {
    if (strcmp(word, current->word) == 0) {
      current->count++;
      return head;
    } else if (previous) {
      previous = current;
    }
    current = current->next;
  }

  previous->next = newEntry;
  return head;
}

int countWords(WordEntry *head) {
  int count = 0;

  while (head) {
    count++;
    head = head->next;
  }

  return count;
}

int main() {
  WordEntry *head = NULL;

  insertWord(head, "apple");
  insertWord(head, "banana");
  insertWord(head, "orange");
  insertWord(head, "grape");
  insertWord(head, "apple");

  int wordCount = countWords(head);

  printf("Total number of words: %d\n", wordCount);

  return 0;
}