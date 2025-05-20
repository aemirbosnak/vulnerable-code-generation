//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the music library
typedef struct music_library {
    char *name;
    char *artist;
    char *album;
    int year;
} music_library;

// Function to create a new music library
music_library *create_music_library(char *name, char *artist, char *album, int year) {
    music_library *new_library = malloc(sizeof(music_library));
    new_library->name = strdup(name);
    new_library->artist = strdup(artist);
    new_library->album = strdup(album);
    new_library->year = year;
    return new_library;
}

// Function to add a song to the music library
void add_song(music_library *library, char *name, char *artist, char *album, int year) {
    library->name = strdup(name);
    library->artist = strdup(artist);
    library->album = strdup(album);
    library->year = year;
}

// Function to print the music library
void print_music_library(music_library *library) {
    printf("Name: %s\n", library->name);
    printf("Artist: %s\n", library->artist);
    printf("Album: %s\n", library->album);
    printf("Year: %d\n", library->year);
}

// Main function
int main() {
    // Create a new music library
    music_library *my_library = create_music_library("My Music Library", "Me", "Myself", 2020);

    // Add some songs to the music library
    add_song(my_library, "Song 1", "Me", "Myself", 2020);
    add_song(my_library, "Song 2", "Me", "Myself", 2020);
    add_song(my_library, "Song 3", "Me", "Myself", 2020);

    // Print the music library
    print_music_library(my_library);

    // Free the memory allocated for the music library
    free(my_library->name);
    free(my_library->artist);
    free(my_library->album);
    free(my_library);

    return 0;
}