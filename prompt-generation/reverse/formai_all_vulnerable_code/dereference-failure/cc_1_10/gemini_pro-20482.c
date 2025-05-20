//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to translate a single line of Cat Language to English
char *translateLine(char *line) {
  // Allocate memory for the translated line
  char *translatedLine = malloc(MAX_LINE_LENGTH);
  if (translatedLine == NULL) {
    fprintf(stderr, "Error: Couldn't allocate memory for translated line.\n");
    exit(1);
  }

  // Initialize the translated line to be empty
  translatedLine[0] = '\0';

  // Iterate over the characters in the line
  int i = 0;
  while (line[i] != '\0') {
    // Check if the current character is a Cat Language character
    switch (line[i]) {
      case 'a':
        strcat(translatedLine, "meow");
        break;
      case 'b':
        strcat(translatedLine, "purr");
        break;
      case 'c':
        strcat(translatedLine, "hiss");
        break;
      case 'd':
        strcat(translatedLine, "scratch");
        break;
      default:
        // If the current character is not a Cat Language character,
        // just append it to the translated line
        strncat(translatedLine, &line[i], 1);
        break;
    }

    // Increment the index of the current character
    i++;
  }

  // Return the translated line
  return translatedLine;
}

// Function to translate a file of Cat Language to English
void translateFile(char *filename) {
  // Open the file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Error: Couldn't open file '%s' for reading.\n", filename);
    exit(1);
  }

  // Read the file line by line
  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
    // Translate the line
    char *translatedLine = translateLine(line);

    // Print the translated line
    printf("%s", translatedLine);

    // Free the memory allocated for the translated line
    free(translatedLine);
  }

  // Close the file
  fclose(file);
}

int main(int argc, char *argv[]) {
  // Check if a filename was provided
  if (argc < 2) {
    fprintf(stderr, "Error: No filename provided.\n");
    exit(1);
  }

  // Translate the file
  translateFile(argv[1]);

  return 0;
}