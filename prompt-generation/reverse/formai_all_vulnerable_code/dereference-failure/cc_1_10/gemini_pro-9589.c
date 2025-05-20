//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

// Data structures
struct Word {
  char word[MAX_WORD_LENGTH];
  int count;
};

struct WordList {
  struct Word words[MAX_WORDS];
  int size;
};

// Function prototypes
int count_words(char *string, struct WordList *word_list);
void print_word_list(struct WordList *word_list);
void free_word_list(struct WordList *word_list);

// Main function
int main(int argc, char *argv[]) {
  // Validate arguments
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <string>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Initialize word list
  struct WordList word_list;
  word_list.size = 0;

  // Count words
  int word_count = count_words(argv[1], &word_list);

  // Print word list
  printf("Word count: %d\n", word_count);
  print_word_list(&word_list);

  // Free word list
  free_word_list(&word_list);

  return EXIT_SUCCESS;
}

// Function to count words in a string
int count_words(char *string, struct WordList *word_list) {
  // Initialize variables
  int word_count = 0;
  char word[MAX_WORD_LENGTH];
  int word_length = 0;

  // Iterate over string
  for (int i = 0; string[i] != '\0'; i++) {
    char character = string[i];

    // Check for whitespace character
    if (isspace(character)) {
      // End of word
      if (word_length > 0) {
        // Add word to word list
        int index = -1;
        for (int j = 0; j < word_list->size; j++) {
          if (strcmp(word_list->words[j].word, word) == 0) {
            index = j;
            break;
          }
        }

        if (index == -1) {
          // New word
          strcpy(word_list->words[word_list->size].word, word);
          word_list->words[word_list->size].count = 1;
          word_list->size++;
        } else {
          // Existing word
          word_list->words[index].count++;
        }

        // Reset word length
        word_length = 0;
      }
    } else {
      // Non-whitespace character
      word[word_length++] = character;
    }
  }

  // Add last word to word list
  if (word_length > 0) {
    // Add word to word list
    int index = -1;
    for (int j = 0; j < word_list->size; j++) {
      if (strcmp(word_list->words[j].word, word) == 0) {
        index = j;
        break;
      }
    }

    if (index == -1) {
      // New word
      strcpy(word_list->words[word_list->size].word, word);
      word_list->words[word_list->size].count = 1;
      word_list->size++;
    } else {
      // Existing word
      word_list->words[index].count++;
    }
  }

  // Return word count
  return word_count;
}

// Function to print word list
void print_word_list(struct WordList *word_list) {
  // Iterate over word list
  for (int i = 0; i < word_list->size; i++) {
    // Print word and count
    printf("%s: %d\n", word_list->words[i].word, word_list->words[i].count);
  }
}

// Function to free word list
void free_word_list(struct WordList *word_list) {
  // No need to free individual words, since they are stored in a static array

  // Free word list itself
  free(word_list);
}