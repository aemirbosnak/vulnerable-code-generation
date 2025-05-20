//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: satisfied
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
} song_t;

// Define the structure of the library
typedef struct library {
    song_t songs[MAX_SONGS];
    int num_songs;
} library_t;

// Create a new library
library_t *create_library() {
    library_t *library = malloc(sizeof(library_t));
    if (library == NULL) {
        return NULL;
    }

    library->num_songs = 0;

    return library;
}

// Destroy a library
void destroy_library(library_t *library) {
    free(library);
}

// Add a song to the library
int add_song(library_t *library, song_t *song) {
    if (library->num_songs >= MAX_SONGS) {
        return -1;
    }

    library->songs[library->num_songs++] = *song;

    return 0;
}

// Remove a song from the library
int remove_song(library_t *library, int index) {
    if (index < 0 || index >= library->num_songs) {
        return -1;
    }

    for (int i = index; i < library->num_songs - 1; i++) {
        library->songs[i] = library->songs[i + 1];
    }

    library->num_songs--;

    return 0;
}

// Search for a song in the library
int search_song(library_t *library, char *title) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].title, title) == 0) {
            return i;
        }
    }

    return -1;
}

// Print the library
void print_library(library_t *library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("%d. %s - %s - %s\n", i + 1, library->songs[i].title, library->songs[i].artist, library->songs[i].album);
    }
}

// Main function
int main() {
    // Create a new library
    library_t *library = create_library();

    // Add some songs to the library
    song_t song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera"};
    song_t song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV"};
    song_t song3 = {"Hotel California", "Eagles", "Hotel California"};
    add_song(library, &song1);
    add_song(library, &song2);
    add_song(library, &song3);

    // Print the library
    print_library(library);

    // Search for a song in the library
    int index = search_song(library, "Stairway to Heaven");
    if (index >= 0) {
        printf("Found the song \"%s\" at index %d.\n", library->songs[index].title, index);
    } else {
        printf("Could not find the song \"%s\".\n", "Stairway to Heaven");
    }

    // Remove a song from the library
    remove_song(library, index);

    // Print the library again
    print_library(library);

    // Destroy the library
    destroy_library(library);

    return 0;
}