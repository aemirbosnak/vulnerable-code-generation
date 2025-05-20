//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Alan Touring
// This program extracts metadata from files in a directory using C language.

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

// Define a structure to hold metadata information
typedef struct {
  char filename[100];
  char type[10];
  int size;
} Metadata;

// Function to extract metadata from a file
Metadata extract_metadata(char *filename) {
  Metadata metadata;
  strcpy(metadata.filename, filename);

  // Open the file
  FILE *fp = fopen(filename, "rb");

  // If file cannot be opened, return empty metadata
  if (fp == NULL) {
    strcpy(metadata.type, "");
    metadata.size = 0;
    return metadata;
  }

  // Determine the file type
  char *extension = strrchr(filename, '.');
  if (extension == NULL) {
    strcpy(metadata.type, "");
  } else {
    strcpy(metadata.type, extension + 1);
  }

  // Determine the file size
  fseek(fp, 0L, SEEK_END);
  metadata.size = ftell(fp);

  // Close the file
  fclose(fp);

  return metadata;
}

int main() {
  DIR *dir_ptr;
  struct dirent *direntp;

  // Open the current directory
  if ((dir_ptr = opendir(".")) == NULL) {
    fprintf(stderr, "Error: Cannot open directory\n");
    exit(1);
  }

  // Loop through all files in the directory
  while ((direntp = readdir(dir_ptr)) != NULL) {
    if (strcmp(direntp->d_name, ".") != 0 && strcmp(direntp->d_name, "..") != 0) {
      Metadata metadata = extract_metadata(direntp->d_name);
      printf("Filename: %s\n", metadata.filename);
      printf("Type: %s\n", metadata.type);
      printf("Size: %d bytes\n", metadata.size);
      printf("--------------------\n");
    }
  }

  // Close the directory
  closedir(dir_ptr);
  return 0;
}