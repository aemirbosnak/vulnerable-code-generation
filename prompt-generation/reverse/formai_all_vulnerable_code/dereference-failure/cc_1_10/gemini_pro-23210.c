//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data Structures

typedef struct Song {
  char *title;
  char *artist;
  char *album;
  int year;
  int duration;
} Song;

typedef struct Playlist {
  char *name;
  Song **songs;
  int num_songs;
} Playlist;

typedef struct Library {
  Playlist **playlists;
  int num_playlists;
} Library;

// Helper Functions

Song *create_song(char *title, char *artist, char *album, int year, int duration) {
  Song *song = malloc(sizeof(Song));

  song->title = strdup(title);
  song->artist = strdup(artist);
  song->album = strdup(album);
  song->year = year;
  song->duration = duration;

  return song;
}

Playlist *create_playlist(char *name) {
  Playlist *playlist = malloc(sizeof(Playlist));

  playlist->name = strdup(name);
  playlist->num_songs = 0;
  playlist->songs = malloc(0);

  return playlist;
}

Library *create_library() {
  Library *library = malloc(sizeof(Library));

  library->num_playlists = 0;
  library->playlists = malloc(0);

  return library;
}

// Main Functions

void add_playlist_to_library(Library *library, Playlist *playlist) {
  library->num_playlists++;
  library->playlists = realloc(library->playlists, sizeof(Playlist *) * library->num_playlists);
  library->playlists[library->num_playlists - 1] = playlist;
}

void add_song_to_playlist(Playlist *playlist, Song *song) {
  playlist->num_songs++;
  playlist->songs = realloc(playlist->songs, sizeof(Song *) * playlist->num_songs);
  playlist->songs[playlist->num_songs - 1] = song;
}

void play_song(Song *song) {
  // Placeholder function to play the song
  printf("Now playing: %s by %s\n", song->title, song->artist);
}

void print_playlist(Playlist *playlist) {
  printf("Playlist: %s\n", playlist->name);
  for (int i = 0; i < playlist->num_songs; i++) {
    printf("  %s by %s\n", playlist->songs[i]->title, playlist->songs[i]->artist);
  }
}

void print_library(Library *library) {
  printf("Library:\n");
  for (int i = 0; i < library->num_playlists; i++) {
    printf("  %s\n", library->playlists[i]->name);
  }
}

// Main

int main() {
  // Create a library
  Library *library = create_library();

  // Create a few playlists
  Playlist *playlist1 = create_playlist("My Favorites");
  Playlist *playlist2 = create_playlist("Workout");

  // Add some songs to the playlists
  add_song_to_playlist(playlist1, create_song("Shape of You", "Ed Sheeran", "÷", 2017, 240));
  add_song_to_playlist(playlist1, create_song("Despacito", "Luis Fonsi", "Despacito & Mis Grandes Éxitos", 2017, 250));
  add_song_to_playlist(playlist2, create_song("Lose Yourself", "Eminem", "The Eminem Show", 2002, 300));
  add_song_to_playlist(playlist2, create_song("Till I Collapse", "Eminem", "The Eminem Show", 2002, 290));

  // Add the playlists to the library
  add_playlist_to_library(library, playlist1);
  add_playlist_to_library(library, playlist2);

  // Print the library
  print_library(library);

  // Play a song
  play_song(playlist1->songs[0]);

  return 0;
}