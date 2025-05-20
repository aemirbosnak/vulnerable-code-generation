//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Metadata struct
typedef struct {
  char *title;
  char *author;
  char *date;
  char *tags;
} Metadata;

// Function to extract metadata from a file
Metadata *extract_metadata(char *filename) {
  // Open the file
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  // Read the file into a buffer
  char *buffer = malloc(1024);
  if (buffer == NULL) {
    return NULL;
  }
  size_t size = fread(buffer, 1, 1024, fp);
  fclose(fp);

  // Parse the metadata
  Metadata *metadata = malloc(sizeof(Metadata));
  if (metadata == NULL) {
    return NULL;
  }

  char *title = strtok(buffer, "\n");
  char *author = strtok(NULL, "\n");
  char *date = strtok(NULL, "\n");
  char *tags = strtok(NULL, "\n");

  metadata->title = strdup(title);
  metadata->author = strdup(author);
  metadata->date = strdup(date);
  metadata->tags = strdup(tags);

  free(buffer);
  return metadata;
}

// Main function
int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Extract the metadata
  Metadata *metadata = extract_metadata(argv[1]);
  if (metadata == NULL) {
    fprintf(stderr, "Error extracting metadata from file %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  // Print the metadata
  printf("Title: %s\n", metadata->title);
  printf("Author: %s\n", metadata->author);
  printf("Date: %s\n", metadata->date);
  printf("Tags: %s\n", metadata->tags);

  // Free the metadata
  free(metadata->title);
  free(metadata->author);
  free(metadata->date);
  free(metadata->tags);
  free(metadata);

  return EXIT_SUCCESS;
}