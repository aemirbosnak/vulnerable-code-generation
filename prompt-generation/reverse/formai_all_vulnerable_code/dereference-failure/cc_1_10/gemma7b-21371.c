//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000

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
    head->next = insertWord(head->next, word);
  }

  return head;
}

void freeWord(Word *word) {
  free(word->word);
  free(word);
}

int main() {
  Word *head = NULL;

  clock_t start, end;
  double timeTaken;

  start = clock();

  // Generate a list of words
  for (int i = 0; i < MAX_WORDS; i++) {
    insertWord(head, "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
  }

  end = clock();

  timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Time taken to insert %d words: %.2f seconds\n", MAX_WORDS, timeTaken);

  // Free the list of words
  freeWord(head);

  return 0;
}