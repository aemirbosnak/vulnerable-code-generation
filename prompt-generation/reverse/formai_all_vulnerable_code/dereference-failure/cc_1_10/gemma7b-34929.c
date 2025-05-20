//Gemma-7B DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store file information
typedef struct FileInfo {
  char *name;
  int size;
  FILE *fp;
} FileInfo;

// Function to open a file
void openFile(FileInfo *file, char *filename) {
  file->name = strdup(filename);
  file->fp = fopen(filename, "r");
  if (file->fp == NULL) {
    perror("Error opening file");
    exit(1);
  }
  file->size = fileSize(file->fp);
}

// Function to close a file
void closeFile(FileInfo *file) {
  fclose(file->fp);
  free(file->name);
}

// Function to get the size of a file in bytes
int fileSize(FILE *fp) {
  long int size = 0;
  fseek(fp, 0L, SEEK_END);
  size = ftell(fp);
  return size;
}

int main() {
  // Create a structure to store file information
  FileInfo file;

  // Open a file
  openFile(&file, "my_file.txt");

  // Get the size of the file
  int size = fileSize(&file);

  // Print the size of the file
  printf("The size of the file is: %d bytes\n", size);

  // Close the file
  closeFile(&file);

  return 0;
}