//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music track
typedef struct music_track {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int duration; // in seconds
} music_track;

// Define the structure of a library
typedef struct library {
    music_track tracks[100];
    int num_tracks;
} library;

// Create a new library
library* create_library() {
    library* lib = malloc(sizeof(library));
    lib->num_tracks = 0;
    return lib;
}

// Add a track to the library
void add_track(library* lib, music_track track) {
    lib->tracks[lib->num_tracks] = track;
    lib->num_tracks++;
}

// Print the library
void print_library(library* lib) {
    for (int i = 0; i < lib->num_tracks; i++) {
        printf("%s - %s (%s, %d, %d seconds)\n",
            lib->tracks[i].title,
            lib->tracks[i].artist,
            lib->tracks[i].album,
            lib->tracks[i].year,
            lib->tracks[i].duration);
    }
}

// Search for a track in the library by title
int find_track_by_title(library* lib, char* title) {
    for (int i = 0; i < lib->num_tracks; i++) {
        if (strcmp(lib->tracks[i].title, title) == 0) {
            return i;
        }
    }
    return -1;
}

// Search for a track in the library by artist
int find_track_by_artist(library* lib, char* artist) {
    for (int i = 0; i < lib->num_tracks; i++) {
        if (strcmp(lib->tracks[i].artist, artist) == 0) {
            return i;
        }
    }
    return -1;
}

// Search for a track in the library by album
int find_track_by_album(library* lib, char* album) {
    for (int i = 0; i < lib->num_tracks; i++) {
        if (strcmp(lib->tracks[i].album, album) == 0) {
            return i;
        }
    }
    return -1;
}

// Delete a track from the library
void delete_track(library* lib, int index) {
    for (int i = index; i < lib->num_tracks - 1; i++) {
        lib->tracks[i] = lib->tracks[i + 1];
    }
    lib->num_tracks--;
}

// Main function
int main() {
    // Create a new library
    library* lib = create_library();

    // Add some tracks to the library
    music_track track1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 360};
    add_track(lib, track1);

    music_track track2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 480};
    add_track(lib, track2);

    music_track track3 = {"Hotel California", "Eagles", "Hotel California", 1976, 390};
    add_track(lib, track3);

    // Print the library
    printf("Initial library:\n");
    print_library(lib);

    // Search for a track by title
    int index = find_track_by_title(lib, "Stairway to Heaven");
    if (index != -1) {
        printf("Found track %s at index %d\n", lib->tracks[index].title, index);
    } else {
        printf("Track not found\n");
    }

    // Delete the track
    delete_track(lib, index);

    // Print the library
    printf("Library after deleting track:\n");
    print_library(lib);

    return 0;
}