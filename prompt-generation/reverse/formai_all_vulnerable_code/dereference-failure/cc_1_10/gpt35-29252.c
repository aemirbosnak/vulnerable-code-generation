//FormAI DATASET v1.0 Category: Text processing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program counts the number of times a given word appears in a text file */

int main(int argc, char *argv[]) {

  // Check that the program was given the correct number of arguments
  if (argc != 3) {
    printf("Usage: %s <text file> <word>\n", argv[0]);
    return 1;
  }

  // Open the text file for reading
  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("Cannot open file %s\n", argv[1]);
    return 1;
  }

  // Initialize variables
  char word[100];          // The word to search for
  int count = 0;           // The count of word occurrences
  char line[1000];         // The line being read from the file

  // Copy the word argument to the word variable
  strncpy(word, argv[2], sizeof(word));

  // Strip newline character from the word variable if it exists
  if (word[strlen(word) - 1] == '\n') {
    word[strlen(word) - 1] = '\0';
  }

  // Read each line of the file
  while (fgets(line, sizeof(line), file) != NULL) {
    char *pos = line;

    // Search for the given word in the line
    while ((pos = strstr(pos, word)) != NULL) {
      count++;
      pos += strlen(word);
    }
  }

  // Close the text file
  fclose(file);

  // Print the number of occurrences of the word
  printf("The word '%s' appears %d times in the text file.\n", word, count);

  return 0;
}