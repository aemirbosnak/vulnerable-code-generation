//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music library
struct music_library {
    char name[50];
    int num_songs;
    struct song *songs;
};

// Define the structure of a song
struct song {
    char name[50];
    char artist[50];
    int duration;
};

// Create a new music library
struct music_library *create_music_library(char *name) {
    struct music_library *library = malloc(sizeof(struct music_library));
    strcpy(library->name, name);
    library->num_songs = 0;
    library->songs = NULL;
    return library;
}

// Add a song to a music library
void add_song_to_library(struct music_library *library, struct song *song) {
    library->num_songs++;
    library->songs = realloc(library->songs, library->num_songs * sizeof(struct song));
    library->songs[library->num_songs - 1] = *song;
}

// Print the contents of a music library
void print_music_library(struct music_library *library) {
    printf("Music Library: %s\n", library->name);
    for (int i = 0; i < library->num_songs; i++) {
        printf("Song: %s\n", library->songs[i].name);
        printf("Artist: %s\n", library->songs[i].artist);
        printf("Duration: %d seconds\n\n", library->songs[i].duration);
    }
}

// Free the memory allocated for a music library
void free_music_library(struct music_library *library) {
    free(library->songs);
    free(library);
}

// Main function
int main() {
    // Create a new music library
    struct music_library *library = create_music_library("My Music Library");

    // Add some songs to the library
    struct song song1 = {"Song 1", "Artist 1", 180};
    struct song song2 = {"Song 2", "Artist 2", 240};
    struct song song3 = {"Song 3", "Artist 3", 300};
    add_song_to_library(library, &song1);
    add_song_to_library(library, &song2);
    add_song_to_library(library, &song3);

    // Print the contents of the library
    print_music_library(library);

    // Free the memory allocated for the library
    free_music_library(library);

    return 0;
}