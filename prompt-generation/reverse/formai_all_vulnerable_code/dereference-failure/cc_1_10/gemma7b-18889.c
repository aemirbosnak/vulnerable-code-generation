//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct WordNode {
  char* word;
  struct WordNode* next;
} WordNode;

WordNode* InsertWord(WordNode* head, char* word) {
  WordNode* newNode = malloc(sizeof(WordNode));
  newNode->word = strdup(word);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = InsertWord(head->next, word);
  }

  return head;
}

int WordFrequency(WordNode* head, char* word) {
  WordNode* current = head;

  while (current) {
    if (strcmp(current->word, word) == 0) {
      return 1;
    }
    current = current->next;
  }

  return 0;
}

int main() {
  WordNode* head = NULL;
  char* text = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

  InsertWord(head, "quick");
  InsertWord(head, "brown");
  InsertWord(head, "fox");
  InsertWord(head, "jumps");
  InsertWord(head, "lazy");
  InsertWord(head, "over");

  int frequency = WordFrequency(head, "quick");

  if (frequency) {
    printf("The word 'quick' appears %d times in the text.\n", frequency);
  } else {
    printf("The word 'quick' does not appear in the text.\n");
  }

  return 0;
}