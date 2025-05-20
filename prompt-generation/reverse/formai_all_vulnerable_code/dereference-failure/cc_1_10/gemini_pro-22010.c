//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_DICTIONARY_SIZE 1000

typedef struct {
  char *alien_word;
  char *english_word;
} DictionaryEntry;

DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];
int dictionary_size = 0;

void load_dictionary() {
  FILE *file = fopen("dictionary.txt", "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening dictionary file\n");
    exit(1);
  }

  char line[256];
  while (fgets(line, sizeof(line), file)) 
  {
    char *alien_word = strtok(line, " ");
    char *english_word = strtok(NULL, "\n");

    if (alien_word == NULL || english_word == NULL) {
      fprintf(stderr, "Error parsing dictionary line: %s\n", line);
      exit(1);
    }

    dictionary[dictionary_size].alien_word = strdup(alien_word);
    dictionary[dictionary_size].english_word = strdup(english_word);
    dictionary_size++;
  }

  fclose(file);
}

char *translate_word(char *alien_word) {
  for (int i = 0; i < dictionary_size; i++) {
    if (strcmp(alien_word, dictionary[i].alien_word) == 0) {
      return dictionary[i].english_word;
    }
  }

  return NULL;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <alien_text_file>\n", argv[0]);
    exit(1);
  }

  load_dictionary();

  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening alien text file\n");
    exit(1);
  }

  char line[256];
  while (fgets(line, sizeof(line), file)) {
    char *alien_word = strtok(line, " ");
    while (alien_word != NULL) {
      char *english_word = translate_word(alien_word);
      if (english_word != NULL) {
        printf("%s ", english_word);
      } else {
        printf("<unknown> ");
      }
      alien_word = strtok(NULL, " ");
    }
    printf("\n");
  }

  fclose(file);

  return 0;
}