//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct WordNode {
  char word[MAX_WORDS];
  int frequency;
  struct WordNode* next;
} WordNode;

WordNode* insertWord(WordNode* head, char* word) {
  WordNode* newNode = malloc(sizeof(WordNode));
  strcpy(newNode->word, word);
  newNode->frequency = 1;
  newNode->next = NULL;

  if (head == NULL) {
    return newNode;
  }

  WordNode* current = head;
  WordNode* previous = NULL;

  while (current) {
    if (strcmp(newNode->word, current->word) == 0) {
      current->frequency++;
      return head;
    } else if (previous) {
      previous = current;
    }
    current = current->next;
  }

  previous->next = newNode;
  return head;
}

void printWordFrequency(WordNode* head) {
  WordNode* current = head;

  while (current) {
    printf("%s: %d\n", current->word, current->frequency);
    current = current->next;
  }
}

int main() {
  WordNode* head = NULL;

  char* text = "This is a sample text that contains many words. The word 'sample' appears twice, while 'text' appears three times. Some other words, such as 'a' and 'the', also appear multiple times.";

  insertWord(head, text);

  printWordFrequency(head);

  return 0;
}