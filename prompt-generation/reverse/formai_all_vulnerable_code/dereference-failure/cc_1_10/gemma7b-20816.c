//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct WordNode {
  char *word;
  struct WordNode *next;
} WordNode;

WordNode *insertWord(WordNode *head, char *word) {
  WordNode *newNode = malloc(sizeof(WordNode));
  newNode->word = strdup(word);
  newNode->next = NULL;

  if (head == NULL) {
    return newNode;
  }

  WordNode *curr = head;
  WordNode *prev = NULL;

  while (curr) {
    if (strcmp(word, curr->word) == 0) {
      return head;
    } else if (prev) {
      prev = curr;
    }
    curr = curr->next;
  }

  prev->next = newNode;
  return head;
}

void printWordFrequency(WordNode *head) {
  WordNode *curr = head;
  int count = 0;

  while (curr) {
    printf("%s: %d\n", curr->word, count);
    count++;
    curr = curr->next;
  }
}

int main() {
  WordNode *head = NULL;

  char *words[] = {"apple", "banana", "orange", "apple", "banana", "grape", "mango"};

  for (int i = 0; i < sizeof(words) / sizeof(char *); i++) {
    insertWord(head, words[i]);
  }

  printWordFrequency(head);

  return 0;
}