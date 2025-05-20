//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the metadata structure
typedef struct {
  char *title;
  char *artist;
  char *album;
  int year;
  int track;
  char *genre;
} Metadata;

// Read the metadata from a file
Metadata *read_metadata(char *filename) {
  // Open the file
  FILE *file = fopen(filename, "rb");
  if (!file) {
    return NULL;
  }

  // Read the file into a buffer
  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  fseek(file, 0, SEEK_SET);
  char *buffer = malloc(size);
  fread(buffer, 1, size, file);
  fclose(file);

  // Parse the metadata from the buffer
  Metadata *metadata = malloc(sizeof(Metadata));
  metadata->title = NULL;
  metadata->artist = NULL;
  metadata->album = NULL;
  metadata->year = 0;
  metadata->track = 0;
  metadata->genre = NULL;

  char *p = buffer;
  while (*p) {
    // Read the tag header
    char tag[4];
    strncpy(tag, p, 4);
    p += 4;

    // Read the tag size
    int size = *(unsigned int *)p;
    p += 4;

    // Read the tag data
    char *data = malloc(size);
    memcpy(data, p, size);
    p += size;

    // Parse the tag data
    if (!strcmp(tag, "TIT2")) {
      metadata->title = strdup(data);
    } else if (!strcmp(tag, "TPE1")) {
      metadata->artist = strdup(data);
    } else if (!strcmp(tag, "TALB")) {
      metadata->album = strdup(data);
    } else if (!strcmp(tag, "TYER")) {
      metadata->year = atoi(data);
    } else if (!strcmp(tag, "TRCK")) {
      metadata->track = atoi(data);
    } else if (!strcmp(tag, "TCON")) {
      metadata->genre = strdup(data);
    }

    free(data);
  }

  free(buffer);

  return metadata;
}

// Print the metadata
void print_metadata(Metadata *metadata) {
  printf("Title: %s\n", metadata->title);
  printf("Artist: %s\n", metadata->artist);
  printf("Album: %s\n", metadata->album);
  printf("Year: %d\n", metadata->year);
  printf("Track: %d\n", metadata->track);
  printf("Genre: %s\n", metadata->genre);
}

// Free the metadata
void free_metadata(Metadata *metadata) {
  free(metadata->title);
  free(metadata->artist);
  free(metadata->album);
  free(metadata->genre);
  free(metadata);
}

// Main function
int main() {
  // Read the metadata from a file
  Metadata *metadata = read_metadata("song.mp3");

  // Print the metadata
  print_metadata(metadata);

  // Free the metadata
  free_metadata(metadata);

  return 0;
}