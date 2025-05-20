//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom error handling macro
#define CHECK_ERROR(condition, error_message)                                                    \
  do {                                                                                          \
    if (!(condition)) {                                                                           \
      fprintf(stderr, "Error: %s\n", error_message);                                             \
      exit(EXIT_FAILURE);                                                                         \
    }                                                                                           \
  } while (0)

// Function to open a file and return a file pointer
FILE *open_file(char *filename) {
  FILE *fp;

  fp = fopen(filename, "r");
  CHECK_ERROR(fp != NULL, "Could not open file");

  return fp;
}

// Function to read a line from a file and return it as a string
char *read_line(FILE *fp) {
  char *line = NULL;
  size_t len = 0;
  ssize_t nread;

  nread = getline(&line, &len, fp);
  CHECK_ERROR(nread != -1, "Could not read line");

  return line;
}

// Function to close a file
void close_file(FILE *fp) {
  fclose(fp);
  CHECK_ERROR(ferror(fp) == 0, "Could not close file");
}

// Main function
int main() {
  FILE *fp;
  char *line;

  // Open the file
  fp = open_file("input.txt");

  // Read the first line
  line = read_line(fp);

  // Print the line
  printf("%s", line);

  // Free the line
  free(line);

  // Close the file
  close_file(fp);

  return 0;
}