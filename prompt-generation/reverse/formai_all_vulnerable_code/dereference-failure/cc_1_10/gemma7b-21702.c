//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10

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

int detectSpam(WordNode *head, char *phrase) {
  char *words[MAX_WORDS];
  int i = 0;
  char *p = phrase;

  // Extract words from the phrase
  while (p) {
    char *word = strtok(p, " ");
    if (word) {
      words[i++] = strdup(word);
    }
    p = strtok(NULL, " ");
  }

  // Check if the extracted words are in the blacklist
  for (i = 0; i < MAX_WORDS && words[i] != NULL; i++) {
    if (strstr(words[i], head->word) != NULL) {
      return 1;
    }
  }

  return 0;
}

int main() {
  WordNode *head = insertWord(NULL, "spam");
  insertWord(head, "eggs");
  insertWord(head, "ham");

  char *phrase = "I love spam and eggs!";

  if (detectSpam(head, phrase) == 1) {
    printf("Spam detected!");
  } else {
    printf("No spam detected.");
  }

  return 0;
}