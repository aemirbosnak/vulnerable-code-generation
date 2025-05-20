//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the metadata structure
typedef struct {
  char *title;
  char *author;
  char *description;
  int year;
  int pages;
} Metadata;

// Function to parse the metadata from a file
Metadata *parse_metadata(char *filename) {
  // Open the file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return NULL;
  }

  // Read the file contents into a buffer
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  fseek(file, 0, SEEK_SET);
  char *buffer = malloc(file_size + 1);
  fread(buffer, file_size, 1, file);
  fclose(file);

  // Extract the metadata from the buffer
  Metadata *metadata = malloc(sizeof(Metadata));
  char *line;
  char *delim = ":";

  // Get the title
  line = strtok(buffer, delim);
  metadata->title = strdup(line);

  // Get the author
  line = strtok(NULL, delim);
  metadata->author = strdup(line);

  // Get the description
  line = strtok(NULL, delim);
  metadata->description = strdup(line);

  // Get the year
  line = strtok(NULL, delim);
  metadata->year = atoi(line);

  // Get the pages
  line = strtok(NULL, delim);
  metadata->pages = atoi(line);

  // Return the metadata
  return metadata;
}

// Function to print the metadata
void print_metadata(Metadata *metadata) {
  printf("Title: %s\n", metadata->title);
  printf("Author: %s\n", metadata->author);
  printf("Description: %s\n", metadata->description);
  printf("Year: %d\n", metadata->year);
  printf("Pages: %d\n", metadata->pages);
}

// Main function
int main(int argc, char *argv[]) {
  // Check if a filename was provided
  if (argc != 2) {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Parse the metadata from the file
  Metadata *metadata = parse_metadata(argv[1]);
  if (metadata == NULL) {
    fprintf(stderr, "Error parsing metadata from file %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  // Print the metadata
  print_metadata(metadata);

  // Free the memory allocated for the metadata
  free(metadata->title);
  free(metadata->author);
  free(metadata->description);
  free(metadata);

  return EXIT_SUCCESS;
}