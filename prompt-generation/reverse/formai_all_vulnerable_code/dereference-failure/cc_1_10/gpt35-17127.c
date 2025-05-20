//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100

// Helper function to print alien language translations
void printTranslation(char* alienLanguage, char* englishTranslation) {
  printf("Alien Language: %s --- English Translation: %s\n", alienLanguage, englishTranslation);
}

// Main function for translating C Alien Language to English
int main() {
  // Declare variables
  char* input = malloc(sizeof(char) * MAX_INPUT);
  char* token;
  char* delimiters = " ,.?!"; // Possible delimiters in the sentences
  char* englishWords[100];
  int translationIndex = 0;

  // Print welcome message
  printf("Welcome to the C Alien Language Translator!\n\n");

  // Get input from user
  printf("Please enter a sentence in C Alien Language (end with period):\n");
  fgets(input, MAX_INPUT, stdin);

  // Get rid of the newline character at the end of the string
  input[strcspn(input, "\n")] = '\0';

  // Tokenize the input
  token = strtok(input, delimiters);

  while (token != NULL) {
    if (strcmp(token, "int") == 0) {
      englishWords[translationIndex] = "integer";
    } else if (strcmp(token, "char") == 0) {
      englishWords[translationIndex] = "character";
    } else if (strcmp(token, "float") == 0) {
      englishWords[translationIndex] = "floating point number";
    } else if (strcmp(token, "double") == 0) {
      englishWords[translationIndex] = "double precision number";
    } else if (strcmp(token, "if") == 0) {
      englishWords[translationIndex] = "conditional statement";
    } else if (strcmp(token, "else") == 0) {
      englishWords[translationIndex] = "alternative statement";
    } else if (strcmp(token, "for") == 0) {
      englishWords[translationIndex] = "repeating statement";
    } else if (strcmp(token, "while") == 0) {
      englishWords[translationIndex] = "conditional repeating statement";
    } else if (strcmp(token, "do") == 0) {
      englishWords[translationIndex] = "repeating conditional statement";
    } else if (strcmp(token, "switch") == 0) {
      englishWords[translationIndex] = "control statement";
    } else {
      englishWords[translationIndex] = "unknown";
    }

    // Print the translation of the word
    printTranslation(token, englishWords[translationIndex]);

    // Move to next word
    token = strtok(NULL, delimiters);
    translationIndex++;
  }

  // Say goodbye!
  printf("\nThank you for using the C Alien Language Translator!\n");

  return 0;
}