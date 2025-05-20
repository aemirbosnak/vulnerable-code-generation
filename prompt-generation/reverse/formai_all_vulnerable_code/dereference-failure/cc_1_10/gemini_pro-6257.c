//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store music library data
struct music_library {
    char *song_name;
    char *artist_name;
    char *album_name;
    int year_released;
    int num_streams;
};

// Function to create a new music library
struct music_library *create_music_library(char *song_name, char *artist_name, char *album_name, int year_released, int num_streams) {
    struct music_library *new_library = malloc(sizeof(struct music_library));
    new_library->song_name = strdup(song_name);
    new_library->artist_name = strdup(artist_name);
    new_library->album_name = strdup(album_name);
    new_library->year_released = year_released;
    new_library->num_streams = num_streams;
    return new_library;
}

// Function to print music library data
void print_music_library(struct music_library *library) {
    printf("Song Name: %s\n", library->song_name);
    printf("Artist Name: %s\n", library->artist_name);
    printf("Album Name: %s\n", library->album_name);
    printf("Year Released: %d\n", library->year_released);
    printf("Number of Streams: %d\n", library->num_streams);
}

// Function to free music library data
void free_music_library(struct music_library *library) {
    free(library->song_name);
    free(library->artist_name);
    free(library->album_name);
    free(library);
}

// Main function
int main() {
    // Create a new music library
    struct music_library *library = create_music_library("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 100000000);

    // Print music library data
    print_music_library(library);

    // Free music library data
    free_music_library(library);

    return 0;
}