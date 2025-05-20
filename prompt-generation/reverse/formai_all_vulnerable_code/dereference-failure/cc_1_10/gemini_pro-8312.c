//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a music library
typedef struct music_library {
    char *name;
    char *artist;
    char *album;
    int year;
    int duration;
} music_library;

// Function to create a new music library
music_library *create_music_library(char *name, char *artist, char *album, int year, int duration) {
    music_library *new_library = malloc(sizeof(music_library));
    if (new_library == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for new music library.\n");
        return NULL;
    }

    new_library->name = strdup(name);
    new_library->artist = strdup(artist);
    new_library->album = strdup(album);
    new_library->year = year;
    new_library->duration = duration;

    return new_library;
}

// Function to print the details of a music library
void print_music_library(music_library *library) {
    printf("Name: %s\n", library->name);
    printf("Artist: %s\n", library->artist);
    printf("Album: %s\n", library->album);
    printf("Year: %d\n", library->year);
    printf("Duration: %d\n", library->duration);
}

// Function to free the memory allocated for a music library
void free_music_library(music_library *library) {
    free(library->name);
    free(library->artist);
    free(library->album);
    free(library);
}

// Main function
int main() {
    // Create a new music library
    music_library *library = create_music_library("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 5);

    // Print the details of the music library
    print_music_library(library);

    // Free the memory allocated for the music library
    free_music_library(library);

    return 0;
}