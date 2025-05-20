//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music library
typedef struct MusicLibrary {
    char *name;
    char *artist;
    char *album;
    int year;
    int track_number;
    int disc_number;
    int length;
    char *genre;
} MusicLibrary;

// Create a new music library
MusicLibrary *create_music_library(char *name, char *artist, char *album, int year, int track_number, int disc_number, int length, char *genre) {
    MusicLibrary *library = malloc(sizeof(MusicLibrary));
    library->name = strdup(name);
    library->artist = strdup(artist);
    library->album = strdup(album);
    library->year = year;
    library->track_number = track_number;
    library->disc_number = disc_number;
    library->length = length;
    library->genre = strdup(genre);
    return library;
}

// Print the details of a music library
void print_music_library(MusicLibrary *library) {
    printf("Name: %s\n", library->name);
    printf("Artist: %s\n", library->artist);
    printf("Album: %s\n", library->album);
    printf("Year: %d\n", library->year);
    printf("Track Number: %d\n", library->track_number);
    printf("Disc Number: %d\n", library->disc_number);
    printf("Length: %d\n", library->length);
    printf("Genre: %s\n", library->genre);
}

// Free the memory allocated for a music library
void free_music_library(MusicLibrary *library) {
    free(library->name);
    free(library->artist);
    free(library->album);
    free(library->genre);
    free(library);
}

// Main function
int main() {
    // Create a new music library
    MusicLibrary *library = create_music_library("The Turing Test", "Alan Turing", "The Imitation Game", 2014, 1, 1, 180, "Electronic");

    // Print the details of the music library
    print_music_library(library);

    // Free the memory allocated for the music library
    free_music_library(library);

    return 0;
}