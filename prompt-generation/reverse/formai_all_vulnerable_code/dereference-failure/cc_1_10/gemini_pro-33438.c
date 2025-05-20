//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Song structure
typedef struct {
  char title[50];
  char artist[50];
  char album[50];
  int year;
  int duration; // in seconds
} Song;

// Library structure
typedef struct {
  Song* songs;
  int num_songs;
  int capacity;
} Library;

// Create a new library
Library* create_library() {
  Library* library = malloc(sizeof(Library));
  library->songs = malloc(10 * sizeof(Song));
  library->num_songs = 0;
  library->capacity = 10;
  return library;
}

// Add a song to the library
void add_song(Library* library, Song song) {
  // Check if the library is full
  if (library->num_songs == library->capacity) {
    // Reallocate the library to double its capacity
    library->capacity *= 2;
    library->songs = realloc(library->songs, library->capacity * sizeof(Song));
  }
  // Add the song to the library
  library->songs[library->num_songs] = song;
  library->num_songs++;
}

// Print the library
void print_library(Library* library) {
  printf("Library:\n");
  for (int i = 0; i < library->num_songs; i++) {
    printf("\t%s - %s (%d)\n",
           library->songs[i].title,
           library->songs[i].artist,
           library->songs[i].year);
  }
}

// Free the library
void free_library(Library* library) {
  free(library->songs);
  free(library);
}

// Main function
int main() {
  // Create a new library
  Library* library = create_library();

  // Add some songs to the library
  Song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 360};
  add_song(library, song1);
  Song song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 480};
  add_song(library, song2);
  Song song3 = {"Hotel California", "Eagles", "Hotel California", 1976, 390};
  add_song(library, song3);

  // Print the library
  printf("\nInitial Library:\n");
  print_library(library);

  // Remove a song from the library
  printf("Removing \"Stairway to Heaven\" from library.\n");
  for (int i = 0; i < library->num_songs; i++) {
    if (strcmp(library->songs[i].title, "Stairway to Heaven") == 0) {
      for (int j = i; j < library->num_songs - 1; j++) {
        library->songs[j] = library->songs[j + 1];
      }
      library->num_songs--;
      break;
    }
  }

  // Print the library after removing the song
  printf("\nLibrary after removing \"Stairway to Heaven\":\n");
  print_library(library);

  // Search for a song in the library
  printf("\nSearching for \"Bohemian Rhapsody\" in library:\n");
  for (int i = 0; i < library->num_songs; i++) {
    if (strcmp(library->songs[i].title, "Bohemian Rhapsody") == 0) {
      printf("\tFound \"Bohemian Rhapsody\" at index %d.\n", i);
      break;
    }
  }

  // Free the library
  free_library(library);

  return 0;
}