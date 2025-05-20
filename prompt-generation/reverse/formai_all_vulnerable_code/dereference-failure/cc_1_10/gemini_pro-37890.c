//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a song
typedef struct song {
    char *title;
    char *artist;
    int year;
    int length;
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

// Add a song to a library
void add_song_to_library(library_t *library, song_t *song) {
    library->songs = realloc(library->songs, sizeof(song_t) * (library->num_songs + 1));
    library->songs[library->num_songs] = *song;
    library->num_songs++;
}

// Print the songs in a library
void print_library(library_t *library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("%s by %s (%d, %d seconds)\n", library->songs[i].title, library->songs[i].artist, library->songs[i].year, library->songs[i].length);
    }
}

// Free the memory used by a library
void free_library(library_t *library) {
    for (int i = 0; i < library->num_songs; i++) {
        free(library->songs[i].title);
        free(library->songs[i].artist);
    }
    free(library->songs);
    free(library);
}

int main() {
    // Create a new library
    library_t *library = create_library();

    // Add some songs to the library
    song_t song1 = {"Bohemian Rhapsody", "Queen", 1975, 360};
    add_song_to_library(library, &song1);
    song_t song2 = {"Stairway to Heaven", "Led Zeppelin", 1971, 480};
    add_song_to_library(library, &song2);
    song_t song3 = {"Hotel California", "The Eagles", 1976, 390};
    add_song_to_library(library, &song3);

    // Print the songs in the library
    print_library(library);

    // Free the memory used by the library
    free_library(library);

    return 0;
}