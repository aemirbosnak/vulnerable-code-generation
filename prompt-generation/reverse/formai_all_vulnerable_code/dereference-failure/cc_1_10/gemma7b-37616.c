//Gemma-7B DATASET v1.0 Category: File handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to open a file
int openFile(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return -1;
  }
  return fp;
}

// Function to read data from a file
int readData(int fd, char *buffer, int size) {
  int bytesRead = fread(buffer, size, 1, (FILE *)fd);
  if (bytesRead == 0) {
    perror("Error reading file");
    return -1;
  }
  return bytesRead;
}

// Function to write data to a file
int writeData(int fd, char *buffer, int size) {
  int bytesWritten = fwrite(buffer, size, 1, (FILE *)fd);
  if (bytesWritten == 0) {
    perror("Error writing file");
    return -1;
  }
  return bytesWritten;
}

// Function to close a file
int closeFile(int fd) {
  fclose((FILE *)fd);
  return 0;
}

int main() {
  // Open a file
  int fd = openFile("my_file.txt");

  // Read data from the file
  char buffer[1024];
  int bytesRead = readData(fd, buffer, 1024);

  // Write data to the file
  buffer[0] = 'H';
  int bytesWritten = writeData(fd, buffer, 1);

  // Close the file
  closeFile(fd);

  return 0;
}