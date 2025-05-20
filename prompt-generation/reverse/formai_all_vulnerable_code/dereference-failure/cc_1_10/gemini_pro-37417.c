//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a song
typedef struct song {
  char title[50];
  char artist[50];
  char album[50];
  int year;
} song_t;

// Function to create a new song
song_t *create_song(char *title, char *artist, char *album, int year) {
  song_t *new_song = malloc(sizeof(song_t));
  strcpy(new_song->title, title);
  strcpy(new_song->artist, artist);
  strcpy(new_song->album, album);
  new_song->year = year;
  return new_song;
}

// Function to print a song
void print_song(song_t *song) {
  printf("Title: %s\n", song->title);
  printf("Artist: %s\n", song->artist);
  printf("Album: %s\n", song->album);
  printf("Year: %d\n", song->year);
}

// Function to add a song to the library
void add_song(song_t *song, song_t **library, int *num_songs) {
  library[*num_songs] = song;
  *num_songs += 1;
}

// Function to search for a song in the library
song_t *search_song(char *title, song_t **library, int num_songs) {
  for (int i = 0; i < num_songs; i++) {
    if (strcmp(library[i]->title, title) == 0) {
      return library[i];
    }
  }
  return NULL;
}

// Function to print the library
void print_library(song_t **library, int num_songs) {
  for (int i = 0; i < num_songs; i++) {
    print_song(library[i]);
    printf("\n");
  }
}

// Main function
int main() {
  // Create a new music library
  song_t **library = malloc(sizeof(song_t *) * 100);
  int num_songs = 0;

  // Add some songs to the library
  add_song(create_song("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975), library, &num_songs);
  add_song(create_song("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971), library, &num_songs);
  add_song(create_song("Hotel California", "The Eagles", "Hotel California", 1976), library, &num_songs);
  add_song(create_song("Imagine", "John Lennon", "Imagine", 1971), library, &num_songs);
  add_song(create_song("Hey Jude", "The Beatles", "Hey Jude", 1968), library, &num_songs);

  // Print the library
  printf("Your music library:\n");
  print_library(library, num_songs);

  // Search for a song in the library
  char *title = "Bohemian Rhapsody";
  song_t *song = search_song(title, library, num_songs);
  if (song != NULL) {
    printf("Found song:\n");
    print_song(song);
  } else {
    printf("Song not found.\n");
  }

  // Free the library
  for (int i = 0; i < num_songs; i++) {
    free(library[i]);
  }
  free(library);

  return 0;
}