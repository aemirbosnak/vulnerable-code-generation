//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: realistic
// Alien Language Translator

// Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to translate a single word from Alien to English
char* translateWord(char* alienWord) {
  // Create a static buffer to store the translated word
  static char translatedWord[100];

  // Check if the word is in the dictionary
  if (strcmp(alienWord, "kor") == 0) {
    strcpy(translatedWord, "hello");
  } else if (strcmp(alienWord, "mar") == 0) {
    strcpy(translatedWord, "world");
  } else if (strcmp(alienWord, "sel") == 0) {
    strcpy(translatedWord, "goodbye");
  } else {
    strcpy(translatedWord, "unknown");
  }

  // Return the translated word
  return translatedWord;
}

// Function to translate a sentence from Alien to English
char* translateSentence(char* alienSentence) {
  // Allocate memory for the translated sentence
  char* translatedSentence = malloc(strlen(alienSentence) * 2);

  // Split the sentence into words
  char* words[100];
  int numWords = 0;
  char* word = strtok(alienSentence, " ");
  while (word != NULL) {
    words[numWords++] = word;
    word = strtok(NULL, " ");
  }

  // Translate each word
  for (int i = 0; i < numWords; i++) {
    strcat(translatedSentence, translateWord(words[i]));
    strcat(translatedSentence, " ");
  }

  // Remove the trailing space
  translatedSentence[strlen(translatedSentence) - 1] = '\0';

  // Return the translated sentence
  return translatedSentence;
}

// Main function
int main() {
  // Get the Alien sentence from the user
  char alienSentence[100];
  printf("Enter an Alien sentence: ");
  gets(alienSentence);

  // Translate the sentence
  char* translatedSentence = translateSentence(alienSentence);

  // Print the translated sentence
  printf("Translated sentence: %s\n", translatedSentence);

  // Free the memory allocated for the translated sentence
  free(translatedSentence);

  return 0;
}