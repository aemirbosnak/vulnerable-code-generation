//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the maximum number of words in the dictionary
#define MAX_WORDS 1000

// Define the structure of a word
typedef struct word {
  char *word;
  int count;
} word;

// Define the structure of the dictionary
typedef struct dictionary {
  word words[MAX_WORDS];
  int size;
} dictionary;

// Create a new dictionary
dictionary *new_dictionary() {
  dictionary *dict = malloc(sizeof(dictionary));
  dict->size = 0;
  return dict;
}

// Add a word to the dictionary
void add_word(dictionary *dict, char *word) {
  // Convert the word to lowercase
  for (int i = 0; i < strlen(word); i++) {
    word[i] = tolower(word[i]);
  }

  // Check if the word is already in the dictionary
  for (int i = 0; i < dict->size; i++) {
    if (strcmp(dict->words[i].word, word) == 0) {
      dict->words[i].count++;
      return;
    }
  }

  // Add the word to the dictionary
  dict->words[dict->size].word = strdup(word);
  dict->words[dict->size].count = 1;
  dict->size++;
}

// Free the memory allocated for the dictionary
void free_dictionary(dictionary *dict) {
  for (int i = 0; i < dict->size; i++) {
    free(dict->words[i].word);
  }
  free(dict);
}

// Print the dictionary
void print_dictionary(dictionary *dict) {
  for (int i = 0; i < dict->size; i++) {
    printf("%s: %d\n", dict->words[i].word, dict->words[i].count);
  }
}

// Read a file and count the number of occurrences of each word
dictionary *count_words(char *filename) {
  // Open the file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Create a new dictionary
  dictionary *dict = new_dictionary();

  // Read the file line by line
  char line[1024];
  while (fgets(line, sizeof(line), file)) {
    // Tokenize the line into words
    char *word = strtok(line, " ");
    while (word != NULL) {
      // Add the word to the dictionary
      add_word(dict, word);

      // Get the next word
      word = strtok(NULL, " ");
    }
  }

  // Close the file
  fclose(file);

  // Return the dictionary
  return dict;
}

// Main function
int main(int argc, char *argv[]) {
  // Check if there is a filename specified
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Count the words in the file
  dictionary *dict = count_words(argv[1]);

  // Print the dictionary
  print_dictionary(dict);

  // Free the memory allocated for the dictionary
  free_dictionary(dict);

  return 0;
}