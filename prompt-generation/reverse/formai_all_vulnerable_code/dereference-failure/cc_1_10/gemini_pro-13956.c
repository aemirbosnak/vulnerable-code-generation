//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the song struct
typedef struct {
    char title[50];
    char artist[50];
    int year;
    int track_number;
} song;

// Define the library struct
typedef struct {
    song songs[100];
    int num_songs;
} library;

// Create a new library
library* create_library() {
    library* lib = malloc(sizeof(library));
    lib->num_songs = 0;
    return lib;
}

// Add a song to the library
void add_song(library* lib, song* s) {
    lib->songs[lib->num_songs] = *s;
    lib->num_songs++;
}

// Print the library
void print_library(library* lib) {
    for (int i = 0; i < lib->num_songs; i++) {
        printf("%s by %s (%d)\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].year);
    }
}

// Free the library
void free_library(library* lib) {
    free(lib);
}

// Main function
int main() {
    // Create a new library
    library* lib = create_library();

    // Add some songs to the library
    song s1 = {"Bohemian Rhapsody", "Queen", 1975, 1};
    add_song(lib, &s1);
    song s2 = {"Stairway to Heaven", "Led Zeppelin", 1971, 4};
    add_song(lib, &s2);
    song s3 = {"Hotel California", "Eagles", 1976, 3};
    add_song(lib, &s3);

    // Print the library
    printf("My Music Library:\n");
    print_library(lib);

    // Free the library
    free_library(lib);

    return 0;
}