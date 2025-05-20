//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALIEN_WORDS 100
#define MAX_ALIEN_WORD_LENGTH 100

// The Alien Language Dictionary
typedef struct {
  char *alien_word;
  char *english_translation;
} AlienLanguageDictionaryEntry;

// The Alien Language Translator
typedef struct {
  AlienLanguageDictionaryEntry *dictionary;
  int num_dictionary_entries;
} AlienLanguageTranslator;

// Create a new Alien Language Translator
AlienLanguageTranslator *create_alien_language_translator() {
  AlienLanguageTranslator *translator = malloc(sizeof(AlienLanguageTranslator));
  translator->dictionary = NULL;
  translator->num_dictionary_entries = 0;
  return translator;
}

// Destroy an Alien Language Translator
void destroy_alien_language_translator(AlienLanguageTranslator *translator) {
  if (translator->dictionary != NULL) {
    for (int i = 0; i < translator->num_dictionary_entries; i++) {
      free(translator->dictionary[i].alien_word);
      free(translator->dictionary[i].english_translation);
    }
    free(translator->dictionary);
  }
  free(translator);
}

// Add a new word to the Alien Language Dictionary
void add_word_to_dictionary(AlienLanguageTranslator *translator, char *alien_word, char *english_translation) {
  translator->dictionary = realloc(translator->dictionary, (translator->num_dictionary_entries + 1) * sizeof(AlienLanguageDictionaryEntry));
  translator->dictionary[translator->num_dictionary_entries].alien_word = strdup(alien_word);
  translator->dictionary[translator->num_dictionary_entries].english_translation = strdup(english_translation);
  translator->num_dictionary_entries++;
}

// Translate an Alien word to English
char *translate_alien_word(AlienLanguageTranslator *translator, char *alien_word) {
  for (int i = 0; i < translator->num_dictionary_entries; i++) {
    if (strcmp(translator->dictionary[i].alien_word, alien_word) == 0) {
      return translator->dictionary[i].english_translation;
    }
  }
  return NULL;
}

// Translate an English word to Alien
char *translate_english_word(AlienLanguageTranslator *translator, char *english_word) {
  for (int i = 0; i < translator->num_dictionary_entries; i++) {
    if (strcmp(translator->dictionary[i].english_translation, english_word) == 0) {
      return translator->dictionary[i].alien_word;
    }
  }
  return NULL;
}

// Print the Alien Language Dictionary
void print_dictionary(AlienLanguageTranslator *translator) {
  for (int i = 0; i < translator->num_dictionary_entries; i++) {
    printf("%s: %s\n", translator->dictionary[i].alien_word, translator->dictionary[i].english_translation);
  }
}

// Main function
int main() {
  // Create a new Alien Language Translator
  AlienLanguageTranslator *translator = create_alien_language_translator();

  // Add some words to the dictionary
  add_word_to_dictionary(translator, "xarpti", "hello");
  add_word_to_dictionary(translator, "xarpti an", "hello there");
  add_word_to_dictionary(translator, "xarpti en", "hello world");
  add_word_to_dictionary(translator, "xarpti na", "hello my friend");
  add_word_to_dictionary(translator, "xarpti na an", "hello my friend there");
  add_word_to_dictionary(translator, "xarpti na en", "hello my friend world");

  // Print the dictionary
  print_dictionary(translator);

  // Translate some words
  char *alien_word = "xarpti";
  char *english_translation = translate_alien_word(translator, alien_word);
  printf("%s: %s\n", alien_word, english_translation);

  char *english_word = "hello";
  char *alien_translation = translate_english_word(translator, english_word);
  printf("%s: %s\n", english_word, alien_translation);

  // Destroy the translator
  destroy_alien_language_translator(translator);

  return 0;
}