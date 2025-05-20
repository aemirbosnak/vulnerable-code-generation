//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a music track
typedef struct Track {
  char *title;
  char *artist;
  char *album;
  int year;
  int duration;
} Track;

// Structure to store the music library
typedef struct Library {
  Track **tracks;
  int num_tracks;
} Library;

// Function to create a new music track
Track *create_track(char *title, char *artist, char *album, int year, int duration) {
  Track *track = malloc(sizeof(Track));
  track->title = strdup(title);
  track->artist = strdup(artist);
  track->album = strdup(album);
  track->year = year;
  track->duration = duration;
  return track;
}

// Function to add a track to the library
void add_track(Library *library, Track *track) {
  library->tracks = realloc(library->tracks, (library->num_tracks + 1) * sizeof(Track *));
  library->tracks[library->num_tracks++] = track;
}

// Function to print the library
void print_library(Library *library) {
  for (int i = 0; i < library->num_tracks; i++) {
    Track *track = library->tracks[i];
    printf("%s by %s from the album %s (%d) [%d seconds]\n",
           track->title, track->artist, track->album, track->year, track->duration);
  }
}

// Function to free the library
void free_library(Library *library) {
  for (int i = 0; i < library->num_tracks; i++) {
    free(library->tracks[i]);
  }
  free(library->tracks);
  free(library);
}

// Main function
int main() {
  // Create a new music library
  Library *library = malloc(sizeof(Library));
  library->tracks = NULL;
  library->num_tracks = 0;

  // Add some tracks to the library
  add_track(library, create_track("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 360));
  add_track(library, create_track("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 480));
  add_track(library, create_track("Hotel California", "Eagles", "Hotel California", 1976, 390));

  // Print the library
  print_library(library);

  // Free the library
  free_library(library);

  return 0;
}