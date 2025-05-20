//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a music track
typedef struct track {
    char *title;
    char *artist;
    char *album;
    int year;
    int length;
} track;

// Structure to store the music library
typedef struct library {
    track *tracks;
    int num_tracks;
} library;

// Function to create a new music library
library *create_library() {
    library *lib = malloc(sizeof(library));
    lib->tracks = NULL;
    lib->num_tracks = 0;
    return lib;
}

// Function to add a new track to the music library
void add_track(library *lib, track *track) {
    lib->tracks = realloc(lib->tracks, (lib->num_tracks + 1) * sizeof(track));
    lib->tracks[lib->num_tracks++] = *track;
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

// Function to print the music library
void print_library(library *lib) {
    for (int i = 0; i < lib->num_tracks; i++) {
        printf("%s by %s from the album %s (%d) [%d seconds]\n", lib->tracks[i].title, lib->tracks[i].artist, lib->tracks[i].album, lib->tracks[i].year, lib->tracks[i].length);
    }
}

// Function to free the memory allocated for the music library
void free_library(library *lib) {
    for (int i = 0; i < lib->num_tracks; i++) {
        free(lib->tracks[i].title);
        free(lib->tracks[i].artist);
        free(lib->tracks[i].album);
    }
    free(lib->tracks);
    free(lib);
}

// Main function
int main() {
    // Create a new music library
    library *lib = create_library();

    // Add some tracks to the music library
    track track1 = { "The Turing Test", "Alan Turing", "The Turing Test", 2018, 180 };
    add_track(lib, &track1);
    track track2 = { "The Imitation Game", "Alan Turing", "The Imitation Game", 2014, 120 };
    add_track(lib, &track2);
    track track3 = { "The Man Who Knew Infinity", "Alan Turing", "The Man Who Knew Infinity", 2015, 150 };
    add_track(lib, &track3);

    // Print the music library
    print_library(lib);

    // Find a track in the music library by title
    track *track = find_track_by_title(lib, "The Turing Test");
    if (track != NULL) {
        printf("Found track: %s by %s from the album %s (%d) [%d seconds]\n", track->title, track->artist, track->album, track->year, track->length);
    } else {
        printf("Track not found.\n");
    }

    // Free the memory allocated for the music library
    free_library(lib);

    return 0;
}