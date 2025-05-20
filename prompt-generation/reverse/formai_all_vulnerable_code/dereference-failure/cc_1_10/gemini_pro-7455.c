//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the metadata structure.
typedef struct {
  char *title;
  char *author;
  char *description;
  int year;
} Metadata;

// Function to extract metadata from a file.
Metadata *extract_metadata(const char *filename) {
  // Open the file.
  FILE *file = fopen(filename, "r");
  if (!file) {
    return NULL;
  }

  // Read the file into a buffer.
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  rewind(file);
  char *buffer = malloc(file_size + 1);
  fread(buffer, file_size, 1, file);
  fclose(file);

  // Extract the metadata from the buffer.
  Metadata *metadata = malloc(sizeof(Metadata));
  metadata->title = NULL;
  metadata->author = NULL;
  metadata->description = NULL;
  metadata->year = 0;

  // Parse the buffer for the title.
  char *title_start = strstr(buffer, "<title>");
  if (title_start) {
    char *title_end = strstr(title_start, "</title>");
    if (title_end) {
      metadata->title = strndup(title_start + 7, title_end - title_start - 7);
    }
  }

  // Parse the buffer for the author.
  char *author_start = strstr(buffer, "<author>");
  if (author_start) {
    char *author_end = strstr(author_start, "</author>");
    if (author_end) {
      metadata->author = strndup(author_start + 8, author_end - author_start - 8);
    }
  }

  // Parse the buffer for the description.
  char *description_start = strstr(buffer, "<description>");
  if (description_start) {
    char *description_end = strstr(description_start, "</description>");
    if (description_end) {
      metadata->description = strndup(description_start + 13, description_end - description_start - 13);
    }
  }

  // Parse the buffer for the year.
  char *year_start = strstr(buffer, "<year>");
  if (year_start) {
    char *year_end = strstr(year_start, "</year>");
    if (year_end) {
      metadata->year = strtol(year_start + 6, NULL, 10);
    }
  }

  // Free the buffer.
  free(buffer);

  // Return the metadata.
  return metadata;
}

// Function to print metadata.
void print_metadata(const Metadata *metadata) {
  printf("Title: %s\n", metadata->title);
  printf("Author: %s\n", metadata->author);
  printf("Description: %s\n", metadata->description);
  printf("Year: %d\n", metadata->year);
}

// Main function.
int main(int argc, char **argv) {
  // Check if a filename was provided.
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Extract the metadata from the file.
  Metadata *metadata = extract_metadata(argv[1]);
  if (!metadata) {
    printf("Error: Could not extract metadata from file.\n");
    return 1;
  }

  // Print the metadata.
  print_metadata(metadata);

  // Free the metadata.
  free(metadata->title);
  free(metadata->author);
  free(metadata->description);
  free(metadata);

  return 0;
}