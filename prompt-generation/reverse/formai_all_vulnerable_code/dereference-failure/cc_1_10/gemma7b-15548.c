//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: future-proof
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

  WordNode *currNode = head;
  WordNode *prevNode = NULL;

  while (currNode) {
    if (strcmp(currNode->word, word) == 0) {
      return head;
    } else if (prevNode == NULL) {
      prevNode = currNode;
    }
    currNode = currNode->next;
  }

  prevNode->next = newNode;
  return head;
}

int countWords(WordNode *head) {
  int count = 0;

  WordNode *currNode = head;

  while (currNode) {
    count++;
    currNode = currNode->next;
  }

  return count;
}

int main() {
  WordNode *head = NULL;

  insertWord(head, "apple");
  insertWord(head, "banana");
  insertWord(head, "cherry");
  insertWord(head, "orange");

  int wordCount = countWords(head);

  printf("Number of words: %d\n", wordCount);

  return 0;
}