//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of songs that can be stored in the library
#define MAX_SONGS 100

// Define the structure of a song
typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int length;
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
void add_song(library_t *library, char *title, char *artist, char *album, int year, int length) {
    if (library->num_songs < MAX_SONGS) {
        strcpy(library->songs[library->num_songs].title, title);
        strcpy(library->songs[library->num_songs].artist, artist);
        strcpy(library->songs[library->num_songs].album, album);
        library->songs[library->num_songs].year = year;
        library->songs[library->num_songs].length = length;
        library->num_songs++;
    } else {
        printf("Error: Library is full.\n");
    }
}

// Print the library
void print_library(library_t *library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("%s\n", library->songs[i].title);
        printf("%s\n", library->songs[i].artist);
        printf("%s\n", library->songs[i].album);
        printf("%d\n", library->songs[i].year);
        printf("%d\n", library->songs[i].length);
        printf("\n");
    }
}

// Free the memory allocated for the library
void free_library(library_t *library) {
    free(library);
}

// Main function
int main() {
    // Create a new library
    library_t *library = create_library();

    // Add some songs to the library
    add_song(library, "Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 544);
    add_song(library, "Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 802);
    add_song(library, "Hotel California", "Eagles", "Hotel California", 1977, 635);

    // Print the library
    print_library(library);

    // Free the memory allocated for the library
    free_library(library);

    return 0;
}