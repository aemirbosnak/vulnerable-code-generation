//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a music track
typedef struct track {
    char title[100];
    char artist[100];
    int duration;
    int genre;
} track;

// Function to add a new track to the library
void add_track(track *tracks, int num_tracks, track new_track) {
    tracks[num_tracks] = new_track;
    num_tracks++;
}

// Function to remove a track from the library
void remove_track(track *tracks, int num_tracks, int index) {
    for (int i = index; i < num_tracks - 1; i++) {
        tracks[i] = tracks[i + 1];
    }
    num_tracks--;
}

// Function to display the tracks in the library
void display_tracks(track *tracks, int num_tracks) {
    printf("Track\tArtist\tDuration\tGenre\n");
    for (int i = 0; i < num_tracks; i++) {
        printf("%s\t%s\t%d\t%d\n", tracks[i].title, tracks[i].artist, tracks[i].duration, tracks[i].genre);
    }
}

int main() {
    track tracks[100]; // Create an array of 100 tracks
    int num_tracks = 0; // Initialize the number of tracks to 0

    // Prompt the user to add tracks to the library
    printf("Add a track to the library:\n");
    while (1) {
        printf("Enter the track title: ");
        fgets(tracks[num_tracks].title, sizeof(tracks[num_tracks].title), stdin);
        if (tracks[num_tracks].title[0] == '\0') {
            break; // End of input
        }
        printf("Enter the artist name: ");
        fgets(tracks[num_tracks].artist, sizeof(tracks[num_tracks].artist), stdin);
        if (tracks[num_tracks].artist[0] == '\0') {
            break; // End of input
        }
        printf("Enter the track duration (in minutes): ");
        scanf("%d", &tracks[num_tracks].duration);
        if (tracks[num_tracks].duration <= 0) {
            printf("Invalid duration. Please enter a positive integer.\n");
            continue; // Try again
        }
        printf("Enter the track genre (1-10): ");
        scanf("%d", &tracks[num_tracks].genre);
        if (tracks[num_tracks].genre < 1 || tracks[num_tracks].genre > 10) {
            printf("Invalid genre. Please enter a number between 1 and 10.\n");
            continue; // Try again
        }
        num_tracks++; // Increment the number of tracks
    }

    // Display the tracks in the library
    display_tracks(tracks, num_tracks);

    // Prompt the user to remove a track from the library
    printf("Remove a track from the library:\n");
    while (1) {
        printf("Enter the index of the track to remove (0-based): ");
        scanf("%d", &index);
        if (index < 0 || index >= num_tracks) {
            printf("Invalid index. Please enter a number between 0 and %d.\n", num_tracks - 1);
            continue; // Try again
        }
        remove_track(tracks, num_tracks, index);
        display_tracks(tracks, num_tracks);
    }

    return 0;
}