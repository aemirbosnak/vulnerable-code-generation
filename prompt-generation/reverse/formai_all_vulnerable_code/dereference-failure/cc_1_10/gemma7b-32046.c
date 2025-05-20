//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Define the number of songs in the library
#define NUM_SONGS 10

// Define the structure of a song
typedef struct Song {
    char title[50];
    char artist[50];
    int year;
    struct Song* next;
} Song;

// Create a linked list of songs
Song* head = NULL;

// Function to add a song to the library
void addSong(char* title, char* artist, int year) {
    // Allocate memory for a new song
    Song* newSong = (Song*)malloc(sizeof(Song));

    // Copy the song title, artist, and year into the new song
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->year = year;

    // If the library is empty, make the new song the first song
    if (head == NULL) {
        head = newSong;
    } else {
        // Traverse the library until the last song is reached
        Song* lastSong = head;
        while (lastSong->next != NULL) {
            lastSong = lastSong->next;
        }

        // Add the new song to the last song's next pointer
        lastSong->next = newSong;
    }
}

// Function to search for a song in the library
Song* searchSong(char* title) {
    // Traverse the library to find the song
    Song* song = head;
    while (song != NULL) {
        if (strcmp(song->title, title) == 0) {
            return song;
        }
        song = song->next;
    }

    // Return NULL if the song is not found
    return NULL;
}

// Function to print the library
void printLibrary() {
    // Traverse the library and print each song
    Song* song = head;
    while (song != NULL) {
        printf("%s - %s (%d)\n", song->title, song->artist, song->year);
        song = song->next;
    }
}

int main() {
    // Add some songs to the library
    addSong("Song 1", "Artist 1", 2020);
    addSong("Song 2", "Artist 2", 2021);
    addSong("Song 3", "Artist 3", 2022);

    // Search for a song in the library
    Song* song = searchSong("Song 2");
    if (song != NULL) {
        printf("Found song: %s - %s (%d)\n", song->title, song->artist, song->year);
    } else {
        printf("Song not found.\n");
    }

    // Print the library
    printLibrary();

    return 0;
}