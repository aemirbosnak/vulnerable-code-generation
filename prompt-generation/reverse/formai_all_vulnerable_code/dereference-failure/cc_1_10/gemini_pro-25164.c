//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a song
typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int track_number;
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
void add_song(library *lib, song *s) {
    lib->songs = realloc(lib->songs, (lib->num_songs + 1) * sizeof(song));
    lib->songs[lib->num_songs] = *s;
    lib->num_songs++;
}

// Print a song
void print_song(song *s) {
    printf("Title: %s\n", s->title);
    printf("Artist: %s\n", s->artist);
    printf("Album: %s\n", s->album);
    printf("Year: %d\n", s->year);
    printf("Track number: %d\n\n", s->track_number);
}

// Print a library
void print_library(library *lib) {
    for (int i = 0; i < lib->num_songs; i++) {
        print_song(&lib->songs[i]);
    }
}

// Free a library
void free_library(library *lib) {
    free(lib->songs);
    free(lib);
}

// Main function
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

    // Print the library
    print_library(lib);

    // Free the library
    free_library(lib);

    return 0;
}