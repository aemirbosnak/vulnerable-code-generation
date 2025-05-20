//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a song
typedef struct Song {
  char title[50];
  char artist[50];
  char album[50];
  int year;
  float duration;
} Song;

// Structure to store a playlist
typedef struct Playlist {
  char name[50];
  Song songs[100];
  int num_songs;
} Playlist;

// Function to create a new song
Song* create_song(char* title, char* artist, char* album, int year, float duration) {
  Song* song = malloc(sizeof(Song));
  strcpy(song->title, title);
  strcpy(song->artist, artist);
  strcpy(song->album, album);
  song->year = year;
  song->duration = duration;

  return song;
}

// Function to create a new playlist
Playlist* create_playlist(char* name) {
  Playlist* playlist = malloc(sizeof(Playlist));
  strcpy(playlist->name, name);
  playlist->num_songs = 0;

  return playlist;
}

// Function to add a song to a playlist
void add_song_to_playlist(Playlist* playlist, Song* song) {
  playlist->songs[playlist->num_songs] = *song;
  playlist->num_songs++;
}

// Function to print a song
void print_song(Song* song) {
  printf("Title: %s\n", song->title);
  printf("Artist: %s\n", song->artist);
  printf("Album: %s\n", song->album);
  printf("Year: %d\n", song->year);
  printf("Duration: %.2f\n", song->duration);
}

// Function to print a playlist
void print_playlist(Playlist* playlist) {
  printf("Playlist: %s\n", playlist->name);
  printf("Number of songs: %d\n", playlist->num_songs);
  for (int i = 0; i < playlist->num_songs; i++) {
    print_song(&playlist->songs[i]);
  }
}

// Main function
int main() {
  // Create some songs
  Song* song1 = create_song("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 5.54);
  Song* song2 = create_song("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 8.02);
  Song* song3 = create_song("Imagine", "John Lennon", "Imagine", 1971, 3.01);

  // Create a playlist
  Playlist* playlist = create_playlist("My Favorite Songs");

  // Add the songs to the playlist
  add_song_to_playlist(playlist, song1);
  add_song_to_playlist(playlist, song2);
  add_song_to_playlist(playlist, song3);

  // Print the playlist
  print_playlist(playlist);

  return 0;
}