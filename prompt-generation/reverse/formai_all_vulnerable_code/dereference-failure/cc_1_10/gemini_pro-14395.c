//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a song
typedef struct song {
    char *title;
    char *artist;
    int year;
    int duration;
} song;

// Define the structure of a library
typedef struct library {
    song *songs;
    int num_songs;
} library;

// Create a new song
song *new_song(char *title, char *artist, int year, int duration) {
    song *s = malloc(sizeof(song));
    s->title = strdup(title);
    s->artist = strdup(artist);
    s->year = year;
    s->duration = duration;
    return s;
}

// Create a new library
library *new_library() {
    library *l = malloc(sizeof(library));
    l->songs = NULL;
    l->num_songs = 0;
    return l;
}

// Add a song to a library
void add_song(library *l, song *s) {
    l->songs = realloc(l->songs, (l->num_songs + 1) * sizeof(song));
    l->songs[l->num_songs++] = *s;
}

// Print a song
void print_song(song *s) {
    printf("%s by %s (%d, %d seconds)\n", s->title, s->artist, s->year, s->duration);
}

// Print a library
void print_library(library *l) {
    printf("Library:\n");
    for (int i = 0; i < l->num_songs; i++) {
        print_song(&l->songs[i]);
    }
}

int main() {
    // Create a new library
    library *l = new_library();

    // Add some songs to the library
    add_song(l, new_song("Bohemian Rhapsody", "Queen", 1975, 360));
    add_song(l, new_song("Stairway to Heaven", "Led Zeppelin", 1971, 480));
    add_song(l, new_song("Hotel California", "The Eagles", 1976, 390));
    add_song(l, new_song("Imagine", "John Lennon", 1971, 180));

    // Print the library
    print_library(l);

    // Free the memory allocated for the library
    for (int i = 0; i < l->num_songs; i++) {
        free(l->songs[i].title);
        free(l->songs[i].artist);
    }
    free(l->songs);
    free(l);

    return 0;
}