//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the music library
typedef struct music_library {
  char **tracks; // Array of track names
  int num_tracks; // Number of tracks in the library
} music_library;

// Function to create a new music library
music_library *create_music_library() {
  music_library *library = (music_library *)malloc(sizeof(music_library));
  library->tracks = (char **)malloc(sizeof(char *) * 100);
  library->num_tracks = 0;
  return library;
}

// Function to add a track to the music library
void add_track(music_library *library, char *track) {
  library->tracks[library->num_tracks] = strdup(track);
  library->num_tracks++;
}

// Function to print the music library
void print_music_library(music_library *library) {
  for (int i = 0; i < library->num_tracks; i++) {
    printf("%s\n", library->tracks[i]);
  }
}

// Function to free the memory allocated for the music library
void free_music_library(music_library *library) {
  for (int i = 0; i < library->num_tracks; i++) {
    free(library->tracks[i]);
  }
  free(library->tracks);
  free(library);
}

// Main function
int main() {
  // Create a new music library
  music_library *library = create_music_library();

  // Add some tracks to the library
  add_track(library, "Track 1");
  add_track(library, "Track 2");
  add_track(library, "Track 3");

  // Print the music library
  print_music_library(library);

  // Free the memory allocated for the music library
  free_music_library(library);

  return 0;
}