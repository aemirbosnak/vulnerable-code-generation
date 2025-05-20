//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char title[50];
    char artist[50];
    char genre[20];
    int year;
    float duration;
    struct Song *next;
} Song;

Song *head = NULL;

void addSong(char *title, char *artist, char *genre, int year, float duration) {
    Song *newSong = (Song *)malloc(sizeof(Song));
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    strcpy(newSong->genre, genre);
    newSong->year = year;
    newSong->duration = duration;
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
    Song *current = head, *prev = NULL;
    while (current != NULL && strcmp(current->title, title) != 0) {
        prev = current;
        current = current->next;
    }
    if (current == NULL)
        return;
    if (prev == NULL)
        head = current->next;
    else
        prev->next = current->next;
    free(current);
}

void printList() {
    Song *current = head;
    while (current != NULL) {
        printf("%s by %s (%d) - %s - %.2f minutes\n", current->title, current->artist, current->year, current->genre, current->duration);
        current = current->next;
    }
}

int main() {
    addSong("Bohemian Rhapsody", "Queen", "Rock", 1975, 5.59);
    addSong("Stairway to Heaven", "Led Zeppelin", "Hard Rock", 1971, 8.02);
    addSong("Imagine", "John Lennon", "Rock", 1971, 3.00);

    printList();

    Song *foundSong = searchSong("Stairway to Heaven");
    if (foundSong != NULL)
        printf("Found: %s by %s (%d)\n", foundSong->title, foundSong->artist, foundSong->year);

    deleteSong("Imagine");
    printList();

    return 0;
}