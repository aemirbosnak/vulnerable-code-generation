//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 255

typedef struct WordNode {
  char word[MAX_WORD_LENGTH];
  int frequency;
  struct WordNode* next;
} WordNode;

WordNode* insertWord(WordNode* head, char* word) {
  WordNode* newNode = malloc(sizeof(WordNode));
  strcpy(newNode->word, word);
  newNode->frequency = 1;
  newNode->next = NULL;

  if (head == NULL) {
    return newNode;
  }

  WordNode* current = head;
  WordNode* previous = NULL;

  while (current) {
    if (strcmp(newNode->word, current->word) == 0) {
      current->frequency++;
      free(newNode);
      return head;
    }

    previous = current;
    current = current->next;
  }

  previous->next = newNode;
  return head;
}

void printWordFrequency(WordNode* head) {
  WordNode* current = head;

  while (current) {
    printf("%s: %d\n", current->word, current->frequency);
    current = current->next;
  }
}

int main() {
  WordNode* head = NULL;

  char* text = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

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