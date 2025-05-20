//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of songs that can be stored in the library
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
library *create_library() {
  library *lib = (library *)malloc(sizeof(library));
  lib->num_songs = 0;
  return lib;
}

// Add a song to the library
void add_song(library *lib, song *s) {
  if (lib->num_songs < MAX_SONGS) {
    lib->songs[lib->num_songs++] = *s;
  } else {
    printf("Error: Library is full!\n");
  }
}

// Remove a song from the library
void remove_song(library *lib, char *title) {
  int i;
  for (i = 0; i < lib->num_songs; i++) {
    if (strcmp(lib->songs[i].title, title) == 0) {
      lib->songs[i] = lib->songs[lib->num_songs - 1];
      lib->num_songs--;
      return;
    }
  }
  printf("Error: Song not found!\n");
}

// Print the library
void print_library(library *lib) {
  int i;
  for (i = 0; i < lib->num_songs; i++) {
    printf("%s\n", lib->songs[i].title);
  }
}

// Free the memory allocated for the library
void free_library(library *lib) {
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

  // Print the library
  print_library(lib);

  // Remove a song from the library
  remove_song(lib, "Stairway to Heaven");

  // Print the library again
  print_library(lib);

  // Free the memory allocated for the library
  free_library(lib);

  return 0;
}