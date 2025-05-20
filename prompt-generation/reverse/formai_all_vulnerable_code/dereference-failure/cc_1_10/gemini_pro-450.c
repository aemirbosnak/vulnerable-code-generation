//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct to store the metadata of a music track
typedef struct music_track {
    char *title;
    char *artist;
    char *album; 
    int year;
    char *genre;
    int track_number;
    int duration; //in seconds
} music_track;

//Struct to store the library of music tracks
typedef struct music_library {
    music_track *tracks; //array of music tracks
    int num_tracks; //number of tracks in the library
} music_library;

//Function to create a new music library
music_library *create_library() {
    music_library *library = (music_library *) malloc(sizeof(music_library));
    library->tracks = NULL;
    library->num_tracks = 0;
    return library;
}

//Function to add a new track to the library
void add_track(music_library *library, music_track *track) {
    library->tracks = (music_track *) realloc(library->tracks, (library->num_tracks + 1) * sizeof(music_track));
    library->tracks[library->num_tracks] = *track;
    library->num_tracks++;
}

//Function to search for a track by title
music_track *search_track_by_title(music_library *library, char *title) {
    for (int i = 0; i < library->num_tracks; i++) {
        if (strcmp(library->tracks[i].title, title) == 0) {
            return &library->tracks[i];
        }
    }
    return NULL;
}

//Function to print the library
void print_library(music_library *library) {
    printf("Library: \n");
    for (int i = 0; i < library->num_tracks; i++) {
        printf("\tTitle: %s\n", library->tracks[i].title);
        printf("\tArtist: %s\n", library->tracks[i].artist);
        printf("\tAlbum: %s\n", library->tracks[i].album);
        printf("\tYear: %d\n", library->tracks[i].year);
        printf("\tGenre: %s\n", library->tracks[i].genre);
        printf("\tTrack number: %d\n", library->tracks[i].track_number);
        printf("\tDuration: %d seconds\n", library->tracks[i].duration);
        printf("\n");
    }
}

//Function to free the memory allocated for the library
void free_library(music_library *library) {
    for (int i = 0; i < library->num_tracks; i++) {
        free(library->tracks[i].title);
        free(library->tracks[i].artist);
        free(library->tracks[i].album);
        free(library->tracks[i].genre);
    }
    free(library->tracks);
    free(library);
}

//Main function
int main() {
    //Create a new music library
    music_library *library = create_library();

    //Add some tracks to the library
    music_track track1 = {"Running Up That Hill", "Kate Bush", "Hounds of Love", 1985, "Art Pop", 1, 240};
    add_track(library, &track1);
    music_track track2 = {"Dreams", "Fleetwood Mac", "Rumours", 1977, "Soft Rock", 2, 280};
    add_track(library, &track2);
    music_track track3 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, "Progressive Rock", 6, 350};
    add_track(library, &track3);

    //Print the library
    print_library(library);

    //Search for a track by title
    music_track *track = search_track_by_title(library, "Dreams");
    if (track != NULL) {
        printf("Found track: %s\n", track->title);
    } else {
        printf("Track not found.\n");
    }

    //Free the memory allocated for the library
    free_library(library);

    return 0;
}