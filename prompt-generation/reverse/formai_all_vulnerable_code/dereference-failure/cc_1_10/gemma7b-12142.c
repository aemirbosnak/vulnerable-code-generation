//Gemma-7B DATASET v1.0 Category: Data mining ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct Word {
  char *word;
  struct Word *next;
} Word;

Word *insertWord(Word *head, char *word) {
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->next = NULL;

  if (head == NULL) {
    head = newWord;
  } else {
    head->next = newWord;
  }

  return head;
}

int main() {
  Word *head = NULL;

  // Gather evidence
  insertWord(head, "The");
  insertWord(head, "curious");
  insertWord(head, "case");
  insertWord(head, "of");
  insertWord(head, "Sherlock");
  insertWord(head, "Holmes");
  insertWord(head, "was");
  insertWord(head, "a");
  insertWord(head, "master");
  insertWord(head, "detective");

  // Analyze the evidence
  Word *currentWord = head;
  while (currentWord) {
    printf("%s ", currentWord->word);
    currentWord = currentWord->next;
  }

  printf("\n");

  // Draw conclusions
  if (head) {
    printf("The evidence suggests that Sherlock Holmes was a master detective.\n");
  } else {
    printf("No evidence was gathered.\n");
  }

  return 0;
}