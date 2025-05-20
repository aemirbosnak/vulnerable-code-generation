//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// This function will extract the metadata from the given file.
char *extract_metadata(char *filename) {
  // Open the file.
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Read the first 1024 bytes of the file.
  char *buffer = malloc(1024);
  if (fread(buffer, 1, 1024, file) != 1024) {
    perror("Error reading file");
    fclose(file);
    return NULL;
  }

  // Close the file.
  fclose(file);

  // Extract the metadata from the buffer.
  char *metadata = NULL;
  metadata = strstr(buffer, "metadata");
  if (metadata == NULL) {
    printf("No metadata found in file.\n");
    return NULL;
  }

  // Remove the "metadata" string from the buffer.
  metadata += strlen("metadata");

  // Return the metadata.
  return metadata;
}

// This function will print the metadata to the console.
void print_metadata(char *metadata) {
  // Print the metadata to the console.
  printf("%s\n", metadata);
}

int main(int argc, char *argv[]) {
  // Check if the user has provided a filename.
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Extract the metadata from the file.
  char *metadata = extract_metadata(argv[1]);
  if (metadata == NULL) {
    return 1;
  }

  // Print the metadata to the console.
  print_metadata(metadata);

  // Free the memory allocated for the metadata.
  free(metadata);

  return 0;
}