//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music library
typedef struct {
    char *title;
    char *artist;
    char *album;
    int year;
    int track;
} Song;

// Define the structure of a music library
typedef struct {
    Song *songs;
    int num_songs;
} MusicLibrary;

// Function to create a new music library
MusicLibrary *create_music_library() {
    MusicLibrary *library = malloc(sizeof(MusicLibrary));
    library->songs = NULL;
    library->num_songs = 0;
    return library;
}

// Function to add a song to a music library
void add_song_to_library(MusicLibrary *library, Song *song) {
    library->songs = realloc(library->songs, (library->num_songs + 1) * sizeof(Song));
    library->songs[library->num_songs] = *song;
    library->num_songs++;
}

// Function to print the songs in a music library
void print_music_library(MusicLibrary *library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("%s - %s (%s, %d, track %d)\n", library->songs[i].title, library->songs[i].artist, library->songs[i].album, library->songs[i].year, library->songs[i].track);
    }
}

// Function to free the memory allocated for a song
void free_song(Song *song) {
    free(song->title);
    free(song->artist);
    free(song->album);
    free(song);
}

// Function to free the memory allocated for a music library
void free_music_library(MusicLibrary *library) {
    for (int i = 0; i < library->num_songs; i++) {
        free_song(&library->songs[i]);
    }
    free(library->songs);
    free(library);
}

// Main function
int main() {
    // Create a new music library
    MusicLibrary *library = create_music_library();

    // Add some songs to the library
    Song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1};
    add_song_to_library(library, &song1);

    Song song2 = {"Imagine", "John Lennon", "Imagine", 1971, 3};
    add_song_to_library(library, &song2);

    Song song3 = {"Strawberry Fields Forever", "The Beatles", "Magical Mystery Tour", 1967, 2};
    add_song_to_library(library, &song3);

    // Print the songs in the library
    printf("The music library contains the following songs:\n");
    print_music_library(library);

    // Free the memory allocated for the library
    free_music_library(library);

    return 0;
}