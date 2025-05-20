//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent the Alien language
typedef struct {
  char *alphabet;  // The alien alphabet
  int num_letters; // The number of letters in the alphabet
  char *translation[26]; // The translation table for the English alphabet
} AlienLanguage;

// Function to create a new Alien language
AlienLanguage *create_alien_language(char *alphabet, int num_letters) {
  AlienLanguage *language = malloc(sizeof(AlienLanguage));
  language->alphabet = malloc(num_letters + 1);
  strcpy(language->alphabet, alphabet);
  language->num_letters = num_letters;
  for (int i = 0; i < 26; i++) {
    language->translation[i] = NULL;
  }
  return language;
}

// Function to destroy an Alien language
void destroy_alien_language(AlienLanguage *language) {
  free(language->alphabet);
  for (int i = 0; i < 26; i++) {
    free(language->translation[i]);
  }
  free(language);
}

// Function to add a translation to an Alien language
void add_translation(AlienLanguage *language, char english_letter,
                      char alien_letter) {
  language->translation[english_letter - 'a'] = malloc(2);
  language->translation[english_letter - 'a'][0] = alien_letter;
  language->translation[english_letter - 'a'][1] = '\0';
}

// Function to translate a string from English to an Alien language
char *translate_to_alien(AlienLanguage *language, char *english) {
  int length = strlen(english);
  char *alien = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    char alien_letter = language->translation[english[i] - 'a'][0];
    alien[i] = alien_letter;
  }
  alien[length] = '\0';
  return alien;
}

// Function to translate a string from an Alien language to English
char *translate_to_english(AlienLanguage *language, char *alien) {
  int length = strlen(alien);
  char *english = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    char english_letter = 0;
    for (int j = 0; j < 26; j++) {
      if (strcmp(language->translation[j], alien[i]) == 0) {
        english_letter = j + 'a';
        break;
      }
    }
    english[i] = english_letter;
  }
  english[length] = '\0';
  return english;
}

int main() {
  // Create an Alien language
  AlienLanguage *language = create_alien_language("abcdefghijklmnopqrstuvwxyz", 26);

  // Add some translations
  add_translation(language, 'a', 'b');
  add_translation(language, 'b', 'c');
  add_translation(language, 'c', 'd');
  add_translation(language, 'd', 'e');
  add_translation(language, 'e', 'f');

  // Translate a string from English to the Alien language
  char *alien = translate_to_alien(language, "Hello");
  printf("English: Hello\n");
  printf("Alien: %s\n", alien);

  // Translate a string from the Alien language to English
  char *english = translate_to_english(language, alien);
  printf("Alien: %s\n", alien);
  printf("English: %s\n", english);

  // Destroy the Alien language
  destroy_alien_language(language);

  return 0;
}