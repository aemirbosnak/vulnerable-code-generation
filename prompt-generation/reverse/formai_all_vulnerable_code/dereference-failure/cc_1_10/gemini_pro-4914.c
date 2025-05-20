//GEMINI-pro DATASET v1.0 Category: File handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a file and print its contents
void readFile(char *fileName) {
  FILE *file = fopen(fileName, "r");
  if (file == NULL) {
    printf("Error opening file: %s\n", fileName);
    return;
  }

  // Read the file line by line and print it
  char line[1024];
  while (fgets(line, sizeof(line), file) != NULL) {
    printf("%s", line);
  }

  fclose(file);
}

// Function to write a file with a given string
void writeFile(char *fileName, char *string) {
  FILE *file = fopen(fileName, "w");
  if (file == NULL) {
    printf("Error opening file: %s\n", fileName);
    return;
  }

  // Write the string to the file
  fprintf(file, "%s", string);

  fclose(file);
}

// Function to copy a file
void copyFile(char *sourceFileName, char *destinationFileName) {
  FILE *sourceFile = fopen(sourceFileName, "r");
  if (sourceFile == NULL) {
    printf("Error opening source file: %s\n", sourceFileName);
    return;
  }

  FILE *destinationFile = fopen(destinationFileName, "w");
  if (destinationFile == NULL) {
    printf("Error opening destination file: %s\n", destinationFileName);
    return;
  }

  // Read the source file line by line and write it to the destination file
  char line[1024];
  while (fgets(line, sizeof(line), sourceFile) != NULL) {
    fprintf(destinationFile, "%s", line);
  }

  fclose(sourceFile);
  fclose(destinationFile);
}

// Function to delete a file
void deleteFile(char *fileName) {
  if (remove(fileName) == 0) {
    printf("File %s deleted successfully\n", fileName);
  } else {
    printf("Error deleting file: %s\n", fileName);
  }
}

// Function to rename a file
void renameFile(char *oldFileName, char *newFileName) {
  if (rename(oldFileName, newFileName) == 0) {
    printf("File %s renamed to %s successfully\n", oldFileName, newFileName);
  } else {
    printf("Error renaming file: %s\n", oldFileName);
  }
}

// Function to get the file size
long getFileSize(char *fileName) {
  FILE *file = fopen(fileName, "r");
  if (file == NULL) {
    printf("Error opening file: %s\n", fileName);
    return -1;
  }

  fseek(file, 0, SEEK_END);
  long size = ftell(file);

  fclose(file);

  return size;
}

// Function to check if a file exists
int fileExists(char *fileName) {
  FILE *file = fopen(fileName, "r");
  if (file == NULL) {
    return 0;
  }

  fclose(file);

  return 1;
}

// Main function
int main() {
  // Create a file with some text
  writeFile("test.txt", "This is a test file.\n");

  // Read the file and print its contents
  readFile("test.txt");

  // Copy the file to a new file
  copyFile("test.txt", "test2.txt");

  // Delete the original file
  deleteFile("test.txt");

  // Rename the new file
  renameFile("test2.txt", "renamed_test.txt");

  // Get the file size
  long fileSize = getFileSize("renamed_test.txt");
  printf("File size: %ld bytes\n", fileSize);

  // Check if a file exists
  if (fileExists("renamed_test.txt")) {
    printf("File exists.\n");
  } else {
    printf("File does not exist.\n");
  }

  return 0;
}