//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a song
typedef struct song {
  char title[50];
  char artist[50];
  char album[50];
  int year;
  struct song *next;
} song;

// Define the structure of the library
typedef struct library {
  song *head;
  song *tail;
} library;

// Create a new song
song *new_song(char *title, char *artist, char *album, int year) {
  song *new_song = malloc(sizeof(song));
  strcpy(new_song->title, title);
  strcpy(new_song->artist, artist);
  strcpy(new_song->album, album);
  new_song->year = year;
  new_song->next = NULL;
  return new_song;
}

// Add a song to the library
void add_song(library *lib, song *new_song) {
  if (lib->head == NULL) {
    lib->head = new_song;
    lib->tail = new_song;
  } else {
    lib->tail->next = new_song;
    lib->tail = new_song;
  }
}

// Print the library
void print_library(library *lib) {
  song *current_song = lib->head;
  while (current_song != NULL) {
    printf("%s by %s from the album %s (%d)\n", current_song->title, current_song->artist, current_song->album, current_song->year);
    current_song = current_song->next;
  }
}

// Free the library
void free_library(library *lib) {
  song *current_song = lib->head;
  while (current_song != NULL) {
    song *next_song = current_song->next;
    free(current_song);
    current_song = next_song;
  }
}

// Main function
int main() {
  // Create a new library
  library *lib = malloc(sizeof(library));
  lib->head = NULL;
  lib->tail = NULL;

  // Add some songs to the library
  add_song(lib, new_song("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975));
  add_song(lib, new_song("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971));
  add_song(lib, new_song("Hotel California", "Eagles", "Hotel California", 1976));
  add_song(lib, new_song("Imagine", "John Lennon", "Imagine", 1971));
  add_song(lib, new_song("Strawberry Fields Forever", "The Beatles", "Magical Mystery Tour", 1967));

  // Print the library
  print_library(lib);

  // Free the library
  free_library(lib);

  return 0;
}