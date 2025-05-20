//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: Dennis Ritchie
#include <stdio.h>
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
    WordNode *traverse = head;
    while (traverse->next) {
      traverse = traverse->next;
    }
    traverse->next = newNode;
  }

  return head;
}

int countWords(WordNode *head) {
  int count = 0;
  WordNode *traverse = head;

  while (traverse) {
    count++;
    traverse = traverse->next;
  }

  return count;
}

int main() {
  WordNode *head = NULL;

  insertWord(head, "apple");
  insertWord(head, "banana");
  insertWord(head, "orange");
  insertWord(head, "grape");

  int wordCount = countWords(head);

  printf("Total number of words: %d\n", wordCount);

  return 0;
}