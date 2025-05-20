//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct WordNode {
  char *word;
  int frequency;
  struct WordNode *next;
} WordNode;

WordNode *insertWord(WordNode *head, char *word) {
  WordNode *newNode = malloc(sizeof(WordNode));
  newNode->word = strdup(word);
  newNode->frequency = 1;
  newNode->next = NULL;

  if (head == NULL) {
    return newNode;
  }

  WordNode *traversal = head;
  while (traversal->next) {
    traversal = traversal->next;
  }

  traversal->next = newNode;
  return head;
}

int main() {
  WordNode *head = NULL;
  char text[] = "This is a sample text that will be analyzed to find word frequency.";

  // Insert words into the linked list
  insertWord(head, "is");
  insertWord(head, "a");
  insertWord(head, "sample");
  insertWord(head, "text");
  insertWord(head, "that");
  insertWord(head, "will");
  insertWord(head, "be");
  insertWord(head, "analyzed");
  insertWord(head, "word");
  insertWord(head, "frequency");

  // Print word frequency
  WordNode *traversal = head;
  while (traversal) {
    printf("%s: %d\n", traversal->word, traversal->frequency);
    traversal = traversal->next;
  }

  return 0;
}