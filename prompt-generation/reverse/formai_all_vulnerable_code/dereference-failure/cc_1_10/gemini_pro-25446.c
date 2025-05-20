//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: modular
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
} song;

// Define the structure of a library
typedef struct library {
    song *songs;
    int num_songs;
} library;

// Create a new song
song *new_song(char *title, char *artist, char *album, int year, int track_number) {
    song *s = malloc(sizeof(song));
    strcpy(s->title, title);
    strcpy(s->artist, artist);
    strcpy(s->album, album);
    s->year = year;
    s->track_number = track_number;
    return s;
}

// Create a new library
library *new_library() {
    library *l = malloc(sizeof(library));
    l->songs = malloc(0);
    l->num_songs = 0;
    return l;
}

// Add a song to a library
void add_song(library *l, song *s) {
    l->songs = realloc(l->songs, (l->num_songs + 1) * sizeof(song));
    l->songs[l->num_songs] = *s;
    l->num_songs++;
}

// Print the songs in a library
void print_library(library *l) {
    for (int i = 0; i < l->num_songs; i++) {
        printf("%s - %s - %s - %d - %d\n", l->songs[i].title, l->songs[i].artist, l->songs[i].album, l->songs[i].year, l->songs[i].track_number);
    }
}

// Free the memory allocated for a song
void free_song(song *s) {
    free(s);
}

// Free the memory allocated for a library
void free_library(library *l) {
    for (int i = 0; i < l->num_songs; i++) {
        free_song(&l->songs[i]);
    }
    free(l->songs);
    free(l);
}

// Main function
int main() {
    // Create a new library
    library *l = new_library();

    // Add some songs to the library
    song *s1 = new_song("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1);
    add_song(l, s1);
    song *s2 = new_song("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 1);
    add_song(l, s2);
    song *s3 = new_song("Hotel California", "Eagles", "Hotel California", 1976, 1);
    add_song(l, s3);

    // Print the songs in the library
    print_library(l);

    // Free the memory allocated for the songs and the library
    free_library(l);

    return 0;
}