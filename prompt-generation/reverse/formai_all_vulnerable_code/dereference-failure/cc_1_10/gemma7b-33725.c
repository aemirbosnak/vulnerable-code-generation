//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct WordNode {
  char word[MAX_WORDS];
  int frequency;
  struct WordNode* next;
} WordNode;

WordNode* InsertWord(WordNode* head, char* word) {
  WordNode* newNode = malloc(sizeof(WordNode));
  strcpy(newNode->word, word);
  newNode->frequency = 1;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    WordNode* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = newNode;
  }

  return head;
}

int CountWords(WordNode* head) {
  int count = 0;
  WordNode* current = head;
  while (current) {
    count++;
    current = current->next;
  }
  return count;
}

int main() {
  WordNode* head = NULL;
  char text[] = "This is a sample text with many words. The words are repeated many times.";

  InsertWord(head, text);

  int wordCount = CountWords(head);
  printf("Number of words in the text: %d", wordCount);

  return 0;
}