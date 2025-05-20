//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 256

typedef struct {
  char *word;
  int frequency;
} Word;

typedef struct {
  Word *words;
  int size;
} Dictionary;

Dictionary *create_dictionary(char *filename) {
  Dictionary *dictionary = malloc(sizeof(Dictionary));
  dictionary->words = NULL;
  dictionary->size = 0;

  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return NULL;
  }

  char buffer[MAX_WORD_LEN];
  while (fgets(buffer, MAX_WORD_LEN, file) != NULL) {
    char *word = malloc(strlen(buffer) + 1);
    strcpy(word, buffer);
    word[strlen(word) - 1] = '\0';

    Word *new_word = malloc(sizeof(Word));
    new_word->word = word;
    new_word->frequency = 0;

    dictionary->words = realloc(dictionary->words, (dictionary->size + 1) * sizeof(Word));
    dictionary->words[dictionary->size] = *new_word;
    dictionary->size++;
  }

  fclose(file);

  return dictionary;
}

void destroy_dictionary(Dictionary *dictionary) {
  for (int i = 0; i < dictionary->size; i++) {
    free(dictionary->words[i].word);
  }
  free(dictionary->words);
  free(dictionary);
}

int check_spelling(char *word, Dictionary *dictionary) {
  for (int i = 0; i < dictionary->size; i++) {
    if (strcmp(word, dictionary->words[i].word) == 0) {
      return 1;
    }
  }
  return 0;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <dictionary file> <text file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  Dictionary *dictionary = create_dictionary(argv[1]);
  if (dictionary == NULL) {
    return EXIT_FAILURE;
  }

  FILE *file = fopen(argv[2], "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening file %s\n", argv[2]);
    return EXIT_FAILURE;
  }

  char buffer[MAX_WORD_LEN];
  while (fgets(buffer, MAX_WORD_LEN, file) != NULL) {
    char *word = malloc(strlen(buffer) + 1);
    strcpy(word, buffer);
    word[strlen(word) - 1] = '\0';

    if (!check_spelling(word, dictionary)) {
      printf("%s: not in dictionary\n", word);
    }

    free(word);
  }

  fclose(file);
  destroy_dictionary(dictionary);

  return EXIT_SUCCESS;
}