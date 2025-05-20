//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of songs in the library
#define MAX_SONGS 100

// Define the structure of a song
typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int track_number;
} song;

// Define the structure of the library
typedef struct library {
    song songs[MAX_SONGS];
    int num_songs;
} library;

// Create a new library
library *create_library() {
    library *lib = malloc(sizeof(library));
    lib->num_songs = 0;
    return lib;
}

// Add a song to the library
void add_song(library *lib, song *s) {
    if (lib->num_songs < MAX_SONGS) {
        lib->songs[lib->num_songs] = *s;
        lib->num_songs++;
    } else {
        printf("Error: Library is full.\n");
    }
}

// Print the library
void print_library(library *lib) {
    for (int i = 0; i < lib->num_songs; i++) {
        printf("%s - %s - %s (%d)\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].album, lib->songs[i].year);
    }
}

// Search for a song by title
song *search_song_by_title(library *lib, char *title) {
    for (int i = 0; i < lib->num_songs; i++) {
        if (strcmp(lib->songs[i].title, title) == 0) {
            return &lib->songs[i];
        }
    }
    return NULL;
}

// Search for a song by artist
song *search_song_by_artist(library *lib, char *artist) {
    for (int i = 0; i < lib->num_songs; i++) {
        if (strcmp(lib->songs[i].artist, artist) == 0) {
            return &lib->songs[i];
        }
    }
    return NULL;
}

// Search for a song by album
song *search_song_by_album(library *lib, char *album) {
    for (int i = 0; i < lib->num_songs; i++) {
        if (strcmp(lib->songs[i].album, album) == 0) {
            return &lib->songs[i];
        }
    }
    return NULL;
}

// Delete a song from the library
void delete_song(library *lib, song *s) {
    for (int i = 0; i < lib->num_songs; i++) {
        if (&lib->songs[i] == s) {
            for (int j = i; j < lib->num_songs - 1; j++) {
                lib->songs[j] = lib->songs[j + 1];
            }
            lib->num_songs--;
            break;
        }
    }
}

// Free the memory allocated for the library
void free_library(library *lib) {
    free(lib);
}

int main() {
    // Create a new library
    library *lib = create_library();

    // Add some songs to the library
    song s1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1};
    add_song(lib, &s1);
    song s2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 4};
    add_song(lib, &s2);
    song s3 = {"Hotel California", "The Eagles", "Hotel California", 1976, 3};
    add_song(lib, &s3);

    // Print the library
    printf("Library:\n");
    print_library(lib);

    // Search for a song by title
    song *s = search_song_by_title(lib, "Bohemian Rhapsody");
    if (s != NULL) {
        printf("Found song by title: %s - %s - %s (%d)\n", s->title, s->artist, s->album, s->year);
    } else {
        printf("Song not found.\n");
    }

    // Search for a song by artist
    s = search_song_by_artist(lib, "Led Zeppelin");
    if (s != NULL) {
        printf("Found song by artist: %s - %s - %s (%d)\n", s->title, s->artist, s->album, s->year);
    } else {
        printf("Song not found.\n");
    }

    // Search for a song by album
    s = search_song_by_album(lib, "Hotel California");
    if (s != NULL) {
        printf("Found song by album: %s - %s - %s (%d)\n", s->title, s->artist, s->album, s->year);
    } else {
        printf("Song not found.\n");
    }

    // Delete a song from the library
    delete_song(lib, &s1);

    // Print the library
    printf("Library after deleting a song:\n");
    print_library(lib);

    // Free the memory allocated for the library
    free_library(lib);

    return 0;
}