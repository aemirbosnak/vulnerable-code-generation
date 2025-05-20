//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: complete
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
} song_t;

// Define the structure of a library
typedef struct library {
    song_t *songs;
    int num_songs;
} library_t;

// Create a new library
library_t *create_library() {
    library_t *library = malloc(sizeof(library_t));
    library->songs = NULL;
    library->num_songs = 0;
    return library;
}

// Add a song to the library
void add_song(library_t *library, song_t song) {
    library->songs = realloc(library->songs, (library->num_songs + 1) * sizeof(song_t));
    library->songs[library->num_songs] = song;
    library->num_songs++;
}

// Print the library
void print_library(library_t *library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("%s - %s - %s - %d - %d\n", library->songs[i].title, library->songs[i].artist, library->songs[i].album, library->songs[i].year, library->songs[i].track_number);
    }
}

// Free the memory allocated for the library
void free_library(library_t *library) {
    free(library->songs);
    free(library);
}

// Main function
int main() {
    // Create a new library
    library_t *library = create_library();

    // Add some songs to the library
    song_t song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1};
    add_song(library, song1);
    song_t song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 4};
    add_song(library, song2);
    song_t song3 = {"Hotel California", "Eagles", "Hotel California", 1976, 3};
    add_song(library, song3);

    // Print the library
    print_library(library);

    // Free the memory allocated for the library
    free_library(library);

    return 0;
}