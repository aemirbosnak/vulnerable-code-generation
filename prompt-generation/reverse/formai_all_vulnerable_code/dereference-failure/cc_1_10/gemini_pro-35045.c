//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of songs in the library
#define MAX_SONGS 100

// Define the structure of a song
typedef struct song {
  char *title;
  char *artist;
  char *album;
  int year;
  int track_number;
} song;

// Define the structure of the library
typedef struct library {
  song songs[MAX_SONGS];
  int num_songs;
} library;

// Create a new library
library *create_library() {
  library *lib = malloc(sizeof(library));
  lib->num_songs = 0;
  return lib;
}

// Add a song to the library
void add_song(library *lib, song *song) {
  if (lib->num_songs < MAX_SONGS) {
    lib->songs[lib->num_songs] = *song;
    lib->num_songs++;
  } else {
    printf("The library is full!\n");
  }
}

// Print the library
void print_library(library *lib) {
  for (int i = 0; i < lib->num_songs; i++) {
    printf("%d. %s by %s from the album %s (%d)\n",
      i + 1,
      lib->songs[i].title,
      lib->songs[i].artist,
      lib->songs[i].album,
      lib->songs[i].year);
  }
}

// Free the library
void free_library(library *lib) {
  for (int i = 0; i < lib->num_songs; i++) {
    free(lib->songs[i].title);
    free(lib->songs[i].artist);
    free(lib->songs[i].album);
  }
  free(lib);
}

// Main function
int main() {
  // Create a new library
  library *lib = create_library();

  // Add some songs to the library
  song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1};
  add_song(lib, &song1);
  song song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 4};
  add_song(lib, &song2);
  song song3 = {"Hotel California", "Eagles", "Hotel California", 1976, 5};
  add_song(lib, &song3);

  // Print the library
  printf("Here's a look at the amazing music library we've built:\n");
  print_library(lib);

  // Free the library
  free_library(lib);

  return 0;
}