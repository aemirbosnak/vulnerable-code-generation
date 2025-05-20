//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000

typedef struct {
  char *word;
  int count;
} WordCount;

int compare_words(const void *a, const void *b) {
  WordCount *wa = (WordCount *)a;
  WordCount *wb = (WordCount *)b;
  return strcmp(wa->word, wb->word);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    fprintf(stderr, "Error: could not open file %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  char *buffer = malloc(1024);
  if (buffer == NULL) {
    fprintf(stderr, "Error: could not allocate memory\n");
    return EXIT_FAILURE;
  }

  WordCount words[MAX_WORDS];
  int num_words = 0;

  while (fgets(buffer, 1024, file) != NULL) {
    char *word = strtok(buffer, " \t\n");
    while (word != NULL) {
      int found = 0;
      for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i].word, word) == 0) {
          words[i].count++;
          found = 1;
          break;
        }
      }
      if (!found) {
        words[num_words].word = strdup(word);
        words[num_words].count = 1;
        num_words++;
      }
      word = strtok(NULL, " \t\n");
    }
  }

  qsort(words, num_words, sizeof(WordCount), compare_words);

  for (int i = 0; i < num_words; i++) {
    printf("%s: %d\n", words[i].word, words[i].count);
  }

  free(buffer);
  for (int i = 0; i < num_words; i++) {
    free(words[i].word);
  }
  fclose(file);

  return EXIT_SUCCESS;
}