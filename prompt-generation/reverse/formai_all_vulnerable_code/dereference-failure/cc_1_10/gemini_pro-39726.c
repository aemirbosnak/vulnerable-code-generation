//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A macro to define the maximum length of a line.
#define MAX_LINE_LENGTH 1024

// A function to read a line of text from a file.
char *readline(FILE *file) {
  char *line = malloc(MAX_LINE_LENGTH);
  if (line == NULL) {
    return NULL;
  }

  // Read a line of text from the file.
  if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
    free(line);
    return NULL;
  }

  // Remove the newline character from the end of the line.
  if (line[strlen(line) - 1] == '\n') {
    line[strlen(line) - 1] = '\0';
  }

  return line;
}

// A function to print a line of text to a file.
void printline(FILE *file, char *line) {
  // Print the line of text to the file.
  fprintf(file, "%s\n", line);
}

// A function to process a line of text.
void processline(char *line) {
  // Convert the line of text to lowercase.
  for (int i = 0; i < strlen(line); i++) {
    line[i] = tolower(line[i]);
  }

  // Print the processed line of text.
  printf("%s\n", line);
}

// A function to main function.
int main(int argc, char **argv) {
  // Check if the user specified a filename.
  if (argc < 2) {
    printf("Usage: %s filename\n", argv[0]);
    return 1;
  }

  // Open the file.
  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("Error: Could not open file '%s'.\n", argv[1]);
    return 1;
  }

  // Read a line of text from the file.
  char *line = readline(file);

  // Process the line of text.
  while (line != NULL) {
    processline(line);

    // Read the next line of text from the file.
    line = readline(file);
  }

  // Close the file.
  fclose(file);

  return 0;
}