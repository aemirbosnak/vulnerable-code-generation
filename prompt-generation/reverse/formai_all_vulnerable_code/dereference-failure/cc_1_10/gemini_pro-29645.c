//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a song
typedef struct song {
  char *title;
  char *artist;
  int year;
  int length;
} song;

// Define the structure of a library
typedef struct library {
  song *songs;
  int num_songs;
} library;

// Create a new library
library *create_library() {
  library *lib = malloc(sizeof(library));
  lib->songs = NULL;
  lib->num_songs = 0;
  return lib;
}

// Add a song to a library
void add_song(library *lib, song *s) {
  lib->songs = realloc(lib->songs, (lib->num_songs + 1) * sizeof(song));
  lib->songs[lib->num_songs] = *s;
  lib->num_songs++;
}

// Print the contents of a library
void print_library(library *lib) {
  for (int i = 0; i < lib->num_songs; i++) {
    printf("%s by %s (%d, %d minutes)\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].year, lib->songs[i].length);
  }
}

// Free the memory allocated for a library
void free_library(library *lib) {
  for (int i = 0; i < lib->num_songs; i++) {
    free(lib->songs[i].title);
    free(lib->songs[i].artist);
  }
  free(lib->songs);
  free(lib);
}

// Main function
int main() {
  // Create a new library
  library *lib = create_library();

  // Add some songs to the library
  song *s1 = malloc(sizeof(song));
  s1->title = strdup("Bohemian Rhapsody");
  s1->artist = strdup("Queen");
  s1->year = 1975;
  s1->length = 6;
  add_song(lib, s1);

  song *s2 = malloc(sizeof(song));
  s2->title = strdup("Stairway to Heaven");
  s2->artist = strdup("Led Zeppelin");
  s2->year = 1971;
  s2->length = 8;
  add_song(lib, s2);

  song *s3 = malloc(sizeof(song));
  s3->title = strdup("Hotel California");
  s3->artist = strdup("Eagles");
  s3->year = 1976;
  s3->length = 7;
  add_song(lib, s3);

  // Print the contents of the library
  print_library(lib);

  // Free the memory allocated for the library
  free_library(lib);

  return 0;
}