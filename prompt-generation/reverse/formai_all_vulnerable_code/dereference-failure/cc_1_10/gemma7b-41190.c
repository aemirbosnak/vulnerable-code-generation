//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: Donald Knuth
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 100
#define WORDS_PER_LINE 20

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
  char **words = malloc(MAX_WORDS * sizeof(char *));

  for (int i = 0; i < MAX_WORDS; i++) {
    words[i] = malloc(WORDS_PER_LINE * sizeof(char));
  }

  time_t start, end;
  start = time(NULL);

  // Type as fast as you can
  for (int i = 0; i < MAX_WORDS; i++) {
    printf("%s ", words[i]);
  }

  end = time(NULL);

  printf("\nTime taken: %ld seconds\n", end - start);

  freeWord(head);
  for (int i = 0; i < MAX_WORDS; i++) {
    free(words[i]);
  }

  free(words);

  return 0;
}