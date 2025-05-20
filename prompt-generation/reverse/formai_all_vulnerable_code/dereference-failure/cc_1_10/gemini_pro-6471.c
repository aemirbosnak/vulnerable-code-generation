//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a song
typedef struct song {
    char *title;
    char *artist;
    int year;
    int duration;
} Song;

// Define the structure of a library
typedef struct library {
    Song *songs;
    int num_songs;
} Library;

// Create a new library
Library *create_library() {
    Library *library = malloc(sizeof(Library));
    library->songs = NULL;
    library->num_songs = 0;
    return library;
}

// Add a song to the library
void add_song(Library *library, Song *song) {
    library->songs = realloc(library->songs, (library->num_songs + 1) * sizeof(Song));
    library->songs[library->num_songs] = *song;
    library->num_songs++;
}

// Print the library
void print_library(Library *library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("%s by %s (%d)\n", library->songs[i].title, library->songs[i].artist, library->songs[i].year);
    }
}

// Free the library
void free_library(Library *library) {
    for (int i = 0; i < library->num_songs; i++) {
        free(library->songs[i].title);
        free(library->songs[i].artist);
    }
    free(library->songs);
    free(library);
}

// Main function
int main() {
    // Create a new library
    Library *library = create_library();

    // Add some songs to the library
    Song song1 = {"Moonlight Sonata", "Ludwig van Beethoven", 1801, 15};
    add_song(library, &song1);
    Song song2 = {"Für Elise", "Ludwig van Beethoven", 1810, 3};
    add_song(library, &song2);
    Song song3 = {"Clair de Lune", "Claude Debussy", 1890, 5};
    add_song(library, &song3);
    Song song4 = {"Gymnopédie No. 1", "Erik Satie", 1888, 3};
    add_song(library, &song4);
    Song song5 = {"Ave Maria", "Franz Schubert", 1825, 5};
    add_song(library, &song5);

    // Print the library
    print_library(library);

    // Free the library
    free_library(library);

    return 0;
}