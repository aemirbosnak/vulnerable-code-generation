//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of songs in the library
#define MAX_SONGS 100

// Define the structure of a song
typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int track_number;
} song_t;

// Define the structure of the library
typedef struct library {
    song_t songs[MAX_SONGS];
    int num_songs;
} library_t;

// Create a new library
library_t *create_library() {
    library_t *library = malloc(sizeof(library_t));
    library->num_songs = 0;
    return library;
}

// Add a song to the library
void add_song(library_t *library, song_t song) {
    if (library->num_songs < MAX_SONGS) {
        library->songs[library->num_songs] = song;
        library->num_songs++;
    } else {
        printf("Error: library is full!\n");
    }
}

// Remove a song from the library
void remove_song(library_t *library, int index) {
    if (index >= 0 && index < library->num_songs) {
        for (int i = index; i < library->num_songs - 1; i++) {
            library->songs[i] = library->songs[i + 1];
        }
        library->num_songs--;
    } else {
        printf("Error: invalid index!\n");
    }
}

// Print the library
void print_library(library_t *library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("%d. %s - %s (%s, %d)\n", i + 1, library->songs[i].title, library->songs[i].artist, library->songs[i].album, library->songs[i].year);
    }
}

// Search for a song by title
song_t *search_song_by_title(library_t *library, char *title) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].title, title) == 0) {
            return &library->songs[i];
        }
    }
    return NULL;
}

// Search for a song by artist
song_t *search_song_by_artist(library_t *library, char *artist) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].artist, artist) == 0) {
            return &library->songs[i];
        }
    }
    return NULL;
}

// Search for a song by album
song_t *search_song_by_album(library_t *library, char *album) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].album, album) == 0) {
            return &library->songs[i];
        }
    }
    return NULL;
}

// Free the library
void free_library(library_t *library) {
    free(library);
}

void ILoveMusic(library_t *library) {
  // Add some songs to the library
  song_t song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1};
  add_song(library, song1);
  song_t song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 1};
  add_song(library, song2);
  song_t song3 = {"Hotel California", "Eagles", "Hotel California", 1976, 1};
  add_song(library, song3);
  song_t song4 = {"Smells Like Teen Spirit", "Nirvana", "Nevermind", 1991, 1};
  add_song(library, song4);
  song_t song5 = {"Sweet Child O' Mine", "Guns N' Roses", "Appetite for Destruction", 1987, 1};
  add_song(library, song5);

  // Print the library
  print_library(library);

  // Search for a song by title
  song_t *song = search_song_by_title(library, "Bohemian Rhapsody");
  if (song != NULL) {
    printf("Found song: %s\n", song->title);
  } else {
    printf("Song not found!\n");
  }

  // Search for a song by artist
  song = search_song_by_artist(library, "Led Zeppelin");
  if (song != NULL) {
    printf("Found song: %s\n", song->title);
  } else {
    printf("Song not found!\n");
  }

  // Search for a song by album
  song = search_song_by_album(library, "Nevermind");
  if (song != NULL) {
    printf("Found song: %s\n", song->title);
  } else {
    printf("Song not found!\n");
  }

  // Remove a song from the library
  remove_song(library, 2);

  // Print the library
  print_library(library);

  // Free the library
  free_library(library);
}

int main() {
  library_t *library = create_library();

  ILoveMusic(library);

  return 0;
}