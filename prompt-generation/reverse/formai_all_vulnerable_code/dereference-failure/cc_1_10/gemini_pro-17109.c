//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language symbols
char alienSymbols[] = "XTGISA";

// Define the English alphabet
char englishAlphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Create a function to translate an Alien language word to English
char *alienToEnglish(char *alienWord) {
  // Allocate memory for the English translation
  char *englishTranslation = malloc(strlen(alienWord) + 1);

  // Iterate over the Alien language word
  for (int i = 0; i < strlen(alienWord); i++) {
    // Find the index of the Alien language symbol in the Alien language symbols array
    int alienSymbolIndex = strchr(alienSymbols, alienWord[i]) - alienSymbols;

    // If the Alien language symbol is not found, set the corresponding English letter to '?'
    if (alienSymbolIndex == -1) {
      englishTranslation[i] = '?';
    } else {
      // Otherwise, set the corresponding English letter to the English letter at the same index in the English alphabet array
      englishTranslation[i] = englishAlphabet[alienSymbolIndex];
    }
  }

  // Terminate the English translation with a null character
  englishTranslation[strlen(alienWord)] = '\0';

  // Return the English translation
  return englishTranslation;
}

// Create a function to translate an English word to Alien language
char *englishToAlien(char *englishWord) {
  // Allocate memory for the Alien language translation
  char *alienTranslation = malloc(strlen(englishWord) + 1);

  // Iterate over the English word
  for (int i = 0; i < strlen(englishWord); i++) {
    // Find the index of the English letter in the English alphabet array
    int englishLetterIndex = strchr(englishAlphabet, englishWord[i]) - englishAlphabet;

    // If the English letter is not found, set the corresponding Alien language symbol to 'X'
    if (englishLetterIndex == -1) {
      alienTranslation[i] = 'X';
    } else {
      // Otherwise, set the corresponding Alien language symbol to the Alien language symbol at the same index in the Alien language symbols array
      alienTranslation[i] = alienSymbols[englishLetterIndex];
    }
  }

  // Terminate the Alien language translation with a null character
  alienTranslation[strlen(englishWord)] = '\0';

  // Return the Alien language translation
  return alienTranslation;
}

// Create a main function to test the alien language translator
int main() {
  // Create an Alien language word
  char *alienWord = "XTXTXGT";

  // Translate the Alien language word to English
  char *englishTranslation = alienToEnglish(alienWord);

  // Print the English translation
  printf("English translation: %s\n", englishTranslation);

  // Create an English word
  char *englishWord = "HELLO";

  // Translate the English word to Alien language
  char *alienTranslation = englishToAlien(englishWord);

  // Print the Alien language translation
  printf("Alien language translation: %s\n", alienTranslation);

  // Free the memory allocated for the English translation
  free(englishTranslation);

  // Free the memory allocated for the Alien language translation
  free(alienTranslation);

  return 0;
}