//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *title;
  char *artist;
  char *album;
  int year;
  int track;
} Song;

typedef struct {
  Song *songs;
  int num_songs;
} Library;

Library *create_library() {
  Library *lib = malloc(sizeof(Library));
  lib->songs = NULL;
  lib->num_songs = 0;
  return lib;
}

void add_song_to_library(Library *lib, Song *song) {
  lib->songs = realloc(lib->songs, sizeof(Song) * (lib->num_songs + 1));
  lib->songs[lib->num_songs++] = *song;
}

void free_song(Song *song) {
  free(song->title);
  free(song->artist);
  free(song->album);
  free(song);
}

void free_library(Library *lib) {
  for (int i = 0; i < lib->num_songs; i++) {
    free_song(&lib->songs[i]);
  }
  free(lib->songs);
  free(lib);
}

int main() {
  Library *lib = create_library();
  Song song1 = {"Song 1", "Artist 1", "Album 1", 2023, 1};
  Song song2 = {"Song 2", "Artist 2", "Album 2", 2022, 2};
  Song song3 = {"Song 3", "Artist 3", "Album 3", 2021, 3};
  add_song_to_library(lib, &song1);
  add_song_to_library(lib, &song2);
  add_song_to_library(lib, &song3);

  for (int i = 0; i < lib->num_songs; i++) {
    printf("%s by %s from %s\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].album);
  }

  free_library(lib);
  return 0;
}