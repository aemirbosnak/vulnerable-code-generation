//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

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

  WordNode *currNode = head;
  WordNode *prevNode = NULL;

  while (currNode) {
    if (strcmp(newNode->word, currNode->word) == 0) {
      currNode->frequency++;
      return head;
    } else if (prevNode == NULL) {
      prevNode = newNode;
    } else {
      prevNode = currNode;
      currNode = currNode->next;
    }
  }

  prevNode->next = newNode;
  return head;
}

void printWordFrequencies(WordNode *head) {
  WordNode *currNode = head;

  while (currNode) {
    printf("%s: %d\n", currNode->word, currNode->frequency);
    currNode = currNode->next;
  }
}

int main() {
  WordNode *head = NULL;

  char *text = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

  insertWord(head, "quick");
  insertWord(head, "brown");
  insertWord(head, "fox");
  insertWord(head, "jumps");
  insertWord(head, "lazy");
  insertWord(head, "over");

  printWordFrequencies(head);

  return 0;
}