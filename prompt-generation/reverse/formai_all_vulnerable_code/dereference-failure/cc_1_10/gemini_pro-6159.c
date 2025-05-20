//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: Romeo and Juliet
// Where art thou, Romeo?
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Extract metadata from a file
int main(int argc, char *argv[]) {
  // The path to the file
  char *filepath = argv[1];

  // Open the file
  FILE *file = fopen(filepath, "r");
  if (file == NULL) {
    printf("Could not open file %s\n", filepath);
    return 1;
  }

  // Read the file into memory
  char *buffer = malloc(1024);
  size_t size = fread(buffer, 1, 1024, file);
  if (size == 0) {
    printf("Could not read file %s\n", filepath);
    return 1;
  }

  // Close the file
  fclose(file);

  // Extract the metadata
  char *title = malloc(1024);
  char *author = malloc(1024);
  char *subject = malloc(1024);
  char *keywords = malloc(1024);
  char *description = malloc(1024);

  // Parse the metadata
  char *line = strtok(buffer, "\n");
  while (line != NULL) {
    if (strncmp(line, "Title:", 6) == 0) {
      strcpy(title, line + 6);
    } else if (strncmp(line, "Author:", 7) == 0) {
      strcpy(author, line + 7);
    } else if (strncmp(line, "Subject:", 8) == 0) {
      strcpy(subject, line + 8);
    } else if (strncmp(line, "Keywords:", 9) == 0) {
      strcpy(keywords, line + 9);
    } else if (strncmp(line, "Description:", 12) == 0) {
      strcpy(description, line + 12);
    }

    line = strtok(NULL, "\n");
  }

  // Print the metadata
  printf("Title: %s\n", title);
  printf("Author: %s\n", author);
  printf("Subject: %s\n", subject);
  printf("Keywords: %s\n", keywords);
  printf("Description: %s\n", description);

  // Free the memory
  free(buffer);
  free(title);
  free(author);
  free(subject);
  free(keywords);
  free(description);

  return 0;
}