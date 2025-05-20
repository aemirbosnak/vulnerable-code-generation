//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Music library data structure
typedef struct music_library {
    char **songs;
    int num_songs;
} music_library;

// Create a new music library
music_library *create_music_library() {
    music_library *lib = malloc(sizeof(music_library));
    lib->songs = NULL;
    lib->num_songs = 0;
    return lib;
}

// Add a song to the music library
void add_song(music_library *lib, char *song) {
    lib->songs = realloc(lib->songs, (lib->num_songs + 1) * sizeof(char *));
    lib->songs[lib->num_songs++] = strdup(song);
}

// Remove a song from the music library
void remove_song(music_library *lib, char *song) {
    int i;
    for (i = 0; i < lib->num_songs; i++) {
        if (strcmp(lib->songs[i], song) == 0) {
            free(lib->songs[i]);
            lib->songs[i] = lib->songs[lib->num_songs - 1];
            lib->num_songs--;
            break;
        }
    }
}

// Print the music library
void print_music_library(music_library *lib) {
    int i;
    for (i = 0; i < lib->num_songs; i++) {
        printf("%s\n", lib->songs[i]);
    }
}

// Destroy the music library
void destroy_music_library(music_library *lib) {
    int i;
    for (i = 0; i < lib->num_songs; i++) {
        free(lib->songs[i]);
    }
    free(lib->songs);
    free(lib);
}

int main() {
    // Create a new music library
    music_library *lib = create_music_library();

    // Add some songs to the music library
    add_song(lib, "Bullet for My Valentine");
    add_song(lib, "Avenged Sevenfold");
    add_song(lib, "Three Days Grace");
    add_song(lib, "Metallica");
    add_song(lib, "Slipknot");

    // Print the music library
    print_music_library(lib);

    // Remove a song from the music library
    remove_song(lib, "Metallica");

    // Print the music library again
    print_music_library(lib);

    // Destroy the music library
    destroy_music_library(lib);

    return 0;
}