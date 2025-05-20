//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music library
typedef struct music_library {
    char *name;
    char *artist;
    char *album;
    int year;
    float duration;
} music_library;

// Define the maximum number of songs in the library
#define MAX_SONGS 100

// Create a new music library
music_library *create_library() {
    music_library *library = malloc(sizeof(music_library));
    library->name = NULL;
    library->artist = NULL;
    library->album = NULL;
    library->year = 0;
    library->duration = 0.0;
    return library;
}

// Destroy a music library
void destroy_library(music_library *library) {
    free(library->name);
    free(library->artist);
    free(library->album);
    free(library);
}

// Add a song to the library
void add_song(music_library *library, char *name, char *artist, char *album, int year, float duration) {
    // Check if the library is full
    if (library->name == NULL) {
        library->name = malloc(strlen(name) + 1);
        strcpy(library->name, name);
        library->artist = malloc(strlen(artist) + 1);
        strcpy(library->artist, artist);
        library->album = malloc(strlen(album) + 1);
        strcpy(library->album, album);
        library->year = year;
        library->duration = duration;
    } else {
        // Find the first empty slot in the library
        int i;
        for (i = 0; i < MAX_SONGS; i++) {
            if (library[i].name == NULL) {
                break;
            }
        }

        // If there are no empty slots, return an error
        if (i == MAX_SONGS) {
            printf("Error: Library is full.\n");
            return;
        }

        // Add the song to the library
        library[i].name = malloc(strlen(name) + 1);
        strcpy(library[i].name, name);
        library[i].artist = malloc(strlen(artist) + 1);
        strcpy(library[i].artist, artist);
        library[i].album = malloc(strlen(album) + 1);
        strcpy(library[i].album, album);
        library[i].year = year;
        library[i].duration = duration;
    }
}

// Print the library
void print_library(music_library *library) {
    // Print the header
    printf("Name\t\t\t\tArtist\t\t\t\tAlbum\t\t\t\tYear\t\t\t\tDuration\n");

    // Print the songs
    int i;
    for (i = 0; i < MAX_SONGS; i++) {
        if (library[i].name != NULL) {
            printf("%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%d\t\t\t\t%.2f\n", library[i].name, library[i].artist, library[i].album, library[i].year, library[i].duration);
        }
    }
}

// Main function
int main() {
    // Create a new music library
    music_library *library = create_library();

    // Add some songs to the library
    add_song(library, "Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 5.54);
    add_song(library, "Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 8.02);
    add_song(library, "Hotel California", "The Eagles", "Hotel California", 1976, 6.30);
    add_song(library, "Imagine", "John Lennon", "Imagine", 1971, 3.01);
    add_song(library, "Strawberry Fields Forever", "The Beatles", "Sgt. Pepper's Lonely Hearts Club Band", 1967, 4.05);

    // Print the library
    print_library(library);

    // Destroy the library
    destroy_library(library);

    return 0;
}