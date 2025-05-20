//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music track
typedef struct music_track {
    char *artist;
    char *title;
    int year;
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
void add_track(music_library *library, char *artist, char *title, int year) {
    // Allocate memory for the new track
    music_track *track = malloc(sizeof(music_track));

    // Set the artist, title, and year of the new track
    track->artist = strdup(artist);
    track->title = strdup(title);
    track->year = year;

    // Add the new track to the library
    library->tracks = realloc(library->tracks, (library->num_tracks + 1) * sizeof(music_track));
    library->tracks[library->num_tracks] = *track;
    library->num_tracks++;
}

// Print the music library
void print_library(music_library *library) {
    for (int i = 0; i < library->num_tracks; i++) {
        printf("%s - %s (%d)\n", library->tracks[i].artist, library->tracks[i].title, library->tracks[i].year);
    }
}

// Free the memory allocated for the music library
void free_library(music_library *library) {
    for (int i = 0; i < library->num_tracks; i++) {
        free(library->tracks[i].artist);
        free(library->tracks[i].title);
    }
    free(library->tracks);
    free(library);
}

// Main function
int main() {
    // Create a new music library
    music_library *library = create_library();

    // Add some tracks to the music library
    add_track(library, "The Beatles", "Hey Jude", 1968);
    add_track(library, "The Rolling Stones", "Satisfaction", 1965);
    add_track(library, "Bob Dylan", "Blowin' in the Wind", 1963);

    // Print the music library
    print_library(library);

    // Free the memory allocated for the music library
    free_library(library);

    return 0;
}