//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 256

// Define the maximum number of words to store
#define MAX_WORDS 10000

// Define the structure of a word
typedef struct {
  char word[MAX_WORD_LENGTH];
  int count;
} word_t;

// Define the structure of a word list
typedef struct {
  word_t words[MAX_WORDS];
  int size;
} word_list_t;

// Create a new word list
word_list_t* new_word_list() {
  word_list_t* list = malloc(sizeof(word_list_t));
  list->size = 0;
  return list;
}

// Add a word to a word list
void add_word(word_list_t* list, char* word) {
  // Convert the word to lowercase
  for (int i = 0; i < strlen(word); i++) {
    word[i] = tolower(word[i]);
  }

  // Check if the word is already in the list
  for (int i = 0; i < list->size; i++) {
    if (strcmp(list->words[i].word, word) == 0) {
      list->words[i].count++;
      return;
    }
  }

  // Add the word to the list
  strcpy(list->words[list->size].word, word);
  list->words[list->size].count = 1;
  list->size++;
}

// Sort the word list by word count
void sort_word_list(word_list_t* list) {
  for (int i = 0; i < list->size - 1; i++) {
    for (int j = i + 1; j < list->size; j++) {
      if (list->words[i].count < list->words[j].count) {
        word_t temp = list->words[i];
        list->words[i] = list->words[j];
        list->words[j] = temp;
      }
    }
  }
}

// Print the word list
void print_word_list(word_list_t* list) {
  for (int i = 0; i < list->size; i++) {
    printf("%s: %d\n", list->words[i].word, list->words[i].count);
  }
}

// Free the memory allocated by the word list
void free_word_list(word_list_t* list) {
  free(list);
}

// The main function
int main() {
  // Create a new word list
  word_list_t* list = new_word_list();

  // Read the input text
  char buffer[1024];
  while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
    // Tokenize the input text
    char* token = strtok(buffer, " ,;:!?.-");
    while (token != NULL) {
      // Add the token to the word list
      add_word(list, token);

      // Get the next token
      token = strtok(NULL, " ,;:!?.-");
    }
  }

  // Sort the word list
  sort_word_list(list);

  // Print the word list
  print_word_list(list);

  // Free the memory allocated by the word list
  free_word_list(list);

  return 0;
}