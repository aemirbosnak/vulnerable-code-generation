//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define WORDS_PER_PAGE 20

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
  Word *words = insertWord(NULL, "Knuth");
  insertWord(words, "Morris");
  insertWord(words, "Papa");
  insertWord(words, "Theor");

  time_t start, end;
  start = clock();

  for (int i = 0; i < MAX_WORDS; i++) {
    for (int j = 0; j < WORDS_PER_PAGE; j++) {
      printf("%s ", words->word);
      words = words->next;
    }

    printf("\n");
  }

  end = clock();
  printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

  freeWord(words);

  return 0;
}