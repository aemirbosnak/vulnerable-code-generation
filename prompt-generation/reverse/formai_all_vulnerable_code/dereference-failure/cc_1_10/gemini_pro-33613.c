//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a song
typedef struct song {
  char* title;       // Title of the song
  char* artist;      // Artist of the song
  char* album;       // Album of the song
  int year;          // Year the song was released
  int duration;      // Duration of the song in seconds
  struct song* next;  // Pointer to the next song in the list
} song;

// Function to create a new song
song* create_song(char* title, char* artist, char* album, int year, int duration) {
  song* new_song = (song*)malloc(sizeof(song));
  new_song->title = strdup(title);
  new_song->artist = strdup(artist);
  new_song->album = strdup(album);
  new_song->year = year;
  new_song->duration = duration;
  new_song->next = NULL;
  return new_song;
}

// Function to add a song to the library
void add_song(song** library, song* new_song) {
  if (*library == NULL) {
    *library = new_song;
  } else {
    song* current = *library;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_song;
  }
}

// Function to print the library
void print_library(song* library) {
  song* current = library;
  while (current != NULL) {
    printf("%s - %s (%s, %d, %d seconds)\n",
           current->title, current->artist, current->album, current->year, current->duration);
    current = current->next;
  }
}

// Function to free the memory allocated for the library
void free_library(song* library) {
  song* current = library;
  while (current != NULL) {
    song* next = current->next;
    free(current->title);
    free(current->artist);
    free(current->album);
    free(current);
    current = next;
  }
}

// Main function
int main() {
  // Create a new library
  song* library = NULL;

  // Add some songs to the library
  add_song(&library, create_song("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 360));
  add_song(&library, create_song("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 480));
  add_song(&library, create_song("Hotel California", "The Eagles", "Hotel California", 1976, 390));
  add_song(&library, create_song("Imagine", "John Lennon", "Imagine", 1971, 180));
  add_song(&library, create_song("Born to Run", "Bruce Springsteen", "Born to Run", 1975, 240));

  // Print the library
  printf("Library:\n");
  print_library(library);

  // Free the memory allocated for the library
  free_library(library);

  return 0;
}