//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of songs in the library
#define MAX_SONGS 100

// Define the structure of a song
typedef struct song {
  char title[50];
  char artist[50];
  char album[50];
  int year;
  int track_number;
} song;

// Define the structure of the library
typedef struct library {
  song songs[MAX_SONGS];
  int num_songs;
} library;

// Create a new library
library* create_library() {
  library* lib = (library*)malloc(sizeof(library));
  lib->num_songs = 0;
  return lib;
}

// Add a song to the library
void add_song(library* lib, song* s) {
  if (lib->num_songs < MAX_SONGS) {
    lib->songs[lib->num_songs] = *s;
    lib->num_songs++;
  } else {
    printf("Library is full!\n");
  }
}

// Print the library
void print_library(library* lib) {
  for (int i = 0; i < lib->num_songs; i++) {
    printf("Song %d:\n", i + 1);
    printf("Title: %s\n", lib->songs[i].title);
    printf("Artist: %s\n", lib->songs[i].artist);
    printf("Album: %s\n", lib->songs[i].album);
    printf("Year: %d\n", lib->songs[i].year);
    printf("Track number: %d\n\n", lib->songs[i].track_number);
  }
}

// Free the memory allocated for the library
void free_library(library* lib) {
  free(lib);
}

// Main function
int main() {
  // Create a new library
  library* lib = create_library();

  // Add some songs to the library
  song s1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1};
  add_song(lib, &s1);
  song s2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 4};
  add_song(lib, &s2);
  song s3 = {"Hotel California", "Eagles", "Hotel California", 1976, 3};
  add_song(lib, &s3);

  // Print the library
  print_library(lib);

  // Free the memory allocated for the library
  free_library(lib);

  return 0;
}