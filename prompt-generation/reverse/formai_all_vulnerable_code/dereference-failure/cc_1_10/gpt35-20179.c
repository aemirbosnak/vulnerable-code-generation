//FormAI DATASET v1.0 Category: Music Library Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent songs
struct Song {
  char title[100];
  char artist[100];
  char album[100];
  int year;
  float length;
};

// Define a struct to represent albums
struct Album {
  char title[100];
  char artist[100];
  int year;
  int num_songs;
  struct Song *songs;
};

// Define a function to create a song and return a pointer to it
struct Song *create_song(char *title, char *artist, char *album, int year, float length) {
  struct Song *song = (struct Song *) malloc(sizeof(struct Song));
  strcpy(song->title, title);
  strcpy(song->artist, artist);
  strcpy(song->album, album);
  song->year = year;
  song->length = length;
  return song;
}

// Define a function to create an album and return a pointer to it
struct Album *create_album(char *title, char *artist, int year, int num_songs, char **titles, char **artists, char **albums, int *years, float *lengths) {
  struct Album *album = (struct Album *) malloc(sizeof(struct Album));
  strcpy(album->title, title);
  strcpy(album->artist, artist);
  album->year = year;
  album->num_songs = num_songs;
  album->songs = (struct Song *) malloc(num_songs * sizeof(struct Song));
  for (int i = 0; i < num_songs; i++) {
    album->songs[i] = *create_song(titles[i], artists[i], albums[i], years[i], lengths[i]);
  }
  return album;
}

// Define a function to print out a song
void print_song(struct Song *song) {
  printf("%s\n", song->title);
  printf("  Artist: %s\n", song->artist);
  printf("  Album: %s\n", song->album);
  printf("  Year: %d\n", song->year);
  printf("  Length: %.2f\n", song->length);
}

// Define a function to print out an album
void print_album(struct Album *album) {
  printf("%s\n", album->title);
  printf("  Artist: %s\n", album->artist);
  printf("  Year: %d\n", album->year);
  printf("  Songs:\n");
  for (int i = 0; i < album->num_songs; i++) {
    printf("    %d. ", i + 1);
    print_song(&album->songs[i]);
  }
}

// Define a function to free the memory allocated for a song
void free_song(struct Song *song) {
  free(song);
}

// Define a function to free the memory allocated for an album
void free_album(struct Album *album) {
  for (int i = 0; i < album->num_songs; i++) {
    free_song(&album->songs[i]);
  }
  free(album->songs);
  free(album);
}

int main() {
  // Create some songs
  struct Song *song1 = create_song("Yesterday", "The Beatles", "Help!", 1965, 2.08);
  struct Song *song2 = create_song("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 5.55);
  struct Song *song3 = create_song("Thriller", "Michael Jackson", "Thriller", 1983, 5.57);
  struct Song *song4 = create_song("Don't Stop Believin'", "Journey", "Escape", 1981, 4.11);
  
  // Create an album
  char *titles[] = {"Yesterday", "Help!", "Ticket to Ride", "You've Got to Hide Your Love Away", "I Need You"};
  char *artists[] = {"The Beatles", "The Beatles", "The Beatles", "The Beatles", "The Beatles"};
  char *albums[] = {"Help!", "Help!", "Help!", "Help!", "Help!"};
  int years[] = {1965, 1965, 1965, 1965, 1965};
  float lengths[] = {2.08, 2.33, 3.09, 2.08, 2.28};
  struct Album *album = create_album("Help!", "The Beatles", 1965, 5, titles, artists, albums, years, lengths);
  
  // Print out a song and an album
  print_song(song1);
  print_album(album);
  
  // Free the memory allocated for the song and album
  free_song(song1);
  free_song(song2);
  free_song(song3);
  free_song(song4);
  free_album(album);
  
  return 0;
}