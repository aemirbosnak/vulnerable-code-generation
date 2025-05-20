//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 50

// Define the maximum number of misspelled words
#define MAX_MISSPELLED_WORDS 100

// Define the dictionary
char *dictionary[] = {"a", "an", "and", "are", "as", "at", "be", "but", "by", "can"};

// Function to check if a word is misspelled
int is_misspelled(char *word) {
  // Iterate through the dictionary
  for (int i = 0; i < 10; i++) {
    // If the word is found in the dictionary, return 0
    if (strcmp(word, dictionary[i]) == 0) {
      return 0;
    }
  }

  // If the word is not found in the dictionary, return 1
  return 1;
}

// Function to find the misspelled words in a sentence
char **find_misspelled_words(char *sentence) {
  // Allocate memory for the array of misspelled words
  char **misspelled_words = malloc(MAX_MISSPELLED_WORDS * sizeof(char *));

  // Initialize the array of misspelled words
  for (int i = 0; i < MAX_MISSPELLED_WORDS; i++) {
    misspelled_words[i] = NULL;
  }

  // Tokenize the sentence
  char *token = strtok(sentence, " ");

  // Iterate through the tokens
  while (token != NULL) {
    // Check if the token is misspelled
    if (is_misspelled(token)) {
      // Add the token to the array of misspelled words
      int i = 0;
      while (misspelled_words[i] != NULL) {
        i++;
      }
      misspelled_words[i] = token;
    }

    // Get the next token
    token = strtok(NULL, " ");
  }

  // Return the array of misspelled words
  return misspelled_words;
}

// Function to print the array of misspelled words
void print_misspelled_words(char **misspelled_words) {
  // Iterate through the array of misspelled words
  for (int i = 0; i < MAX_MISSPELLED_WORDS; i++) {
    // If the misspelled word is not NULL, print it
    if (misspelled_words[i] != NULL) {
      printf("%s\n", misspelled_words[i]);
    }
  }
}

// Main function
int main() {
  // Get the sentence from the user
  char sentence[100];
  printf("Enter a sentence: ");
  gets(sentence);

  // Find the misspelled words in the sentence
  char **misspelled_words = find_misspelled_words(sentence);

  // Print the array of misspelled words
  printf("The following words are misspelled:\n");
  print_misspelled_words(misspelled_words);

  // Free the memory allocated for the array of misspelled words
  free(misspelled_words);

  return 0;
}