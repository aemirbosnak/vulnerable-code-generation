//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: satisfied
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
    int track_number;
} song;

// Define the structure of the library
typedef struct library {
    song songs[MAX_SONGS];
    int num_songs;
} library;

// Create a new library
library *create_library() {
    library *lib = malloc(sizeof(library));
    if (lib == NULL) {
        return NULL;
    }

    lib->num_songs = 0;

    return lib;
}

// Add a song to the library
void add_song(library *lib, song *new_song) {
    if (lib->num_songs == MAX_SONGS) {
        printf("The library is full. No more songs can be added.\n");
        return;
    }

    lib->songs[lib->num_songs] = *new_song;
    lib->num_songs++;
}

// Print the library
void print_library(library *lib) {
    for (int i = 0; i < lib->num_songs; i++) {
        printf("%s - %s\n", lib->songs[i].title, lib->songs[i].artist);
    }
}

// Search the library for a song by title
song *search_by_title(library *lib, char *title) {
    for (int i = 0; i < lib->num_songs; i++) {
        if (strcmp(lib->songs[i].title, title) == 0) {
            return &lib->songs[i];
        }
    }

    return NULL;
}

// Search the library for a song by artist
song *search_by_artist(library *lib, char *artist) {
    for (int i = 0; i < lib->num_songs; i++) {
        if (strcmp(lib->songs[i].artist, artist) == 0) {
            return &lib->songs[i];
        }
    }

    return NULL;
}

// Search the library for a song by album
song *search_by_album(library *lib, char *album) {
    for (int i = 0; i < lib->num_songs; i++) {
        if (strcmp(lib->songs[i].album, album) == 0) {
            return &lib->songs[i];
        }
    }

    return NULL;
}

// Delete a song from the library
void delete_song(library *lib, song *song_to_delete) {
    for (int i = 0; i < lib->num_songs; i++) {
        if (&lib->songs[i] == song_to_delete) {
            for (int j = i; j < lib->num_songs - 1; j++) {
                lib->songs[j] = lib->songs[j + 1];
            }

            lib->num_songs--;

            return;
        }
    }
}

// Free the memory allocated for the library
void free_library(library *lib) {
    free(lib);
}

// Main function
int main() {
    // Create a new library
    library *lib = create_library();

    // Add some songs to the library
    song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1};
    song song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 4};
    song song3 = {"Hotel California", "Eagles", "Hotel California", 1976, 3};
    song song4 = {"Imagine", "John Lennon", "Imagine", 1971, 1};
    song song5 = {"Like a Rolling Stone", "Bob Dylan", "Highway 61 Revisited", 1965, 6};

    add_song(lib, &song1);
    add_song(lib, &song2);
    add_song(lib, &song3);
    add_song(lib, &song4);
    add_song(lib, &song5);

    // Print the library
    printf("The library contains the following songs:\n");
    print_library(lib);

    // Search the library for a song by title
    song *song_by_title = search_by_title(lib, "Bohemian Rhapsody");
    if (song_by_title != NULL) {
        printf("The song '%s' by %s was found in the library.\n", song_by_title->title, song_by_title->artist);
    } else {
        printf("The song 'Bohemian Rhapsody' was not found in the library.\n");
    }

    // Search the library for a song by artist
    song *song_by_artist = search_by_artist(lib, "Led Zeppelin");
    if (song_by_artist != NULL) {
        printf("The song '%s' by %s was found in the library.\n", song_by_artist->title, song_by_artist->artist);
    } else {
        printf("No songs by Led Zeppelin were found in the library.\n");
    }

    // Search the library for a song by album
    song *song_by_album = search_by_album(lib, "Hotel California");
    if (song_by_album != NULL) {
        printf("The song '%s' by %s was found in the library.\n", song_by_album->title, song_by_album->artist);
    } else {
        printf("No songs from the album 'Hotel California' were found in the library.\n");
    }

    // Delete a song from the library
    delete_song(lib, &song1);

    // Print the library again
    printf("\nThe library now contains the following songs:\n");
    print_library(lib);

    // Free the memory allocated for the library
    free_library(lib);

    return 0;
}