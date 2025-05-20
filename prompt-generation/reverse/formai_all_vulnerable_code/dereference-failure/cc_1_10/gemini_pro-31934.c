//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A curious struct to represent a song
typedef struct Song {
  char *title;
  char *artist;
  int year;
  int length;
} Song;

// A curious struct to represent a library
typedef struct Library {
  Song **songs;
  int num_songs;
} Library;

// A curious function to create a new song
Song *create_song(char *title, char *artist, int year, int length) {
  Song *song = malloc(sizeof(Song));
  song->title = malloc(strlen(title) + 1);
  strcpy(song->title, title);
  song->artist = malloc(strlen(artist) + 1);
  strcpy(song->artist, artist);
  song->year = year;
  song->length = length;
  return song;
}

// A curious function to create a new library
Library *create_library() {
  Library *library = malloc(sizeof(Library));
  library->songs = malloc(sizeof(Song *) * 10);
  library->num_songs = 0;
  return library;
}

// A curious function to add a song to a library
void add_song_to_library(Library *library, Song *song) {
  library->songs[library->num_songs] = song;
  library->num_songs++;
}

// A curious function to print a song
void print_song(Song *song) {
  printf("Title: %s\n", song->title);
  printf("Artist: %s\n", song->artist);
  printf("Year: %d\n", song->year);
  printf("Length: %d\n", song->length);
  printf("\n");
}

// A curious function to print a library
void print_library(Library *library) {
  for (int i = 0; i < library->num_songs; i++) {
    print_song(library->songs[i]);
  }
}

// A curious function to free a song
void free_song(Song *song) {
  free(song->title);
  free(song->artist);
  free(song);
}

// A curious function to free a library
void free_library(Library *library) {
  for (int i = 0; i < library->num_songs; i++) {
    free_song(library->songs[i]);
  }
  free(library->songs);
  free(library);
}

// A curious main function
int main() {
  // Create a new library
  Library *library = create_library();

  // Add some songs to the library
  add_song_to_library(library, create_song("Bohemian Rhapsody", "Queen", 1975, 5));
  add_song_to_library(library, create_song("Stairway to Heaven", "Led Zeppelin", 1971, 8));
  add_song_to_library(library, create_song("Hotel California", "Eagles", 1976, 6));

  // Print the library
  print_library(library);

  // Free the library
  free_library(library);

  return 0;
}