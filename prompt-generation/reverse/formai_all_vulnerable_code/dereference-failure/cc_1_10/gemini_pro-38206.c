//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: Linus Torvalds
// Linus Torvalds style C Music Library Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a song
typedef struct song {
  char *title;
  char *artist;
  char *album;
  int year;
  int track;
} song;

// Function to create a new song
song *new_song(char *title, char *artist, char *album, int year, int track) {
  song *s = malloc(sizeof(song));
  s->title = strdup(title);
  s->artist = strdup(artist);
  s->album = strdup(album);
  s->year = year;
  s->track = track;
  return s;
}

// Function to print a song
void print_song(song *s) {
  printf("%s by %s from the album %s (%d, track %d)\n", s->title, s->artist, s->album, s->year, s->track);
}

// Function to compare two songs
int compare_songs(const void *a, const void *b) {
  song *sa = (song *)a;
  song *sb = (song *)b;
  return strcmp(sa->title, sb->title);
}

// Function to sort an array of songs
void sort_songs(song *songs, int num_songs) {
  qsort(songs, num_songs, sizeof(song), compare_songs);
}

// Function to find a song by title
song *find_song_by_title(song *songs, int num_songs, char *title) {
  int i;
  for (i = 0; i < num_songs; i++) {
    if (strcmp(songs[i].title, title) == 0) {
      return &songs[i];
    }
  }
  return NULL;
}

// Function to free a song
void free_song(song *s) {
  free(s->title);
  free(s->artist);
  free(s->album);
  free(s);
}

// Main function
int main(int argc, char *argv[]) {
  // Create an array of songs
  song *songs[] = {
    new_song("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1),
    new_song("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 8),
    new_song("Hotel California", "Eagles", "Hotel California", 1976, 3),
    new_song("Imagine", "John Lennon", "Imagine", 1971, 1),
    new_song("Strawberry Fields Forever", "The Beatles", "Sgt. Pepper's Lonely Hearts Club Band", 1967, 7),
  };

  // Sort the songs by title
  sort_songs(songs, sizeof(songs) / sizeof(song));

  // Print the sorted songs
  for (int i = 0; i < sizeof(songs) / sizeof(song); i++) {
    print_song(songs[i]);
  }

  // Find a song by title
  char *title = "Bohemian Rhapsody";
  song *s = find_song_by_title(songs, sizeof(songs) / sizeof(song), title);
  if (s != NULL) {
    printf("Found song: %s\n", s->title);
  } else {
    printf("Song not found: %s\n", title);
  }

  // Free the songs
  for (int i = 0; i < sizeof(songs) / sizeof(song); i++) {
    free_song(songs[i]);
  }

  return 0;
}