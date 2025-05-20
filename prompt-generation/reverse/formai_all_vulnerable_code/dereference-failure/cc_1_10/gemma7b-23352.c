//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: imaginative
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
    WordNode* traverse = head;
    while (traverse->next) {
      traverse = traverse->next;
    }
    traverse->next = newNode;
  }

  return head;
}

void PrintWordFrequency(WordNode* head) {
  int wordCount = 0;
  WordNode* traverse = head;
  while (traverse) {
    wordCount++;
    printf("%s: %d\n", traverse->word, wordCount);
    traverse = traverse->next;
  }

  printf("Total words: %d\n", wordCount);
}

int main() {
  WordNode* head = NULL;

  char* text = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

  char* words[] = {"quick", "brown", "fox", "jumps", "over", "lazy", "dog", "The"};

  for (int i = 0; i < 8; i++) {
    InsertWord(head, words[i]);
  }

  PrintWordFrequency(head);

  return 0;
}