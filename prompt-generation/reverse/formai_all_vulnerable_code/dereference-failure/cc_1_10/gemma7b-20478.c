//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINES 1024

int main() {
  char **lines = NULL;
  char **metadata = NULL;
  int lines_count = 0;
  int i = 0;
  char line[MAX_LINES];

  // Read the file
  FILE *fp = fopen("test.txt", "r");
  if (fp == NULL) {
    return 1;
  }

  // Allocate memory for lines
  lines = malloc(MAX_LINES * sizeof(char *));
  if (lines == NULL) {
    return 1;
  }

  // Allocate memory for metadata
  metadata = malloc(MAX_LINES * sizeof(char *));
  if (metadata == NULL) {
    return 1;
  }

  // Count the number of lines
  while (fgets(line, MAX_LINES, fp) != NULL) {
    lines_count++;
  }

  // Read the file again and extract metadata
  rewind(fp);
  for (i = 0; i < lines_count; i++) {
    fgets(line, MAX_LINES, fp);
    // Check if the line is metadata
    if (line[0] == '#') {
      // Extract the metadata
      metadata[i] = strdup(line);
    }
  }

  // Print the metadata
  for (i = 0; i < lines_count; i++) {
    if (metadata[i] != NULL) {
      printf("%s\n", metadata[i]);
    }
  }

  // Free memory
  free(lines);
  free(metadata);

  return 0;
}