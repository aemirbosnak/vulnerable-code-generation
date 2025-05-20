//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a song
typedef struct Song {
  char *title;
  char *artist;
  char *album;
  int year;
  int duration;
} Song;

// Structure to represent a music library
typedef struct MusicLibrary {
  Song *songs;
  int num_songs;
} MusicLibrary;

// Function to create a new song
Song *create_song(char *title, char *artist, char *album, int year, int duration) {
  Song *song = malloc(sizeof(Song));
  song->title = strdup(title);
  song->artist = strdup(artist);
  song->album = strdup(album);
  song->year = year;
  song->duration = duration;
  return song;
}

// Function to add a song to a music library
void add_song_to_library(MusicLibrary *library, Song *song) {
  library->songs = realloc(library->songs, (library->num_songs + 1) * sizeof(Song));
  library->songs[library->num_songs++] = *song;
}

// Function to print a song
void print_song(Song *song) {
  printf("Title: %s\n", song->title);
  printf("Artist: %s\n", song->artist);
  printf("Album: %s\n", song->album);
  printf("Year: %d\n", song->year);
  printf("Duration: %d seconds\n\n", song->duration);
}

// Function to print a music library
void print_music_library(MusicLibrary *library) {
  printf("Music Library:\n");
  for (int i = 0; i < library->num_songs; i++) {
    print_song(&library->songs[i]);
  }
}

// Function to free the memory allocated for a song
void free_song(Song *song) {
  free(song->title);
  free(song->artist);
  free(song->album);
  free(song);
}

// Function to free the memory allocated for a music library
void free_music_library(MusicLibrary *library) {
  for (int i = 0; i < library->num_songs; i++) {
    free_song(&library->songs[i]);
  }
  free(library->songs);
  free(library);
}

int main() {
  // Create a new music library
  MusicLibrary *library = malloc(sizeof(MusicLibrary));
  library->songs = NULL;
  library->num_songs = 0;

  // Add some songs to the library
  Song *song1 = create_song("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 355);
  add_song_to_library(library, song1);
  Song *song2 = create_song("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 480);
  add_song_to_library(library, song2);
  Song *song3 = create_song("Hotel California", "Eagles", "Hotel California", 1976, 382);
  add_song_to_library(library, song3);

  // Print the music library
  print_music_library(library);

  // Free the memory allocated for the music library
  free_music_library(library);

  return 0;
}