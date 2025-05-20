//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Music {
  char title[50];
  char artist[50];
  int year;
  int duration;
};

struct MusicLibrary {
  struct Music *songs;
  int num_songs;
  int capacity;
};

void createLibrary(struct MusicLibrary *library) {
  library->num_songs = 0;
  library->capacity = 10;
  library->songs = (struct Music *)malloc(library->capacity * sizeof(struct Music));
}

void addSong(struct MusicLibrary *library, struct Music song) {
  if (library->num_songs == library->capacity) {
    library->capacity *= 2;
    library->songs = (struct Music *)realloc(library->songs, library->capacity * sizeof(struct Music));
  }
  library->songs[library->num_songs++] = song;
}

void removeSong(struct MusicLibrary *library, int index) {
  if (index < 0 || index >= library->num_songs) {
    printf("Invalid index\n");
    return;
  }
  for (int i = index; i < library->num_songs - 1; i++) {
    library->songs[i] = library->songs[i + 1];
  }
  library->num_songs--;
}

void searchSong(struct MusicLibrary *library, char *title) {
  int found = 0;
  for (int i = 0; i < library->num_songs; i++) {
    if (strcmp(library->songs[i].title, title) == 0) {
      printf("Found song: %s by %s\n", library->songs[i].title, library->songs[i].artist);
      found = 1;
    }
  }
  if (!found) {
    printf("Song not found\n");
  }
}

void printLibrary(struct MusicLibrary *library) {
  printf("Music Library:\n");
  for (int i = 0; i < library->num_songs; i++) {
    printf("%s by %s (%d) [%d:%02d]\n", library->songs[i].title, library->songs[i].artist, library->songs[i].year,
           library->songs[i].duration / 60, library->songs[i].duration % 60);
  }
}

int main() {
  struct MusicLibrary library;
  createLibrary(&library);

  struct Music song1 = {"Bohemian Rhapsody", "Queen", 1975, 352};
  addSong(&library, song1);

  struct Music song2 = {"Stairway to Heaven", "Led Zeppelin", 1971, 480};
  addSong(&library, song2);

  struct Music song3 = {"Sweet Child O' Mine", "Guns N' Roses", 1987, 310};
  addSong(&library, song3);

  removeSong(&library, 1);

  searchSong(&library, "Stairway to Heaven");

  printLibrary(&library);

  return 0;
}