//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a song
typedef struct song {
  char *title;
  char *artist;
  char *album;
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
  library *lib = (library *)malloc(sizeof(library));
  lib->songs = NULL;
  lib->num_songs = 0;
  return lib;
}

// Add a song to a library
void add_song(library *lib, song *s) {
  lib->songs = (song *)realloc(lib->songs, (lib->num_songs + 1) * sizeof(song));
  lib->songs[lib->num_songs] = *s;
  lib->num_songs++;
}

// Print the songs in a library
void print_library(library *lib) {
  for (int i = 0; i < lib->num_songs; i++) {
    printf("%s by %s from the album %s (%d)\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].album, lib->songs[i].year);
  }
}

// Free the memory allocated for a library
void free_library(library *lib) {
  for (int i = 0; i < lib->num_songs; i++) {
    free(lib->songs[i].title);
    free(lib->songs[i].artist);
    free(lib->songs[i].album);
  }
  free(lib->songs);
  free(lib);
}

// Main function
int main() {
  // Create a new library
  library *lib = create_library();

  // Add some songs to the library
  song *s1 = (song *)malloc(sizeof(song));
  s1->title = "Bohemian Rhapsody";
  s1->artist = "Queen";
  s1->album = "A Night at the Opera";
  s1->year = 1975;
  s1->track_number = 1;
  add_song(lib, s1);

  song *s2 = (song *)malloc(sizeof(song));
  s2->title = "Strawberry Fields Forever";
  s2->artist = "The Beatles";
  s2->album = "Sgt. Pepper's Lonely Hearts Club Band";
  s2->year = 1967;
  s2->track_number = 7;
  add_song(lib, s2);

  song *s3 = (song *)malloc(sizeof(song));
  s3->title = "Hey Jude";
  s3->artist = "The Beatles";
  s3->album = "Hey Jude";
  s3->year = 1968;
  s3->track_number = 1;
  add_song(lib, s3);

  // Print the songs in the library
  print_library(lib);

  // Free the memory allocated for the library
  free_library(lib);

  return 0;
}