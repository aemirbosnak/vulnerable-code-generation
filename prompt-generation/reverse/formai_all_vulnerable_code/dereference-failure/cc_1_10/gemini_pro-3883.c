//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: random
// A note-tastic music library management system!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Representing a musical masterpiece
typedef struct Song {
  char *title;
  char *artist;
  int year;
  struct Song *next;
} Song;

// A symphony of songs
typedef struct Playlist {
  char *name;
  Song *head;
  struct Playlist *next;
} Playlist;

// A harmonious manager
typedef struct MusicLibrary {
  Playlist *head;
} MusicLibrary;

// A maestro of functions
void add_song(MusicLibrary *lib, char *playlist_name, char *title, char *artist, int year) {
  Playlist *playlist = lib->head;
  while (playlist != NULL) {
    if (strcmp(playlist->name, playlist_name) == 0) {
      Song *new_song = malloc(sizeof(Song));
      new_song->title = strdup(title);
      new_song->artist = strdup(artist);
      new_song->year = year;
      new_song->next = NULL;
      if (playlist->head == NULL) {
        playlist->head = new_song;
      } else {
        Song *last_song = playlist->head;
        while (last_song->next != NULL) {
          last_song = last_song->next;
        }
        last_song->next = new_song;
      }
      return;
    }
    playlist = playlist->next;
  }
  // If the playlist doesn't exist, create it and add the song
  Playlist *new_playlist = malloc(sizeof(Playlist));
  new_playlist->name = strdup(playlist_name);
  new_playlist->head = malloc(sizeof(Song));
  new_playlist->head->title = strdup(title);
  new_playlist->head->artist = strdup(artist);
  new_playlist->head->year = year;
  new_playlist->head->next = NULL;
  new_playlist->next = lib->head;
  lib->head = new_playlist;
}

void print_library(MusicLibrary *lib) {
  Playlist *playlist = lib->head;
  while (playlist != NULL) {
    printf("Playlist: %s\n", playlist->name);
    Song *song = playlist->head;
    while (song != NULL) {
      printf("\t%s - %s (%d)\n", song->title, song->artist, song->year);
      song = song->next;
    }
    playlist = playlist->next;
  }
}

void free_library(MusicLibrary *lib) {
  Playlist *playlist = lib->head;
  while (playlist != NULL) {
    Song *song = playlist->head;
    while (song != NULL) {
      Song *next_song = song->next;
      free(song->title);
      free(song->artist);
      free(song);
      song = next_song;
    }
    Playlist *next_playlist = playlist->next;
    free(playlist->name);
    free(playlist);
    playlist = next_playlist;
  }
}

int main() {
  // Let's create a musical masterpiece!
  MusicLibrary lib;
  lib.head = NULL;

  // Adding some groovy tunes
  add_song(&lib, "Rock Classics", "Stairway to Heaven", "Led Zeppelin", 1971);
  add_song(&lib, "Pop Hits", "Thriller", "Michael Jackson", 1982);
  add_song(&lib, "Classical Gems", "Moonlight Sonata", "Ludwig van Beethoven", 1801);

  // Showtime! Let's listen to our musical journey
  print_library(&lib);

  // Time to bid farewell to our musical companions
  free_library(&lib);

  return 0;
}