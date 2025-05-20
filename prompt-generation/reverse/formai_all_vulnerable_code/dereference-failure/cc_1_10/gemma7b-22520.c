//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

typedef struct Node {
  char **words;
  struct Node *next;
} Node;

void insertWord(Node *node, char *word) {
  if (node == NULL) {
    node = malloc(sizeof(Node));
    node->words = malloc(sizeof(char *) * MAX_WORDS);
    node->next = NULL;
  }

  int i = 0;
  for (; i < MAX_WORDS && node->words[i] != NULL; i++) {}

  node->words[i] = strdup(word);
}

int detectSpam(char *text) {
  Node *head = NULL;

  char *words = strtok(text, " ");
  while (words) {
    insertWord(head, words);
    words = strtok(NULL, " ");
  }

  int spamScore = 0;
  for (Node *node = head; node; node) {
    char **words = node->words;
    for (int i = 0; words[i] != NULL; i++) {
      if (strcmp(words[i], "buy") == 0 || strcmp(words[i], "sell") == 0) {
        spamScore++;
      }
    }
  }

  return spamScore;
}

int main() {
  char *text = "This is a sample text with some spam words like buy and sell.";

  int spamScore = detectSpam(text);

  printf("Spam score: %d\n", spamScore);

  return 0;
}