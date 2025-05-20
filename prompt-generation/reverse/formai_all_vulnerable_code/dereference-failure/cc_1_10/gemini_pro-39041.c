//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Initialize the dictionary with a list of common words
const char* dictionary[] = {"the", "of", "and", "a", "to", "in", "is", "it", "you", "that"};

// Check if a word is in the dictionary
int is_in_dictionary(const char* word) {
  for (int i = 0; i < sizeof(dictionary) / sizeof(const char*); i++) {
    if (strcmp(word, dictionary[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

// Check if a word is a valid word
int is_valid_word(const char* word) {
  if (strlen(word) == 0) {
    return 0;
  }
  for (int i = 0; i < strlen(word); i++) {
    if (!isalpha(word[i])) {
      return 0;
    }
  }
  return 1;
}

// Suggest a list of corrections for a misspelled word
char** suggest_corrections(const char* word) {
  char** suggestions = malloc(sizeof(char*) * 5);
  for (int i = 0; i < 5; i++) {
    suggestions[i] = malloc(sizeof(char) * 20);
  }

  // Try replacing each character with every other character in the alphabet
  for (int i = 0; i < strlen(word); i++) {
    for (int j = 0; j < 26; j++) {
      char new_word[20];
      strcpy(new_word, word);
      new_word[i] = 'a' + j;
      if (is_in_dictionary(new_word)) {
        suggestions[i] = new_word;
      }
    }
  }

  // Try adding a character to the beginning of the word
  for (int i = 0; i < 26; i++) {
    char new_word[20];
    strcpy(new_word, word);
    new_word[0] = 'a' + i;
    if (is_in_dictionary(new_word)) {
      suggestions[i + 26] = new_word;
    }
  }

  // Try removing a character from the end of the word
  for (int i = 0; i < strlen(word); i++) {
    char new_word[20];
    strcpy(new_word, word);
    new_word[strlen(new_word) - 1] = '\0';
    if (is_in_dictionary(new_word)) {
      suggestions[i + 52] = new_word;
    }
  }

  return suggestions;
}

// Get a word from the user
char* get_word() {
  char* word = malloc(sizeof(char) * 20);
  printf("Enter a word: ");
  scanf("%s", word);
  return word;
}

// Print a list of suggestions
void print_suggestions(char** suggestions) {
  printf("Did you mean:\n");
  for (int i = 0; i < 5; i++) {
    printf("  %s\n", suggestions[i]);
  }
}

// Main function
int main() {
  // Get a word from the user
  char* word = get_word();

  // Check if the word is valid
  if (!is_valid_word(word)) {
    printf("Invalid word.\n");
    return 1;
  }

  // Check if the word is in the dictionary
  if (is_in_dictionary(word)) {
    printf("Word is correct.\n");
    return 0;
  } else {
    // Suggest a list of corrections
    char** suggestions = suggest_corrections(word);

    // Print the list of suggestions
    print_suggestions(suggestions);

    // Free the memory allocated for the suggestions
    for (int i = 0; i < 5; i++) {
      free(suggestions[i]);
    }
    free(suggestions);
  }

  // Free the memory allocated for the word
  free(word);

  return 0;
}