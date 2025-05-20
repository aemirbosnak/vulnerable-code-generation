//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of songs in the library
#define MAX_SONGS 100

// Define the structure of a song
typedef struct song {
  int id;
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
  library->num_songs = 0;
  return library;
}

// Add a song to the library
void add_song(library_t *library, song_t song) {
  library->songs[library->num_songs++] = song;
}

// Print the library
void print_library(library_t *library) {
  for (int i = 0; i < library->num_songs; i++) {
    printf("Song %d: %s by %s from the album %s (%d)\n", i + 1, library->songs[i].title, library->songs[i].artist, library->songs[i].album, library->songs[i].year);
  }
}

// Search for a song by title
song_t *search_song_by_title(library_t *library, char *title) {
  for (int i = 0; i < library->num_songs; i++) {
    if (strcmp(library->songs[i].title, title) == 0) {
      return &library->songs[i];
    }
  }
  return NULL;
}

// Search for a song by artist
song_t *search_song_by_artist(library_t *library, char *artist) {
  for (int i = 0; i < library->num_songs; i++) {
    if (strcmp(library->songs[i].artist, artist) == 0) {
      return &library->songs[i];
    }
  }
  return NULL;
}

// Search for a song by album
song_t *search_song_by_album(library_t *library, char *album) {
  for (int i = 0; i < library->num_songs; i++) {
    if (strcmp(library->songs[i].album, album) == 0) {
      return &library->songs[i];
    }
  }
  return NULL;
}

// Delete a song from the library
void delete_song(library_t *library, int id) {
  for (int i = 0; i < library->num_songs; i++) {
    if (library->songs[i].id == id) {
      library->songs[i] = library->songs[library->num_songs - 1];
      library->num_songs--;
      break;
    }
  }
}

// Main function
int main() {
  // Create a new library
  library_t *library = create_library();

  // Add some songs to the library
  song_t song1 = {1, "Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975};
  add_song(library, song1);
  song_t song2 = {2, "Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971};
  add_song(library, song2);
  song_t song3 = {3, "Hotel California", "Eagles", "Hotel California", 1976};
  add_song(library, song3);

  // Print the library
  print_library(library);

  // Search for a song by title
  song_t *song = search_song_by_title(library, "Stairway to Heaven");
  if (song != NULL) {
    printf("Found song %s by %s from the album %s (%d)\n", song->title, song->artist, song->album, song->year);
  } else {
    printf("Song not found\n");
  }

  // Search for a song by artist
  song = search_song_by_artist(library, "Queen");
  if (song != NULL) {
    printf("Found song %s by %s from the album %s (%d)\n", song->title, song->artist, song->album, song->year);
  } else {
    printf("Song not found\n");
  }

  // Search for a song by album
  song = search_song_by_album(library, "Hotel California");
  if (song != NULL) {
    printf("Found song %s by %s from the album %s (%d)\n", song->title, song->artist, song->album, song->year);
  } else {
    printf("Song not found\n");
  }

  // Delete a song from the library
  delete_song(library, 2);

  // Print the library
  print_library(library);

  // Free the memory allocated for the library
  free(library);

  return 0;
}