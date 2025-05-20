//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: modular
// C Music Library Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a music track
typedef struct track {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int length;
} track;

// Structure to store the music library
typedef struct library {
    int num_tracks;
    track *tracks;
} library;

// Function to create a new music library
library *create_library() {
    library *lib = malloc(sizeof(library));
    if (lib == NULL) {
        fprintf(stderr, "Error allocating memory for library\n");
        return NULL;
    }
    lib->num_tracks = 0;
    lib->tracks = NULL;
    return lib;
}

// Function to add a new track to the music library
void add_track(library *lib, track *track) {
    lib->tracks = realloc(lib->tracks, (lib->num_tracks + 1) * sizeof(track));
    if (lib->tracks == NULL) {
        fprintf(stderr, "Error reallocating memory for tracks\n");
        return;
    }
    lib->tracks[lib->num_tracks] = *track;
    lib->num_tracks++;
}

// Function to find a track in the music library by title
track *find_track_by_title(library *lib, char *title) {
    for (int i = 0; i < lib->num_tracks; i++) {
        if (strcmp(lib->tracks[i].title, title) == 0) {
            return &lib->tracks[i];
        }
    }
    return NULL;
}

// Function to find a track in the music library by artist
track *find_track_by_artist(library *lib, char *artist) {
    for (int i = 0; i < lib->num_tracks; i++) {
        if (strcmp(lib->tracks[i].artist, artist) == 0) {
            return &lib->tracks[i];
        }
    }
    return NULL;
}

// Function to find a track in the music library by album
track *find_track_by_album(library *lib, char *album) {
    for (int i = 0; i < lib->num_tracks; i++) {
        if (strcmp(lib->tracks[i].album, album) == 0) {
            return &lib->tracks[i];
        }
    }
    return NULL;
}

// Function to print the music library
void print_library(library *lib) {
    for (int i = 0; i < lib->num_tracks; i++) {
        printf("%s by %s from %s (%d, %d seconds)\n", lib->tracks[i].title, lib->tracks[i].artist, lib->tracks[i].album, lib->tracks[i].year, lib->tracks[i].length);
    }
}

// Function to free the memory allocated for the music library
void free_library(library *lib) {
    free(lib->tracks);
    free(lib);
}

// Main function
int main() {
    // Create a new music library
    library *lib = create_library();

    // Add some tracks to the music library
    track track1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 360};
    add_track(lib, &track1);
    track track2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 480};
    add_track(lib, &track2);
    track track3 = {"Hotel California", "Eagles", "Hotel California", 1976, 390};
    add_track(lib, &track3);

    // Print the music library
    print_library(lib);

    // Find a track in the music library by title
    track *track = find_track_by_title(lib, "Stairway to Heaven");
    if (track != NULL) {
        printf("Found track: %s by %s from %s (%d, %d seconds)\n", track->title, track->artist, track->album, track->year, track->length);
    } else {
        printf("Track not found\n");
    }

    // Free the memory allocated for the music library
    free_library(lib);

    return 0;
}