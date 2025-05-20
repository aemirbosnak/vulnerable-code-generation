//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void countWords(WordNode *head) {
  int wordCount = 0;

  WordNode *curr = head;

  while (curr) {
    wordCount++;
    curr = curr->next;
  }

  printf("Total number of words: %d\n", wordCount);
}

int main() {
  WordNode *head = NULL;

  char text[] = "This is a sample text with many words. Some words are repeated. The quick brown fox jumps over the lazy dog.";

  insertWord(head, "the");
  insertWord(head, "is");
  insertWord(head, "a");
  insertWord(head, "sample");
  insertWord(head, "text");
  insertWord(head, "many");
  insertWord(head, "words");
  insertWord(head, "some");
  insertWord(head, "repeated");
  insertWord(head, "quick");
  insertWord(head, "brown");
  insertWord(head, "fox");
  insertWord(head, "jumps");
  insertWord(head, "over");
  insertWord(head, "lazy");
  insertWord(head, "dog");

  countWords(head);

  return 0;
}