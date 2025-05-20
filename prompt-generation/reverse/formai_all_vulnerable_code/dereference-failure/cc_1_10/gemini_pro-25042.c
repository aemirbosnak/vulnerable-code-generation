//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Holy smokes! It's a music library management system!

// Declare the library's music collection.
struct Song {
    char *title;
    char *artist;
    int year;
};

struct Library {
    struct Song *songs;
    int num_songs;
};

// Initialize the library.
struct Library *init_library() {
    struct Library *library = malloc(sizeof(struct Library));
    library->songs = NULL;
    library->num_songs = 0;
    return library;
}

// Add a song to the library.
void add_song(struct Library *library, char *title, char *artist, int year) {
    struct Song *new_song = malloc(sizeof(struct Song));
    new_song->title = strdup(title);
    new_song->artist = strdup(artist);
    new_song->year = year;
    library->songs = realloc(library->songs, (library->num_songs + 1) * sizeof(struct Song));
    library->songs[library->num_songs++] = *new_song;
}

// Print the library's music collection.
void print_library(struct Library *library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("%s\n", library->songs[i].title);
        printf("%s\n", library->songs[i].artist);
        printf("%d\n", library->songs[i].year);
        printf("\n");
    }
}

// Free the library's memory.
void free_library(struct Library *library) {
    for (int i = 0; i < library->num_songs; i++) {
        free(library->songs[i].title);
        free(library->songs[i].artist);
    }
    free(library->songs);
    free(library);
}

// Main function.
int main() {
    // Create a new library.
    struct Library *library = init_library();

    // Add some songs to the library.
    add_song(library, "Bohemian Rhapsody", "Queen", 1975);
    add_song(library, "Stairway to Heaven", "Led Zeppelin", 1971);
    add_song(library, "Hotel California", "Eagles", 1976);

    // Print the library's music collection.
    print_library(library);

    // Free the library's memory.
    free_library(library);

    return 0;
}