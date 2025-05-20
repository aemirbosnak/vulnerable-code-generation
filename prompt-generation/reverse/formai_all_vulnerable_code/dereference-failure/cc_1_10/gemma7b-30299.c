//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store information about a music track
typedef struct Track {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct Track* next;
} Track;

// Create a linked list of music tracks
Track* head = NULL;

// Function to add a track to the linked list
void addTrack(char* title, char* artist, char* genre, int year) {
    Track* newTrack = malloc(sizeof(Track));
    strcpy(newTrack->title, title);
    strcpy(newTrack->artist, artist);
    strcpy(newTrack->genre, genre);
    newTrack->year = year;
    newTrack->next = NULL;

    if (head == NULL) {
        head = newTrack;
    } else {
        Track* currentTrack = head;
        while (currentTrack->next != NULL) {
            currentTrack = currentTrack->next;
        }
        currentTrack->next = newTrack;
    }
}

// Function to search for a track by title
Track* searchTrackByTitle(char* title) {
    Track* currentTrack = head;
    while (currentTrack) {
        if (strcmp(currentTrack->title, title) == 0) {
            return currentTrack;
        }
        currentTrack = currentTrack->next;
    }
    return NULL;
}

// Function to search for a track by artist
Track* searchTrackByArtist(char* artist) {
    Track* currentTrack = head;
    while (currentTrack) {
        if (strcmp(currentTrack->artist, artist) == 0) {
            return currentTrack;
        }
        currentTrack = currentTrack->next;
    }
    return NULL;
}

// Function to search for a track by genre
Track* searchTrackByGenre(char* genre) {
    Track* currentTrack = head;
    while (currentTrack) {
        if (strcmp(currentTrack->genre, genre) == 0) {
            return currentTrack;
        }
        currentTrack = currentTrack->next;
    }
    return NULL;
}

// Function to print all tracks
void printTracks() {
    Track* currentTrack = head;
    while (currentTrack) {
        printf("%s by %s (%d) - %s\n", currentTrack->title, currentTrack->artist, currentTrack->year, currentTrack->genre);
        currentTrack = currentTrack->next;
    }
}

int main() {
    // Add some tracks to the linked list
    addTrack("The Sound of Silence", "Led Zeppelin", "Rock", 1969);
    addTrack("Another One Bites the Dust", "Queen", "Rock", 1975);
    addTrack("Stairway to Heaven", "Deep Purple", "Rock", 1968);
    addTrack("The Long and Winding Road", "The Doors", "Rock", 1967);

    // Search for a track by title
    Track* track = searchTrackByTitle("The Sound of Silence");
    if (track) {
        printf("Track: %s\n", track->title);
    }

    // Search for a track by artist
    track = searchTrackByArtist("Led Zeppelin");
    if (track) {
        printf("Track: %s\n", track->title);
    }

    // Search for a track by genre
    track = searchTrackByGenre("Rock");
    if (track) {
        printf("Track: %s\n", track->title);
    }

    // Print all tracks
    printTracks();

    return 0;
}