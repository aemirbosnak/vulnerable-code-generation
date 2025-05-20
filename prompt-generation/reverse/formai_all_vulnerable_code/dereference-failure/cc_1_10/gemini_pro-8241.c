//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
  char *title;
  char *artist;
  char *genre;
  int year_released;
  int length;
};

struct library {
  struct song *songs;
  int num_songs;
};

struct library *create_library(void) {
  struct library *library = malloc(sizeof(struct library));
  library->songs = NULL;
  library->num_songs = 0;
  return library;
}

void add_song_to_library(struct library *library, struct song *song) {
  library->num_songs++;
  library->songs = realloc(library->songs, sizeof(struct song) * library->num_songs);
  library->songs[library->num_songs - 1] = *song;
}

void print_library(struct library *library) {
  for (int i = 0; i < library->num_songs; i++) {
    printf("%s by %s (%s, %d, %d minutes)\n", library->songs[i].title, library->songs[i].artist, library->songs[i].genre, library->songs[i].year_released, library->songs[i].length);
  }
}

void free_library(struct library *library) {
  for (int i = 0; i < library->num_songs; i++) {
    free(library->songs[i].title);
    free(library->songs[i].artist);
    free(library->songs[i].genre);
  }
  free(library->songs);
  free(library);
}

int main(void) {
  struct library *library = create_library();

  struct song song1 = {.title = "Bohemian Rhapsody", .artist = "Queen", .genre = "Rock", .year_released = 1975, .length = 6};
  add_song_to_library(library, &song1);

  struct song song2 = {.title = "Stairway to Heaven", .artist = "Led Zeppelin", .genre = "Rock", .year_released = 1971, .length = 8};
  add_song_to_library(library, &song2);

  struct song song3 = {.title = "Hotel California", .artist = "The Eagles", .genre = "Rock", .year_released = 1977, .length = 7};
  add_song_to_library(library, &song3);

  print_library(library);

  free_library(library);

  return 0;
}