//FormAI DATASET v1.0 Category: Music Library Management System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIBRARY_SIZE 100

typedef struct {
  char title[50];
  char artist[50];
  int year;
  char genre[20];
} Song;

typedef struct {
  Song *songs[MAX_LIBRARY_SIZE];
  int num_songs;
} MusicLibrary;

MusicLibrary *create_library() {
  MusicLibrary *library = malloc(sizeof(MusicLibrary));
  library->num_songs = 0;
  return library;
}

void add_song(MusicLibrary *library, Song *song) {
  if (library->num_songs < MAX_LIBRARY_SIZE) {
    library->songs[library->num_songs] = song;
    library->num_songs += 1;
  } else {
    printf("Library is already full.\n");
  }
}

Song *find_song_by_title(MusicLibrary *library, char *title) {
  for (int i = 0; i < library->num_songs; i++) {
    if (strcmp(library->songs[i]->title, title) == 0) {
      return library->songs[i];
    }
  }
  return NULL;
}

void print_song(Song *song) {
  printf("Title: %s\n", song->title);
  printf("Artist: %s\n", song->artist);
  printf("Year: %d\n", song->year);
  printf("Genre: %s\n", song->genre);
}

void print_library(MusicLibrary *library) {
  printf("---------------\n");
  for (int i = 0; i < library->num_songs; i++) {
    print_song(library->songs[i]);
    printf("---------------\n");
  }
}

int main() {
  MusicLibrary *library1 = create_library();
  MusicLibrary *library2 = create_library();

  Song *song1 = malloc(sizeof(Song));
  strcpy(song1->title, "Bohemian Rhapsody");
  strcpy(song1->artist, "Queen");
  song1->year = 1975;
  strcpy(song1->genre, "Rock");

  Song *song2 = malloc(sizeof(Song));
  strcpy(song2->title, "Hotel California");
  strcpy(song2->artist, "Eagles");
  song2->year = 1977;
  strcpy(song2->genre, "Rock");

  add_song(library1, song1);
  add_song(library1, song2);

  Song *song3 = malloc(sizeof(Song));
  strcpy(song3->title, "Earth Song");
  strcpy(song3->artist, "Michael Jackson");
  song3->year = 1995;
  strcpy(song3->genre, "Pop");

  Song *song4 = malloc(sizeof(Song));
  strcpy(song4->title, "Stairway to Heaven");
  strcpy(song4->artist, "Led Zeppelin");
  song4->year = 1971;
  strcpy(song4->genre, "Rock");

  add_song(library2, song3);
  add_song(library2, song4);

  printf("Library 1:\n");
  print_library(library1);

  printf("Library 2:\n");
  print_library(library2);

  char *title_to_find = "Bohemian Rhapsody";
  Song *song_found = find_song_by_title(library1, title_to_find);
  if (song_found == NULL) {
    printf("%s not found in Library 1.\n", title_to_find);
  } else {
    printf("%s found in Library 1:\n", title_to_find);
    print_song(song_found);
  }

  title_to_find = "Stairway to Heaven";
  song_found = find_song_by_title(library2, title_to_find);
  if (song_found == NULL) {
    printf("%s not found in Library 2.\n", title_to_find);
  } else {
    printf("%s found in Library 2:\n", title_to_find);
    print_song(song_found);
  }

  return 0;
}