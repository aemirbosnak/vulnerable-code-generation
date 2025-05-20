//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: expert-level
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_CHAR 128

typedef struct Word {
  char *word;
  int length;
  struct Word *next;
} Word;

Word *createWord(char *word, int length) {
  Word *newWord = malloc(sizeof(Word));
  newWord->word = malloc(length * sizeof(char));
  newWord->length = length;
  newWord->next = NULL;
  memcpy(newWord->word, word, length * sizeof(char));
  return newWord;
}

void freeWord(Word *word) {
  free(word->word);
  free(word);
}

int main() {
  srand(time(NULL));
  int numWords = rand() % MAX_WORDS + 1;
  Word *words = NULL;

  for (int i = 0; i < numWords; i++) {
    char *word = malloc(rand() % MAX_CHAR + 1);
    word[rand() % MAX_CHAR] = '\0';
    words = createWord(word, rand() % MAX_CHAR + 1);
  }

  printf("Type the following words as quickly as possible:\n");
  for (Word *word = words; word; word = word->next) {
    printf("%s ", word->word);
  }

  char input[MAX_CHAR];
  clock_t start, end;
  start = clock();
  scanf("%s", input);
  end = clock();

  int correctWords = 0;
  for (Word *word = words; word; word = word->next) {
    if (strcmp(input, word->word) == 0) {
      correctWords++;
    }
  }

  printf("Number of correct words: %d\n", correctWords);
  printf("Time taken: %.2f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

  freeWord(words);
  return 0;
}