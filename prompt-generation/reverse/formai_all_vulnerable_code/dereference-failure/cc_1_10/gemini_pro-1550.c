//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a song
typedef struct song {
    char *title;
    char *artist;
    int year;
    int length;
} song;

// Define the structure of a library
typedef struct library {
    char *name;
    int num_songs;
    song *songs;
} library;

// Create a new song
song *new_song(char *title, char *artist, int year, int length) {
    song *s = malloc(sizeof(song));
    s->title = strdup(title);
    s->artist = strdup(artist);
    s->year = year;
    s->length = length;
    return s;
}

// Create a new library
library *new_library(char *name) {
    library *l = malloc(sizeof(library));
    l->name = strdup(name);
    l->num_songs = 0;
    l->songs = NULL;
    return l;
}

// Add a song to a library
void add_song(library *l, song *s) {
    l->songs = realloc(l->songs, (l->num_songs + 1) * sizeof(song));
    l->songs[l->num_songs++] = *s;
}

// Print the details of a song
void print_song(song *s) {
    printf("%s by %s (%d, %d minutes)\n", s->title, s->artist, s->year, s->length);
}

// Print the details of a library
void print_library(library *l) {
    printf("Library: %s\n", l->name);
    for (int i = 0; i < l->num_songs; i++) {
        print_song(&l->songs[i]);
    }
}

// Free the memory allocated for a song
void free_song(song *s) {
    free(s->title);
    free(s->artist);
    free(s);
}

// Free the memory allocated for a library
void free_library(library *l) {
    for (int i = 0; i < l->num_songs; i++) {
        free_song(&l->songs[i]);
    }
    free(l->songs);
    free(l->name);
    free(l);
}

int main() {
    // Create a new library
    library *l = new_library("My Music Library");

    // Add some songs to the library
    add_song(l, new_song("Bohemian Rhapsody", "Queen", 1975, 6));
    add_song(l, new_song("Imagine", "John Lennon", 1971, 3));
    add_song(l, new_song("Hey Jude", "The Beatles", 1968, 7));

    // Print the details of the library
    print_library(l);

    // Free the memory allocated for the library
    free_library(l);

    return 0;
}