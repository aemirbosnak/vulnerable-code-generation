//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024

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
    WordNode *curr = head;
    while (curr->next) {
      curr = curr->next;
    }
    curr->next = newNode;
  }

  return head;
}

void printWordFrequency(WordNode *head) {
  printf("Word frequency:\n");
  WordNode *curr = head;
  while (curr) {
    printf("%s: %d\n", curr->word, countOccurrences(head, curr->word));
  }
}

int countOccurrences(WordNode *head, char *word) {
  WordNode *curr = head;
  int count = 0;
  while (curr) {
    if (strcmp(curr->word, word) == 0) {
      count++;
    }
    curr = curr->next;
  }
  return count;
}

int main() {
  WordNode *head = NULL;

  char *text = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

  insertWord(head, "the");
  insertWord(head, "quick");
  insertWord(head, "brown");
  insertWord(head, "fox");
  insertWord(head, "jumps");
  insertWord(head, "over");
  insertWord(head, "lazy");
  insertWord(head, "dog");

  printWordFrequency(head);

  return 0;
}