//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a song
typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
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

// Add a song to a library
void add_song(library_t *library, song_t *song) {
    library->songs = realloc(library->songs, (library->num_songs + 1) * sizeof(song_t));
    library->songs[library->num_songs] = *song;
    library->num_songs++;
}

// Print a library
void print_library(library_t *library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("%s - %s - %s (%d)\n", library->songs[i].title, library->songs[i].artist, library->songs[i].album, library->songs[i].year);
    }
}

// Get the number of songs in a library
int get_num_songs(library_t *library) {
    return library->num_songs;
}

// Get a song by its index
song_t *get_song_by_index(library_t *library, int index) {
    if (index < 0 || index >= library->num_songs) {
        return NULL;
    }

    return &library->songs[index];
}

// Get a song by its title
song_t *get_song_by_title(library_t *library, char *title) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].title, title) == 0) {
            return &library->songs[i];
        }
    }

    return NULL;
}

// Get a song by its artist
song_t *get_song_by_artist(library_t *library, char *artist) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].artist, artist) == 0) {
            return &library->songs[i];
        }
    }

    return NULL;
}

// Get a song by its album
song_t *get_song_by_album(library_t *library, char *album) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].album, album) == 0) {
            return &library->songs[i];
        }
    }

    return NULL;
}

// Get a song by its year
song_t *get_song_by_year(library_t *library, int year) {
    for (int i = 0; i < library->num_songs; i++) {
        if (library->songs[i].year == year) {
            return &library->songs[i];
        }
    }

    return NULL;
}

// Delete a song from a library
void delete_song(library_t *library, int index) {
    if (index < 0 || index >= library->num_songs) {
        return;
    }

    for (int i = index; i < library->num_songs - 1; i++) {
        library->songs[i] = library->songs[i + 1];
    }

    library->num_songs--;
}

// Free a library
void free_library(library_t *library) {
    free(library->songs);
    free(library);
}

// Main function
int main() {
    // Create a new library
    library_t *library = create_library();

    // Add some songs to the library
    song_t song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975};
    add_song(library, &song1);
    song_t song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971};
    add_song(library, &song2);
    song_t song3 = {"Hotel California", "Eagles", "Hotel California", 1976};
    add_song(library, &song3);
    song_t song4 = {"Imagine", "John Lennon", "Imagine", 1971};
    add_song(library, &song4);
    song_t song5 = {"Sweet Home Alabama", "Lynyrd Skynyrd", "(Pronounced 'Lĕh-'nérd 'Skin-'nérd)", 1974};
    add_song(library, &song5);

    // Print the library
    printf("The library contains the following songs:\n");
    print_library(library);

    // Get the number of songs in the library
    printf("The library contains %d songs.\n", get_num_songs(library));

    // Get a song by its index
    song_t *song = get_song_by_index(library, 2);
    printf("The song at index 2 is: %s - %s - %s (%d)\n", song->title, song->artist, song->album, song->year);

    // Get a song by its title
    song = get_song_by_title(library, "Bohemian Rhapsody");
    printf("The song with the title 'Bohemian Rhapsody' is: %s - %s - %s (%d)\n", song->title, song->artist, song->album, song->year);

    // Get a song by its artist
    song = get_song_by_artist(library, "Led Zeppelin");
    printf("The song with the artist 'Led Zeppelin' is: %s - %s - %s (%d)\n", song->title, song->artist, song->album, song->year);

    // Get a song by its album
    song = get_song_by_album(library, "Hotel California");
    printf("The song with the album 'Hotel California' is: %s - %s - %s (%d)\n", song->title, song->artist, song->album, song->year);

    // Get a song by its year
    song = get_song_by_year(library, 1971);
    printf("The song with the year 1971 is: %s - %s - %s (%d)\n", song->title, song->artist, song->album, song->year);

    // Delete a song from the library
    delete_song(library, 1);

    // Print the library
    printf("The library contains the following songs after deleting the song at index 1:\n");
    print_library(library);

    // Free the library
    free_library(library);

    return 0;
}