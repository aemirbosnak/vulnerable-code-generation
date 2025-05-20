//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a music library
struct MusicLibrary {
    char name[50];
    int num_albums;
    struct Album *albums;
};

// Structure to represent an album
struct Album {
    char name[50];
    int num_tracks;
    struct Track *tracks;
};

// Structure to represent a track
struct Track {
    char name[50];
    int duration;
};

// Function to create a new music library
struct MusicLibrary *create_music_library(char *name) {
    struct MusicLibrary *library = (struct MusicLibrary *)malloc(sizeof(struct MusicLibrary));
    strcpy(library->name, name);
    library->num_albums = 0;
    library->albums = NULL;
    return library;
}

// Function to add an album to a music library
void add_album(struct MusicLibrary *library, struct Album *album) {
    library->albums = (struct Album *)realloc(library->albums, (library->num_albums + 1) * sizeof(struct Album));
    library->albums[library->num_albums] = *album;
    library->num_albums++;
}

// Function to create a new album
struct Album *create_album(char *name) {
    struct Album *album = (struct Album *)malloc(sizeof(struct Album));
    strcpy(album->name, name);
    album->num_tracks = 0;
    album->tracks = NULL;
    return album;
}

// Function to add a track to an album
void add_track(struct Album *album, struct Track *track) {
    album->tracks = (struct Track *)realloc(album->tracks, (album->num_tracks + 1) * sizeof(struct Track));
    album->tracks[album->num_tracks] = *track;
    album->num_tracks++;
}

// Function to create a new track
struct Track *create_track(char *name, int duration) {
    struct Track *track = (struct Track *)malloc(sizeof(struct Track));
    strcpy(track->name, name);
    track->duration = duration;
    return track;
}

// Function to print the details of a music library
void print_music_library(struct MusicLibrary *library) {
    printf("Music Library: %s\n", library->name);
    for (int i = 0; i < library->num_albums; i++) {
        printf("  Album: %s\n", library->albums[i].name);
        for (int j = 0; j < library->albums[i].num_tracks; j++) {
            printf("    Track: %s (%d seconds)\n", library->albums[i].tracks[j].name, library->albums[i].tracks[j].duration);
        }
    }
}

// Main function
int main() {
    // Create a new music library
    struct MusicLibrary *library = create_music_library("My Music Library");

    // Add some albums to the library
    struct Album *album1 = create_album("Album 1");
    add_album(library, album1);

    struct Album *album2 = create_album("Album 2");
    add_album(library, album2);

    // Add some tracks to the albums
    struct Track *track1 = create_track("Track 1", 180);
    add_track(album1, track1);

    struct Track *track2 = create_track("Track 2", 240);
    add_track(album1, track2);

    struct Track *track3 = create_track("Track 3", 300);
    add_track(album2, track3);

    struct Track *track4 = create_track("Track 4", 240);
    add_track(album2, track4);

    // Print the details of the music library
    print_music_library(library);

    return 0;
}