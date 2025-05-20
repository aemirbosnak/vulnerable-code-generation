//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the metadata keys
#define ARTIST "artist"
#define ALBUM "album"
#define TITLE "title"
#define TRACK "track"
#define YEAR "year"
#define COMMENT "comment"

// Define the metadata structure
typedef struct {
  char *artist;
  char *album;
  char *title;
  int track;
  int year;
  char *comment;
} Metadata;

// Create a new metadata object
Metadata *new_metadata(char *artist, char *album, char *title, int track, int year, char *comment) {
  Metadata *metadata = malloc(sizeof(Metadata));
  metadata->artist = strdup(artist);
  metadata->album = strdup(album);
  metadata->title = strdup(title);
  metadata->track = track;
  metadata->year = year;
  metadata->comment = strdup(comment);
  return metadata;
}

// Free the memory allocated for a metadata object
void free_metadata(Metadata *metadata) {
  free(metadata->artist);
  free(metadata->album);
  free(metadata->title);
  free(metadata->comment);
  free(metadata);
}

// Print the metadata object
void print_metadata(Metadata *metadata) {
  printf("Artist: %s\n", metadata->artist);
  printf("Album: %s\n", metadata->album);
  printf("Title: %s\n", metadata->title);
  printf("Track: %d\n", metadata->track);
  printf("Year: %d\n", metadata->year);
  printf("Comment: %s\n", metadata->comment);
}

// Extract the metadata from a file path
Metadata *extract_metadata(char *file_path) {
  // Open the file
  FILE *file = fopen(file_path, "r");
  if (file == NULL) {
    return NULL;
  }

  // Read the file contents
  char *file_contents = NULL;
  long file_size = 0;
  fseek(file, 0, SEEK_END);
  file_size = ftell(file);
  fseek(file, 0, SEEK_SET);
  file_contents = malloc(file_size + 1);
  fread(file_contents, 1, file_size, file);
  file_contents[file_size] = '\0';

  // Close the file
  fclose(file);

  // Extract the metadata
  Metadata *metadata = NULL;
  char *artist = NULL;
  char *album = NULL;
  char *title = NULL;
  int track = 0;
  int year = 0;
  char *comment = NULL;

  // Artist
  char *artist_start = strstr(file_contents, ARTIST);
  if (artist_start != NULL) {
    artist_start += strlen(ARTIST) + 1;
    char *artist_end = strstr(artist_start, ";");
    if (artist_end != NULL) {
      artist = strndup(artist_start, artist_end - artist_start);
    }
  }

  // Album
  char *album_start = strstr(file_contents, ALBUM);
  if (album_start != NULL) {
    album_start += strlen(ALBUM) + 1;
    char *album_end = strstr(album_start, ";");
    if (album_end != NULL) {
      album = strndup(album_start, album_end - album_start);
    }
  }

  // Title
  char *title_start = strstr(file_contents, TITLE);
  if (title_start != NULL) {
    title_start += strlen(TITLE) + 1;
    char *title_end = strstr(title_start, ";");
    if (title_end != NULL) {
      title = strndup(title_start, title_end - title_start);
    }
  }

  // Track
  char *track_start = strstr(file_contents, TRACK);
  if (track_start != NULL) {
    track_start += strlen(TRACK) + 1;
    char *track_end = strstr(track_start, ";");
    if (track_end != NULL) {
      track = atoi(track_start);
    }
  }

  // Year
  char *year_start = strstr(file_contents, YEAR);
  if (year_start != NULL) {
    year_start += strlen(YEAR) + 1;
    char *year_end = strstr(year_start, ";");
    if (year_end != NULL) {
      year = atoi(year_start);
    }
  }

  // Comment
  char *comment_start = strstr(file_contents, COMMENT);
  if (comment_start != NULL) {
    comment_start += strlen(COMMENT) + 1;
    char *comment_end = strstr(comment_start, ";");
    if (comment_end != NULL) {
      comment = strndup(comment_start, comment_end - comment_start);
    }
  }

  // Create the metadata object
  metadata = new_metadata(artist, album, title, track, year, comment);

  // Free the temporary variables
  free(file_contents);
  free(artist);
  free(album);
  free(title);
  free(comment);

  // Return the metadata object
  return metadata;
}

// Main function
int main(int argc, char *argv[]) {
  // Check if a file path was provided
  if (argc < 2) {
    printf("Usage: %s <file_path>\n", argv[0]);
    return 1;
  }

  // Extract the metadata from the file path
  Metadata *metadata = extract_metadata(argv[1]);

  // Print the metadata
  print_metadata(metadata);

  // Free the memory allocated for the metadata object
  free_metadata(metadata);

  return 0;
}