//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: rigorous
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
    head->next = insertWord(head->next, word);
  }

  return head;
}

int wordFrequency(WordNode *head, char *word) {
  WordNode *current = head;

  while (current) {
    if (strcmp(current->word, word) == 0) {
      return 1;
    }
    current = current->next;
  }

  return 0;
}

int main() {
  WordNode *head = NULL;
  char *text = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

  insertWord(head, "the");
  insertWord(head, "quick");
  insertWord(head, "brown");
  insertWord(head, "fox");
  insertWord(head, "jumps");
  insertWord(head, "over");
  insertWord(head, "lazy");
  insertWord(head, "dog");

  int frequency = wordFrequency(head, "quick");

  printf("The frequency of the word 'quick' is: %d\n", frequency);

  return 0;
}