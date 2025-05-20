//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1024

typedef struct WordNode {
  char word[MAX_WORDS];
  int count;
  struct WordNode* next;
} WordNode;

WordNode* insertWord(WordNode* head, char* word) {
  WordNode* newNode = malloc(sizeof(WordNode));
  strcpy(newNode->word, word);
  newNode->count = 1;
  newNode->next = NULL;

  if (head == NULL) {
    return newNode;
  }

  WordNode* current = head;
  WordNode* previous = NULL;

  while (current) {
    if (strcmp(newNode->word, current->word) == 0) {
      current->count++;
      return head;
    } else if (previous) {
      previous = current;
    }
    current = current->next;
  }

  previous->next = newNode;
  return head;
}

int main() {
  WordNode* head = NULL;

  char* text = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

  insertWord(head, text);

  WordNode* current = head;

  while (current) {
    printf("%s: %d\n", current->word, current->count);
    current = current->next;
  }

  return 0;
}