//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music library
struct music_library {
    char *name;
    int num_songs;
    char **songs;
};

// Create a new music library
struct music_library *create_music_library(char *name) {
    struct music_library *library = malloc(sizeof(struct music_library));
    library->name = strdup(name);
    library->num_songs = 0;
    library->songs = NULL;
    return library;
}

// Add a song to a music library
void add_song(struct music_library *library, char *song) {
    library->songs = realloc(library->songs, (library->num_songs + 1) * sizeof(char *));
    library->songs[library->num_songs++] = strdup(song);
}

// Print the contents of a music library
void print_music_library(struct music_library *library) {
    printf("Music Library: %s\n", library->name);
    for (int i = 0; i < library->num_songs; i++) {
        printf("  %s\n", library->songs[i]);
    }
}

// Free the memory allocated for a music library
void free_music_library(struct music_library *library) {
    free(library->name);
    for (int i = 0; i < library->num_songs; i++) {
        free(library->songs[i]);
    }
    free(library->songs);
    free(library);
}

// Main function
int main() {
    // Create two music libraries
    struct music_library *library1 = create_music_library("My Music");
    struct music_library *library2 = create_music_library("Your Music");

    // Add some songs to each library
    add_song(library1, "Song 1");
    add_song(library1, "Song 2");
    add_song(library1, "Song 3");
    add_song(library2, "Song 4");
    add_song(library2, "Song 5");
    add_song(library2, "Song 6");

    // Print the contents of each library
    print_music_library(library1);
    print_music_library(library2);

    // Free the memory allocated for each library
    free_music_library(library1);
    free_music_library(library2);

    return 0;
}