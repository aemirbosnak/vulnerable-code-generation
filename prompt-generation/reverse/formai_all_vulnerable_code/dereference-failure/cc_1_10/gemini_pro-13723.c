//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum number of songs in the library
#define MAX_SONGS 100

// Define the structure of a song
typedef struct {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int track_number;
} song;

// Define the structure of the library
typedef struct {
    song songs[MAX_SONGS];
    int num_songs;
} library;

// Create a new library
library *create_library() {
    library *lib = malloc(sizeof(library));
    lib->num_songs = 0;
    return lib;
}

// Add a song to the library
void add_song(library *lib, song *s) {
    if (lib->num_songs < MAX_SONGS) {
        lib->songs[lib->num_songs] = *s;
        lib->num_songs++;
    } else {
        printf("The library is full. Cannot add more songs.\n");
    }
}

// Print the library
void print_library(library *lib) {
    for (int i = 0; i < lib->num_songs; i++) {
        printf("%s by %s from the album %s (%d)\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].album, lib->songs[i].year);
    }
}

// Search the library for a song by title
song *search_by_title(library *lib, char *title) {
    for (int i = 0; i < lib->num_songs; i++) {
        if (strcmp(lib->songs[i].title, title) == 0) {
            return &lib->songs[i];
        }
    }
    return NULL;
}

// Search the library for a song by artist
song *search_by_artist(library *lib, char *artist) {
    for (int i = 0; i < lib->num_songs; i++) {
        if (strcmp(lib->songs[i].artist, artist) == 0) {
            return &lib->songs[i];
        }
    }
    return NULL;
}

// Main program
int main() {
    // Create a new library
    library *lib = create_library();

    // Add some songs to the library
    song s1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1};
    add_song(lib, &s1);
    song s2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 4};
    add_song(lib, &s2);
    song s3 = {"Hotel California", "Eagles", "Hotel California", 1976, 3};
    add_song(lib, &s3);
    song s4 = {"Billie Jean", "Michael Jackson", "Thriller", 1982, 2};
    add_song(lib, &s4);

    // Print the library
    printf("Current library:\n");
    print_library(lib);

    // Search for a song by title
    char *title = "Bohemian Rhapsody";
    song *song = search_by_title(lib, title);
    if (song != NULL) {
        printf("Found song by title:\n");
        printf("%s by %s from the album %s (%d)\n", song->title, song->artist, song->album, song->year);
    } else {
        printf("Song not found.\n");
    }

    // Search for a song by artist
    char *artist = "Led Zeppelin";
    song = search_by_artist(lib, artist);
    if (song != NULL) {
        printf("Found song by artist:\n");
        printf("%s by %s from the album %s (%d)\n", song->title, song->artist, song->album, song->year);
    } else {
        printf("Song not found.\n");
    }

    return 0;
}