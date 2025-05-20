//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_SIZE 1024
#define MAX_FILE_SIZE 1024*1024

struct metadata {
  char title[MAX_METADATA_SIZE];
  char artist[MAX_METADATA_SIZE];
  char album[MAX_METADATA_SIZE];
  int year;
  int track_number;
  int duration;
};

int extract_metadata(const char *file_path, struct metadata *metadata) {
  // Open the file
  FILE *file = fopen(file_path, "rb");
  if (file == NULL) {
    return -1;
  }

  // Read the file into a buffer
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  rewind(file);
  char *buffer = malloc(file_size);
  if (buffer == NULL) {
    fclose(file);
    return -1;
  }
  fread(buffer, file_size, 1, file);
  fclose(file);

  // Search for the metadata tags
  const char *title_tag = "Title: ";
  const char *artist_tag = "Artist: ";
  const char *album_tag = "Album: ";
  const char *year_tag = "Year: ";
  const char *track_number_tag = "Track Number: ";
  const char *duration_tag = "Duration: ";

  char *title_start = strstr(buffer, title_tag);
  char *artist_start = strstr(buffer, artist_tag);
  char *album_start = strstr(buffer, album_tag);
  char *year_start = strstr(buffer, year_tag);
  char *track_number_start = strstr(buffer, track_number_tag);
  char *duration_start = strstr(buffer, duration_tag);

  if (title_start == NULL || artist_start == NULL || album_start == NULL || year_start == NULL || track_number_start == NULL || duration_start == NULL) {
    free(buffer);
    return -1;
  }

  // Extract the metadata values
  strcpy(metadata->title, title_start + strlen(title_tag));
  strcpy(metadata->artist, artist_start + strlen(artist_tag));
  strcpy(metadata->album, album_start + strlen(album_tag));
  metadata->year = atoi(year_start + strlen(year_tag));
  metadata->track_number = atoi(track_number_start + strlen(track_number_tag));
  metadata->duration = atoi(duration_start + strlen(duration_tag));

  // Free the buffer
  free(buffer);

  return 0;
}

int main(void) {
  // Declare the metadata structure
  struct metadata metadata;

  // Extract the metadata from a file
  int result = extract_metadata("song.mp3", &metadata);
  if (result != 0) {
    printf("Error extracting metadata\n");
    return 1;
  }

  // Print the metadata
  printf("Title: %s\n", metadata.title);
  printf("Artist: %s\n", metadata.artist);
  printf("Album: %s\n", metadata.album);
  printf("Year: %d\n", metadata.year);
  printf("Track Number: %d\n", metadata.track_number);
  printf("Duration: %d seconds\n", metadata.duration);

  return 0;
}