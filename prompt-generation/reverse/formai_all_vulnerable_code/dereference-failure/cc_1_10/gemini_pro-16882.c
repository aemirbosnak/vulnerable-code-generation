//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: lively
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

// Create a new library
library *create_library() {
    library *lib = malloc(sizeof(library));
    lib->songs = NULL;
    lib->num_songs = 0;
    return lib;
}

// Add a song to a library
void add_song(library *lib, song *s) {
    lib->songs = realloc(lib->songs, (lib->num_songs + 1) * sizeof(song));
    lib->songs[lib->num_songs] = *s;
    lib->num_songs++;
}

// Print the songs in a library
void print_library(library *lib) {
    for (int i = 0; i < lib->num_songs; i++) {
        printf("%s by %s from the album %s (%d)\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].album, lib->songs[i].year);
    }
}

// Search for a song in a library by title
song *search_song_by_title(library *lib, char *title) {
    for (int i = 0; i < lib->num_songs; i++) {
        if (strcmp(lib->songs[i].title, title) == 0) {
            return &lib->songs[i];
        }
    }
    return NULL;
}

// Search for a song in a library by artist
song *search_song_by_artist(library *lib, char *artist) {
    for (int i = 0; i < lib->num_songs; i++) {
        if (strcmp(lib->songs[i].artist, artist) == 0) {
            return &lib->songs[i];
        }
    }
    return NULL;
}

// Search for a song in a library by album
song *search_song_by_album(library *lib, char *album) {
    for (int i = 0; i < lib->num_songs; i++) {
        if (strcmp(lib->songs[i].album, album) == 0) {
            return &lib->songs[i];
        }
    }
    return NULL;
}

// Delete a song from a library
void delete_song(library *lib, song *s) {
    for (int i = 0; i < lib->num_songs; i++) {
        if (&lib->songs[i] == s) {
            for (int j = i + 1; j < lib->num_songs; j++) {
                lib->songs[j - 1] = lib->songs[j];
            }
            lib->num_songs--;
            break;
        }
    }
}

// Free the memory allocated for a library
void free_library(library *lib) {
    free(lib->songs);
    free(lib);
}

int main() {
    // Create a new library
    library *lib = create_library();

    // Add some songs to the library
    song *s1 = malloc(sizeof(song));
    strcpy(s1->title, "Bohemian Rhapsody");
    strcpy(s1->artist, "Queen");
    strcpy(s1->album, "A Night at the Opera");
    s1->year = 1975;
    s1->track_number = 1;
    add_song(lib, s1);

    song *s2 = malloc(sizeof(song));
    strcpy(s2->title, "Imagine");
    strcpy(s2->artist, "John Lennon");
    strcpy(s2->album, "Imagine");
    s2->year = 1971;
    s2->track_number = 1;
    add_song(lib, s2);

    song *s3 = malloc(sizeof(song));
    strcpy(s3->title, "Hotel California");
    strcpy(s3->artist, "Eagles");
    strcpy(s3->album, "Hotel California");
    s3->year = 1976;
    s3->track_number = 1;
    add_song(lib, s3);

    // Print the songs in the library
    printf("The songs in the library are:\n");
    print_library(lib);

    // Search for a song in the library by title
    song *s = search_song_by_title(lib, "Bohemian Rhapsody");
    if (s != NULL) {
        printf("Found the song %s by %s from the album %s (%d)\n", s->title, s->artist, s->album, s->year);
    } else {
        printf("Could not find the song.\n");
    }

    // Search for a song in the library by artist
    s = search_song_by_artist(lib, "John Lennon");
    if (s != NULL) {
        printf("Found the song %s by %s from the album %s (%d)\n", s->title, s->artist, s->album, s->year);
    } else {
        printf("Could not find the song.\n");
    }

    // Search for a song in the library by album
    s = search_song_by_album(lib, "Hotel California");
    if (s != NULL) {
        printf("Found the song %s by %s from the album %s (%d)\n", s->title, s->artist, s->album, s->year);
    } else {
        printf("Could not find the song.\n");
    }

    // Delete a song from the library
    delete_song(lib, s1);

    // Print the songs in the library
    printf("The songs in the library are:\n");
    print_library(lib);

    // Free the memory allocated for the library
    free_library(lib);

    return 0;
}