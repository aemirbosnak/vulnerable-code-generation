//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define TABLE_SIZE 101

typedef struct Song {
    char title[100];
    char artist[50];
    char album[50];
    int year;
    struct Song *next;
} Song;

Song *table[TABLE_SIZE];

// Hash function to calculate index based on title
int hash(char *title) {
    int hash = 0;
    for (int i = 0; title[i] != '\0'; i++) {
        hash += tolower(title[i]);
    }
    return hash % TABLE_SIZE;
}

// Function to add a song to the library
void addSong(char *title, char *artist, char *album, int year) {
    int index = hash(title);
    Song *newSong = (Song *) malloc(sizeof(Song));
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    strcpy(newSong->album, album);
    newSong->year = year;
    newSong->next = table[index];
    table[index] = newSong;
}

// Function to search a song by title
Song *searchSong(char *title) {
    int index = hash(title);
    Song *current = table[index];
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete a song by title
void deleteSong(char *title) {
    int index = hash(title);
    Song *prev = NULL;
    Song *current = table[index];
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            if (prev == NULL) {
                table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    addSong("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975);
    addSong("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971);
    addSong("Back in Black", "AC/DC", "Back in Black", 1980);

    Song *song = searchSong("Bohemian Rhapsody");
    if (song != NULL) {
        printf("Found song:\nTitle: %s\nArtist: %s\nAlbum: %s\nYear: %d\n", song->title, song->artist, song->album, song->year);
    } else {
        printf("Song not found.\n");
    }

    deleteSong("Stairway to Heaven");

    return 0;
}