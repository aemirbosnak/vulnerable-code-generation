//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store music library data
typedef struct music_library {
    char *title;
    char *artist;
    char *album;
    int year;
    int duration;
} music_library;

// Function to create a new music library
music_library *create_music_library(char *title, char *artist, char *album, int year, int duration) {
    music_library *new_library = malloc(sizeof(music_library));
    new_library->title = strdup(title);
    new_library->artist = strdup(artist);
    new_library->album = strdup(album);
    new_library->year = year;
    new_library->duration = duration;
    return new_library;
}

// Function to print the details of a music library
void print_music_library(music_library *library) {
    printf("Title: %s\n", library->title);
    printf("Artist: %s\n", library->artist);
    printf("Album: %s\n", library->album);
    printf("Year: %d\n", library->year);
    printf("Duration: %d seconds\n", library->duration);
}

// Function to add a new song to a music library
void add_song_to_library(music_library *library, char *title, char *artist, char *album, int year, int duration) {
    library->title = strdup(title);
    library->artist = strdup(artist);
    library->album = strdup(album);
    library->year = year;
    library->duration = duration;
}

// Function to search for a song in a music library by title
music_library *search_song_by_title(music_library *library, char *title) {
    if (strcmp(library->title, title) == 0) {
        return library;
    } else {
        return NULL;
    }
}

// Function to search for a song in a music library by artist
music_library *search_song_by_artist(music_library *library, char *artist) {
    if (strcmp(library->artist, artist) == 0) {
        return library;
    } else {
        return NULL;
    }
}

// Function to search for a song in a music library by album
music_library *search_song_by_album(music_library *library, char *album) {
    if (strcmp(library->album, album) == 0) {
        return library;
    } else {
        return NULL;
    }
}

// Function to free the memory allocated to a music library
void free_music_library(music_library *library) {
    free(library->title);
    free(library->artist);
    free(library->album);
    free(library);
}

// Main function
int main() {
    // Create a new music library
    music_library *my_library = create_music_library("Brave", "Sara Bareilles", "Brave", 2013, 220);

    // Print the details of the music library
    print_music_library(my_library);

    // Add a new song to the music library
    add_song_to_library(my_library, "Love Song", "Sara Bareilles", "Brave", 2013, 240);

    // Search for a song in the music library by title
    music_library *song = search_song_by_title(my_library, "Love Song");
    if (song != NULL) {
        printf("Song found: %s\n", song->title);
    } else {
        printf("Song not found.\n");
    }

    // Search for a song in the music library by artist
    song = search_song_by_artist(my_library, "Sara Bareilles");
    if (song != NULL) {
        printf("Song found: %s\n", song->title);
    } else {
        printf("Song not found.\n");
    }

    // Search for a song in the music library by album
    song = search_song_by_album(my_library, "Brave");
    if (song != NULL) {
        printf("Song found: %s\n", song->title);
    } else {
        printf("Song not found.\n");
    }

    // Free the memory allocated to the music library
    free_music_library(my_library);

    return 0;
}