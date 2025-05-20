//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music library
typedef struct music_library {
    char **songs;
    int num_songs;
    char **artists;
    int num_artists;
    char **albums;
    int num_albums;
    char **genres;
    int num_genres;
} music_library;

// Function to create a new music library
music_library *create_music_library() {
    music_library *library = malloc(sizeof(music_library));
    library->songs = NULL;
    library->num_songs = 0;
    library->artists = NULL;
    library->num_artists = 0;
    library->albums = NULL;
    library->num_albums = 0;
    library->genres = NULL;
    library->num_genres = 0;
    return library;
}

// Function to add a song to the music library
void add_song(music_library *library, char *song) {
    library->songs = realloc(library->songs, (library->num_songs + 1) * sizeof(char *));
    library->songs[library->num_songs++] = strdup(song);
}

// Function to add an artist to the music library
void add_artist(music_library *library, char *artist) {
    library->artists = realloc(library->artists, (library->num_artists + 1) * sizeof(char *));
    library->artists[library->num_artists++] = strdup(artist);
}

// Function to add an album to the music library
void add_album(music_library *library, char *album) {
    library->albums = realloc(library->albums, (library->num_albums + 1) * sizeof(char *));
    library->albums[library->num_albums++] = strdup(album);
}

// Function to add a genre to the music library
void add_genre(music_library *library, char *genre) {
    library->genres = realloc(library->genres, (library->num_genres + 1) * sizeof(char *));
    library->genres[library->num_genres++] = strdup(genre);
}

// Function to print the music library
void print_music_library(music_library *library) {
    printf("Songs:\n");
    for (int i = 0; i < library->num_songs; i++) {
        printf("    %s\n", library->songs[i]);
    }
    printf("Artists:\n");
    for (int i = 0; i < library->num_artists; i++) {
        printf("    %s\n", library->artists[i]);
    }
    printf("Albums:\n");
    for (int i = 0; i < library->num_albums; i++) {
        printf("    %s\n", library->albums[i]);
    }
    printf("Genres:\n");
    for (int i = 0; i < library->num_genres; i++) {
        printf("    %s\n", library->genres[i]);
    }
}

// Function to free the memory allocated for the music library
void free_music_library(music_library *library) {
    for (int i = 0; i < library->num_songs; i++) {
        free(library->songs[i]);
    }
    free(library->songs);
    for (int i = 0; i < library->num_artists; i++) {
        free(library->artists[i]);
    }
    free(library->artists);
    for (int i = 0; i < library->num_albums; i++) {
        free(library->albums[i]);
    }
    free(library->albums);
    for (int i = 0; i < library->num_genres; i++) {
        free(library->genres[i]);
    }
    free(library->genres);
    free(library);
}

// Main function
int main() {
    // Create a new music library
    music_library *library = create_music_library();

    // Add some songs to the music library
    add_song(library, "Song 1");
    add_song(library, "Song 2");
    add_song(library, "Song 3");

    // Add some artists to the music library
    add_artist(library, "Artist 1");
    add_artist(library, "Artist 2");
    add_artist(library, "Artist 3");

    // Add some albums to the music library
    add_album(library, "Album 1");
    add_album(library, "Album 2");
    add_album(library, "Album 3");

    // Add some genres to the music library
    add_genre(library, "Genre 1");
    add_genre(library, "Genre 2");
    add_genre(library, "Genre 3");

    // Print the music library
    print_music_library(library);

    // Free the memory allocated for the music library
    free_music_library(library);

    return 0;
}