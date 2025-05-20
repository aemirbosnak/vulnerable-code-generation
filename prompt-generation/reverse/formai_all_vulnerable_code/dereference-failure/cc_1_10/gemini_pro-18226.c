//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a song
typedef struct Song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int length;
} Song;

// Define the structure of a library
typedef struct Library {
    Song songs[100];
    int num_songs;
} Library;

// Function to create a new library
Library* create_library() {
    Library* library = malloc(sizeof(Library));
    library->num_songs = 0;
    return library;
}

// Function to add a song to a library
void add_song(Library* library, Song song) {
    library->songs[library->num_songs] = song;
    library->num_songs++;
}

// Function to print a song
void print_song(Song song) {
    printf("%s by %s from the album %s (%d, %d minutes)\n", song.title, song.artist, song.album, song.year, song.length);
}

// Function to print a library
void print_library(Library* library) {
    for (int i = 0; i < library->num_songs; i++) {
        print_song(library->songs[i]);
    }
}

// Function to find a song in a library by title
Song* find_song_by_title(Library* library, char* title) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].title, title) == 0) {
            return &library->songs[i];
        }
    }
    return NULL;
}

// Function to find a song in a library by artist
Song* find_song_by_artist(Library* library, char* artist) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].artist, artist) == 0) {
            return &library->songs[i];
        }
    }
    return NULL;
}

// Function to find a song in a library by album
Song* find_song_by_album(Library* library, char* album) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].album, album) == 0) {
            return &library->songs[i];
        }
    }
    return NULL;
}

// Function to delete a song from a library by title
void delete_song_by_title(Library* library, char* title) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].title, title) == 0) {
            for (int j = i + 1; j < library->num_songs; j++) {
                library->songs[j - 1] = library->songs[j];
            }
            library->num_songs--;
            break;
        }
    }
}

// Function to delete a song from a library by artist
void delete_song_by_artist(Library* library, char* artist) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].artist, artist) == 0) {
            for (int j = i + 1; j < library->num_songs; j++) {
                library->songs[j - 1] = library->songs[j];
            }
            library->num_songs--;
            break;
        }
    }
}

// Function to delete a song from a library by album
void delete_song_by_album(Library* library, char* album) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].album, album) == 0) {
            for (int j = i + 1; j < library->num_songs; j++) {
                library->songs[j - 1] = library->songs[j];
            }
            library->num_songs--;
            break;
        }
    }
}

// Main function
int main() {
    // Create a new library
    Library* library = create_library();

    // Add some songs to the library
    Song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 6};
    add_song(library, song1);
    Song song2 = {"Imagine", "John Lennon", "Imagine", 1971, 3};
    add_song(library, song2);
    Song song3 = {"Strawberry Fields Forever", "The Beatles", "Sgt. Pepper's Lonely Hearts Club Band", 1967, 4};
    add_song(library, song3);

    // Print the library
    printf("The library contains the following songs:\n");
    print_library(library);

    // Find a song by title
    Song* song = find_song_by_title(library, "Bohemian Rhapsody");
    if (song != NULL) {
        printf("Found the song %s by %s from the album %s (%d, %d minutes)\n", song->title, song->artist, song->album, song->year, song->length);
    } else {
        printf("Could not find the song Bohemian Rhapsody.\n");
    }

    // Delete a song by title
    delete_song_by_title(library, "Strawberry Fields Forever");

    // Print the library again
    printf("The library now contains the following songs:\n");
    print_library(library);

    // Free the memory allocated for the library
    free(library);

    return 0;
}