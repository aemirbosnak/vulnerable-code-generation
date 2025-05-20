//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music library
struct music_library {
    char *name;
    int num_albums;
    struct album *albums;
};

// Define the structure of an album
struct album {
    char *name;
    int num_tracks;
    struct track *tracks;
};

// Define the structure of a track
struct track {
    char *name;
    int length;
};

// Create a new music library
struct music_library *create_music_library(char *name) {
    struct music_library *library = malloc(sizeof(struct music_library));
    library->name = strdup(name);
    library->num_albums = 0;
    library->albums = NULL;
    return library;
}

// Add an album to a music library
void add_album_to_library(struct music_library *library, struct album *album) {
    library->albums = realloc(library->albums, (library->num_albums + 1) * sizeof(struct album));
    library->albums[library->num_albums] = *album;
    library->num_albums++;
}

// Create a new album
struct album *create_album(char *name) {
    struct album *album = malloc(sizeof(struct album));
    album->name = strdup(name);
    album->num_tracks = 0;
    album->tracks = NULL;
    return album;
}

// Add a track to an album
void add_track_to_album(struct album *album, struct track *track) {
    album->tracks = realloc(album->tracks, (album->num_tracks + 1) * sizeof(struct track));
    album->tracks[album->num_tracks] = *track;
    album->num_tracks++;
}

// Create a new track
struct track *create_track(char *name, int length) {
    struct track *track = malloc(sizeof(struct track));
    track->name = strdup(name);
    track->length = length;
    return track;
}

// Print the music library
void print_music_library(struct music_library *library) {
    printf("Music library: %s\n", library->name);
    for (int i = 0; i < library->num_albums; i++) {
        struct album *album = &library->albums[i];
        printf("  Album: %s\n", album->name);
        for (int j = 0; j < album->num_tracks; j++) {
            struct track *track = &album->tracks[j];
            printf("    Track: %s (%d seconds)\n", track->name, track->length);
        }
    }
}

// Free the memory allocated for the music library
void free_music_library(struct music_library *library) {
    free(library->name);
    for (int i = 0; i < library->num_albums; i++) {
        struct album *album = &library->albums[i];
        free(album->name);
        for (int j = 0; j < album->num_tracks; j++) {
            struct track *track = &album->tracks[j];
            free(track->name);
        }
        free(album->tracks);
    }
    free(library->albums);
    free(library);
}

// Main function
int main() {
    // Create a new music library
    struct music_library *library = create_music_library("My Music Library");

    // Add some albums to the library
    struct album *album1 = create_album("Album 1");
    add_album_to_library(library, album1);
    struct album *album2 = create_album("Album 2");
    add_album_to_library(library, album2);

    // Add some tracks to the albums
    struct track *track1 = create_track("Track 1", 240);
    add_track_to_album(album1, track1);
    struct track *track2 = create_track("Track 2", 180);
    add_track_to_album(album1, track2);
    struct track *track3 = create_track("Track 3", 300);
    add_track_to_album(album2, track3);
    struct track *track4 = create_track("Track 4", 240);
    add_track_to_album(album2, track4);

    // Print the music library
    print_music_library(library);

    // Free the memory allocated for the music library
    free_music_library(library);

    return 0;
}