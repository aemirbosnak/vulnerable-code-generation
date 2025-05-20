//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_DICTIONARY_SIZE 1000

typedef struct {
  char *alienWord;
  char *englishWord;
} DictionaryEntry;

DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];
int dictionarySize = 0;

void loadDictionary() {
  // Open the dictionary file
  FILE *file = fopen("alien_dictionary.txt", "r");
  if (file == NULL) {
    perror("Error opening dictionary file");
    exit(EXIT_FAILURE);
  }

  // Read the dictionary entries into the array
  char line[MAX_WORD_LENGTH * 2 + 2];
  while (fgets(line, sizeof(line), file)) {
    // Parse the line into the alien word and the English word
    char *alienWord = strtok(line, ":");
    char *englishWord = strtok(NULL, ":");

    // Add the entry to the dictionary
    dictionary[dictionarySize].alienWord = malloc(strlen(alienWord) + 1);
    strcpy(dictionary[dictionarySize].alienWord, alienWord);
    dictionary[dictionarySize].englishWord = malloc(strlen(englishWord) + 1);
    strcpy(dictionary[dictionarySize].englishWord, englishWord);
    dictionarySize++;
  }

  // Close the dictionary file
  fclose(file);
}

void translateAlienWord(char *alienWord) {
  // Search the dictionary for the alien word
  for (int i = 0; i < dictionarySize; i++) {
    if (strcmp(alienWord, dictionary[i].alienWord) == 0) {
      // Found the alien word in the dictionary, so print the English translation
      printf("%s\n", dictionary[i].englishWord);
      return;
    }
  }

  // Alien word not found in the dictionary, so print an error message
  printf("Unknown alien word: %s\n", alienWord);
}

void translateEnglishWord(char *englishWord) {
  // Search the dictionary backwards for the English word
  for (int i = dictionarySize - 1; i >= 0; i--) {
    if (strcmp(englishWord, dictionary[i].englishWord) == 0) {
      // Found the English word in the dictionary, so print the alien translation
      printf("%s\n", dictionary[i].alienWord);
      return;
    }
  }

  // English word not found in the dictionary, so print an error message
  printf("Unknown English word: %s\n", englishWord);
}

int main() {
  // Load the dictionary
  loadDictionary();

  // Get the user's input
  char input[MAX_WORD_LENGTH + 1];
  printf("Enter an alien word or an English word to translate (or \"quit\" to exit): ");
  fgets(input, sizeof(input), stdin);

  // Remove the newline character from the input
  input[strcspn(input, "\n")] = 0;

  // Translate the input
  if (strcmp(input, "quit") == 0) {
    // User entered "quit", so exit the program
    return 0;
  } else if (isalpha(input[0])) {
    // Input is an English word, so translate it to alien
    translateEnglishWord(input);
  } else {
    // Input is an alien word, so translate it to English
    translateAlienWord(input);
  }

  // Return to the main loop
  main();

  return 0;
}