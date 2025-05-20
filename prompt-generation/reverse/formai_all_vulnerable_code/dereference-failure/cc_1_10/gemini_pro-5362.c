//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

typedef struct {
  char** words;
  int num_words;
} alien_dictionary;

alien_dictionary* create_alien_dictionary() {
  alien_dictionary* dict = malloc(sizeof(alien_dictionary));
  dict->words = malloc(sizeof(char*) * 100);
  dict->num_words = 0;
  return dict;
}

void add_word_to_alien_dictionary(alien_dictionary* dict, char* word) {
  dict->words[dict->num_words] = malloc(sizeof(char) * (strlen(word) + 1));
  strcpy(dict->words[dict->num_words], word);
  dict->num_words++;
}

void free_alien_dictionary(alien_dictionary* dict) {
  for (int i = 0; i < dict->num_words; i++) {
    free(dict->words[i]);
  }
  free(dict->words);
  free(dict);
}

char* translate_word_from_alien_to_english(alien_dictionary* dict, char* alien_word) {
  for (int i = 0; i < dict->num_words; i++) {
    if (strcmp(alien_word, dict->words[i]) == 0) {
      return dict->words[i];
    }
  }
  return NULL;
}

char* translate_sentence_from_alien_to_english(alien_dictionary* dict, char* alien_sentence) {
  char* english_sentence = malloc(sizeof(char) * (strlen(alien_sentence) + 1));
  char* word = strtok(alien_sentence, " ");
  while (word != NULL) {
    char* english_word = translate_word_from_alien_to_english(dict, word);
    if (english_word != NULL) {
      strcat(english_sentence, english_word);
      strcat(english_sentence, " ");
    }
    word = strtok(NULL, " ");
  }
  english_sentence[strlen(english_sentence) - 1] = '\0';
  return english_sentence;
}

int main() {
  alien_dictionary* dict = create_alien_dictionary();
  add_word_to_alien_dictionary(dict, "hello");
  add_word_to_alien_dictionary(dict, "world");
  add_word_to_alien_dictionary(dict, "how");
  add_word_to_alien_dictionary(dict, "are");
  add_word_to_alien_dictionary(dict, "you");

  char* alien_sentence = "hello world how are you";
  char* english_sentence = translate_sentence_from_alien_to_english(dict, alien_sentence);

  printf("%s\n", english_sentence);

  free_alien_dictionary(dict);
  free(english_sentence);

  return 0;
}