//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the metadata structure
typedef struct Metadata {
  char *title;
  char *artist;
  char *album;
  int year;
  int track_number;
} Metadata;

// Extract the metadata from the file
Metadata extract_metadata(char *filename) {
  // Open the file
  FILE *file = fopen(filename, "rb");
  if (!file) {
    perror("Error opening file");
    exit(1);
  }

  // Read the file into a buffer
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  rewind(file);
  char *buffer = malloc(file_size);
  if (!buffer) {
    perror("Error allocating buffer");
    exit(1);
  }
  fread(buffer, file_size, 1, file);
  fclose(file);

  // Parse the metadata
  Metadata metadata;
  metadata.title = NULL;
  metadata.artist = NULL;
  metadata.album = NULL;
  metadata.year = 0;
  metadata.track_number = 0;

  // Search for the ID3v2 tag
  char *id3v2_tag = strstr(buffer, "ID3");
  if (id3v2_tag) {
    // Parse the ID3v2 tag
    char *title_frame = strstr(id3v2_tag, "TIT2");
    if (title_frame) {
      metadata.title = strdup(title_frame + 6);
    }
    char *artist_frame = strstr(id3v2_tag, "TPE1");
    if (artist_frame) {
      metadata.artist = strdup(artist_frame + 6);
    }
    char *album_frame = strstr(id3v2_tag, "TALB");
    if (album_frame) {
      metadata.album = strdup(album_frame + 6);
    }
    char *year_frame = strstr(id3v2_tag, "TYER");
    if (year_frame) {
      metadata.year = atoi(year_frame + 6);
    }
    char *track_number_frame = strstr(id3v2_tag, "TRCK");
    if (track_number_frame) {
      metadata.track_number = atoi(track_number_frame + 6);
    }
  }

  // Return the metadata
  return metadata;
}

// Print the metadata
void print_metadata(Metadata metadata) {
  printf("Title: %s\n", metadata.title);
  printf("Artist: %s\n", metadata.artist);
  printf("Album: %s\n", metadata.album);
  printf("Year: %d\n", metadata.year);
  printf("Track number: %d\n", metadata.track_number);
}

// Free the memory allocated for the metadata
void free_metadata(Metadata metadata) {
  free(metadata.title);
  free(metadata.artist);
  free(metadata.album);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    exit(1);
  }

  // Extract the metadata from the file
  Metadata metadata = extract_metadata(argv[1]);

  // Print the metadata
  print_metadata(metadata);

  // Free the memory allocated for the metadata
  free_metadata(metadata);

  return 0;
}