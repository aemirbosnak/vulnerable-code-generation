//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a song
typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int track_number;
} song_t;

// Define the structure of a library
typedef struct library {
    song_t *songs;
    int num_songs;
} library_t;

// Create a new library
library_t *create_library() {
    library_t *library = malloc(sizeof(library_t));
    library->songs = NULL;
    library->num_songs = 0;
    return library;
}

// Add a song to the library
void add_song(library_t *library, song_t song) {
    library->songs = realloc(library->songs, (library->num_songs + 1) * sizeof(song_t));
    library->songs[library->num_songs] = song;
    library->num_songs++;
}

// Print the library
void print_library(library_t *library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("%s by %s from %s (%d)\n", library->songs[i].title, library->songs[i].artist, library->songs[i].album, library->songs[i].year);
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
    if (index == -1) {
        return;
    }
    for (int i = index; i < library->num_songs - 1; i++) {
        library->songs[i] = library->songs[i + 1];
    }
    library->num_songs--;
    library->songs = realloc(library->songs, library->num_songs * sizeof(song_t));
}

// Main function
int main() {
    // Create a new library
    library_t *library = create_library();

    // Add some songs to the library
    song_t song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1};
    song_t song2 = {"Imagine", "John Lennon", "Imagine", 1971, 3};
    song_t song3 = {"Hotel California", "Eagles", "Hotel California", 1976, 3};
    add_song(library, song1);
    add_song(library, song2);
    add_song(library, song3);

    // Print the library
    printf("The library currently contains %d songs:\n", library->num_songs);
    print_library(library);

    // Search for a song in the library
    song_t *song = search_song(library, "Bohemian Rhapsody");
    if (song != NULL) {
        printf("\nFound the song \"%s\" by %s\n", song->title, song->artist);
    } else {
        printf("\nCould not find the song \"Bohemian Rhapsody\"\n");
    }

    // Delete a song from the library
    delete_song(library, "Imagine");
    printf("\nDeleted the song \"Imagine\"\n");

    // Print the library again
    printf("\nThe library now contains %d songs:\n", library->num_songs);
    print_library(library);

    // Free the memory allocated for the library
    free(library->songs);
    free(library);

    return 0;
}