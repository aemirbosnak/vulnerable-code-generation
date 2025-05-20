//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: lively
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
    head = newNode;
  } else {
    head->next = insertWord(head->next, word);
  }

  return head;
}

int wordFrequency(WordNode *head, char *word) {
  WordNode *current = head;

  while (current) {
    if (strcmp(current->word, word) == 0) {
      return 1;
    }
    current = current->next;
  }

  return 0;
}

int main() {
  WordNode *wordHead = NULL;

  char *text = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

  char *words[] = {"quick", "brown", "fox", "jumps", "lazy", "over", "the", "quick", "brown", "fox"};

  for (int i = 0; i < 10; i++) {
    insertWord(wordHead, words[i]);
  }

  for (int i = 0; i < 10; i++) {
    printf("%s occurs %d times\n", words[i], wordFrequency(wordHead, words[i]));
  }

  return 0;
}