//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of songs in the library
#define MAX_SONGS 100

// Define the song structure
typedef struct Song {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct Song* next;
} Song;

// Create a linked list of songs
Song* createSongList() {
    return NULL;
}

// Insert a song into the linked list
void insertSong(Song* head, Song* newSong) {
    if (head == NULL) {
        head = newSong;
    } else {
        newSong->next = head;
        head = newSong;
    }
}

// Search for a song in the linked list
Song* searchSong(Song* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Print the songs in the linked list
void printSongs(Song* head) {
    while (head) {
        printf("%s - %s (%d) | %s\n", head->title, head->artist, head->year, head->genre);
        head = head->next;
    }
}

int main() {
    // Create a linked list of songs
    Song* songList = createSongList();

    // Insert some songs into the list
    Song* newSong1 = malloc(sizeof(Song));
    strcpy(newSong1->title, "Bohemian Rhapsody");
    strcpy(newSong1->artist, "Queen");
    strcpy(newSong1->genre, "Rock");
    newSong1->year = 1975;
    insertSong(songList, newSong1);

    Song* newSong2 = malloc(sizeof(Song));
    strcpy(newSong2->title, "Like a Rolling Stone");
    strcpy(newSong2->artist, "The Rolling Stones");
    strcpy(newSong2->genre, "Rock");
    newSong2->year = 1965;
    insertSong(songList, newSong2);

    Song* newSong3 = malloc(sizeof(Song));
    strcpy(newSong3->title, "Stairway to Heaven");
    strcpy(newSong3->artist, "Led Zeppelin");
    strcpy(newSong3->genre, "Rock");
    newSong3->year = 1969;
    insertSong(songList, newSong3);

    // Search for a song in the list
    Song* foundSong = searchSong(songList, "Bohemian Rhapsody");

    // Print the found song
    if (foundSong) {
        printf("%s - %s (%d) | %s\n", foundSong->title, foundSong->artist, foundSong->year, foundSong->genre);
    } else {
        printf("Song not found.\n");
    }

    // Print all songs in the list
    printSongs(songList);

    return 0;
}