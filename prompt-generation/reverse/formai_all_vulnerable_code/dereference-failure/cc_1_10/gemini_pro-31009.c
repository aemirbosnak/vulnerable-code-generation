//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
    char *title;
    char *artist;
    char *album;
    int year;
    int plays;
} song_t;

typedef struct library {
    song_t *songs;
    int num_songs;
} library_t;

void add_song_to_library(library_t *library, song_t *song) {
    library->songs = realloc(library->songs, (library->num_songs + 1) * sizeof(song_t));
    library->songs[library->num_songs++] = *song;
}

void print_library(library_t *library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("%s by %s from the album %s (%d)\n", library->songs[i].title, library->songs[i].artist, library->songs[i].album, library->songs[i].year);
    }
}

void free_library(library_t *library) {
    for (int i = 0; i < library->num_songs; i++) {
        free(library->songs[i].title);
        free(library->songs[i].artist);
        free(library->songs[i].album);
    }
    free(library->songs);
}

int main() {
    library_t *library = malloc(sizeof(library_t));
    library->songs = NULL;
    library->num_songs = 0;

    // Add some songs to the library
    song_t song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1000000};
    add_song_to_library(library, &song1);

    song_t song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 500000};
    add_song_to_library(library, &song2);

    song_t song3 = {"Hotel California", "Eagles", "Hotel California", 1976, 250000};
    add_song_to_library(library, &song3);

    // Print the library
    printf("The library contains the following songs:\n");
    print_library(library);

    // Free the library
    free_library(library);
    free(library);

    return 0;
}