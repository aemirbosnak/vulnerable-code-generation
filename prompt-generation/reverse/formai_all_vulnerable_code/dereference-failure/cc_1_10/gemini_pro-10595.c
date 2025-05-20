//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a song
typedef struct song {
  char *title;
  char *artist;
  char *album;
  int year;
  int length;
} Song;

// Define the structure of a library
typedef struct library {
  Song *songs;
  int num_songs;
} Library;

// Create a new library
Library *create_library() {
  Library *library = (Library *)malloc(sizeof(Library));
  library->songs = NULL;
  library->num_songs = 0;
  return library;
}

// Add a song to the library
void add_song(Library *library, Song *song) {
  library->songs = (Song *)realloc(library->songs, (library->num_songs + 1) * sizeof(Song));
  library->songs[library->num_songs] = *song;
  library->num_songs++;
}

// Print the library
void print_library(Library *library) {
  for (int i = 0; i < library->num_songs; i++) {
    Song song = library->songs[i];
    printf("Title: %s\n", song.title);
    printf("Artist: %s\n", song.artist);
    printf("Album: %s\n", song.album);
    printf("Year: %d\n", song.year);
    printf("Length: %d\n\n", song.length);
  }
}

// Free the library
void free_library(Library *library) {
  for (int i = 0; i < library->num_songs; i++) {
    free(library->songs[i].title);
    free(library->songs[i].artist);
    free(library->songs[i].album);
  }
  free(library->songs);
  free(library);
}

// Main function
int main() {
  // Create a new library
  Library *library = create_library();

  // Add some songs to the library
  Song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 540};
  add_song(library, &song1);
  Song song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 802};
  add_song(library, &song2);
  Song song3 = {"Hotel California", "Eagles", "Hotel California", 1976, 636};
  add_song(library, &song3);

  // Print the library
  print_library(library);

  // Free the library
  free_library(library);

  return 0;
}