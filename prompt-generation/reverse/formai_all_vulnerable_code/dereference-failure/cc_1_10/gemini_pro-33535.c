//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 256
#define MAX_DICTIONARY_SIZE 10000

typedef struct {
  char *alien_word;
  char *english_word;
} DictionaryEntry;

DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];
int dictionary_size = 0;

void load_dictionary(char *filename) {
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    perror("Error opening dictionary file");
    exit(1);
  }

  while (!feof(f)) {
    char alien_word[MAX_WORD_LENGTH];
    char english_word[MAX_WORD_LENGTH];
    fscanf(f, "%s %s\n", alien_word, english_word);
    if (strlen(alien_word) > 0 && strlen(english_word) > 0) {
      dictionary[dictionary_size].alien_word = strdup(alien_word);
      dictionary[dictionary_size].english_word = strdup(english_word);
      dictionary_size++;
    }
  }

  fclose(f);
}

char *translate_word(char *alien_word) {
  for (int i = 0; i < dictionary_size; i++) {
    if (!strcmp(alien_word, dictionary[i].alien_word)) {
      return dictionary[i].english_word;
    }
  }

  return NULL;
}

void translate_sentence(char *sentence) {
  char *token;
  token = strtok(sentence, " ");
  while (token != NULL) {
    char *english_word = translate_word(token);
    if (english_word != NULL) {
      printf("%s ", english_word);
    } else {
      printf("%s ", token);
    }
    token = strtok(NULL, " ");
  }
  printf("\n");
}

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("Usage: %s dictionary.txt sentence\n", argv[0]);
    return 1;
  }

  load_dictionary(argv[1]);
  translate_sentence(argv[2]);

  return 0;
}