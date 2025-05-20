//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 4096

int main() {
  char buffer[MAX_BUFFER_SIZE];
  char *line = NULL;
  int line_length = 0;
  char **metadata = NULL;
  int metadata_size = 0;

  // Read the file
  FILE *file = fopen("sample.txt", "r");
  if (file == NULL) {
    return 1;
  }

  // Allocate memory for the line and metadata
  line = malloc(MAX_BUFFER_SIZE);
  metadata = malloc(MAX_BUFFER_SIZE);

  // Loop over the file line by line
  while (getline(file, line, MAX_BUFFER_SIZE) != -1) {
    // Extract metadata from the line
    char *key = strstr(line, ":");
    char *value = strstr(line, "=");

    // If the line has metadata, add it to the metadata list
    if (key && value) {
      metadata = realloc(metadata, (metadata_size + 1) * sizeof(char *));
      metadata[metadata_size++] = malloc((value - key - 1) * sizeof(char));
      memcpy(metadata[metadata_size - 1], key + 1, value - key - 1);
    }
  }

  // Print the metadata
  for (int i = 0; i < metadata_size; i++) {
    printf("%s: %s\n", metadata[i], metadata[i + 1]);
  }

  // Free the memory
  free(line);
  free(metadata);
  fclose(file);

  return 0;
}