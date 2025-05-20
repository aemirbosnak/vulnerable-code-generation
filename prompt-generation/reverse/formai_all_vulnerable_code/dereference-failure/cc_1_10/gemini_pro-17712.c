//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LEN 100

typedef struct {
  char *word;
  int count;
} word_t;

int compare_words(const void *a, const void *b) {
  return strcmp(((word_t *)a)->word, ((word_t *)b)->word);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <text file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  char *text = malloc(MAX_LEN * MAX_WORDS);
  if (text == NULL) {
    perror("malloc");
    return EXIT_FAILURE;
  }

  int len = fread(text, sizeof(char), MAX_LEN * MAX_WORDS, fp);
  if (len == 0) {
    fprintf(stderr, "fread: empty file\n");
    return EXIT_FAILURE;
  }

  fclose(fp);

  char *words[MAX_WORDS];
  int counts[MAX_WORDS];
  int nwords = 0;

  char *token = strtok(text, " ");
  while (token != NULL) {
    int i;
    for (i = 0; i < nwords; i++) {
      if (strcmp(token, words[i]) == 0) {
        counts[i]++;
        break;
      }
    }
    if (i == nwords) {
      words[nwords] = strdup(token);
      counts[nwords] = 1;
      nwords++;
    }
    token = strtok(NULL, " ");
  }

  qsort(words, nwords, sizeof(word_t), compare_words);

  int i;
  for (i = 0; i < nwords; i++) {
    printf("%s: %d\n", words[i], counts[i]);
  }

  return EXIT_SUCCESS;
}