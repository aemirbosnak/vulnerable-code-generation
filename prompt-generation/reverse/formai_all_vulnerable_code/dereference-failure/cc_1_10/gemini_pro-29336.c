//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a song
typedef struct song {
    char *title;
    char *artist;
    char *album;
    int year;
} song;

// Define the structure of a library
typedef struct library {
    song *songs;
    int num_songs;
} library;

// Create a new library
library *create_library() {
    library *lib = malloc(sizeof(library));
    lib->songs = NULL;
    lib->num_songs = 0;
    return lib;
}

// Add a song to a library
void add_song_to_library(library *lib, song *song) {
    lib->songs = realloc(lib->songs, (lib->num_songs + 1) * sizeof(song));
    lib->songs[lib->num_songs] = *song;
    lib->num_songs++;
}

// Print a library
void print_library(library *lib) {
    for (int i = 0; i < lib->num_songs; i++) {
        printf("%s - %s - %s - %d\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].album, lib->songs[i].year);
    }
}

// Free a library
void free_library(library *lib) {
    for (int i = 0; i < lib->num_songs; i++) {
        free(lib->songs[i].title);
        free(lib->songs[i].artist);
        free(lib->songs[i].album);
    }
    free(lib->songs);
    free(lib);
}

// Main function
int main() {
    // Create a library
    library *lib = create_library();

    // Add some songs to the library
    song *song1 = malloc(sizeof(song));
    song1->title = strdup("Bohemian Rhapsody");
    song1->artist = strdup("Queen");
    song1->album = strdup("A Night at the Opera");
    song1->year = 1975;
    add_song_to_library(lib, song1);

    song *song2 = malloc(sizeof(song));
    song2->title = strdup("Stairway to Heaven");
    song2->artist = strdup("Led Zeppelin");
    song2->album = strdup("Led Zeppelin IV");
    song2->year = 1971;
    add_song_to_library(lib, song2);

    song *song3 = malloc(sizeof(song));
    song3->title = strdup("Imagine");
    song3->artist = strdup("John Lennon");
    song3->album = strdup("Imagine");
    song3->year = 1971;
    add_song_to_library(lib, song3);

    // Print the library
    printf("The library contains the following songs:\n");
    print_library(lib);

    // Free the library
    free_library(lib);

    return 0;
}