//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of songs in the library
#define MAX_SONGS 100

// Define the structure of a song
typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
} song_t;

// Define the structure of the library
typedef struct library {
    song_t songs[MAX_SONGS];
    int num_songs;
} library_t;

// Create a new library
library_t *create_library() {
    library_t *library = malloc(sizeof(library_t));
    library->num_songs = 0;
    return library;
}

// Add a song to the library
void add_song(library_t *library, song_t song) {
    if (library->num_songs < MAX_SONGS) {
        library->songs[library->num_songs] = song;
        library->num_songs++;
    } else {
        printf("Error: Library is full\n");
    }
}

// Print the library
void print_library(library_t *library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("%s by %s from %d\n", library->songs[i].title, library->songs[i].artist, library->songs[i].year);
    }
}

// Search for a song in the library
song_t *search_song(library_t *library, char *title) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].title, title) == 0) {
            return &library->songs[i];
        }
    }

    return NULL;
}

// Delete a song from the library
void delete_song(library_t *library, char *title) {
    int index = -1;

    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].title, title) == 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < library->num_songs - 1; i++) {
            library->songs[i] = library->songs[i + 1];
        }
        library->num_songs--;
    } else {
        printf("Error: Song not found\n");
    }
}

// Free the library
void free_library(library_t *library) {
    free(library);
}

// Main function
int main() {
    // Create a new library
    library_t *library = create_library();

    // Add some songs to the library
    song_t song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975};
    song_t song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971};
    song_t song3 = {"Hotel California", "Eagles", "Hotel California", 1976};
    add_song(library, song1);
    add_song(library, song2);
    add_song(library, song3);

    // Print the library
    printf("Library:\n");
    print_library(library);

    // Search for a song in the library
    song_t *song = search_song(library, "Hotel California");
    if (song != NULL) {
        printf("Song found: %s by %s from %d\n", song->title, song->artist, song->year);
    } else {
        printf("Song not found\n");
    }

    // Delete a song from the library
    delete_song(library, "Stairway to Heaven");

    // Print the library
    printf("Library after deleting Stairway to Heaven:\n");
    print_library(library);

    // Free the library
    free_library(library);

    return 0;
}