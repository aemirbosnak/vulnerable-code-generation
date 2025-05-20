//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a song
typedef struct Song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
} Song;

// Function to create a new song
Song* create_song(char *title, char *artist, char *album, int year) {
    Song *song = (Song*)malloc(sizeof(Song));
    strcpy(song->title, title);
    strcpy(song->artist, artist);
    strcpy(song->album, album);
    song->year = year;
    return song;
}

// Function to print a song
void print_song(Song *song) {
    printf("Title: %s\n", song->title);
    printf("Artist: %s\n", song->artist);
    printf("Album: %s\n", song->album);
    printf("Year: %d\n", song->year);
}

// Function to add a song to a library
void add_song_to_library(Song **library, int *library_size, Song *song) {
    // Reallocate the library to hold one more song
    *library = (Song*)realloc(*library, (*library_size + 1) * sizeof(Song));

    // Add the song to the end of the library
    (*library)[*library_size] = *song;

    // Increment the library size
    (*library_size)++;
}

// Function to remove a song from a library
void remove_song_from_library(Song **library, int *library_size, int index) {
    // Move all songs after the one to be removed up one position
    for (int i = index; i < *library_size - 1; i++) {
        (*library)[i] = (*library)[i + 1];
    }

    // Decrement the library size
    (*library_size)--;

    // Reallocate the library to hold one less song
    *library = (Song*)realloc(*library, (*library_size) * sizeof(Song));
}

// Function to find a song in a library by title
Song* find_song_by_title(Song **library, int library_size, char *title) {
    for (int i = 0; i < library_size; i++) {
        if (strcmp((*library)[i].title, title) == 0) {
            return &(*library)[i];
        }
    }
    return NULL;
}

// Function to print the entire library
void print_library(Song **library, int library_size) {
    for (int i = 0; i < library_size; i++) {
        print_song(&(*library)[i]);
        printf("\n");
    }
}

int main() {
    // Create an empty library
    Song *library = NULL;
    int library_size = 0;

    // Add some songs to the library
    Song *song1 = create_song("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975);
    add_song_to_library(&library, &library_size, song1);

    Song *song2 = create_song("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971);
    add_song_to_library(&library, &library_size, song2);

    Song *song3 = create_song("Hotel California", "The Eagles", "Hotel California", 1976);
    add_song_to_library(&library, &library_size, song3);

    // Print the entire library
    print_library(&library, library_size);

    // Find a song by title
    Song *found_song = find_song_by_title(&library, library_size, "Stairway to Heaven");
    if (found_song != NULL) {
        printf("Found song:\n");
        print_song(found_song);
    } else {
        printf("Song not found.\n");
    }

    // Remove a song from the library
    remove_song_from_library(&library, &library_size, 1);

    // Print the entire library again
    print_library(&library, library_size);

    // Free the memory allocated for the library
    free(library);

    return 0;
}