//FormAI DATASET v1.0 Category: Music Library Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold information about each song
typedef struct {
  char title[100];
  char artist[100];
  char album[100];
  int year;
} Song;

// Define a struct to hold information about the whole library
typedef struct {
  Song* songs[1000];
  int numSongs;
} Library;

// Function to add a song to the library
void addSong(Library* library, Song* song) {
  library->songs[library->numSongs] = song;
  library->numSongs++;
}

// Function to search for a song in the library
Song* findSong(Library* library, char* title) {
  for (int i=0; i<library->numSongs; i++) {
    if (strcmp(library->songs[i]->title, title) == 0) {
      return library->songs[i];
    }
  }
  return NULL;
}

// Function to print all songs in the library
void printLibrary(Library* library) {
  for (int i=0; i<library->numSongs; i++) {
    printf("%s by %s, from the album %s (%d)\n", library->songs[i]->title, library->songs[i]->artist, library->songs[i]->album, library->songs[i]->year);
  }
}

int main() {
  // Create a new library
  Library* myLibrary = malloc(sizeof(Library));
  myLibrary->numSongs = 0;

  // Create some example songs
  Song* song1 = malloc(sizeof(Song));
  strcpy(song1->title, "Bohemian Rhapsody");
  strcpy(song1->artist, "Queen");
  strcpy(song1->album, "A Night at the Opera");
  song1->year = 1975;
  
  Song* song2 = malloc(sizeof(Song));
  strcpy(song2->title, "Billie Jean");
  strcpy(song2->artist, "Michael Jackson");
  strcpy(song2->album, "Thriller");
  song2->year = 1982;

  // Add the songs to the library
  addSong(myLibrary, song1);
  addSong(myLibrary, song2);

  // Print out all the songs in the library
  printf("My Music Library:\n");
  printLibrary(myLibrary);

  // Search for a specific song
  Song* foundSong = findSong(myLibrary, "Billie Jean");
  if (foundSong != NULL) {
    printf("\nFound song: %s by %s, from the album %s (%d)\n", foundSong->title, foundSong->artist, foundSong->album, foundSong->year);
  } else {
    printf("\nSong not found.\n");
  }

  // Free all the memory we allocated
  free(song1);
  free(song2);
  free(myLibrary);

  return 0;
}