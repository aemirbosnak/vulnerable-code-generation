//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 1024

typedef struct Word {
  char *word;
  struct Word *next;
} Word;

typedef struct Translator {
  Word *dictionary;
  char **language_map;
  int language_map_size;
} Translator;

Translator *create_translator(int language_map_size) {
  Translator *translator = malloc(sizeof(Translator));
  translator->dictionary = NULL;
  translator->language_map = NULL;
  translator->language_map_size = language_map_size;

  return translator;
}

void add_word(Translator *translator, char *word) {
  Word *new_word = malloc(sizeof(Word));
  new_word->word = strdup(word);
  new_word->next = translator->dictionary;
  translator->dictionary = new_word;
}

char *translate(Translator *translator, char *source) {
  char *target = malloc(MAX_WORD_LENGTH);
  char *word = strtok(source, " ");

  while (word) {
    Word *word_search = translator->dictionary;

    while (word_search) {
      if (strcmp(word, word_search->word) == 0) {
        sprintf(target, "%s ", word_search->word);
        break;
      } else if (word_search->next) {
        word_search = word_search->next;
      } else {
        break;
      }
    }

    if (word_search == NULL) {
      sprintf(target, "UNKNOWN WORD: %s ", word);
    }

    word = strtok(NULL, " ");
  }

  return target;
}

int main() {
  Translator *translator = create_translator(2);
  add_word(translator, "hello");
  add_word(translator, "world");
  add_word(translator, "programmer");

  char *source = "Hello, world, my dear programmer.";
  char *target = translate(translator, source);

  printf("%s\n", target);

  return 0;
}