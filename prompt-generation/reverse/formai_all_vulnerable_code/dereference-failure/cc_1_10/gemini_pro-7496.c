//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct {
  char *word;
  int count;
} word_count;

int compare_words(const void *a, const void *b) {
  return strcmp(((word_count *)a)->word, ((word_count *)b)->word);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  char *line = NULL;
  size_t len = 0;
  ssize_t nread;

  word_count words[MAX_WORDS];
  int num_words = 0;

  while ((nread = getline(&line, &len, fp)) != -1) {
    char *p = line;
    while (*p != '\0') {
      while (*p != '\0' && *p != ' ' && *p != '\t' && *p != '\n') {
        p++;
      }
      if (*p == '\0' || *p == '\n') {
        break;
      }
      *p++ = '\0';
      int i;
      for (i = 0; i < num_words; i++) {
        if (strcmp(words[i].word, line) == 0) {
          words[i].count++;
          break;
        }
      }
      if (i == num_words) {
        if (num_words == MAX_WORDS) {
          fprintf(stderr, "Too many words\n");
          return EXIT_FAILURE;
        }
        words[num_words].word = strdup(line);
        words[num_words].count = 1;
        num_words++;
      }
      line = p;
    }
  }

  qsort(words, num_words, sizeof(word_count), compare_words);

  for (int i = 0; i < num_words; i++) {
    printf("%s: %d\n", words[i].word, words[i].count);
  }

  for (int i = 0; i < num_words; i++) {
    free(words[i].word);
  }

  free(line);
  fclose(fp);

  return EXIT_SUCCESS;
}