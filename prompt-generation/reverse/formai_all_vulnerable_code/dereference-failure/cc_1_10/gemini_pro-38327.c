//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
  char word[MAX_WORD_LENGTH];
  int count;
} Word;

int compareWords(const void *a, const void *b) {
  const Word *wa = (const Word *)a;
  const Word *wb = (const Word *)b;
  return strcmp(wa->word, wb->word);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  char *buffer = malloc(10000);
  if (buffer == NULL) {
    perror("malloc");
    return EXIT_FAILURE;
  }

  fread(buffer, 1, 10000, fp);
  fclose(fp);

  char *words[MAX_WORDS];
  int numWords = 0;

  char *token = strtok(buffer, " ");
  while (token != NULL) {
    if (numWords < MAX_WORDS) {
      words[numWords] = malloc(strlen(token) + 1);
      if (words[numWords] == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
      }
      strcpy(words[numWords], token);
      numWords++;
    }
    token = strtok(NULL, " ");
  }

  Word wordCounts[MAX_WORDS];
  for (int i = 0; i < numWords; i++) {
    strcpy(wordCounts[i].word, words[i]);
    wordCounts[i].count = 0;
  }

  for (int i = 0; i < numWords; i++) {
    for (int j = 0; j < numWords; j++) {
      if (strcmp(wordCounts[i].word, words[j]) == 0) {
        wordCounts[i].count++;
      }
    }
  }

  qsort(wordCounts, numWords, sizeof(Word), compareWords);

  for (int i = 0; i < numWords; i++) {
    printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
  }

  for (int i = 0; i < numWords; i++) {
    free(words[i]);
  }
  free(buffer);

  return EXIT_SUCCESS;
}