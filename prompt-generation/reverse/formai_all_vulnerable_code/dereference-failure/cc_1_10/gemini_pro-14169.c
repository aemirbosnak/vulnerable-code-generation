//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Music {
  char title[50];
  char artist[50];
  char album[50];
  int year;
  char genre[50];
};

// Database
struct MusicLibrary {
  struct Music *songs;
  int num_songs;
};

// Functions
void add_song(struct MusicLibrary *lib, char *title, char *artist, char *album, int year, char *genre) {
  lib->songs = realloc(lib->songs, (lib->num_songs + 1) * sizeof(struct Music));
  strcpy(lib->songs[lib->num_songs].title, title);
  strcpy(lib->songs[lib->num_songs].artist, artist);
  strcpy(lib->songs[lib->num_songs].album, album);
  lib->songs[lib->num_songs].year = year;
  strcpy(lib->songs[lib->num_songs].genre, genre);
  lib->num_songs++;
}

void print_library(struct MusicLibrary *lib) {
  for (int i = 0; i < lib->num_songs; i++) {
    printf("%s - %s (%s, %d, %s)\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].album, lib->songs[i].year, lib->songs[i].genre);
  }
}

void search_by_title(struct MusicLibrary *lib, char *title) {
  for (int i = 0; i < lib->num_songs; i++) {
    if (strcmp(lib->songs[i].title, title) == 0) {
      printf("%s - %s (%s, %d, %s)\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].album, lib->songs[i].year, lib->songs[i].genre);
      return;
    }
  }
  printf("Song not found.\n");
}

void search_by_artist(struct MusicLibrary *lib, char *artist) {
  for (int i = 0; i < lib->num_songs; i++) {
    if (strcmp(lib->songs[i].artist, artist) == 0) {
      printf("%s - %s (%s, %d, %s)\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].album, lib->songs[i].year, lib->songs[i].genre);
      return;
    }
  }
  printf("Artist not found.\n");
}

// Initialize the music library with some holographic tunes
struct MusicLibrary *init_library() {
  struct MusicLibrary *lib = malloc(sizeof(struct MusicLibrary));
  lib->num_songs = 0;
  add_song(lib, "Interstellar Symphony", "XYZ Orchestra", "Cosmic Journeys", 2042, "Classical");
  add_song(lib, "Binary Beat", "01101110", "Digital Dawn", 2045, "Electronic");
  add_song(lib, "Quantum Groove", "Dr. Qubit", "Subatomic Soundscapes", 2048, "Experimental");
  add_song(lib, "Temporal Tapestry", "The Chrononauts", "Timeless Melodies", 2051, "Ambient");
  add_song(lib, "Singularity Suite", "AI Harmony", "Machine Dreams", 2054, "Artificial Intelligence");
  return lib;
}

int main() {
  // Welcome to the holographic music library
  printf("Welcome to the Holographic Music Library!\n");

  // Create the library
  struct MusicLibrary *lib = init_library();

  // Print the library
  printf("Current Library:\n");
  print_library(lib);

  // Search for a song by title
  char title[50];
  printf("Enter the title of the song you want to search for: ");
  scanf("%s", title);
  search_by_title(lib, title);

  // Search for a song by artist
  char artist[50];
  printf("Enter the artist of the song you want to search for: ");
  scanf("%s", artist);
  search_by_artist(lib, artist);

  // Free the library
  free(lib->songs);
  free(lib);

  return 0;
}