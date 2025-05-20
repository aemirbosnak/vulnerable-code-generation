//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct AlienLanguageTranslator {
  char *buffer;
  int capacity;
  int pos;
} AlienLanguageTranslator;

AlienLanguageTranslator *translate_alien_language(int capacity)
{
  AlienLanguageTranslator *translator = malloc(sizeof(AlienLanguageTranslator));
  translator->buffer = malloc(capacity * sizeof(char));
  translator->capacity = capacity;
  translator->pos = 0;

  return translator;
}

void translate_alien_language_add_char(AlienLanguageTranslator *translator, char character)
{
  if (translator->pos >= translator->capacity - 1) {
    translator->buffer = realloc(translator->buffer, translator->capacity * 2 * sizeof(char));
    translator->capacity *= 2;
  }

  translator->buffer[translator->pos++] = character;
}

void translate_alien_language_print(AlienLanguageTranslator *translator)
{
  for (int i = 0; i < translator->pos; i++) {
    printf("%c", translator->buffer[i]);
  }
}

int main()
{
  AlienLanguageTranslator *translator = translate_alien_language(MAX_BUFFER_SIZE);

  translate_alien_language_add_char(translator, 'a');
  translate_alien_language_add_char(translator, 'b');
  translate_alien_language_add_char(translator, 'c');
  translate_alien_language_add_char(translator, 'd');

  translate_alien_language_print(translator);

  free(translator->buffer);
  free(translator);

  return 0;
}