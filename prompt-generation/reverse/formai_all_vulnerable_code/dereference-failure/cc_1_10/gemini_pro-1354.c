//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a song
typedef struct Song {
    char *title;
    char *artist;
    int year;
    int length;
} Song;

// Define the structure of a library
typedef struct Library {
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
    library->songs[library->num_songs++] = *song;
}

// Print the library
void print_library(Library *library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("%s by %s (%d, %d minutes)\n", library->songs[i].title, library->songs[i].artist, library->songs[i].year, library->songs[i].length);
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
    Song song1 = {"Bohemian Rhapsody", "Queen", 1975, 6};
    Song song2 = {"Stairway to Heaven", "Led Zeppelin", 1971, 8};
    Song song3 = {"Hotel California", "Eagles", 1976, 7};
    add_song(library, &song1);
    add_song(library, &song2);
    add_song(library, &song3);

    // Print the library
    print_library(library);

    // Free the library
    free_library(library);

    return 0;
}