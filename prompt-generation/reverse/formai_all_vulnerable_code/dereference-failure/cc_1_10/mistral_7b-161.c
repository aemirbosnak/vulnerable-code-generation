//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

struct Song {
    char title[MAX_SIZE];
    char artist[MAX_SIZE];
    char album[MAX_SIZE];
    char genre[MAX_SIZE];
    int duration;
    struct Song *next;
};

struct Library {
    struct Song *head;
};

void addSong(struct Library *library, char *title, char *artist, char *album, char *genre, int duration) {
    struct Song *newSong = (struct Song *) malloc(sizeof(struct Song));

    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    strcpy(newSong->album, album);
    strcpy(newSong->genre, genre);
    newSong->duration = duration;
    newSong->next = library->head;

    library->head = newSong;
}

void displayLibrary(struct Library *library) {
    struct Song *currentSong = library->head;

    printf("\nCurrent songs in the library:\n");
    printf("-------------------------------\n");

    while (currentSong != NULL) {
        printf("%s by %s (%s) - Genre: %s, Duration: %d seconds\n", currentSong->title, currentSong->artist, currentSong->album, currentSong->genre, currentSong->duration);
        currentSong = currentSong->next;
    }
}

int main() {
    struct Library library;
    library.head = NULL;

    addSong(&library, "Bohemian Rhapsody", "Queen", "A Night at the Opera", "Rock", 551);
    addSong(&library, "Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", "Classic Rock", 802);
    addSong(&library, "Smells Like Teen Spirit", "Nirvana", "Nevermind", "Grunge", 201);

    displayLibrary(&library);

    return 0;
}