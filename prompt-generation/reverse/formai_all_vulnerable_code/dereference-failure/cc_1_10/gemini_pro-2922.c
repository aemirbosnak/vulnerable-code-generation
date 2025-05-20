//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music library
typedef struct music_library {
    char *name;
    char *artist;
    char *album;
    int year;
    int length;
} music_library;

// Create a new music library
music_library *create_music_library(char *name, char *artist, char *album, int year, int length) {
    music_library *new_library = malloc(sizeof(music_library));
    new_library->name = strdup(name);
    new_library->artist = strdup(artist);
    new_library->album = strdup(album);
    new_library->year = year;
    new_library->length = length;
    return new_library;
}

// Add a song to the music library
void add_song(music_library *library, char *name, char *artist, char *album, int year, int length) {
    library->name = strdup(name);
    library->artist = strdup(artist);
    library->album = strdup(album);
    library->year = year;
    library->length = length;
}

// Print the music library
void print_music_library(music_library *library) {
    printf("Name: %s\n", library->name);
    printf("Artist: %s\n", library->artist);
    printf("Album: %s\n", library->album);
    printf("Year: %d\n", library->year);
    printf("Length: %d\n", library->length);
}

// Free the memory allocated for the music library
void free_music_library(music_library *library) {
    free(library->name);
    free(library->artist);
    free(library->album);
    free(library);
}

// Main function
int main() {
    // Create a new music library
    music_library *my_library = create_music_library("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 360);

    // Add a few more songs to the library
    add_song(my_library, "Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 480);
    add_song(my_library, "Hotel California", "Eagles", "Hotel California", 1976, 390);
    add_song(my_library, "Imagine", "John Lennon", "Imagine", 1971, 220);
    add_song(my_library, "Hey Jude", "The Beatles", "Hey Jude", 1968, 360);

    // Print the music library
    print_music_library(my_library);

    // Free the memory allocated for the music library
    free_music_library(my_library);

    return 0;
}