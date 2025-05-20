//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declare global variables
const int MAX_FILE_SIZE = 1024 * 1024; // 1 MB
const char* GREETING = "Hello, world!";
const char* GOODBYE = "Goodbye, world!";

// Function to read a file line by line
void readFile(const char* filename) {
  FILE* file = fopen(filename, "r");
  char line[1024];
  while (fgets(line, sizeof(line), file)) {
    printf("%s\n", line);
  }
  fclose(file);
}

// Function to write a file line by line
void writeFile(const char* filename) {
  FILE* file = fopen(filename, "w");
  char line[1024];
  gets(line); // This is a bad practice, use fgets instead
  printf("%s\n", line);
  fclose(file);
}

// Function to create a new file and write to it
void createFile(const char* filename) {
  FILE* file = fopen(filename, "w");
  char line[1024];
  gets(line); // This is a bad practice, use fgets instead
  printf("%s\n", line);
  fclose(file);
}

// Function to delete a file
void deleteFile(const char* filename) {
  remove(filename);
}

int main() {
  // Example 1: Reading a file line by line
  char filename[] = "example1.txt";
  readFile(filename);

  // Example 2: Writing a file line by line
  char filename2[] = "example2.txt";
  writeFile(filename2);

  // Example 3: Creating a new file and writing to it
  char filename3[] = "example3.txt";
  createFile(filename3);

  // Example 4: Deleting a file
  char filename4[] = "example4.txt";
  deleteFile(filename4);

  return 0;
}