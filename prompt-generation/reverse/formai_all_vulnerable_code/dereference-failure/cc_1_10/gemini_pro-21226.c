//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the dictionary
char *dictionary[] = {"love", "heart", "passion", "romance", "desire", "affection", "intimacy", "adoration", "devotion", "cherish"};

// Define the maximum word length
#define MAX_WORD_LENGTH 20

// Get a word from the user
char *get_word(void) {
  char *word = malloc(MAX_WORD_LENGTH);
  printf("Enter a word: ");
  scanf("%s", word);
  return word;
}

// Check if a word is in the dictionary
int is_in_dictionary(char *word) {
  for (int i = 0; i < sizeof(dictionary) / sizeof(char *); i++) {
    if (strcmp(word, dictionary[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

// Print a message indicating whether the word is spelled correctly
void print_result(char *word, int is_correct) {
  if (is_correct) {
    printf("Your word, '%s', is spelled correctly.\n", word);
  } else {
    printf("Your word, '%s', is not spelled correctly.\n", word);
  }
}

// Main function
int main(void) {
  // Get the word from the user
  char *word = get_word();

  // Check if the word is in the dictionary
  int is_correct = is_in_dictionary(word);

  // Print the result
  print_result(word, is_correct);

  // Free the memory allocated for the word
  free(word);

  return 0;
}