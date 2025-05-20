//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold the word and its count
typedef struct word_count {
  char *word;
  int count;
} word_count;

// Define a function to compare two word_count structs by their word
int compare_word_count(const void *a, const void *b) {
  const word_count *wa = (const word_count *)a;
  const word_count *wb = (const word_count *)b;
  return strcmp(wa->word, wb->word);
}

// Define a function to count the words in a string
word_count *count_words(const char *str) {
  // Allocate memory for the word_count array
  word_count *word_counts = malloc(sizeof(word_count));
  int word_count_size = 1;

  // Tokenize the string and count the words
  char *token = strtok(str, " ,.-");
  while (token != NULL) {
    // Check if the word is already in the array
    int found = 0;
    for (int i = 0; i < word_count_size; i++) {
      if (strcmp(token, word_counts[i].word) == 0) {
        word_counts[i].count++;
        found = 1;
        break;
      }
    }

    // If the word is not in the array, add it
    if (!found) {
      word_counts = realloc(word_counts, sizeof(word_count) * (word_count_size + 1));
      word_counts[word_count_size].word = malloc(strlen(token) + 1);
      strcpy(word_counts[word_count_size].word, token);
      word_counts[word_count_size].count = 1;
      word_count_size++;
    }

    // Get the next token
    token = strtok(NULL, " ,.-");
  }

  // Sort the word_count array by word
  qsort(word_counts, word_count_size, sizeof(word_count), compare_word_count);

  // Return the word_count array
  return word_counts;
}

// Define a function to print the word_count array
void print_word_count(word_count *word_counts, int word_count_size) {
  for (int i = 0; i < word_count_size; i++) {
    printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
  }
}

// Get the input string from the user
char *get_input_string() {
  // Allocate memory for the input string
  char *input_string = malloc(1024);

  // Get the input string from the user
  printf("Enter a string: ");
  fgets(input_string, 1024, stdin);

  // Remove the newline character from the input string
  input_string[strcspn(input_string, "\n")] = 0;

  // Return the input string
  return input_string;
}

// Main function
int main() {
  // Get the input string from the user
  char *input_string = get_input_string();

  // Count the words in the input string
  word_count *word_counts = count_words(input_string);

  // Get the number of words in the input string
  int word_count_size = 0;
  while (word_counts[word_count_size].word != NULL) {
    word_count_size++;
  }

  // Print the word_count array
  print_word_count(word_counts, word_count_size);

  // Free the memory allocated for the word_count array
  for (int i = 0; i < word_count_size; i++) {
    free(word_counts[i].word);
  }
  free(word_counts);

  // Free the memory allocated for the input string
  free(input_string);

  return 0;
}