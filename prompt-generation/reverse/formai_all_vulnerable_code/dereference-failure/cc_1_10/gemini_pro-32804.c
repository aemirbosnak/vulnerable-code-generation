//GEMINI-pro DATASET v1.0 Category: File handling ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the file that can be opened
#define MAX_FILE_SIZE 1024

// Define the maximum number of characters that can be read from the file at a time
#define MAX_BUFFER_SIZE 1024

// Open a file for reading
FILE *open_file(char *filename) {
  // Attempt to open the file for reading
  FILE *file = fopen(filename, "r");

  // Check if the file was opened successfully
  if (file == NULL) {
    // Print an error message and exit the program
    fprintf(stderr, "Error: could not open file %s\n", filename);
    exit(1);
  }

  // Return the file pointer
  return file;
}

// Close a file
void close_file(FILE *file) {
  // Close the file
  fclose(file);
}

// Read a line from a file
char *read_line(FILE *file) {
  // Allocate memory for the line
  char *line = malloc(MAX_BUFFER_SIZE);

  // Read a line from the file
  fgets(line, MAX_BUFFER_SIZE, file);

  // Return the line
  return line;
}

// Write a line to a file
void write_line(FILE *file, char *line) {
  // Write the line to the file
  fputs(line, file);
}

// Copy a file
void copy_file(char *source_filename, char *destination_filename) {
  // Open the source file for reading
  FILE *source_file = open_file(source_filename);

  // Open the destination file for writing
  FILE *destination_file = open_file(destination_filename);

  // Read a line from the source file
  char *line = read_line(source_file);

  // While the line is not NULL, write it to the destination file and read the next line from the source file
  while (line != NULL) {
    write_line(destination_file, line);
    line = read_line(source_file);
  }

  // Close the source file
  close_file(source_file);

  // Close the destination file
  close_file(destination_file);
}

// Print the contents of a file
void print_file(char *filename) {
  // Open the file for reading
  FILE *file = open_file(filename);

  // Read a line from the file
  char *line = read_line(file);

  // While the line is not NULL, print it to the console and read the next line from the file
  while (line != NULL) {
    printf("%s", line);
    line = read_line(file);
  }

  // Close the file
  close_file(file);
}

// Main function
int main(int argc, char **argv) {
  // Check if the user has provided a source filename and a destination filename
  if (argc != 3) {
    // Print an error message and exit the program
    fprintf(stderr, "Error: usage: %s source_filename destination_filename\n", argv[0]);
    exit(1);
  }

  // Copy the file
  copy_file(argv[1], argv[2]);

  // Print the contents of the destination file
  print_file(argv[2]);

  // Exit the program
  return 0;
}