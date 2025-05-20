//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
  char *word;
  int count;
} word_count;

int compare_word_count(const void *a, const void *b) {
  const word_count *wa = (const word_count *)a;
  const word_count *wb = (const word_count *)b;
  return strcmp(wa->word, wb->word);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  // Read the file into a string.
  fseek(fp, 0, SEEK_END);
  long file_size = ftell(fp);
  rewind(fp);
  char *file_contents = malloc(file_size + 1);
  if (file_contents == NULL) {
    perror("malloc");
    fclose(fp);
    return EXIT_FAILURE;
  }
  fread(file_contents, file_size, 1, fp);
  fclose(fp);
  file_contents[file_size] = '\0';

  // Tokenize the string into words.
  char *token = strtok(file_contents, " \n\t\r\f\v");
  int num_words = 0;
  while (token != NULL) {
    num_words++;
    token = strtok(NULL, " \n\t\r\f\v");
  }

  // Count the frequency of each word.
  word_count *word_counts = malloc(num_words * sizeof(word_count));
  if (word_counts == NULL) {
    perror("malloc");
    free(file_contents);
    return EXIT_FAILURE;
  }
  token = strtok(file_contents, " \n\t\r\f\v");
  int i = 0;
  while (token != NULL) {
    int found = 0;
    for (int j = 0; j < i; j++) {
      if (strcmp(token, word_counts[j].word) == 0) {
        word_counts[j].count++;
        found = 1;
        break;
      }
    }
    if (!found) {
      word_counts[i].word = strdup(token);
      word_counts[i].count = 1;
      i++;
    }
    token = strtok(NULL, " \n\t\r\f\v");
  }

  // Sort the word counts by word.
  qsort(word_counts, i, sizeof(word_count), compare_word_count);

  // Print the word counts.
  for (int j = 0; j < i; j++) {
    printf("%s: %d\n", word_counts[j].word, word_counts[j].count);
  }

  // Free the allocated memory.
  for (int j = 0; j < i; j++) {
    free(word_counts[j].word);
  }
  free(word_counts);
  free(file_contents);

  return EXIT_SUCCESS;
}