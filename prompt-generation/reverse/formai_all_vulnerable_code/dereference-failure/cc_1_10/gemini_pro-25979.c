//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *word;
  int count;
} WordFrequency;

int compareWordFrequencies(const void *a, const void *b) {
  const WordFrequency *wa = (const WordFrequency *)a;
  const WordFrequency *wb = (const WordFrequency *)b;

  return strcmp(wa->word, wb->word);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file: %s\n", argv[1]);
    return 1;
  }

  char buffer[1024];
  char *words[1024];
  int wordCount = 0;

  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    char *word = strtok(buffer, " ");
    while (word != NULL) {
      int i;
      for (i = 0; i < wordCount; i++) {
        if (strcmp(word, words[i]) == 0) {
          break;
        }
      }

      if (i == wordCount) {
        words[wordCount] = malloc(strlen(word) + 1);
        strcpy(words[wordCount], word);
        wordCount++;
      }

      word = strtok(NULL, " ");
    }
  }

  fclose(fp);

  WordFrequency wordFrequencies[wordCount];
  for (int i = 0; i < wordCount; i++) {
    wordFrequencies[i].word = words[i];
    wordFrequencies[i].count = 0;
  }

  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file: %s\n", argv[1]);
    return 1;
  }

  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    char *word = strtok(buffer, " ");
    while (word != NULL) {
      int i;
      for (i = 0; i < wordCount; i++) {
        if (strcmp(word, words[i]) == 0) {
          break;
        }
      }

      if (i != wordCount) {
        wordFrequencies[i].count++;
      }

      word = strtok(NULL, " ");
    }
  }

  fclose(fp);

  qsort(wordFrequencies, wordCount, sizeof(WordFrequency), compareWordFrequencies);

  for (int i = 0; i < wordCount; i++) {
    printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
  }

  return 0;
}