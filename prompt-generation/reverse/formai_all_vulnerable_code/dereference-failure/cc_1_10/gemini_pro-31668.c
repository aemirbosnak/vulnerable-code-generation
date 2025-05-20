//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: systematic
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
} song_t;

// Define the structure of the library
typedef struct library {
  song_t songs[MAX_SONGS];
  int num_songs;
} library_t;

// Function to create a new library
library_t *create_library() {
  library_t *library = malloc(sizeof(library_t));
  library->num_songs = 0;
  return library;
}

// Function to add a song to the library
void add_song(library_t *library, song_t song) {
  if (library->num_songs < MAX_SONGS) {
    library->songs[library->num_songs++] = song;
  } else {
    printf("Error: Library is full.\n");
  }
}

// Function to search for a song in the library by title
song_t *search_song_by_title(library_t *library, char *title) {
  for (int i = 0; i < library->num_songs; i++) {
    if (strcmp(library->songs[i].title, title) == 0) {
      return &library->songs[i];
    }
  }
  return NULL;
}

// Function to search for a song in the library by artist
song_t *search_song_by_artist(library_t *library, char *artist) {
  for (int i = 0; i < library->num_songs; i++) {
    if (strcmp(library->songs[i].artist, artist) == 0) {
      return &library->songs[i];
    }
  }
  return NULL;
}

// Function to search for a song in the library by album
song_t *search_song_by_album(library_t *library, char *album) {
  for (int i = 0; i < library->num_songs; i++) {
    if (strcmp(library->songs[i].album, album) == 0) {
      return &library->songs[i];
    }
  }
  return NULL;
}

// Function to print the library
void print_library(library_t *library) {
  for (int i = 0; i < library->num_songs; i++) {
    printf("%s by %s from the album %s (%d)\n", library->songs[i].title, library->songs[i].artist, library->songs[i].album, library->songs[i].year);
  }
}

// Function to free the memory allocated for the library
void free_library(library_t *library) {
  free(library);
}

// Main function
int main() {
  // Create a new library
  library_t *library = create_library();

  // Add some songs to the library
  song_t song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975};
  add_song(library, song1);
  song_t song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971};
  add_song(library, song2);
  song_t song3 = {"Hotel California", "Eagles", "Hotel California", 1976};
  add_song(library, song3);

  // Search for a song in the library by title
  song_t *song4 = search_song_by_title(library, "Bohemian Rhapsody");
  if (song4 != NULL) {
    printf("Found song: %s by %s from the album %s (%d)\n", song4->title, song4->artist, song4->album, song4->year);
  } else {
    printf("Song not found.\n");
  }

  // Search for a song in the library by artist
  song_t *song5 = search_song_by_artist(library, "Led Zeppelin");
  if (song5 != NULL) {
    printf("Found song: %s by %s from the album %s (%d)\n", song5->title, song5->artist, song5->album, song5->year);
  } else {
    printf("Song not found.\n");
  }

  // Search for a song in the library by album
  song_t *song6 = search_song_by_album(library, "Hotel California");
  if (song6 != NULL) {
    printf("Found song: %s by %s from the album %s (%d)\n", song6->title, song6->artist, song6->album, song6->year);
  } else {
    printf("Song not found.\n");
  }

  // Print the library
  print_library(library);

  // Free the memory allocated for the library
  free_library(library);

  return 0;
}