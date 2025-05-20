//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: lively
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
        printf("The library is full!\n");
    }
}

// Print the library
void print_library(library_t *library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("%s - %s - %s - %d\n", library->songs[i].title, library->songs[i].artist, library->songs[i].album, library->songs[i].year);
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
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].title, title) == 0) {
            for (int j = i; j < library->num_songs - 1; j++) {
                library->songs[j] = library->songs[j + 1];
            }
            library->num_songs--;
            break;
        }
    }
}

// Main function
int main() {
    // Create a new library
    library_t *library = create_library();

    // Add some songs to the library
    song_t song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975};
    add_song(library, song1);
    song_t song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971};
    add_song(library, song2);
    song_t song3 = {"Hotel California", "Eagles", "Hotel California", 1976};
    add_song(library, song3);

    // Print the library
    printf("The library contains the following songs:\n");
    print_library(library);

    // Search for a song in the library
    char *title = "Bohemian Rhapsody";
    song_t *song = search_song(library, title);
    if (song != NULL) {
        printf("Found the song %s in the library.\n", song->title);
    } else {
        printf("Could not find the song %s in the library.\n", title);
    }

    // Delete a song from the library
    title = "Hotel California";
    delete_song(library, title);

    // Print the library
    printf("The library now contains the following songs:\n");
    print_library(library);

    // Free the library
    free(library);

    return 0;
}