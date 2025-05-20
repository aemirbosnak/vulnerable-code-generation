//GEMINI-pro DATASET v1.0 Category: File handling ; Style: introspective
// Hello, world! An introspection into file handling.

#include <stdio.h>
#include <stdlib.h>

// A function to open a file for reading.
FILE* open_file(const char* filename) {
  // Try to open the file.
  FILE* file = fopen(filename, "r");

  // If the file could not be opened, print an error message and exit.
  if (file == NULL) {
    printf("Error: could not open file '%s'.\n", filename);
    exit(1);
  }

  // Return the file pointer.
  return file;
}

// A function to read a line from a file.
char* read_line(FILE* file) {
  // Allocate memory for the line.
  char* line = malloc(1024);

  // Read the line from the file.
  fgets(line, 1024, file);

  // Return the line.
  return line;
}

// A function to close a file.
void close_file(FILE* file) {
  // Close the file.
  fclose(file);
}

// A function to print the contents of a file.
void print_file(const char* filename) {
  // Open the file.
  FILE* file = open_file(filename);

  // Read a line from the file.
  char* line = read_line(file);

  // While the line is not NULL, print it and read the next line.
  while (line != NULL) {
    printf("%s", line);
    free(line);
    line = read_line(file);
  }

  // Close the file.
  close_file(file);
}

int main() {
  // Print the contents of a file.
  print_file("file.txt");

  return 0;
}