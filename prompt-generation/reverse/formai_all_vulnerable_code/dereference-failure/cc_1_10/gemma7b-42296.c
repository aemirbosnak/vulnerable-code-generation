//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: artistic
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

  WordNode *current = head;
  WordNode *previous = NULL;

  while (current) {
    if (strcmp(newNode->word, current->word) == 0) {
      return head;
    } else if (previous) {
      previous = current;
    }
    current = current->next;
  }

  previous->next = newNode;
  return head;
}

int main() {
  WordNode *head = NULL;

  char text[] = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

  char *words[] = {"quick", "brown", "fox", "jumps", "over", "lazy", "dog"};

  for (int i = 0; i < 7; i++) {
    insertWord(head, words[i]);
  }

  WordNode *current = head;

  while (current) {
    printf("%s ", current->word);
    current = current->next;
  }

  return 0;
}