//Gemma-7B DATASET v1.0 Category: Data mining ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 1024

typedef struct Word {
  char *word;
  int frequency;
  struct Word *next;
} Word;

Word *insertWord(Word *head, char *word) {
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->frequency = 1;
  newWord->next = NULL;

  if (head == NULL) {
    return newWord;
  }

  Word *currWord = head;
  while (currWord->next) {
    currWord = currWord->next;
  }

  currWord->next = newWord;

  return head;
}

void analyzeText(char *text) {
  Word *head = NULL;

  char *words = strtok(text, " ");
  while (words) {
    insertWord(head, words);
    words = strtok(NULL, " ");
  }

  // Calculate word frequencies
  Word *currWord = head;
  while (currWord) {
    currWord->frequency++;
    currWord = currWord->next;
  }

  // Print word frequencies
  printf("Word frequencies:\n");
  currWord = head;
  while (currWord) {
    printf("%s: %d\n", currWord->word, currWord->frequency);
    currWord = currWord->next;
  }
}

int main() {
  analyzeText("The quick brown fox jumps over the lazy dog.");

  return 0;
}