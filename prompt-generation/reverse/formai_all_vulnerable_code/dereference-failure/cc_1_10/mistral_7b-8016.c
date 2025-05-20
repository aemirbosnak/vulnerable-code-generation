//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char title[100];
    char artist[100];
    char album[100];
    int length;
    struct Song *next;
} Song;

Song *head = NULL;

void addSong(char *title, char *artist, char *album, int length) {
    Song *newSong = (Song *) malloc(sizeof(Song));
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    strcpy(newSong->album, album);
    newSong->length = length;
    newSong->next = head;
    head = newSong;
}

Song *searchSong(char *title) {
    Song *current = head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}

void deleteSong(char *title) {
    Song *current = head;
    Song *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void printLibrary() {
    Song *current = head;
    while (current != NULL) {
        printf("%s by %s (%s) - %d seconds\n", current->title, current->artist, current->album, current->length);
        current = current->next;
    }
}

int main() {
    addSong("Bohemian Rhapsody", "Queen", "A Night at the Opera", 551);
    addSong("Another One Bites the Dust", "Queen", "Queen II", 295);
    addSong("We Will Rock You", "Queen", "News of the World", 201);

    printLibrary();

    Song *song = searchSong("Another One Bites the Dust");
    if (song != NULL) {
        printf("Found song: %s by %s (%s) - %d seconds\n", song->title, song->artist, song->album, song->length);
    } else {
        printf("Song not found\n");
    }

    deleteSong("Another One Bites the Dust");
    printLibrary();

    return 0;
}