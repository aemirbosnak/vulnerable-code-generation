//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main() {
  // Open a file for reading.
  FILE *file = fopen("input.txt", "r");
  if (file == NULL) {
    // Check if the file could not be opened due to an error.
    if (errno == ENOENT) {
      printf("File not found.\n");
    } else {
      // Print the error message.
      perror("fopen");
    }
    return EXIT_FAILURE;
  }

  // Read a line from the file.
  char line[1024];
  if (fgets(line, sizeof(line), file) == NULL) {
    // Check if there was an error reading the line.
    if (ferror(file)) {
      // Print the error message.
      perror("fgets");
      fclose(file);
      return EXIT_FAILURE;
    }
  }

  // Close the file.
  if (fclose(file) == EOF) {
    // Check if there was an error closing the file.
    perror("fclose");
    return EXIT_FAILURE;
  }

  // Parse the line.
  int number;
  if (sscanf(line, "%d", &number) != 1) {
    // Check if the line could not be parsed as an integer.
    printf("Invalid input.\n");
    return EXIT_FAILURE;
  }

  // Print the number.
  printf("Number: %d\n", number);

  return EXIT_SUCCESS;
}