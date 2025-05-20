//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: portable
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
    return newNode;
  }

  WordNode *curr = head;
  WordNode *prev = NULL;

  while (curr) {
    if (strcmp(newNode->word, curr->word) == 0) {
      return head;
    } else if (prev) {
      prev = curr;
    }
    curr = curr->next;
  }

  prev->next = newNode;
  return head;
}

void printWordFrequency(WordNode *head) {
  WordNode *curr = head;

  while (curr) {
    int frequency = 0;
    WordNode *temp = head;

    while (temp) {
      if (strcmp(curr->word, temp->word) == 0) {
        frequency++;
      }
      temp = temp->next;
    }

    printf("%s: %d\n", curr->word, frequency);
    curr = curr->next;
  }
}

int main() {
  WordNode *head = NULL;
  char *text = "This is a sample text that contains many words. Some words are repeated multiple times.";

  insertWord(head, text);

  printWordFrequency(head);

  return 0;
}