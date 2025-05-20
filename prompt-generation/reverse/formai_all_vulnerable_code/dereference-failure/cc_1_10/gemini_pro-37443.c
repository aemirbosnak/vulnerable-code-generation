//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a music library
typedef struct music_library {
    char name[50];
    int num_songs;
    char songs[100][50];
} music_library_t;

// Function to create a new music library
music_library_t* create_music_library(char* name) {
    music_library_t* library = (music_library_t*)malloc(sizeof(music_library_t));
    strcpy(library->name, name);
    library->num_songs = 0;
    return library;
}

// Function to add a song to a music library
void add_song_to_library(music_library_t* library, char* song) {
    strcpy(library->songs[library->num_songs], song);
    library->num_songs++;
}

// Function to print the songs in a music library
void print_songs_in_library(music_library_t* library) {
    printf("Songs in %s:\n", library->name);
    for (int i = 0; i < library->num_songs; i++) {
        printf("%s\n", library->songs[i]);
    }
}

// Function to free the memory allocated for a music library
void free_music_library(music_library_t* library) {
    free(library);
}

int main() {
    // Create a new music library
    music_library_t* my_library = create_music_library("My Music Library");

    // Add some songs to the library
    add_song_to_library(my_library, "Song 1");
    add_song_to_library(my_library, "Song 2");
    add_song_to_library(my_library, "Song 3");

    // Print the songs in the library
    print_songs_in_library(my_library);

    // Free the memory allocated for the library
    free_music_library(my_library);

    return 0;
}