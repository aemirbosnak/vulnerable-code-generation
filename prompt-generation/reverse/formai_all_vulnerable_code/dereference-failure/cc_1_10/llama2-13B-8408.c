//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global variables
const int MAX_FILE_NAME_LENGTH = 20;
const int MAX_LINE_LENGTH = 100;

// Function to read a file and store its contents in a string
void readFile(char *filename, char *buffer) {
  int fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return;
  }

  // Store the file contents in a string
  char *ptr = buffer;
  while (fgets(ptr, MAX_LINE_LENGTH, fp) != NULL) {
    ptr += strlen(ptr);
  }
  fclose(fp);
}

// Function to write a string to a file
void writeFile(char *filename, char *buffer) {
  int fp = fopen(filename, "w");
  if (fp == NULL) {
    perror("Error opening file");
    return;
  }

  // Write the contents of the string to the file
  fputs(buffer, fp);
  fclose(fp);
}

int main() {
  // Open a file and read its contents
  char filename[] = "happystory.txt";
  char buffer[MAX_LINE_LENGTH];
  readFile(filename, buffer);

  // Print the contents of the file
  printf("File contents: %s\n", buffer);

  // Write a new string to the file
  char *new_contents = "This is a new, happier story!";
  writeFile(filename, new_contents);

  // Read the file again and print the new contents
  readFile(filename, buffer);
  printf("New file contents: %s\n", buffer);

  return 0;
}