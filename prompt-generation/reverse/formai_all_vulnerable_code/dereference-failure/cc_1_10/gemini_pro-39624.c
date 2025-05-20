//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a song
typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int length;
} song;

// Define the structure of a library
typedef struct library {
    char name[50];
    int num_songs;
    song *songs;
} library;

// Create a new library
library *create_library(char *name) {
    library *new_library = malloc(sizeof(library));
    strcpy(new_library->name, name);
    new_library->num_songs = 0;
    new_library->songs = NULL;
    return new_library;
}

// Add a song to a library
void add_song(library *library, song *new_song) {
    library->num_songs++;
    library->songs = realloc(library->songs, sizeof(song) * library->num_songs);
    library->songs[library->num_songs - 1] = *new_song;
}

// Print the songs in a library
void print_library(library *library) {
    printf("Library: %s\n", library->name);
    for (int i = 0; i < library->num_songs; i++) {
        printf("\t%s - %s (%d)\n", library->songs[i].title, library->songs[i].artist, library->songs[i].year);
    }
}

// Free the memory allocated for a library
void free_library(library *library) {
    free(library->songs);
    free(library);
}

// Main function
int main() {
    // Create a new library
    library *my_library = create_library("My Music Library");

    // Add some songs to the library
    song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 5};
    add_song(my_library, &song1);
    song song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 8};
    add_song(my_library, &song2);
    song song3 = {"Hotel California", "Eagles", "Hotel California", 1976, 6};
    add_song(my_library, &song3);

    // Print the songs in the library
    print_library(my_library);

    // Free the memory allocated for the library
    free_library(my_library);

    return 0;
}