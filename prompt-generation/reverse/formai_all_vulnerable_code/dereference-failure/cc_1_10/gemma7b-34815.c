//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a music track
typedef struct MusicTrack {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct MusicTrack* next;
} MusicTrack;

// Define a function to insert a new track into the music library
void insertTrack(MusicTrack** head) {
    MusicTrack* newTrack = (MusicTrack*)malloc(sizeof(MusicTrack));
    printf("Enter the title of the track: ");
    scanf("%s", newTrack->title);
    printf("Enter the artist of the track: ");
    scanf("%s", newTrack->artist);
    printf("Enter the genre of the track: ");
    scanf("%s", newTrack->genre);
    printf("Enter the year of the track: ");
    scanf("%d", &newTrack->year);
    newTrack->next = NULL;

    if (*head == NULL) {
        *head = newTrack;
    } else {
        (*head)->next = newTrack;
    }
}

// Define a function to search for a track in the music library
MusicTrack* searchTrack(MusicTrack* head, char* title) {
    MusicTrack* currentTrack = head;

    while (currentTrack) {
        if (strcmp(currentTrack->title, title) == 0) {
            return currentTrack;
        }
        currentTrack = currentTrack->next;
    }

    return NULL;
}

// Define a function to delete a track from the music library
void deleteTrack(MusicTrack** head, char* title) {
    MusicTrack* currentTrack = searchTrack(*head, title);

    if (currentTrack) {
        MusicTrack* previousTrack = NULL;

        if (currentTrack == *head) {
            *head = currentTrack->next;
        } else {
            previousTrack->next = currentTrack->next;
        }

        free(currentTrack);
    }
}

// Define a function to print the music library
void printLibrary(MusicTrack* head) {
    MusicTrack* currentTrack = head;

    while (currentTrack) {
        printf("%s by %s (%.2d) - %s\n", currentTrack->title, currentTrack->artist, currentTrack->year, currentTrack->genre);
        currentTrack = currentTrack->next;
    }
}

int main() {
    MusicTrack* musicLibrary = NULL;

    // Insert some tracks into the music library
    insertTrack(&musicLibrary);
    insertTrack(&musicLibrary);
    insertTrack(&musicLibrary);

    // Print the music library
    printLibrary(musicLibrary);

    // Search for a track in the music library
    MusicTrack* foundTrack = searchTrack(musicLibrary, "Track 2");

    // If the track was found, print its information
    if (foundTrack) {
        printf("Title: %s\n", foundTrack->title);
        printf("Artist: %s\n", foundTrack->artist);
        printf("Genre: %s\n", foundTrack->genre);
        printf("Year: %d\n", foundTrack->year);
    } else {
        printf("Track not found.\n");
    }

    // Delete a track from the music library
    deleteTrack(&musicLibrary, "Track 1");

    // Print the music library after deleting a track
    printLibrary(musicLibrary);

    return 0;
}