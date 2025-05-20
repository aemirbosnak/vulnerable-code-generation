//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of a word
#define MAX_WORD_SIZE 100

// Function to read a word from a file
char *read_word(FILE *fp) {
  char *word = malloc(MAX_WORD_SIZE);
  int c;
  int i = 0;
  while ((c = fgetc(fp)) != EOF && c != ' ' && c != '\n') {
    word[i++] = c;
  }
  word[i] = '\0';
  return word;
}

// Function to process a word
char *process_word(char *word) {
  // Convert the word to lowercase
  int i;
  for (i = 0; i < strlen(word); i++) {
    word[i] = tolower(word[i]);
  }
  return word;
}

// Function to write a word to a file
void write_word(FILE *fp, char *word) {
  fprintf(fp, "%s ", word);
}

// Main function
int main() {
  // Open the input and output files
  FILE *fp_in = fopen("input.txt", "r");
  FILE *fp_out = fopen("output.txt", "w");

  // Read the words from the input file
  char *word;
  while ((word = read_word(fp_in))) {
    // Process the word
    word = process_word(word);
    // Write the word to the output file
    write_word(fp_out, word);
    // Free the memory allocated for the word
    free(word);
  }

  // Close the input and output files
  fclose(fp_in);
  fclose(fp_out);

  return 0;
}