//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: Ada Lovelace
// Ada Lovelace style C Metadata Extractor

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to extract metadata from a given file
int extractMetadata(char *filename) {
  // Open the file
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file %s\n", filename);
    return -1;
  }

  // Read the file contents into a buffer
  fseek(fp, 0, SEEK_END);
  long fsize = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  char *buffer = malloc(fsize + 1);
  fread(buffer, fsize, 1, fp);
  fclose(fp);

  // Extract the metadata
  char *metadata = strstr(buffer, "<!-- Metadata -->");
  if (metadata == NULL) {
    printf("No metadata found in file %s\n", filename);
    return -1;
  }

  // Print the metadata
  printf("Metadata:\n%s\n", metadata);

  // Free the buffer
  free(buffer);

  return 0;
}

// Main function
int main(int argc, char *argv[]) {
  // Check if a filename was provided
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return -1;
  }

  // Extract the metadata from the file
  int result = extractMetadata(argv[1]);
  if (result != 0) {
    return result;
  }

  return 0;
}