//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music library
struct music_library {
    char *name;
    int num_songs;
    struct song *songs;
};

// Define the structure of a song
struct song {
    char *title;
    char *artist;
    int duration;
};

// Create a new music library
struct music_library *create_music_library(char *name) {
    struct music_library *library = malloc(sizeof(struct music_library));
    library->name = strdup(name);
    library->num_songs = 0;
    library->songs = NULL;
    return library;
}

// Add a new song to a music library
void add_song_to_library(struct music_library *library, char *title, char *artist, int duration) {
    struct song *new_song = malloc(sizeof(struct song));
    new_song->title = strdup(title);
    new_song->artist = strdup(artist);
    new_song->duration = duration;

    library->num_songs++;
    library->songs = realloc(library->songs, sizeof(struct song) * library->num_songs);
    library->songs[library->num_songs - 1] = *new_song;
}

// Print the contents of a music library
void print_music_library(struct music_library *library) {
    printf("Music Library: %s\n", library->name);
    printf("Number of songs: %d\n", library->num_songs);
    for (int i = 0; i < library->num_songs; i++) {
        printf("Song %d:\n", i + 1);
        printf("Title: %s\n", library->songs[i].title);
        printf("Artist: %s\n", library->songs[i].artist);
        printf("Duration: %d\n", library->songs[i].duration);
        printf("\n");
    }
}

// Free the memory allocated for a music library
void free_music_library(struct music_library *library) {
    for (int i = 0; i < library->num_songs; i++) {
        free(library->songs[i].title);
        free(library->songs[i].artist);
    }
    free(library->songs);
    free(library->name);
    free(library);
}

int main() {
    // Create a new music library
    struct music_library *library = create_music_library("My Music Library");

    // Add some songs to the library
    add_song_to_library(library, "Bohemian Rhapsody", "Queen", 360);
    add_song_to_library(library, "Imagine", "John Lennon", 180);
    add_song_to_library(library, "Strawberry Fields Forever", "The Beatles", 170);

    // Print the contents of the library
    print_music_library(library);

    // Free the memory allocated for the library
    free_music_library(library);

    return 0;
}