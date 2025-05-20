//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Define the Alien language alphabet
char alien_alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Define the English language alphabet
char english_alphabet[] = "zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA";

// Function to translate a single Alien character to English
char translate_character(char alien_char) {
  int index = strchr(alien_alphabet, alien_char) - alien_alphabet;
  if (index >= 0 && index < 26) {
    return english_alphabet[index];
  } else if (index >= 26 && index < 52) {
    return english_alphabet[index - 26] + 32;
  } else {
    return alien_char;
  }
}

// Function to translate an Alien string to English
char *translate_string(char *alien_string) {
  int len = strlen(alien_string);
  char *english_string = malloc(len + 1);
  for (int i = 0; i < len; i++) {
    english_string[i] = translate_character(alien_string[i]);
  }
  english_string[len] = '\0';
  return english_string;
}

// Function to get a random Alien word
char *get_random_alien_word() {
  int len = rand() % 10 + 1;
  char *word = malloc(len + 1);
  for (int i = 0; i < len; i++) {
    word[i] = alien_alphabet[rand() % 52];
  }
  word[len] = '\0';
  return word;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get a random Alien word
  char *alien_word = get_random_alien_word();

  // Translate the Alien word to English
  char *english_word = translate_string(alien_word);

  // Print the Alien word and its English translation
  printf("Alien word: %s\n", alien_word);
  printf("English translation: %s\n", english_word);

  // Free the allocated memory
  free(alien_word);
  free(english_word);

  return 0;
}