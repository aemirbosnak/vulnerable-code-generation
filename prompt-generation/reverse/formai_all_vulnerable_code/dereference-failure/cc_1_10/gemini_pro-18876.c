//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the first line of a file
char* readLine(FILE* file) {
  char* line = NULL;
  size_t len = 0;
  getline(&line, &len, file);
  return line;
}

// Function to read the entire contents of a file into a string
char* readFile(const char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Get the file size
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  rewind(file);

  // Allocate a buffer to hold the file contents
  char* buffer = malloc(size + 1);
  if (buffer == NULL) {
    perror("Error allocating buffer");
    fclose(file);
    return NULL;
  }

  // Read the file contents into the buffer
  fread(buffer, size, 1, file);
  fclose(file);

  // Add a null terminator to the end of the buffer
  buffer[size] = '\0';

  return buffer;
}

// Function to print the first line of a file
void printFirstLine(const char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    return;
  }

  char* line = readLine(file);
  printf("%s", line);
  free(line);
  fclose(file);
}

// Function to print the entire contents of a file
void printFile(const char* filename) {
  char* contents = readFile(filename);
  if (contents == NULL) {
    perror("Error reading file");
    return;
  }

  printf("%s", contents);
  free(contents);
}

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  const char* filename = argv[1];
  printf("Reading the first line of %s:\n", filename);
  printFirstLine(filename);

  printf("\n\nReading the entire contents of %s:\n", filename);
  printFile(filename);

  return 0;
}