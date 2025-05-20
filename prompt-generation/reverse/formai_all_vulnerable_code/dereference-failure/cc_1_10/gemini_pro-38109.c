//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of songs in the library
#define MAX_SONGS 100

// Define the structure of a song
typedef struct song {
    char title[50];
    char artist[50];
    int year;
    int duration; // in seconds
} song_t;

// Define the structure of the library
typedef struct library {
    song_t songs[MAX_SONGS];
    int num_songs;
} library_t;

// Create a new library
library_t *create_library() {
    library_t *library = (library_t *)malloc(sizeof(library_t));
    if (library == NULL) {
        return NULL;
    }
    library->num_songs = 0;
    return library;
}

// Add a song to the library
void add_song(library_t *library, song_t song) {
    if (library->num_songs < MAX_SONGS) {
        library->songs[library->num_songs] = song;
        library->num_songs++;
    }
}

// Print the library
void print_library(library_t *library) {
    for (int i = 0; i < library->num_songs; i++) {
        song_t song = library->songs[i];
        printf("%s - %s (%d, %d seconds)\n", song.title, song.artist, song.year, song.duration);
    }
}

// Free the library
void free_library(library_t *library) {
    free(library);
}

// Main function
int main() {
    // Create a new library
    library_t *library = create_library();

    // Add some songs to the library
    song_t song1 = {"Bohemian Rhapsody", "Queen", 1975, 360};
    add_song(library, song1);
    song_t song2 = {"Stairway to Heaven", "Led Zeppelin", 1971, 480};
    add_song(library, song2);
    song_t song3 = {"Hotel California", "Eagles", 1976, 380};
    add_song(library, song3);

    // Print the library
    print_library(library);

    // Free the library
    free_library(library);

    return 0;
}