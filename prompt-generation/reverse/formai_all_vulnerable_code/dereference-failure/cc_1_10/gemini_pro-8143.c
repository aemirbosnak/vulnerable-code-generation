//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: accurate
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
} song;

// Define the structure of the library
typedef struct library {
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
void add_song(library *lib, song *new_song) {
    if (lib->num_songs < MAX_SONGS) {
        lib->songs[lib->num_songs] = *new_song;
        lib->num_songs++;
    } else {
        printf("Error: Library is full.\n");
    }
}

// Search for a song in the library by title
song *search_song_by_title(library *lib, char *title) {
    for (int i = 0; i < lib->num_songs; i++) {
        if (strcmp(lib->songs[i].title, title) == 0) {
            return &lib->songs[i];
        }
    }
    return NULL;
}

// Search for a song in the library by artist
song *search_song_by_artist(library *lib, char *artist) {
    for (int i = 0; i < lib->num_songs; i++) {
        if (strcmp(lib->songs[i].artist, artist) == 0) {
            return &lib->songs[i];
        }
    }
    return NULL;
}

// Search for a song in the library by album
song *search_song_by_album(library *lib, char *album) {
    for (int i = 0; i < lib->num_songs; i++) {
        if (strcmp(lib->songs[i].album, album) == 0) {
            return &lib->songs[i];
        }
    }
    return NULL;
}

// Print the library
void print_library(library *lib) {
    printf("Library:\n");
    for (int i = 0; i < lib->num_songs; i++) {
        printf("%s by %s from the album %s (%d)\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].album, lib->songs[i].year);
    }
}

// Free the memory allocated for the library
void free_library(library *lib) {
    free(lib);
}

// Main function
int main() {
    // Create a new library
    library *lib = create_library();

    // Add some songs to the library
    song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975};
    add_song(lib, &song1);
    song song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971};
    add_song(lib, &song2);
    song song3 = {"Hotel California", "Eagles", "Hotel California", 1976};
    add_song(lib, &song3);

    // Search for a song in the library by title
    song *found_song = search_song_by_title(lib, "Stairway to Heaven");
    if (found_song != NULL) {
        printf("Found song: %s by %s from the album %s (%d)\n", found_song->title, found_song->artist, found_song->album, found_song->year);
    } else {
        printf("Song not found.\n");
    }

    // Print the library
    print_library(lib);

    // Free the memory allocated for the library
    free_library(lib);

    return 0;
}