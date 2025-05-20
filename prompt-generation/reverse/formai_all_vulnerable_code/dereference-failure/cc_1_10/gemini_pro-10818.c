//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a song
typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int duration;
} song_t;

// Structure to store a library of songs
typedef struct library {
    int num_songs;
    song_t *songs;
} library_t;

// Function to create a new library
library_t *create_library() {
    library_t *library = malloc(sizeof(library_t));
    library->num_songs = 0;
    library->songs = NULL;
    return library;
}

// Function to add a song to a library
void add_song(library_t *library, song_t song) {
    library->num_songs++;
    library->songs = realloc(library->songs, library->num_songs * sizeof(song_t));
    library->songs[library->num_songs - 1] = song;
}

// Function to remove a song from a library
void remove_song(library_t *library, int index) {
    if (index < 0 || index >= library->num_songs) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < library->num_songs - 1; i++) {
        library->songs[i] = library->songs[i + 1];
    }

    library->num_songs--;
    library->songs = realloc(library->songs, library->num_songs * sizeof(song_t));
}

// Function to print a song
void print_song(song_t song) {
    printf("%s by %s from the album %s (%d, %d minutes)\n", song.title, song.artist, song.album, song.year, song.duration);
}

// Function to print a library of songs
void print_library(library_t *library) {
    for (int i = 0; i < library->num_songs; i++) {
        print_song(library->songs[i]);
    }
}

// Function to free the memory allocated for a library
void free_library(library_t *library) {
    free(library->songs);
    free(library);
}

// Main function
int main() {
    // Create a new library
    library_t *library = create_library();

    // Add some songs to the library
    song_t song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 5};
    add_song(library, song1);

    song_t song2 = {"Imagine", "John Lennon", "Imagine", 1971, 3};
    add_song(library, song2);

    song_t song3 = {"Strawberry Fields Forever", "The Beatles", "Sgt. Pepper's Lonely Hearts Club Band", 1967, 4};
    add_song(library, song3);

    // Print the library
    print_library(library);

    // Remove a song from the library
    remove_song(library, 1);

    // Print the library again
    print_library(library);

    // Free the memory allocated for the library
    free_library(library);

    return 0;
}