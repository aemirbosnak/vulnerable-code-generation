//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100

typedef struct {
  char* word;
  char* translation;
} WordTranslation;

WordTranslation dictionary[] = {
  {"hello", "ni hao"},
  {"goodbye", "zai jian"},
  {"thank you", "xie xie"},
  {"you're welcome", "bu ke qi"},
  {"yes", "shi"},
  {"no", "bu shi"},
  {"please", "qing"},
  {"excuse me", "dui bu qi"},
  {"I'm sorry", "wo hen pao qian"},
  {"I don't understand", "wo bu dong"}
};

int num_words_in_dictionary = sizeof(dictionary) / sizeof(WordTranslation);

char* translate_word(char* word) {
  for (int i = 0; i < num_words_in_dictionary; i++) {
    if (strcmp(word, dictionary[i].word) == 0) {
      return dictionary[i].translation;
    }
  }

  return NULL;
}

char* translate_sentence(char* sentence) {
  char* translated_sentence = malloc(MAX_SENTENCE_LENGTH * sizeof(char));

  char* word = strtok(sentence, " ");
  while (word != NULL) {
    char* translation = translate_word(word);
    if (translation != NULL) {
      strcat(translated_sentence, translation);
      strcat(translated_sentence, " ");
    }

    word = strtok(NULL, " ");
  }

  return translated_sentence;
}

int main() {
  char* sentence = "Hello, how are you?";
  char* translated_sentence = translate_sentence(sentence);

  printf("Original sentence: %s\n", sentence);
  printf("Translated sentence: %s\n", translated_sentence);

  free(translated_sentence);

  return 0;
}