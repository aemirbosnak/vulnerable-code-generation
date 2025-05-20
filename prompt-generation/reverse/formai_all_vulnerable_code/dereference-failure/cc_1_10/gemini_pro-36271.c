//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to hold a word and its translation
typedef struct {
  char *word;
  char *translation;
} Word;

// Array of known words and their translations
Word dictionary[] = {
  {"hello", "salu"},
  {"world", "mondo"},
  {"computer", "calcolatore"},
  {"programming", "programmazione"},
  {"language", "lingua"},
  {"alien", "alieno"},
  {"translator", "traduttore"},
  {"example", "esempio"},
  {"unique", "unico"},
  {"dynamic", "dinamico"},
  {"creative", "creativo"},
  {"compile", "compilare"},
  {"run", "eseguire"},
  {"error", "errore"}
};

// Number of words in the dictionary
int dictionary_size = sizeof(dictionary) / sizeof(Word);

// Function to translate a word
char *translate(char *word) {
  for (int i = 0; i < dictionary_size; i++) {
    if (strcmp(word, dictionary[i].word) == 0) {
      return dictionary[i].translation;
    }
  }

  // Word not found in the dictionary
  return NULL;
}

// Function to translate a sentence
char *translate_sentence(char *sentence) {
  // Split the sentence into words
  char *words[100];
  int num_words = 0;
  char *word = strtok(sentence, " ");
  while (word != NULL) {
    words[num_words++] = word;
    word = strtok(NULL, " ");
  }

  // Translate each word and concatenate the translations
  char *translation[100];
  int num_translations = 0;
  for (int i = 0; i < num_words; i++) {
    char *t = translate(words[i]);
    if (t != NULL) {
      translation[num_translations++] = t;
    }
  }

  // Join the translations into a single string
  char *joined_translation = malloc(1000);
  joined_translation[0] = '\0';
  for (int i = 0; i < num_translations; i++) {
    strcat(joined_translation, translation[i]);
    strcat(joined_translation, " ");
  }

  // Return the joined translation
  return joined_translation;
}

int main() {
  // Get the sentence from the user
  char sentence[1000];
  printf("Enter a sentence in English: ");
  fgets(sentence, 1000, stdin);

  // Translate the sentence
  char *translation = translate_sentence(sentence);

  // Print the translation
  printf("Translation: %s\n", translation);

  // Free the memory allocated for the translation
  free(translation);

  return 0;
}