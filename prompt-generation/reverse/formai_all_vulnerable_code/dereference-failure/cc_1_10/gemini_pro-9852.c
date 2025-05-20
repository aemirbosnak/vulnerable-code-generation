//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

// Song structure
typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int duration; // in seconds
} song_t;

// Library structure
typedef struct library {
    song_t songs[MAX_SONGS];
    int num_songs;
} library_t;

// Function to create a new library
library_t* create_library() {
    library_t* library = (library_t*)malloc(sizeof(library_t));
    library->num_songs = 0;
    return library;
}

// Function to add a song to the library
void add_song(library_t* library, song_t song) {
    if (library->num_songs < MAX_SONGS) {
        library->songs[library->num_songs] = song;
        library->num_songs++;
    } else {
        printf("Error: Library is full. Cannot add more songs.\n");
    }
}

// Function to find a song in the library by title
song_t* find_song_by_title(library_t* library, char* title) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].title, title) == 0) {
            return &library->songs[i];
        }
    }
    return NULL;
}

// Function to print the library
void print_library(library_t* library) {
    printf("Library:\n");
    for (int i = 0; i < library->num_songs; i++) {
        printf("  %s by %s from %d\n", library->songs[i].title, library->songs[i].artist, library->songs[i].year);
    }
}

// Main function
int main() {
    // Create a new library
    library_t* library = create_library();

    // Add some songs to the library
    song_t song1 = {"Hyperspace", "Interstellar Orchestra", "Cosmic Echoes", 2023, 240};
    add_song(library, song1);
    song_t song2 = {"Quantum Leap", "Digital Phantoms", "Binary Rhapsody", 2022, 180};
    add_song(library, song2);
    song_t song3 = {"Stardust Melody", "Celestial Harmonies", "Galactic Symphony", 2021, 300};
    add_song(library, song3);

    // Print the library
    print_library(library);

    // Find a song by title
    char* title = "Hyperspace";
    song_t* song = find_song_by_title(library, title);
    if (song != NULL) {
        printf("Found song: %s by %s\n", song->title, song->artist);
    } else {
        printf("Song not found.\n");
    }

    return 0;
}