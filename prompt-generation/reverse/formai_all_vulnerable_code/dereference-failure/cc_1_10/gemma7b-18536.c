//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: decentralized
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

  WordNode *currNode = head;
  while (currNode->next) {
    currNode = currNode->next;
  }

  currNode->next = newNode;

  return head;
}

int main() {
  WordNode *wordHead = NULL;

  // Get the text to analyze
  char text[] = "This is a sample text with many words. Some words are repeated. The frequency of each word is counted and stored in a linked list.";

  // Split the text into words
  char *wordPtr = strtok(text, " ");

  // Insert each word into the linked list
  while (wordPtr) {
    insertWord(wordHead, wordPtr);
    wordPtr = strtok(NULL, " ");
  }

  // Print the word frequency
  WordNode *currNode = wordHead;
  while (currNode) {
    printf("%s: %d\n", currNode->word, currNode->frequency);
    currNode = currNode->next;
  }

  return 0;
}