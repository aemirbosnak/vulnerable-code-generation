//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the maximum number of words in the file
#define MAX_WORDS 1000

// Define the structure of a word
typedef struct word {
  char* word;
  int count;
} word;

// Define the structure of the word frequency counter
typedef struct word_frequency_counter {
  word* words;
  int num_words;
} word_frequency_counter;

// Create a new word frequency counter
word_frequency_counter* create_word_frequency_counter() {
  word_frequency_counter* wfc = malloc(sizeof(word_frequency_counter));
  wfc->words = malloc(sizeof(word) * MAX_WORDS);
  wfc->num_words = 0;
  return wfc;
}

// Destroy a word frequency counter
void destroy_word_frequency_counter(word_frequency_counter* wfc) {
  for (int i = 0; i < wfc->num_words; i++) {
    free(wfc->words[i].word);
  }
  free(wfc->words);
  free(wfc);
}

// Add a word to the word frequency counter
void add_word(word_frequency_counter* wfc, char* word) {
  // Check if the word is already in the word frequency counter
  for (int i = 0; i < wfc->num_words; i++) {
    if (strcmp(wfc->words[i].word, word) == 0) {
      wfc->words[i].count++;
      return;
    }
  }

  // If the word is not in the word frequency counter, add it
  wfc->words[wfc->num_words].word = strdup(word);
  wfc->words[wfc->num_words].count = 1;
  wfc->num_words++;
}

// Print the word frequency counter
void print_word_frequency_counter(word_frequency_counter* wfc) {
  for (int i = 0; i < wfc->num_words; i++) {
    printf("%s: %d\n", wfc->words[i].word, wfc->words[i].count);
  }
}

// Read a file and count the frequency of each word
word_frequency_counter* read_file(char* filename) {
  // Open the file
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    return NULL;
  }

  // Create a word frequency counter
  word_frequency_counter* wfc = create_word_frequency_counter();

  // Read the file line by line
  char line[1000];
  while (fgets(line, sizeof(line), file)) {
    // Tokenize the line into words
    char* word = strtok(line, " ");
    while (word != NULL) {
      // Remove punctuation from the word
      for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
          word[i] = '\0';
        }
      }

      // Add the word to the word frequency counter
      add_word(wfc, word);

      // Get the next word
      word = strtok(NULL, " ");
    }
  }

  // Close the file
  fclose(file);

  // Return the word frequency counter
  return wfc;
}

// Main function
int main() {
  // Read the file
  word_frequency_counter* wfc = read_file("file.txt");

  // Print the word frequency counter
  print_word_frequency_counter(wfc);

  // Destroy the word frequency counter
  destroy_word_frequency_counter(wfc);

  return 0;
}