//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Create a struct to store the word and its count
typedef struct {
  char word[MAX_WORD_LENGTH + 1];
  int count;
} WordCount;

// Create an array of WordCount structs to store the words and their counts
WordCount wordCounts[1000];

// Get the next word from the input stream
char *GetNextWord(FILE *fp) {
  char *word = malloc(MAX_WORD_LENGTH + 1);
  int c;

  // Skip any whitespace characters
  while ((c = fgetc(fp)) != EOF && isspace(c))
    ;

  // Read the word
  int i = 0;
  while (c != EOF && !isspace(c)) {
    word[i++] = c;
    c = fgetc(fp);
  }

  // Add the null-terminator to the word
  word[i] = '\0';

  // Return the word
  return word;
}

// Update the word count for a given word
void UpdateWordCount(char *word) {
  int i;

  // Find the word in the array of WordCount structs
  for (i = 0; i < 1000; i++) {
    if (strcmp(wordCounts[i].word, word) == 0) {
      wordCounts[i].count++;
      return;
    }
  }

  // Add the word to the array of WordCount structs
  strcpy(wordCounts[i].word, word);
  wordCounts[i].count = 1;
}

// Print the word counts
void PrintWordCounts() {
  int i;

  for (i = 0; i < 1000; i++) {
    if (wordCounts[i].count > 0) {
      printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
  }
}

// Main function
int main() {
  FILE *fp;
  char *word;

  // Open the input file
  fp = fopen("input.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  // Get the next word from the input stream
  while ((word = GetNextWord(fp)) != NULL) {
    // Update the word count for the given word
    UpdateWordCount(word);

    // Free the memory allocated for the word
    free(word);
  }

  // Close the input file
  fclose(fp);

  // Print the word counts
  PrintWordCounts();

  return EXIT_SUCCESS;
}