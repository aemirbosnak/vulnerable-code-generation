//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct metadata {
  int year;
  char *title;
  char *artist;
  char *album;
  char *genre;
};

int main() {
  // Create a metadata extractor.
  struct metadata extractor;

  // Open a file.
  FILE *file = fopen("file.mp3", "rb");

  // Read the file's ID3v2 tag.
  char buffer[1024];
  fread(buffer, 1024, 1, file);

  // Parse the ID3v2 tag.
  if (buffer[0] == 'I' && buffer[1] == 'D' && buffer[2] == '3') {
    // Get the year.
    extractor.year = atoi(buffer + 3 + 4);

    // Get the title.
    extractor.title = malloc(strlen(buffer + 3 + 10) + 1);
    strcpy(extractor.title, buffer + 3 + 10);

    // Get the artist.
    extractor.artist = malloc(strlen(buffer + 3 + 33) + 1);
    strcpy(extractor.artist, buffer + 3 + 33);

    // Get the album.
    extractor.album = malloc(strlen(buffer + 3 + 63) + 1);
    strcpy(extractor.album, buffer + 3 + 63);

    // Get the genre.
    extractor.genre = malloc(strlen(buffer + 3 + 93) + 1);
    strcpy(extractor.genre, buffer + 3 + 93);
  }

  // Close the file.
  fclose(file);

  // Print the extracted metadata.
  printf("Year: %d\n", extractor.year);
  printf("Title: %s\n", extractor.title);
  printf("Artist: %s\n", extractor.artist);
  printf("Album: %s\n", extractor.album);
  printf("Genre: %s\n", extractor.genre);

  // Free the allocated memory.
  free(extractor.title);
  free(extractor.artist);
  free(extractor.album);
  free(extractor.genre);

  return 0;
}