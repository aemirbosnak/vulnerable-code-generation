//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of words in a string
int wordCount(char *str) {
  int count = 0;
  int i = 0;
  int inWord = 0;

  while (str[i] != '\0') {
    if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
      inWord = 0;
    } else if (!inWord) {
      count++;
      inWord = 1;
    }
    i++;
  }

  return count;
}

// Function to count the number of characters in a string
int charCount(char *str) {
  int count = 0;
  int i = 0;

  while (str[i] != '\0') {
    count++;
    i++;
  }

  return count;
}

// Function to count the number of lines in a string
int lineCount(char *str) {
  int count = 0;
  int i = 0;

  while (str[i] != '\0') {
    if (str[i] == '\n') {
      count++;
    }
    i++;
  }

  return count;
}

// Main function
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Open the file
  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  // Read the file into a string
  fseek(file, 0, SEEK_END);
  long int size = ftell(file);
  fseek(file, 0, SEEK_SET);
  char *str = malloc(size + 1);
  if (str == NULL) {
    perror("malloc");
    fclose(file);
    return EXIT_FAILURE;
  }
  fread(str, 1, size, file);
  str[size] = '\0';

  // Close the file
  fclose(file);

  // Count the number of words, characters, and lines in the string
  int words = wordCount(str);
  int chars = charCount(str);
  int lines = lineCount(str);

  // Print the results
  printf("Words: %d\n", words);
  printf("Characters: %d\n", chars);
  printf("Lines: %d\n", lines);

  // Free the memory allocated for the string
  free(str);

  return EXIT_SUCCESS;
}