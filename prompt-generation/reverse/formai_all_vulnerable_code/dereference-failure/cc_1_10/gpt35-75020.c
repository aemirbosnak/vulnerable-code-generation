//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to extract metadata from given file name
void extractMetadata(char* fileName) {
  // First, we need to check if the file name ends with .txt
  char* extension = strrchr(fileName, '.');
  if(strcmp(extension, ".txt") != 0) {
    printf("Error: Invalid file format! Please provide a .txt file\n");
    return;
  }

  // Open the file and get its size
  FILE* file = fopen(fileName, "r");
  fseek(file, 0L, SEEK_END);
  int fileSize = ftell(file);
  fseek(file, 0L, SEEK_SET);

  // Allocate memory to store the file contents
  char* fileContents = (char*) malloc(sizeof(char) * fileSize);
  if(fileContents == NULL) {
    printf("Error: Unable to allocate memory!\n");
    fclose(file);
    return;
  }

  // Read the file contents into the allocated memory
  int bytesRead = fread(fileContents, sizeof(char), fileSize, file);

  // Close the file
  fclose(file);

  // Check if the file was read successfully
  if(bytesRead != fileSize) {
    printf("Error: Unable to read file contents!\n");
    free(fileContents);
    return;
  }

  // Now, let's extract the metadata
  char* metadata = strchr(fileContents, '{');
  if(metadata == NULL) {
    printf("Error: Metadata not found!\n");
    free(fileContents);
    return;
  }

  // Remove the metadata from the file
  *metadata = '\0';

  // Print the metadata and the remaining file contents
  printf("Metadata:\n%s\n\n", metadata);
  printf("File Contents:\n%s", fileContents);

  // Free the dynamically allocated memory
  free(fileContents);
}

// Main function to test the metadata extractor
int main() {
  char* fileName = "example.txt";
  printf("Extracting metadata from file: %s\n\n", fileName);
  extractMetadata(fileName);

  return 0;
}