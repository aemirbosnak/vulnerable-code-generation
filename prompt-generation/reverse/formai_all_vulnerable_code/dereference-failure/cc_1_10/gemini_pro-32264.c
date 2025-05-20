//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of words in a file
#define MAX_WORDS 10000

// Define the maximum length of a word
#define MAX_WORD_LENGTH 256

// Define the structure of a word
typedef struct word {
  char *word;
  int count;
} word;

// Define the structure of a word list
typedef struct word_list {
  word *words;
  int num_words;
} word_list;

// Function to create a new word list
word_list *word_list_new() {
  word_list *wl = malloc(sizeof(word_list));
  wl->words = malloc(MAX_WORDS * sizeof(word));
  wl->num_words = 0;
  return wl;
}

// Function to free a word list
void word_list_free(word_list *wl) {
  for (int i = 0; i < wl->num_words; i++) {
    free(wl->words[i].word);
  }
  free(wl->words);
  free(wl);
}

// Function to add a word to a word list
void word_list_add(word_list *wl, char *word) {
  // Check if the word is already in the list
  for (int i = 0; i < wl->num_words; i++) {
    if (strcmp(wl->words[i].word, word) == 0) {
      wl->words[i].count++;
      return;
    }
  }

  // If the word is not in the list, add it to the end
  wl->words[wl->num_words].word = strdup(word);
  wl->words[wl->num_words].count = 1;
  wl->num_words++;
}

// Function to print a word list
void word_list_print(word_list *wl) {
  for (int i = 0; i < wl->num_words; i++) {
    printf("%s: %d\n", wl->words[i].word, wl->words[i].count);
  }
}

// Function to read a file and count the words
word_list *word_count(char *filename) {
  // Open the file
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Create a new word list
  word_list *wl = word_list_new();

  // Read the file line by line
  char line[1024];
  while (fgets(line, sizeof(line), fp)) {
    // Tokenize the line into words
    char *word = strtok(line, " ");
    while (word != NULL) {
      // Add the word to the word list
      word_list_add(wl, word);

      // Get the next word
      word = strtok(NULL, " ");
    }
  }

  // Close the file
  fclose(fp);

  // Return the word list
  return wl;
}

// Main function
int main(int argc, char *argv[]) {
  // Check if a filename was specified
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Read the file and count the words
  word_list *wl = word_count(argv[1]);

  // Print the word list
  word_list_print(wl);

  // Free the word list
  word_list_free(wl);

  return 0;
}