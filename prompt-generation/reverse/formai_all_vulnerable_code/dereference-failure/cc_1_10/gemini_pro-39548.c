//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a music library
typedef struct music_library {
    char *name;
    int num_songs;
    char **songs;
} music_library;

// Function to create a new music library
music_library *create_music_library(char *name) {
    music_library *library = malloc(sizeof(music_library));
    library->name = strdup(name);
    library->num_songs = 0;
    library->songs = NULL;
    return library;
}

// Function to add a song to a music library
void add_song_to_library(music_library *library, char *song) {
    library->songs = realloc(library->songs, (library->num_songs + 1) * sizeof(char *));
    library->songs[library->num_songs++] = strdup(song);
}

// Function to print the contents of a music library
void print_music_library(music_library *library) {
    printf("Music Library: %s\n", library->name);
    for (int i = 0; i < library->num_songs; i++) {
        printf("    %d. %s\n", i + 1, library->songs[i]);
    }
}

// Function to free the memory allocated for a music library
void free_music_library(music_library *library) {
    for (int i = 0; i < library->num_songs; i++) {
        free(library->songs[i]);
    }
    free(library->songs);
    free(library->name);
    free(library);
}

int main() {
    // Create a new music library
    music_library *library = create_music_library("My Music Library");

    // Add some songs to the library
    add_song_to_library(library, "Song 1");
    add_song_to_library(library, "Song 2");
    add_song_to_library(library, "Song 3");

    // Print the contents of the library
    print_music_library(library);

    // Free the memory allocated for the library
    free_music_library(library);

    return 0;
}