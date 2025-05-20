//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define the structure of a music library
typedef struct music_library {
    char *name;
    char *location;
    int num_songs;
    char **songs;
} music_library;

// Define the structure of a song
typedef struct song {
    char *title;
    char *artist;
    int duration;
} song;

// Create a new music library
music_library *create_music_library(char *name, char *location) {
    music_library *library = malloc(sizeof(music_library));
    library->name = strdup(name);
    library->location = strdup(location);
    library->num_songs = 0;
    library->songs = NULL;
    return library;
}

// Add a song to a music library
void add_song(music_library *library, char *title, char *artist, int duration) {
    library->num_songs++;
    library->songs = realloc(library->songs, library->num_songs * sizeof(char *));
    library->songs[library->num_songs - 1] = malloc(strlen(title) + 1);
    strcpy(library->songs[library->num_songs - 1], title);
}

// Print the contents of a music library
void print_music_library(music_library *library) {
    printf("Name: %s\n", library->name);
    printf("Location: %s\n", library->location);
    printf("Number of songs: %d\n", library->num_songs);
    for (int i = 0; i < library->num_songs; i++) {
        printf("Song %d: %s\n", i + 1, library->songs[i]);
    }
}

// Free the memory allocated for a music library
void free_music_library(music_library *library) {
    free(library->name);
    free(library->location);
    for (int i = 0; i < library->num_songs; i++) {
        free(library->songs[i]);
    }
    free(library->songs);
    free(library);
}

// Main function
int main() {
    // Create a new music library
    music_library *library = create_music_library("My Music Library", "/home/user/music");

    // Add some songs to the library
    add_song(library, "Song 1", "Artist 1", 180);
    add_song(library, "Song 2", "Artist 2", 240);
    add_song(library, "Song 3", "Artist 3", 300);

    // Print the contents of the library
    print_music_library(library);

    // Free the memory allocated for the library
    free_music_library(library);

    return 0;
}