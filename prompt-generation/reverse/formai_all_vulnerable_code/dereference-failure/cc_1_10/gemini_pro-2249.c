//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a song
typedef struct song {
    char *title;
    char *artist;
    char *album;
    int year;
    int track;
    float length;
} song;

// Define the structure of a library
typedef struct library {
    song *songs;
    int num_songs;
} library;

// Create a new library
library *create_library() {
    library *new_library = malloc(sizeof(library));
    new_library->songs = NULL;
    new_library->num_songs = 0;
    return new_library;
}

// Add a song to a library
void add_song(library *lib, song *new_song) {
    lib->songs = realloc(lib->songs, (lib->num_songs + 1) * sizeof(song));
    lib->songs[lib->num_songs] = *new_song;
    lib->num_songs++;
}

// Find a song in a library by title
song *find_song_by_title(library *lib, char *title) {
    for (int i = 0; i < lib->num_songs; i++) {
        if (strcmp(lib->songs[i].title, title) == 0) {
            return &lib->songs[i];
        }
    }
    return NULL;
}

// Find a song in a library by artist
song *find_song_by_artist(library *lib, char *artist) {
    for (int i = 0; i < lib->num_songs; i++) {
        if (strcmp(lib->songs[i].artist, artist) == 0) {
            return &lib->songs[i];
        }
    }
    return NULL;
}

// Find a song in a library by album
song *find_song_by_album(library *lib, char *album) {
    for (int i = 0; i < lib->num_songs; i++) {
        if (strcmp(lib->songs[i].album, album) == 0) {
            return &lib->songs[i];
        }
    }
    return NULL;
}

// Print the contents of a library
void print_library(library *lib) {
    for (int i = 0; i < lib->num_songs; i++) {
        printf("%s - %s - %s - %d - %d - %.2f\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].album, lib->songs[i].year, lib->songs[i].track, lib->songs[i].length);
    }
}

// Free the memory allocated for a library
void free_library(library *lib) {
    for (int i = 0; i < lib->num_songs; i++) {
        free(lib->songs[i].title);
        free(lib->songs[i].artist);
        free(lib->songs[i].album);
    }
    free(lib->songs);
    free(lib);
}

// Main function
int main() {
    // Create a new library
    library *my_library = create_library();

    // Add some songs to the library
    song *song1 = malloc(sizeof(song));
    song1->title = strdup("Bohemian Rhapsody");
    song1->artist = strdup("Queen");
    song1->album = strdup("A Night at the Opera");
    song1->year = 1975;
    song1->track = 1;
    song1->length = 5.54;
    add_song(my_library, song1);

    song *song2 = malloc(sizeof(song));
    song2->title = strdup("Stairway to Heaven");
    song2->artist = strdup("Led Zeppelin");
    song2->album = strdup("Led Zeppelin IV");
    song2->year = 1971;
    song2->track = 4;
    song2->length = 8.02;
    add_song(my_library, song2);

    song *song3 = malloc(sizeof(song));
    song3->title = strdup("Hotel California");
    song3->artist = strdup("Eagles");
    song3->album = strdup("Hotel California");
    song3->year = 1976;
    song3->track = 3;
    song3->length = 6.31;
    add_song(my_library, song3);

    // Print the contents of the library
    print_library(my_library);

    // Find a song by title
    song *found_song = find_song_by_title(my_library, "Bohemian Rhapsody");
    if (found_song != NULL) {
        printf("Found the song %s by %s\n", found_song->title, found_song->artist);
    } else {
        printf("Could not find the song Bohemian Rhapsody\n");
    }

    // Free the memory allocated for the library
    free_library(my_library);

    return 0;
}