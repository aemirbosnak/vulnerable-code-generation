//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
  char title[50];
  char artist[50];
  char album[50];
  int year;
  int track;
};

struct playlist {
  char name[50];
  struct song songs[100];
  int num_songs;
};

struct library {
  struct playlist playlists[100];
  int num_playlists;
};

// Function to create a new library
struct library *create_library() {
  struct library *library = malloc(sizeof(struct library));
  library->num_playlists = 0;
  return library;
}

// Function to add a new playlist to a library
void add_playlist(struct library *library, char *name) {
  strcpy(library->playlists[library->num_playlists].name, name);
  library->playlists[library->num_playlists].num_songs = 0;
  library->num_playlists++;
}

// Function to add a new song to a playlist
void add_song(struct playlist *playlist, struct song *song) {
  playlist->songs[playlist->num_songs] = *song;
  playlist->num_songs++;
}

// Function to print a playlist
void print_playlist(struct playlist *playlist) {
  printf("Playlist: %s\n", playlist->name);
  for (int i = 0; i < playlist->num_songs; i++) {
    printf("\t%d. %s - %s (%d)\n", i + 1, playlist->songs[i].title, playlist->songs[i].artist, playlist->songs[i].year);
  }
}

// Function to print a library
void print_library(struct library *library) {
  for (int i = 0; i < library->num_playlists; i++) {
    print_playlist(&library->playlists[i]);
  }
}

int main() {
  // Create a new library
  struct library *library = create_library();

  // Add some playlists to the library
  add_playlist(library, "My Favorites");
  add_playlist(library, "Chill Vibes");
  add_playlist(library, "Workout Motivation");

  // Add some songs to the playlists
  struct song song1 = {"Strawberry Fields Forever", "The Beatles", "Sgt. Pepper's Lonely Hearts Club Band", 1967, 1};
  add_song(&library->playlists[0], &song1);

  struct song song2 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1};
  add_song(&library->playlists[0], &song2);

  struct song song3 = {"Clair de Lune", "Claude Debussy", "Suite bergamasque", 1890, 3};
  add_song(&library->playlists[1], &song3);

  struct song song4 = {"Gymnopédie No. 1", "Erik Satie", "Trois gymnopédies", 1888, 1};
  add_song(&library->playlists[1], &song4);

  struct song song5 = {"Eye of the Tiger", "Survivor", "Eye of the Tiger", 1982, 1};
  add_song(&library->playlists[2], &song5);

  struct song song6 = {"Lose Yourself", "Eminem", "8 Mile", 2002, 1};
  add_song(&library->playlists[2], &song6);

  // Print the library
  print_library(library);

  return 0;
}