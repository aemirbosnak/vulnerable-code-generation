//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct music_library {
  char *name;
  char *artist;
  char *album;
  int year;
  int length;
};

struct music_library *create_library(char *name) {
  struct music_library *library = malloc(sizeof(struct music_library));
  library->name = strdup(name);
  library->artist = NULL;
  library->album = NULL;
  library->year = 0;
  library->length = 0;
  return library;
}

void add_song(struct music_library *library, char *artist, char *album, int year, int length) {
  library->artist = strdup(artist);
  library->album = strdup(album);
  library->year = year;
  library->length = length;
}

void print_library(struct music_library *library) {
  printf("Name: %s\n", library->name);
  printf("Artist: %s\n", library->artist);
  printf("Album: %s\n", library->album);
  printf("Year: %d\n", library->year);
  printf("Length: %d\n", library->length);
}

int main() {
  struct music_library *library = create_library("My Music Library");

  add_song(library, "The Beatles", "Abbey Road", 1969, 47);
  add_song(library, "The Rolling Stones", "Sticky Fingers", 1971, 46);
  add_song(library, "Led Zeppelin", "Led Zeppelin IV", 1971, 45);

  print_library(library);

  free(library->name);
  free(library->artist);
  free(library->album);
  free(library);

  return 0;
}