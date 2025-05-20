//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1024
#define MAX_LINE_SIZE 1024

// Function to read a file and print its contents
void printFileContents(const char *filePath) {
  FILE *file = fopen(filePath, "r");
  if (file == NULL) {
    printf("Error: Unable to open file %s\n", filePath);
    return;
  }

  char buffer[MAX_LINE_SIZE];
  while (fgets(buffer, MAX_LINE_SIZE, file) != NULL) {
    printf("%s\n", buffer);
  }

  fclose(file);
}

// Function to write a file and print its contents
void writeFileContents(const char *filePath, const char *contents) {
  FILE *file = fopen(filePath, "w");
  if (file == NULL) {
    printf("Error: Unable to open file %s for writing\n", filePath);
    return;
  }

  fputs(contents, file);
  fclose(file);
}

int main() {
  // Open a file and print its contents
  printFileContents("example.txt");

  // Create a new file and write some contents
  char *contents = "This is a sample file contents!";
  writeFileContents("new_file.txt", contents);

  // Read the contents of the new file and print them
  printFileContents("new_file.txt");

  // Close the files
  fclose(stdin);
  fclose(stdout);
  fclose(stderr);

  return 0;
}