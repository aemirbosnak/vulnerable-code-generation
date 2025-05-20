//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the maximum number of words in a file
#define MAX_WORDS 1000

// Create a struct to store the word and its count
typedef struct {
  char word[MAX_WORD_LENGTH];
  int count;
} Word;

// Create an array of words to store the words in the file
Word words[MAX_WORDS];

// Get the next word from the file
char *get_next_word(FILE *fp) {
  // Allocate memory for the word
  char *word = malloc(MAX_WORD_LENGTH);

  // Read the next word from the file
  int c = fgetc(fp);
  int i = 0;
  while (c != EOF && !isspace(c)) {
    word[i++] = c;
    c = fgetc(fp);
  }

  // Null-terminate the word
  word[i] = '\0';

  // Return the word
  return word;
}

// Add a word to the array of words
void add_word(char *word) {
  // Find the index of the word in the array of words
  int i = 0;
  while (i < MAX_WORDS && strcmp(words[i].word, word) != 0) {
    i++;
  }

  // If the word is not already in the array of words, add it
  if (i == MAX_WORDS) {
    strcpy(words[i].word, word);
    words[i].count = 1;
  } else {
    // If the word is already in the array of words, increment its count
    words[i].count++;
  }
}

// Print the words and their counts
void print_words() {
  // Print the header
  printf("%-20s %s\n", "Word", "Count");

  // Print the words and their counts
  for (int i = 0; i < MAX_WORDS; i++) {
    if (words[i].count > 0) {
      printf("%-20s %d\n", words[i].word, words[i].count);
    }
  }
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user specified a file name
  if (argc != 2) {
    printf("Usage: %s <file name>\n", argv[0]);
    return 1;
  }

  // Open the file
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Error opening file %s\n", argv[1]);
    return 1;
  }

  // Get the next word from the file
  char *word;
  while ((word = get_next_word(fp)) != NULL) {
    // Add the word to the array of words
    add_word(word);

    // Free the memory allocated for the word
    free(word);
  }

  // Close the file
  fclose(fp);

  // Print the words and their counts
  print_words();

  return 0;
}