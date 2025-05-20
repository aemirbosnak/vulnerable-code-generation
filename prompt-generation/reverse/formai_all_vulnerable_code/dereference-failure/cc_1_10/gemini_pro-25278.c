//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: accurate
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
} song_t;

// Define the structure of the library
typedef struct library {
  song_t songs[MAX_SONGS];
  int num_songs;
} library_t;

// Create a new library
library_t *create_library() {
  library_t *library = malloc(sizeof(library_t));
  if (library == NULL) {
    return NULL;
  }

  library->num_songs = 0;

  return library;
}

// Add a song to the library
int add_song(library_t *library, song_t *song) {
  if (library->num_songs >= MAX_SONGS) {
    return -1;
  }

  library->songs[library->num_songs] = *song;
  library->num_songs++;

  return 0;
}

// Remove a song from the library
int remove_song(library_t *library, int index) {
  if (index < 0 || index >= library->num_songs) {
    return -1;
  }

  for (int i = index; i < library->num_songs - 1; i++) {
    library->songs[i] = library->songs[i + 1];
  }

  library->num_songs--;

  return 0;
}

// Print the library
void print_library(library_t *library) {
  for (int i = 0; i < library->num_songs; i++) {
    printf("%s - %s - %s (%d)\n", library->songs[i].title, library->songs[i].artist, library->songs[i].album, library->songs[i].year);
  }
}

// Free the library
void free_library(library_t *library) {
  free(library);
}

// Main function
int main() {
  // Create a new library
  library_t *library = create_library();

  // Add some songs to the library
  song_t song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975};
  add_song(library, &song1);

  song_t song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971};
  add_song(library, &song2);

  song_t song3 = {"Hotel California", "Eagles", "Hotel California", 1976};
  add_song(library, &song3);

  // Print the library
  print_library(library);

  // Remove a song from the library
  remove_song(library, 1);

  // Print the library
  print_library(library);

  // Free the library
  free_library(library);

  return 0;
}