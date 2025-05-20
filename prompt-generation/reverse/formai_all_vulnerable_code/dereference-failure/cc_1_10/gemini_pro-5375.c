//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of songs that can be stored
#define MAX_SONGS 100

// Define the structure of a song
typedef struct {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int track_number;
} Song;

// Define the structure of the library
typedef struct {
    Song songs[MAX_SONGS];
    int num_songs;
} Library;

// Create a new library
Library* create_library() {
    Library* library = (Library*)malloc(sizeof(Library));
    library->num_songs = 0;
    return library;
}

// Add a song to the library
void add_song(Library* library, Song* song) {
    if (library->num_songs < MAX_SONGS) {
        library->songs[library->num_songs++] = *song;
    } else {
        printf("Error: The library is full.\n");
    }
}

// Print the library
void print_library(Library* library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("%s by %s from the album %s (%d)\n", library->songs[i].title, library->songs[i].artist, library->songs[i].album, library->songs[i].year);
    }
}

// Free the library
void free_library(Library* library) {
    free(library);
}

// Main function
int main() {
    // Create a new library
    Library* library = create_library();

    // Add some songs to the library
    Song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1};
    add_song(library, &song1);

    Song song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 4};
    add_song(library, &song2);

    Song song3 = {"Hotel California", "Eagles", "Hotel California", 1976, 3};
    add_song(library, &song3);

    // Print the library
    print_library(library);

    // Free the library
    free_library(library);

    return 0;
}