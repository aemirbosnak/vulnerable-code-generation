//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to translate an alien word to English
char *alienToEnglish(char *alienWord) {
  // Create a string to store the English translation
  char *englishWord = malloc(strlen(alienWord) + 1);

  // Copy the alien word to the English word
  strcpy(englishWord, alienWord);

  // Replace all occurrences of "a" with "e"
  for (int i = 0; i < strlen(englishWord); i++) {
    if (englishWord[i] == 'a') {
      englishWord[i] = 'e';
    }
  }

  // Replace all occurrences of "e" with "o"
  for (int i = 0; i < strlen(englishWord); i++) {
    if (englishWord[i] == 'e') {
      englishWord[i] = 'o';
    }
  }

  // Replace all occurrences of "i" with "u"
  for (int i = 0; i < strlen(englishWord); i++) {
    if (englishWord[i] == 'i') {
      englishWord[i] = 'u';
    }
  }

  // Replace all occurrences of "o" with "a"
  for (int i = 0; i < strlen(englishWord); i++) {
    if (englishWord[i] == 'o') {
      englishWord[i] = 'a';
    }
  }

  // Replace all occurrences of "u" with "i"
  for (int i = 0; i < strlen(englishWord); i++) {
    if (englishWord[i] == 'u') {
      englishWord[i] = 'i';
    }
  }

  // Return the English translation
  return englishWord;
}

// Function to translate an English word to Alien
char *englishToAlien(char *englishWord) {
  // Create a string to store the Alien translation
  char *alienWord = malloc(strlen(englishWord) + 1);

  // Copy the English word to the Alien word
  strcpy(alienWord, englishWord);

  // Replace all occurrences of "e" with "a"
  for (int i = 0; i < strlen(alienWord); i++) {
    if (alienWord[i] == 'e') {
      alienWord[i] = 'a';
    }
  }

  // Replace all occurrences of "o" with "e"
  for (int i = 0; i < strlen(alienWord); i++) {
    if (alienWord[i] == 'o') {
      alienWord[i] = 'e';
    }
  }

  // Replace all occurrences of "u" with "i"
  for (int i = 0; i < strlen(alienWord); i++) {
    if (alienWord[i] == 'u') {
      alienWord[i] = 'i';
    }
  }

  // Replace all occurrences of "a" with "o"
  for (int i = 0; i < strlen(alienWord); i++) {
    if (alienWord[i] == 'a') {
      alienWord[i] = 'o';
    }
  }

  // Replace all occurrences of "i" with "u"
  for (int i = 0; i < strlen(alienWord); i++) {
    if (alienWord[i] == 'i') {
      alienWord[i] = 'u';
    }
  }

  // Return the Alien translation
  return alienWord;
}

// Main function
int main() {
  // Get the alien word from the user
  char alienWord[100];
  printf("Enter the alien word: ");
  scanf("%s", alienWord);

  // Translate the alien word to English
  char *englishWord = alienToEnglish(alienWord);

  // Print the English translation
  printf("The English translation is: %s\n", englishWord);

  // Translate the English word back to Alien
  char *alienWord2 = englishToAlien(englishWord);

  // Print the Alien translation
  printf("The Alien translation is: %s\n", alienWord2);

  // Free the memory allocated for the English and Alien translations
  free(englishWord);
  free(alienWord2);

  return 0;
}