//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music track
typedef struct music_track {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int duration;
} music_track;

// Define the structure of a music library
typedef struct music_library {
    int num_tracks;
    music_track *tracks;
} music_library;

// Create a new music library
music_library *create_library() {
    music_library *library = malloc(sizeof(music_library));
    library->num_tracks = 0;
    library->tracks = NULL;
    return library;
}

// Add a new track to the music library
void add_track(music_library *library, music_track *track) {
    library->num_tracks++;
    library->tracks = realloc(library->tracks, library->num_tracks * sizeof(music_track));
    library->tracks[library->num_tracks - 1] = *track;
}

// Print the tracks in the music library
void print_library(music_library *library) {
    for (int i = 0; i < library->num_tracks; i++) {
        printf("%s - %s (%s, %d, %d)\n", library->tracks[i].title, library->tracks[i].artist, library->tracks[i].album, library->tracks[i].year, library->tracks[i].duration);
    }
}

// Free the memory allocated for the music library
void free_library(music_library *library) {
    free(library->tracks);
    free(library);
}

// Main function
int main() {
    // Create a new music library
    music_library *library = create_library();

    // Add some tracks to the music library
    music_track track1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 360};
    add_track(library, &track1);
    music_track track2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 480};
    add_track(library, &track2);
    music_track track3 = {"Smells Like Teen Spirit", "Nirvana", "Nevermind", 1991, 300};
    add_track(library, &track3);

    // Print the tracks in the music library
    print_library(library);

    // Free the memory allocated for the music library
    free_library(library);

    return 0;
}