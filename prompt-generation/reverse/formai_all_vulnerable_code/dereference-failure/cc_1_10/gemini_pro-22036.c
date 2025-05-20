//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define the metadata structure.
typedef struct {
  char *title;
  char *author;
  char *date;
  char *publisher;
  char *keywords;
} Metadata;

// Define the function to extract metadata from a file.
Metadata *extract_metadata(FILE *file) {
  // Allocate memory for the metadata structure.
  Metadata *metadata = malloc(sizeof(Metadata));

  // Read the first line of the file.
  char line[1024];
  fgets(line, sizeof(line), file);

  // Extract the title from the first line.
  char *title = strtok(line, "\n");

  // Allocate memory for the title.
  metadata->title = malloc(strlen(title) + 1);

  // Copy the title to the metadata structure.
  strcpy(metadata->title, title);

  // Read the second line of the file.
  fgets(line, sizeof(line), file);

  // Extract the author from the second line.
  char *author = strtok(line, "\n");

  // Allocate memory for the author.
  metadata->author = malloc(strlen(author) + 1);

  // Copy the author to the metadata structure.
  strcpy(metadata->author, author);

  // Read the third line of the file.
  fgets(line, sizeof(line), file);

  // Extract the date from the third line.
  char *date = strtok(line, "\n");

  // Allocate memory for the date.
  metadata->date = malloc(strlen(date) + 1);

  // Copy the date to the metadata structure.
  strcpy(metadata->date, date);

  // Read the fourth line of the file.
  fgets(line, sizeof(line), file);

  // Extract the publisher from the fourth line.
  char *publisher = strtok(line, "\n");

  // Allocate memory for the publisher.
  metadata->publisher = malloc(strlen(publisher) + 1);

  // Copy the publisher to the metadata structure.
  strcpy(metadata->publisher, publisher);

  // Read the fifth line of the file.
  fgets(line, sizeof(line), file);

  // Extract the keywords from the fifth line.
  char *keywords = strtok(line, "\n");

  // Allocate memory for the keywords.
  metadata->keywords = malloc(strlen(keywords) + 1);

  // Copy the keywords to the metadata structure.
  strcpy(metadata->keywords, keywords);

  // Return the metadata structure.
  return metadata;
}

// Define the function to print the metadata.
void print_metadata(Metadata *metadata) {
  // Print the title.
  printf("Title: %s\n", metadata->title);

  // Print the author.
  printf("Author: %s\n", metadata->author);

  // Print the date.
  printf("Date: %s\n", metadata->date);

  // Print the publisher.
  printf("Publisher: %s\n", metadata->publisher);

  // Print the keywords.
  printf("Keywords: %s\n", metadata->keywords);
}

// Define the main function.
int main(int argc, char *argv[]) {
  // Check if the user specified a file name.
  if (argc != 2) {
    printf("Usage: %s <file name>\n", argv[0]);
    return 1;
  }

  // Open the file.
  FILE *file = fopen(argv[1], "r");

  // Check if the file could not be opened.
  if (file == NULL) {
    printf("Error: Could not open file %s\n", argv[1]);
    return 1;
  }

  // Extract the metadata from the file.
  Metadata *metadata = extract_metadata(file);

  // Print the metadata.
  print_metadata(metadata);

  // Free the memory allocated for the metadata structure.
  free(metadata->title);
  free(metadata->author);
  free(metadata->date);
  free(metadata->publisher);
  free(metadata->keywords);
  free(metadata);

  // Close the file.
  fclose(file);

  return 0;
}