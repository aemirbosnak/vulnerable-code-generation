//Code Llama-13B DATASET v1.0 Category: Metadata Extractor ; Style: systematic
// Example: Unique C Metadata Extractor

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store metadata information
typedef struct {
  char *name;
  char *description;
  char *version;
  char *author;
} Metadata;

// Function to extract metadata from a file
void extract_metadata(char *file_path, Metadata *metadata) {
  // Open the file for reading
  FILE *fp = fopen(file_path, "r");

  // Read the metadata from the file
  char buffer[1024];
  fgets(buffer, sizeof(buffer), fp);
  char *token = strtok(buffer, " ");
  metadata->name = strdup(token);
  token = strtok(NULL, " ");
  metadata->description = strdup(token);
  token = strtok(NULL, " ");
  metadata->version = strdup(token);
  token = strtok(NULL, " ");
  metadata->author = strdup(token);

  // Close the file
  fclose(fp);
}

// Main function
int main(int argc, char *argv[]) {
  // Check the number of arguments
  if (argc != 2) {
    printf("Usage: %s <file_path>\n", argv[0]);
    return 1;
  }

  // Extract the metadata from the file
  Metadata metadata;
  extract_metadata(argv[1], &metadata);

  // Print the metadata
  printf("Name: %s\n", metadata.name);
  printf("Description: %s\n", metadata.description);
  printf("Version: %s\n", metadata.version);
  printf("Author: %s\n", metadata.author);

  return 0;
}