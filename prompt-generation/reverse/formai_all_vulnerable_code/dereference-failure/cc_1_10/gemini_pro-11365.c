//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a song
typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int track_number;
} song;

// Define the structure of a library
typedef struct library {
    song *songs;
    int num_songs;
} library;

// Create a new library
library *create_library() {
    library *new_library = malloc(sizeof(library));
    new_library->songs = NULL;
    new_library->num_songs = 0;
    return new_library;
}

// Add a song to a library
void add_song(library *lib, song *new_song) {
    // Reallocate the memory for the songs array
    lib->songs = realloc(lib->songs, (lib->num_songs + 1) * sizeof(song));

    // Copy the new song into the songs array
    lib->songs[lib->num_songs] = *new_song;

    // Increment the number of songs in the library
    lib->num_songs++;
}

// Print the songs in a library
void print_library(library *lib) {
    for (int i = 0; i < lib->num_songs; i++) {
        printf("%s - %s - %s - %d - %d\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].album, lib->songs[i].year, lib->songs[i].track_number);
    }
}

// Free the memory allocated for a library
void free_library(library *lib) {
    free(lib->songs);
    free(lib);
}

// Main function
int main() {
    // Create a new library
    library *my_library = create_library();

    // Add some songs to the library
    song *song1 = malloc(sizeof(song));
    strcpy(song1->title, "Bohemian Rhapsody");
    strcpy(song1->artist, "Queen");
    strcpy(song1->album, "A Night at the Opera");
    song1->year = 1975;
    song1->track_number = 1;
    add_song(my_library, song1);

    song *song2 = malloc(sizeof(song));
    strcpy(song2->title, "Imagine");
    strcpy(song2->artist, "John Lennon");
    strcpy(song2->album, "Imagine");
    song2->year = 1971;
    song2->track_number = 1;
    add_song(my_library, song2);

    song *song3 = malloc(sizeof(song));
    strcpy(song3->title, "Hallelujah");
    strcpy(song3->artist, "Leonard Cohen");
    strcpy(song3->album, "Various Positions");
    song3->year = 1984;
    song3->track_number = 3;
    add_song(my_library, song3);

    // Print the songs in the library
    print_library(my_library);

    // Free the memory allocated for the library
    free_library(my_library);

    return 0;
}