//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a song
typedef struct song {
  char title[50];
  char artist[50];
  char album[50];
  int year;
  int track_number;
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
  lib->songs = realloc(lib->songs, sizeof(song) * (lib->num_songs + 1));
  lib->songs[lib->num_songs++] = *s;
}

// Print the songs in a library
void print_library(library *lib) {
  for (int i = 0; i < lib->num_songs; i++) {
    printf("%s by %s from the album %s (%d)\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].album, lib->songs[i].year);
  }
}

// Free the memory allocated for a song
void free_song(song *s) {
  free(s);
}

// Free the memory allocated for a library
void free_library(library *lib) {
  for (int i = 0; i < lib->num_songs; i++) {
    free_song(&lib->songs[i]);
  }
  free(lib->songs);
  free(lib);
}

// Main function
int main() {
  // Create a new library
  library *lib = create_library();

  // Add some songs to the library
  song s1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1};
  add_song(lib, &s1);
  song s2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 4};
  add_song(lib, &s2);
  song s3 = {"Hotel California", "Eagles", "Hotel California", 1976, 3};
  add_song(lib, &s3);

  // Print the songs in the library
  print_library(lib);

  // Free the memory allocated for the library
  free_library(lib);

  return 0;
}