//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct {
  char *title;
  char *artist;
  char *album;
  int year;
} Song;

typedef struct {
  Song **songs;
  int num_songs;
} Playlist;

// Functions
int add_song_to_playlist(Playlist *playlist, Song *song);
int remove_song_from_playlist(Playlist *playlist, int index);
void print_playlist(Playlist *playlist);

// Global variables
Playlist *library;

int main() {
  // Initialize the library
  library = malloc(sizeof(Playlist));
  library->songs = NULL;
  library->num_songs = 0;

  // Add some songs to the library
  Song *song1 = malloc(sizeof(Song));
  song1->title = "Neon Nights";
  song1->artist = "Cyberpunk";
  song1->album = "Dystopia";
  song1->year = 2077;
  add_song_to_playlist(library, song1);

  Song *song2 = malloc(sizeof(Song));
  song2->title = "Datastream";
  song2->artist = "Glitch";
  song2->album = "Gridlock";
  song2->year = 2080;
  add_song_to_playlist(library, song2);

  Song *song3 = malloc(sizeof(Song));
  song3->title = "Digital Dawn";
  song3->artist = "Aurora";
  song3->album = "Ascension";
  song3->year = 2085;
  add_song_to_playlist(library, song3);

  // Print the library
  print_playlist(library);

  // Remove a song from the library
  remove_song_from_playlist(library, 1);

  // Print the library again
  print_playlist(library);

  // Free the library
  for (int i = 0; i < library->num_songs; i++) {
    free(library->songs[i]);
  }
  free(library->songs);
  free(library);

  return 0;
}

int add_song_to_playlist(Playlist *playlist, Song *song) {
  // Reallocate the playlist to hold one more song
  playlist->songs = realloc(playlist->songs, (playlist->num_songs + 1) * sizeof(Song *));

  // Add the song to the playlist
  playlist->songs[playlist->num_songs] = song;
  playlist->num_songs++;

  return 0;
}

int remove_song_from_playlist(Playlist *playlist, int index) {
  // Check if the index is valid
  if (index < 0 || index >= playlist->num_songs) {
    return -1;
  }

  // Shift the songs after the removed song to the left
  for (int i = index; i < playlist->num_songs - 1; i++) {
    playlist->songs[i] = playlist->songs[i + 1];
  }

  // Decrement the number of songs in the playlist
  playlist->num_songs--;

  // Reallocate the playlist to hold one less song
  playlist->songs = realloc(playlist->songs, playlist->num_songs * sizeof(Song *));

  return 0;
}

void print_playlist(Playlist *playlist) {
  printf("Playlist:\n");
  for (int i = 0; i < playlist->num_songs; i++) {
    printf("%d. %s - %s (%s, %d)\n", i + 1, playlist->songs[i]->title, playlist->songs[i]->artist,
           playlist->songs[i]->album, playlist->songs[i]->year);
  }
}