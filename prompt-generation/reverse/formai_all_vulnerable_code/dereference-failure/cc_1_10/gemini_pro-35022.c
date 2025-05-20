//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
  // Declare variables
  FILE *file;
  char *filename;
  char *line;
  int lineNumber = 0;
  int numErrors = 0;

  // Prompt for the file name
  printf("Enter the name of the log file: ");
  scanf("%s", filename);

  // Open the file
  file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    return EXIT_FAILURE;
  }

  // Read the file line by line
  while ((line = fgets(line, 1024, file)) != NULL) {
    lineNumber++;

    // Check for errors
    if (line[0] == '[') {
      // Check for error codes
      switch (line[1]) {
        case 'E':
          printf("Error on line %d: %s\n", lineNumber, line);
          numErrors++;
          break;
        case 'W':
          printf("Warning on line %d: %s\n", lineNumber, line);
          break;
        default:
          printf("Error: Unrecognized error code %c on line %d\n", line[1], lineNumber);
          numErrors++;
          break;
      }
    }
  }

  // Close the file
  fclose(file);

  // Print the number of errors
  printf("Total number of errors: %d\n", numErrors);

  return EXIT_SUCCESS;
}