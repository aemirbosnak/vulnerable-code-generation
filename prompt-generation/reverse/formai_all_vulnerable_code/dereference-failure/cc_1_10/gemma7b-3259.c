//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main() {
  // Open the metadata file
  FILE *fp = fopen("metadata.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Allocate memory for the buffer
  char *buffer = malloc(MAX_BUFFER_SIZE);

  // Read the file into the buffer
  int bytesRead = fread(buffer, MAX_BUFFER_SIZE, 1, fp);

  // Close the file
  fclose(fp);

  // Search for the metadata key-value pairs
  char *key = "Artist";
  char *value = NULL;
  char *ptr = buffer;
  while (ptr && *ptr) {
    // Check if the key is present
    if (strcmp(ptr, key) == 0) {
      // Extract the value
      value = strchr(ptr, ":") + 1;
      break;
    }

    // Move to the next line
    ptr = strchr(ptr, "\n") + 1;
  }

  // Print the value
  if (value) {
    printf("The artist is: %s\n", value);
  } else {
    printf("The key %s was not found.\n", key);
  }

  // Free the memory
  free(buffer);

  return 0;
}