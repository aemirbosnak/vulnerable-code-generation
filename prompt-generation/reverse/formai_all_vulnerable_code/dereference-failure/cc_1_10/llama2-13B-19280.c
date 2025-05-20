//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to read a file and print its contents
void printFileContents(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error: Could not open file %s\n", filename);
    return;
  }

  char buffer[1024];
  while (fgets(buffer, sizeof(buffer), file)) {
    printf("%s\n", buffer);
  }

  fclose(file);
}

// Function to write a file and print its contents
void writeFileContents(char *filename) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    printf("Error: Could not open file %s\n", filename);
    return;
  }

  char buffer[1024];
  gets(buffer); // ask the user for input
  fputs(buffer, file);

  fclose(file);
}

int main() {
  // Print the contents of a file
  printFileContents("example.txt");

  // Ask the user for input and write it to a file
  char input[1024];
  printf("Enter your name: ");
  gets(input);
  writeFileContents("names.txt");

  // Read the contents of a file and print it
  printFileContents("names.txt");

  // Close the files
  fclose(stdin);
  fclose(stdout);
  fclose(stderr);

  return 0;
}