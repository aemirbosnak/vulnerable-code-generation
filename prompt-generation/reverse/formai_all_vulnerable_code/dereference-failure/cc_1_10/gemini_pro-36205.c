//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: ephemeral
#include <stdio.h>
#include <string.h>

// Define the metadata struct
typedef struct {
  char *artist;
  char *album;
  char *title;
  int year;
} metadata_t;

// Define the function to extract metadata from a file
metadata_t *extract_metadata(const char *filename) {
  // Open the file
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    return NULL;
  }

  // Read the file into a buffer
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  rewind(file);
  char *buffer = malloc(size);
  fread(buffer, 1, size, file);
  fclose(file);

  // Search for the metadata tags
  char *artist = strstr(buffer, "artist=");
  artist += strlen("artist=");
  char *album = strstr(buffer, "album=");
  album += strlen("album=");
  char *title = strstr(buffer, "title=");
  title += strlen("title=");
  char *year = strstr(buffer, "year=");
  year += strlen("year=");

  // Extract the metadata values
  metadata_t *metadata = malloc(sizeof(metadata_t));
  metadata->artist = strdup(artist);
  metadata->album = strdup(album);
  metadata->title = strdup(title);
  metadata->year = atoi(year);

  // Return the metadata
  return metadata;
}

// Define the function to print the metadata
void print_metadata(metadata_t *metadata) {
  printf("Artist: %s\n", metadata->artist);
  printf("Album: %s\n", metadata->album);
  printf("Title: %s\n", metadata->title);
  printf("Year: %d\n", metadata->year);
}

// Define the main function
int main() {
  // Extract the metadata from a file
  metadata_t *metadata = extract_metadata("music.mp3");

  // Print the metadata
  print_metadata(metadata);

  // Free the metadata
  free(metadata->artist);
  free(metadata->album);
  free(metadata->title);
  free(metadata);

  return 0;
}