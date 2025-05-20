//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the maximum number of words in the input
#define MAX_WORDS 10000

// Define the data structure for a word
typedef struct Word {
  char word[MAX_WORD_LENGTH];
  int count;
} Word;

// Define the data structure for the word list
typedef struct WordList {
  Word words[MAX_WORDS];
  int size;
} WordList;

// Create a new word list
WordList *new_word_list() {
  WordList *word_list = malloc(sizeof(WordList));
  word_list->size = 0;
  return word_list;
}

// Free the memory allocated for a word list
void free_word_list(WordList *word_list) {
  free(word_list);
}

// Add a word to the word list
void add_word_to_list(WordList *word_list, char *word) {
  // Check if the word is already in the list
  for (int i = 0; i < word_list->size; i++) {
    if (strcmp(word_list->words[i].word, word) == 0) {
      // If the word is already in the list, increment its count
      word_list->words[i].count++;
      return;
    }
  }

  // If the word is not in the list, add it to the list
  strcpy(word_list->words[word_list->size].word, word);
  word_list->words[word_list->size].count = 1;
  word_list->size++;
}

// Sort the word list in descending order of word count
void sort_word_list(WordList *word_list) {
  // Use the bubble sort algorithm to sort the word list
  for (int i = 0; i < word_list->size - 1; i++) {
    for (int j = 0; j < word_list->size - i - 1; j++) {
      if (word_list->words[j].count < word_list->words[j + 1].count) {
        // Swap the two words
        Word temp = word_list->words[j];
        word_list->words[j] = word_list->words[j + 1];
        word_list->words[j + 1] = temp;
      }
    }
  }
}

// Print the word list
void print_word_list(WordList *word_list) {
  for (int i = 0; i < word_list->size; i++) {
    printf("%s: %d\n", word_list->words[i].word, word_list->words[i].count);
  }
}

// Get the next word from the input
char *get_next_word(FILE *input) {
  // Allocate memory for the word
  char *word = malloc(MAX_WORD_LENGTH);

  // Read the next word from the input
  int c;
  int i = 0;
  while ((c = fgetc(input)) != EOF && c != ' ' && c != '\n') {
    word[i++] = c;
  }

  // Return the word
  word[i] = '\0';
  return word;
}

// Main function
int main() {
  // Open the input file
  FILE *input = fopen("input.txt", "r");
  if (input == NULL) {
    printf("Error opening input file.\n");
    return 1;
  }

  // Create a new word list
  WordList *word_list = new_word_list();

  // Read the input file and add each word to the word list
  char *word;
  while ((word = get_next_word(input)) != NULL) {
    add_word_to_list(word_list, word);
  }

  // Close the input file
  fclose(input);

  // Sort the word list in descending order of word count
  sort_word_list(word_list);

  // Print the word list
  print_word_list(word_list);

  // Free the memory allocated for the word list
  free_word_list(word_list);

  return 0;
}