//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define TABLE_SIZE 5

typedef struct Song {
    char title[MAX_SIZE];
    char artist[MAX_SIZE];
    int duration;
    struct Song *next;
} Song;

Song *library[TABLE_SIZE];

void addSong(char title[], char artist[], int duration) {
    Song *newSong = (Song *) malloc(sizeof(Song));
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->duration = duration;
    newSong->next = NULL;

    int hashIndex = hashFunction(title, TABLE_SIZE);
    library[hashIndex] = newSong;
}

int hashFunction(char *str, int tableSize) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash = (hash * 31 + str[i]) % tableSize;
    }
    return hash;
}

void searchSong(char title[]) {
    int hashIndex = hashFunction(title, TABLE_SIZE);
    Song *current = library[hashIndex];

    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            printf("Song: %s by %s, Duration: %d minutes\n", current->title, current->artist, current->duration / 60);
            return;
        }
        current = current->next;
    }

    printf("Song not found\n");
}

void printLibrary() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("\nIndex %d:\n", i);
        Song *current = library[i];
        while (current != NULL) {
            printf("Title: %s, Artist: %s, Duration: %d minutes\n", current->title, current->artist, current->duration / 60);
            current = current->next;
        }
    }
}

int main() {
    addSong("Bohemian Rhapsody", "Queen", 567);
    addSong("Stairway to Heaven", "Led Zeppelin", 801);
    addSong("Smells Like Teen Spirit", "Nirvana", 251);
    addSong("Sweet Child O' Mine", "Guns N' Roses", 459);
    addSong("Back in Black", "AC/DC", 363);

    searchSong("Bohemian Rhapsody");
    printLibrary();

    return 0;
}