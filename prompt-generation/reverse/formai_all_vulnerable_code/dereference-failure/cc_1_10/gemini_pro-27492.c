//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Define the metadata structure.
typedef struct {
  char *title;
  char *author;
  char *date;
  char *description;
} Metadata;

// Define the function to extract the metadata from a file.
Metadata *extract_metadata(const char *filename) {
  // Open the file.
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }

  // Read the first line of the file.
  char *line = NULL;
  size_t len = 0;
  getline(&line, &len, file);

  // Check if the first line starts with "Metadata:".
  if (strncmp(line, "Metadata:", 9) != 0) {
    free(line);
    fclose(file);
    return NULL;
  }

  // Parse the metadata.
  Metadata *metadata = malloc(sizeof(Metadata));
  metadata->title = NULL;
  metadata->author = NULL;
  metadata->date = NULL;
  metadata->description = NULL;

  while (getline(&line, &len, file) != -1) {
    // Check if the line starts with "Title:".
    if (strncmp(line, "Title:", 6) == 0) {
      // Extract the title.
      metadata->title = strdup(line + 6);
    }

    // Check if the line starts with "Author:".
    else if (strncmp(line, "Author:", 7) == 0) {
      // Extract the author.
      metadata->author = strdup(line + 7);
    }

    // Check if the line starts with "Date:".
    else if (strncmp(line, "Date:", 5) == 0) {
      // Extract the date.
      metadata->date = strdup(line + 5);
    }

    // Check if the line starts with "Description:".
    else if (strncmp(line, "Description:", 11) == 0) {
      // Extract the description.
      metadata->description = strdup(line + 11);
    }
  }

  // Free the line.
  free(line);

  // Close the file.
  fclose(file);

  // Return the metadata.
  return metadata;
}

// Define the function to print the metadata.
void print_metadata(const Metadata *metadata) {
  // Print the title.
  printf("Title: %s\n", metadata->title);

  // Print the author.
  printf("Author: %s\n", metadata->author);

  // Print the date.
  printf("Date: %s\n", metadata->date);

  // Print the description.
  printf("Description: %s\n", metadata->description);
}

// Define the main function.
int main(int argc, char *argv[]) {
  // Check if the number of arguments is correct.
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Extract the metadata from the file.
  Metadata *metadata = extract_metadata(argv[1]);

  // Check if the metadata was extracted successfully.
  if (metadata == NULL) {
    printf("Error: could not extract metadata from file.\n");
    return EXIT_FAILURE;
  }

  // Print the metadata.
  print_metadata(metadata);

  // Free the metadata.
  free(metadata->title);
  free(metadata->author);
  free(metadata->date);
  free(metadata->description);
  free(metadata);

  // Return a successful exit code.
  return EXIT_SUCCESS;
}