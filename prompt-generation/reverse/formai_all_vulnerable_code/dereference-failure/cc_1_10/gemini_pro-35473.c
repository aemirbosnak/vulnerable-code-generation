//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language alphabet
char *alien_alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+=-~`";

// Define the English alphabet
char *english_alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+=-~`";

// Function to translate an Alien word to English
char *alien_to_english(char *alien_word) {
  // Allocate memory for the English translation
  char *english_word = malloc(strlen(alien_word) + 1);

  // Translate each character in the Alien word to English
  for (int i = 0; i < strlen(alien_word); i++) {
    for (int j = 0; j < strlen(alien_alphabet); j++) {
      if (alien_word[i] == alien_alphabet[j]) {
        english_word[i] = english_alphabet[j];
        break;
      }
    }
  }

  // Add the null-terminator to the English translation
  english_word[strlen(alien_word)] = '\0';

  // Return the English translation
  return english_word;
}

// Function to translate an English word to Alien
char *english_to_alien(char *english_word) {
  // Allocate memory for the Alien translation
  char *alien_word = malloc(strlen(english_word) + 1);

  // Translate each character in the English word to Alien
  for (int i = 0; i < strlen(english_word); i++) {
    for (int j = 0; j < strlen(english_alphabet); j++) {
      if (english_word[i] == english_alphabet[j]) {
        alien_word[i] = alien_alphabet[j];
        break;
      }
    }
  }

  // Add the null-terminator to the Alien translation
  alien_word[strlen(english_word)] = '\0';

  // Return the Alien translation
  return alien_word;
}

// Main function
int main() {
  // Get the Alien word from the user
  char *alien_word = malloc(100);
  printf("Enter an Alien word: ");
  scanf("%s", alien_word);

  // Translate the Alien word to English
  char *english_word = alien_to_english(alien_word);

  // Print the English translation
  printf("English translation: %s\n", english_word);

  // Free the memory allocated for the Alien and English words
  free(alien_word);
  free(english_word);

  return 0;
}