//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Define the number of music tracks
#define MAX_TRACKS 10

// Define the structure of a music track
typedef struct MusicTrack {
    char title[50];
    char artist[50];
    char genre[50];
    int trackNumber;
    struct MusicTrack* nextTrack;
} MusicTrack;

// Create a linked list of music tracks
MusicTrack* head = NULL;

// Function to insert a new music track at the end
void insertTrack(char* title, char* artist, char* genre, int trackNumber) {
    MusicTrack* newTrack = (MusicTrack*)malloc(sizeof(MusicTrack));
    strcpy(newTrack->title, title);
    strcpy(newTrack->artist, artist);
    strcpy(newTrack->genre, genre);
    newTrack->trackNumber = trackNumber;
    newTrack->nextTrack = NULL;

    if (head == NULL) {
        head = newTrack;
    } else {
        MusicTrack* currentTrack = head;
        while (currentTrack->nextTrack) {
            currentTrack = currentTrack->nextTrack;
        }
        currentTrack->nextTrack = newTrack;
    }
}

// Function to search for a music track
MusicTrack* searchTrack(char* title) {
    MusicTrack* currentTrack = head;
    while (currentTrack) {
        if (strcmp(currentTrack->title, title) == 0) {
            return currentTrack;
        }
        currentTrack = currentTrack->nextTrack;
    }
    return NULL;
}

// Function to delete a music track
void deleteTrack(char* title) {
    MusicTrack* currentTrack = head;
    MusicTrack* previousTrack = NULL;
    while (currentTrack) {
        if (strcmp(currentTrack->title, title) == 0) {
            if (previousTrack) {
                previousTrack->nextTrack = currentTrack->nextTrack;
            } else {
                head = currentTrack->nextTrack;
            }
            free(currentTrack);
            return;
        }
        previousTrack = currentTrack;
        currentTrack = currentTrack->nextTrack;
    }
    return;
}

// Main function
int main() {
    // Insert some music tracks
    insertTrack("Bohemian Rhapsody", "Queen", "Rock", 1);
    insertTrack("Stairway to Heaven", "Led Zeppelin", "Rock", 2);
    insertTrack("Another One Bites the Dust", "Queen", "Rock", 3);
    insertTrack("Rock and Roll Hall of Fame", "Bruce Springsteen", "Rock", 4);
    insertTrack("The Final Countdown", "The Who", "Rock", 5);

    // Search for a music track
    MusicTrack* track = searchTrack("Bohemian Rhapsody");
    if (track) {
        printf("Title: %s\n", track->title);
        printf("Artist: %s\n", track->artist);
        printf("Genre: %s\n", track->genre);
        printf("Track Number: %d\n", track->trackNumber);
    } else {
        printf("Track not found.\n");
    }

    // Delete a music track
    deleteTrack("Stairway to Heaven");

    // Search for the track again
    track = searchTrack("Stairway to Heaven");
    if (track) {
        printf("Title: %s\n", track->title);
        printf("Artist: %s\n", track->artist);
        printf("Genre: %s\n", track->genre);
        printf("Track Number: %d\n", track->trackNumber);
    } else {
        printf("Track not found.\n");
    }

    return 0;
}