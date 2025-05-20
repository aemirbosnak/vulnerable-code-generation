//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a single music track
typedef struct music_track{
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int track_number;
} music_track;

// Structure to store the entire music library
typedef struct music_library{
    int num_tracks;
    music_track *tracks;
} music_library;

// Function to create a new music library
music_library *create_music_library(){
    music_library *library = (music_library *)malloc(sizeof(music_library));
    library->num_tracks = 0;
    library->tracks = NULL;
    return library;
}

// Function to add a new music track to the library
void add_music_track(music_library *library, char *title, char *artist, char *album, int year, int track_number){
    // Allocate memory for the new track
    music_track *new_track = (music_track *)malloc(sizeof(music_track));

    // Copy the track information into the new track
    strcpy(new_track->title, title);
    strcpy(new_track->artist, artist);
    strcpy(new_track->album, album);
    new_track->year = year;
    new_track->track_number = track_number;

    // Increment the number of tracks in the library
    library->num_tracks++;

    // Reallocate memory for the tracks array to include the new track
    library->tracks = (music_track *)realloc(library->tracks, library->num_tracks * sizeof(music_track));

    // Add the new track to the tracks array
    library->tracks[library->num_tracks - 1] = *new_track;

    // Free the memory allocated for the new track
    free(new_track);
}

// Function to print the music library
void print_music_library(music_library *library){
    for(int i = 0; i < library->num_tracks; i++){
        printf("%s by %s from the album %s (%d)\n", library->tracks[i].title, library->tracks[i].artist, library->tracks[i].album, library->tracks[i].year);
    }
}

// Function to free the memory allocated for the music library
void free_music_library(music_library *library){
    // Free the memory allocated for the tracks array
    free(library->tracks);

    // Free the memory allocated for the library
    free(library);
}

// Main function
int main(){
    // Create a new music library
    music_library *library = create_music_library();

    // Add some music tracks to the library
    add_music_track(library, "Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1);
    add_music_track(library, "Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 4);
    add_music_track(library, "Hotel California", "Eagles", "Hotel California", 1976, 3);
    add_music_track(library, "Smells Like Teen Spirit", "Nirvana", "Nevermind", 1991, 1);

    // Print the music library
    print_music_library(library);

    // Free the memory allocated for the music library
    free_music_library(library);

    return 0;
}