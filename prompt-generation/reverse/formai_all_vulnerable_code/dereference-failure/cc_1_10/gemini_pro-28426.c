//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/*
 * Custom error handling function that prints the error message and exits the program.
 */
void handle_error(const char *error_message) {
  fprintf(stderr, "%s: %s\n", error_message, strerror(errno));
  exit(EXIT_FAILURE);
}

/*
 * Custom function that tries to open a file and returns a FILE pointer if successful, or NULL if an error occurs.
 */
FILE *open_file(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    handle_error("Error opening file");
  }
  return file;
}

/*
 * Main function that demonstrates the use of error handling.
 */
int main() {
  // Try to open a file.
  FILE *file = open_file("input.txt");

  // Check if the file was opened successfully.
  if (file == NULL) {
    // If the file was not opened successfully, print an error message and exit the program.
    handle_error("Error opening file");
  }

  // Read a line from the file.
  char line[1024];
  if (fgets(line, sizeof(line), file) == NULL) {
    // If an error occurs while reading the line, print an error message and exit the program.
    handle_error("Error reading line");
  }

  // Print the line to the console.
  printf("%s", line);

  // Close the file.
  if (fclose(file) != 0) {
    // If an error occurs while closing the file, print an error message and exit the program.
    handle_error("Error closing file");
  }

  return EXIT_SUCCESS;
}