//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store information about a music track
typedef struct MusicTrack {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct MusicTrack* next;
} MusicTrack;

// Function to insert a new music track at the end
void insertMusicTrack(MusicTrack** head) {
    MusicTrack* newTrack = (MusicTrack*)malloc(sizeof(MusicTrack));
    printf("Enter the title of the music track: ");
    scanf("%s", newTrack->title);
    printf("Enter the artist of the music track: ");
    scanf("%s", newTrack->artist);
    printf("Enter the genre of the music track: ");
    scanf("%s", newTrack->genre);
    printf("Enter the year of the music track: ");
    scanf("%d", &newTrack->year);

    if (*head == NULL) {
        *head = newTrack;
    } else {
        (*head)->next = newTrack;
    }
    *head = newTrack;
}

// Function to print all music tracks
void printMusicTracks(MusicTrack* head) {
    MusicTrack* currentTrack = head;
    while (currentTrack) {
        printf("%s - %s (%s, %d)\n", currentTrack->title, currentTrack->artist, currentTrack->genre, currentTrack->year);
        currentTrack = currentTrack->next;
    }
}

// Function to search for a music track by title
MusicTrack* searchMusicTrackByTitle(MusicTrack* head, char* title) {
    MusicTrack* currentTrack = head;
    while (currentTrack) {
        if (strcmp(currentTrack->title, title) == 0) {
            return currentTrack;
        }
        currentTrack = currentTrack->next;
    }
    return NULL;
}

int main() {
    MusicTrack* head = NULL;
    insertMusicTrack(&head);
    insertMusicTrack(&head);
    insertMusicTrack(&head);
    printMusicTracks(head);
    MusicTrack* track = searchMusicTrackByTitle(head, "Track 2");
    if (track) {
        printf("Found track: %s - %s (%s, %d)\n", track->title, track->artist, track->genre, track->year);
    } else {
        printf("Track not found.\n");
    }
    return 0;
}