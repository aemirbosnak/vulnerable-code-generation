//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: visionary
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

  WordNode *traverse = head;
  while (traverse->next) {
    if (strcmp(traverse->word, word) == 0) {
      traverse->frequency++;
      return head;
    }
    traverse = traverse->next;
  }

  traverse->next = newNode;
  return head;
}

void printWordFrequency(WordNode *head) {
  printf("Word frequency:\n");
  WordNode *traverse = head;
  while (traverse) {
    printf("%s: %d\n", traverse->word, traverse->frequency);
    traverse = traverse->next;
  }
}

int main() {
  WordNode *head = NULL;
  char *text = "This is a sample text with many words. The words are repeated many times. Some words are unique. But there are also some common words, such as the, a, and a.";

  insertWord(head, text);

  printWordFrequency(head);

  return 0;
}