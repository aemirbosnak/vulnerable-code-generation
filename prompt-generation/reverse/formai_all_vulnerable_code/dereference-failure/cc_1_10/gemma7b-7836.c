//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024

typedef struct WordNode {
  char *word;
  struct WordNode *next;
} WordNode;

WordNode *word_node_insert(WordNode *head, char *word) {
  WordNode *newNode = malloc(sizeof(WordNode));
  newNode->word = strdup(word);
  newNode->next = NULL;

  if (head == NULL) {
    return newNode;
  }

  WordNode *traverser = head;
  while (traverser->next) {
    traverser = traverser->next;
  }

  traverser->next = newNode;

  return head;
}

int word_frequency(WordNode *head, char *word) {
  WordNode *traverser = head;
  while (traverser) {
    if (strcmp(traverser->word, word) == 0) {
      return 1;
    }
    traverser = traverser->next;
  }

  return 0;
}

int main() {
  WordNode *head = NULL;

  head = word_node_insert(head, "The");
  head = word_node_insert(head, "Quick");
  head = word_node_insert(head, "Brown");
  head = word_node_insert(head, "Fox");
  head = word_node_insert(head, "Jumped");

  int frequency = word_frequency(head, "Quick");

  printf("The frequency of the word 'Quick' is: %d\n", frequency);

  return 0;
}