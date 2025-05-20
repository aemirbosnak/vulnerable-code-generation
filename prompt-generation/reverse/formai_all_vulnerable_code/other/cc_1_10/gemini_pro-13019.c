//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#define N(x) (sizeof(x) / sizeof((x)[0]))
#define S(x) #x
#define P(x, ...) printf(S(x) "\n", ##__VA_ARGS__)
#define F(x, ...) fprintf(stderr, S(x) "\n", ##__VA_ARGS__)

struct {
  char *word;
  int count;
} * words;

int nwords;

int compare(const void *a, const void *b) {
  const struct { char *word; int count; } *x = a, *y = b;
  return strcmp(x->word, y->word);
}

void add(char *word) {
  if (nwords >= 100000) {
    F("Too many words (%d).", nwords);
    exit(EXIT_FAILURE);
  }
  words = realloc(words, (nwords + 1) * sizeof(*words));
  assert(words);
  words[nwords].word = strdup(word);
  words[nwords].count = 1;
  nwords++;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s FILE\n", argv[0]);
    return EXIT_FAILURE;
  }
  FILE *f = fopen(argv[1], "r");
  if (!f) {
    perror(argv[1]);
    return EXIT_FAILURE;
  }
  char buf[1024];
  clock_t start = clock();
  while (fgets(buf, N(buf), f)) {
    char *word, *rest = buf;
    while ((word = strtok_r(rest, ",. \t\n", &rest))) {
      add(word);
    }
  }
  fclose(f);
  clock_t end = clock();
  qsort(words, nwords, sizeof(*words), compare);
  for (int i = 0; i < nwords; i++) {
    P("%s: %d", words[i].word, words[i].count);
  }
  F("Counted %d words in %.3f seconds.", nwords, (double)(end - start) / CLOCKS_PER_SEC);
  for (int i = 0; i < nwords; i++) {
    free(words[i].word);
  }
  free(words);
  return EXIT_SUCCESS;
}