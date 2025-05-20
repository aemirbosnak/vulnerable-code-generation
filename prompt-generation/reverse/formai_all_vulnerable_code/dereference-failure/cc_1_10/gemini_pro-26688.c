//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

typedef struct song {
  char title[50];
  char artist[50];
  char album[50];
  int year;
  int track;
} song_t;

typedef struct library {
  song_t songs[MAX_SONGS];
  int num_songs;
} library_t;

// Create a new library
library_t *create_library() {
  library_t *lib = malloc(sizeof(library_t));
  lib->num_songs = 0;
  return lib;
}

// Add a song to the library
void add_song(library_t *lib, song_t song) {
  if (lib->num_songs < MAX_SONGS) {
    lib->songs[lib->num_songs] = song;
    lib->num_songs++;
  }
}

// Print the library
void print_library(library_t *lib) {
  for (int i = 0; i < lib->num_songs; i++) {
    printf("%s - %s - %s - %d - %d\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].album, lib->songs[i].year, lib->songs[i].track);
  }
}

// Free the library
void free_library(library_t *lib) {
  free(lib);
}

int main() {
  // Create a new library
  library_t *lib = create_library();

  // Add some songs to the library
  song_t song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1};
  song_t song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 4};
  song_t song3 = {"Hotel California", "The Eagles", "Hotel California", 1976, 1};
  add_song(lib, song1);
  add_song(lib, song2);
  add_song(lib, song3);

  // Print the library
  printf("Library:\n");
  print_library(lib);

  // Free the library
  free_library(lib);

  return 0;
}