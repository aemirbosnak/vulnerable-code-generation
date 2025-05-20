//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: Donald Knuth
/*
 * A mighty fine Alien Language Translator in C, by Donald Knuth.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The Alien language alphabet. */
char alien_alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

/* The English language alphabet. */
char english_alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

/* The translation table. */
char translation_table[256];

/*
 * Initializes the translation table.
 */
void initialize_translation_table() {
  for (int i = 0; i < 256; i++) {
    translation_table[i] = i;
  }

  for (int i = 0; i < strlen(alien_alphabet); i++) {
    translation_table[(int) alien_alphabet[i]] = english_alphabet[i];
  }
}

/*
 * Translates an Alien language string into English.
 */
char *translate_alien_to_english(char *alien_string) {
  char *english_string = malloc(strlen(alien_string) + 1);
  for (int i = 0; i < strlen(alien_string); i++) {
    english_string[i] = translation_table[(int) alien_string[i]];
  }
  english_string[strlen(alien_string)] = '\0';
  return english_string;
}

/*
 * The main function.
 */
int main() {
  initialize_translation_table();

  char *alien_string = "This is an Alien language string.";
  char *english_string = translate_alien_to_english(alien_string);

  printf("Alien string: %s\n", alien_string);
  printf("English string: %s\n", english_string);

  free(english_string);
  return 0;
}