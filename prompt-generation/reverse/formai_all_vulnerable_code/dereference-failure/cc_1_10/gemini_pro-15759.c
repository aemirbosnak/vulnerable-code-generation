//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: futuristic
// Holographic Music Library Management System v1.0
// Copyright (C) 2098 Cyberspace Technologies

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music track
typedef struct {
    char *title;
    char *artist;
    char *album;
    int year;
    float duration;
} Track;

// Define the structure of the music library
typedef struct {
    Track *tracks;
    int num_tracks;
} Library;

// Create a new music library
Library *create_library() {
    Library *library = malloc(sizeof(Library));
    library->tracks = NULL;
    library->num_tracks = 0;
    return library;
}

// Add a new track to the music library
void add_track(Library *library, Track *track) {
    library->tracks = realloc(library->tracks, sizeof(Track) * (library->num_tracks + 1));
    library->tracks[library->num_tracks++] = *track;
}

// Search for a track in the music library by title
Track *search_by_title(Library *library, char *title) {
    for (int i = 0; i < library->num_tracks; i++) {
        if (strcmp(library->tracks[i].title, title) == 0) {
            return &library->tracks[i];
        }
    }
    return NULL;
}

// Search for a track in the music library by artist
Track *search_by_artist(Library *library, char *artist) {
    for (int i = 0; i < library->num_tracks; i++) {
        if (strcmp(library->tracks[i].artist, artist) == 0) {
            return &library->tracks[i];
        }
    }
    return NULL;
}

// Search for a track in the music library by album
Track *search_by_album(Library *library, char *album) {
    for (int i = 0; i < library->num_tracks; i++) {
        if (strcmp(library->tracks[i].album, album) == 0) {
            return &library->tracks[i];
        }
    }
    return NULL;
}

// Print the details of a track
void print_track(Track *track) {
    printf("Title: %s\n", track->title);
    printf("Artist: %s\n", track->artist);
    printf("Album: %s\n", track->album);
    printf("Year: %d\n", track->year);
    printf("Duration: %.2f minutes\n", track->duration);
}

// Print the details of all tracks in the music library
void print_library(Library *library) {
    for (int i = 0; i < library->num_tracks; i++) {
        print_track(&library->tracks[i]);
        printf("\n");
    }
}

// Free the memory allocated for a track
void free_track(Track *track) {
    free(track->title);
    free(track->artist);
    free(track->album);
    free(track);
}

// Free the memory allocated for the music library
void free_library(Library *library) {
    for (int i = 0; i < library->num_tracks; i++) {
        free_track(&library->tracks[i]);
    }
    free(library->tracks);
    free(library);
}

// Main function
int main() {
    // Create a new music library
    Library *library = create_library();

    // Add some tracks to the music library
    Track track1 = {"The Future", "Daft Punk", "Discovery", 2001, 6.45};
    add_track(library, &track1);
    Track track2 = {"One More Time", "Daft Punk", "Discovery", 2001, 5.21};
    add_track(library, &track2);
    Track track3 = {"Harder, Better, Faster, Stronger", "Daft Punk", "Discovery", 2001, 3.44};
    add_track(library, &track3);
    Track track4 = {"Aerodynamic", "Daft Punk", "Discovery", 2001, 7.01};
    add_track(library, &track4);

    // Print the details of all tracks in the music library
    printf("Music Library:\n");
    print_library(library);

    // Search for a track in the music library by title
    Track *track = search_by_title(library, "One More Time");
    if (track != NULL) {
        printf("\nTrack found:\n");
        print_track(track);
    } else {
        printf("\nTrack not found.\n");
    }

    // Free the memory allocated for the music library
    free_library(library);

    return 0;
}