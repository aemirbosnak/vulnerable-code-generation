//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_FILE_SIZE 1024
#define MAX_LINE_LENGTH 1024

// Global variables
const char* magicWord = "curious";
int fileSize = 0;
int lineCount = 0;

// Function to read a line from the file
char* readLine(FILE* file) {
  char buffer[MAX_LINE_LENGTH];
  size_t len = fread(buffer, 1, MAX_LINE_LENGTH, file);
  if (len == 0) {
    return NULL;
  }
  buffer[len - 1] = '\0'; // null-terminate the string
  return buffer;
}

// Function to write a line to the file
void writeLine(FILE* file, char* line) {
  size_t len = strlen(line);
  fwrite(line, 1, len, file);
  fwrite("\n", 1, 1, file);
}

int main() {
  // Open the file in read-write mode
  FILE* file = fopen("example.txt", "r+");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  // Read the file size
  fseek(file, 0, SEEK_END);
  fileSize = ftell(file);
  fseek(file, 0, SEEK_SET);

  // Read the file line by line
  char* line;
  while ((line = readLine(file)) != NULL) {
    // Check if the line contains the magic word
    if (strstr(line, magicWord) != NULL) {
      // If it does, print a message
      printf("Found the magic word %s in line %d\n", magicWord, lineCount++);
    }

    // Write the line to the file
    writeLine(file, line);

    // Increment the line count
    lineCount++;
  }

  // Close the file
  fclose(file);

  // Print the final message
  printf("Read %d lines\n", lineCount);

  return 0;
}