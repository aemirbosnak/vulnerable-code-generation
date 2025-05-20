//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: automated
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Song {
    char title[50];
    char artist[50];
    int year;
    struct Song* next;
} Song;

Song* insertSong(Song* head, char* title, char* artist, int year) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->year = year;
    newSong->next = NULL;

    if (head == NULL) {
        head = newSong;
    } else {
        head->next = newSong;
    }

    return head;
}

Song* searchSong(Song* head, char* title, char* artist) {
    Song* currentSong = head;

    while (currentSong) {
        if (strcmp(currentSong->title, title) == 0 && strcmp(currentSong->artist, artist) == 0) {
            return currentSong;
        }

        currentSong = currentSong->next;
    }

    return NULL;
}

void updateSong(Song* song, char* title, char* artist, int year) {
    strcpy(song->title, title);
    strcpy(song->artist, artist);
    song->year = year;
}

void deleteSong(Song* head, char* title, char* artist) {
    Song* currentSong = head;
    Song* previousSong = NULL;

    while (currentSong) {
        if (strcmp(currentSong->title, title) == 0 && strcmp(currentSong->artist, artist) == 0) {
            if (previousSong) {
                previousSong->next = currentSong->next;
            } else {
                head = currentSong->next;
            }

            free(currentSong);
            return;
        }

        previousSong = currentSong;
        currentSong = currentSong->next;
    }

    return;
}

void listSongs(Song* head) {
    Song* currentSong = head;

    while (currentSong) {
        printf("%s - %s (%d)\n", currentSong->title, currentSong->artist, currentSong->year);
        currentSong = currentSong->next;
    }
}

int main() {
    Song* head = NULL;

    insertSong(head, "Blinding Me", "Taylor Swift", 2018);
    insertSong(head, "Watermelon Man", "Harry Styles", 2019);
    insertSong(head, "Someone Like You", "Adele", 2011);

    searchSong(head, "Blinding Me", "Taylor Swift") != NULL ? printf("Song found.\n") : printf("Song not found.\n");

    updateSong(searchSong(head, "Blinding Me", "Taylor Swift"), "Blinding Me", "Ed Sheeran", 2020);

    deleteSong(head, "Someone Like You", "Adele");

    listSongs(head);

    return 0;
}