//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024
#define MAX_WORD_LENGTH 256

typedef struct WordNode {
  char word[MAX_WORD_LENGTH];
  struct WordNode* next;
} WordNode;

WordNode* insertWord(WordNode* head, char* word) {
  WordNode* newNode = malloc(sizeof(WordNode));
  strcpy(newNode->word, word);
  newNode->next = NULL;

  if (head == NULL) {
    return newNode;
  }

  WordNode* current = head;
  WordNode* previous = NULL;

  while (current) {
    if (strcmp(newNode->word, current->word) == 0) {
      return head;
    } else if (previous) {
      previous = current;
    }
    current = current->next;
  }

  previous->next = newNode;
  return head;
}

void printWordFrequency(WordNode* head) {
  WordNode* current = head;

  while (current) {
    printf("%s: %d\n", current->word, countOccurrences(head, current->word));
    current = current->next;
  }
}

int countOccurrences(WordNode* head, char* word) {
  WordNode* current = head;

  while (current) {
    if (strcmp(word, current->word) == 0) {
      return 1 + countOccurrences(head, current->word);
    }
    current = current->next;
  }

  return 0;
}

int main() {
  WordNode* head = NULL;

  insertWord(head, "hello");
  insertWord(head, "world");
  insertWord(head, "hello");
  insertWord(head, "foo");
  insertWord(head, "bar");

  printWordFrequency(head);

  return 0;
}