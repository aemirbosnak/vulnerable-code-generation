//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum number of songs in the library
#define MAX_SONGS 100

// Define the structure of a song
typedef struct song {
  char title[50];
  char artist[50];
  char album[50];
  int year;
  int track_number;
  int duration; // in seconds
} song;

// Define the structure of the library
typedef struct library {
  song songs[MAX_SONGS];
  int num_songs;
} library;

// Create a new library
library *create_library() {
  library *lib = malloc(sizeof(library));
  if (lib == NULL) {
    return NULL;
  }

  lib->num_songs = 0;

  return lib;
}

// Add a song to the library
void add_song(library *lib, song *song) {
  if (lib->num_songs >= MAX_SONGS) {
    return;
  }

  lib->songs[lib->num_songs++] = *song;
}

// Print the library
void print_library(library *lib) {
  for (int i = 0; i < lib->num_songs; i++) {
    song *song = &lib->songs[i];
    printf("%s - %s - %s - %d - %d - %d\n", song->title, song->artist, song->album, song->year, song->track_number, song->duration);
  }
}

// Search for a song by title
song *search_song_by_title(library *lib, char *title) {
  for (int i = 0; i < lib->num_songs; i++) {
    song *song = &lib->songs[i];
    if (strcmp(song->title, title) == 0) {
      return song;
    }
  }

  return NULL;
}

// Search for a song by artist
song *search_song_by_artist(library *lib, char *artist) {
  for (int i = 0; i < lib->num_songs; i++) {
    song *song = &lib->songs[i];
    if (strcmp(song->artist, artist) == 0) {
      return song;
    }
  }

  return NULL;
}

// Search for a song by album
song *search_song_by_album(library *lib, char *album) {
  for (int i = 0; i < lib->num_songs; i++) {
    song *song = &lib->songs[i];
    if (strcmp(song->album, album) == 0) {
      return song;
    }
  }

  return NULL;
}

// Delete a song from the library
void delete_song(library *lib, song *song) {
  for (int i = 0; i < lib->num_songs; i++) {
    if (&lib->songs[i] == song) {
      for (int j = i; j < lib->num_songs - 1; j++) {
        lib->songs[j] = lib->songs[j + 1];
      }
      lib->num_songs--;
      break;
    }
  }
}

// Free the library
void free_library(library *lib) {
  free(lib);
}

int main() {
  // Create a new library
  library *lib = create_library();

  // Add some songs to the library
  song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1, 355};
  add_song(lib, &song1);

  song song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 1, 480};
  add_song(lib, &song2);

  song song3 = {"Hotel California", "Eagles", "Hotel California", 1976, 1, 382};
  add_song(lib, &song3);

  // Print the library
  printf("Library:\n");
  print_library(lib);

  // Search for a song by title
  char *title = "Bohemian Rhapsody";
  song *song = search_song_by_title(lib, title);
  if (song != NULL) {
    printf("Found song by title: %s - %s - %s - %d - %d - %d\n", song->title, song->artist, song->album, song->year, song->track_number, song->duration);
  } else {
    printf("Song not found by title: %s\n", title);
  }

  // Search for a song by artist
  char *artist = "Led Zeppelin";
  song = search_song_by_artist(lib, artist);
  if (song != NULL) {
    printf("Found song by artist: %s - %s - %s - %d - %d - %d\n", song->title, song->artist, song->album, song->year, song->track_number, song->duration);
  } else {
    printf("Song not found by artist: %s\n", artist);
  }

  // Search for a song by album
  char *album = "Hotel California";
  song = search_song_by_album(lib, album);
  if (song != NULL) {
    printf("Found song by album: %s - %s - %s - %d - %d - %d\n", song->title, song->artist, song->album, song->year, song->track_number, song->duration);
  } else {
    printf("Song not found by album: %s\n", album);
  }

  // Delete a song from the library
  song = search_song_by_title(lib, "Hotel California");
  if (song != NULL) {
    delete_song(lib, song);
    printf("Deleted song: %s - %s - %s - %d - %d - %d\n", song->title, song->artist, song->album, song->year, song->track_number, song->duration);
  } else {
    printf("Song not found for deletion: %s\n", "Hotel California");
  }

  // Free the library
  free_library(lib);

  return 0;
}