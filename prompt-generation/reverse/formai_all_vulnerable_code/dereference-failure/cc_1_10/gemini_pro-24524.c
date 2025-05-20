//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of songs in the library
#define MAX_SONGS 100

// Define the structure of a song
typedef struct {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int track_number;
} Song;

// Define the structure of the music library
typedef struct {
    Song songs[MAX_SONGS];
    int num_songs;
} MusicLibrary;

// Create a new music library
MusicLibrary* create_music_library() {
    MusicLibrary* library = malloc(sizeof(MusicLibrary));
    library->num_songs = 0;
    return library;
}

// Add a song to the music library
void add_song_to_library(MusicLibrary* library, Song song) {
    library->songs[library->num_songs] = song;
    library->num_songs++;
}

// Print the music library
void print_music_library(MusicLibrary* library) {
    for (int i = 0; i < library->num_songs; i++) {
        Song song = library->songs[i];
        printf("Title: %s\n", song.title);
        printf("Artist: %s\n", song.artist);
        printf("Album: %s\n", song.album);
        printf("Year: %d\n", song.year);
        printf("Track number: %d\n\n", song.track_number);
    }
}

// Free the memory allocated for the music library
void free_music_library(MusicLibrary* library) {
    free(library);
}

// Main function
int main() {
    // Create a new music library
    MusicLibrary* library = create_music_library();

    // Add some songs to the music library
    Song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1};
    add_song_to_library(library, song1);

    Song song2 = {"Imagine", "John Lennon", "Imagine", 1971, 1};
    add_song_to_library(library, song2);

    Song song3 = {"Hotel California", "Eagles", "Hotel California", 1976, 1};
    add_song_to_library(library, song3);

    // Print the music library
    print_music_library(library);

    // Free the memory allocated for the music library
    free_music_library(library);

    return 0;
}