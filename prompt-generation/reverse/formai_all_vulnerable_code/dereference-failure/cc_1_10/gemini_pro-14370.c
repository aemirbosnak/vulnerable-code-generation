//GEMINI-pro DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to open a file and return a file pointer
FILE *open_file(char *filename, char *mode) {
  FILE *fp = fopen(filename, mode);
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }
  return fp;
}

// Function to close a file
void close_file(FILE *fp) {
  if (fclose(fp) != 0) {
    perror("Error closing file");
    exit(1);
  }
}

// Function to read a line from a file
char *read_line(FILE *fp) {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  read = getline(&line, &len, fp);
  if (read == -1) {
    return NULL;
  }

  // Remove the newline character from the end of the line
  if (line[strlen(line) - 1] == '\n') {
    line[strlen(line) - 1] = '\0';
  }

  return line;
}

// Function to write a line to a file
void write_line(FILE *fp, char *line) {
  if (fprintf(fp, "%s\n", line) < 0) {
    perror("Error writing to file");
    exit(1);
  }
}

// Main function
int main() {
  // Open the input file
  FILE *input_fp = open_file("input.txt", "r");

  // Open the output file
  FILE *output_fp = open_file("output.txt", "w");

  // Read each line from the input file and write it to the output file
  char *line;
  while ((line = read_line(input_fp)) != NULL) {
    write_line(output_fp, line);
    free(line);
  }

  // Close the input file
  close_file(input_fp);

  // Close the output file
  close_file(output_fp);

  return 0;
}