//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int track;
    struct song *next;
} song;

song *head = NULL;

void add_song(char *title, char *artist, char *album, int year, int track) {
    song *new_song = (song *)malloc(sizeof(song));
    strcpy(new_song->title, title);
    strcpy(new_song->artist, artist);
    strcpy(new_song->album, album);
    new_song->year = year;
    new_song->track = track;
    new_song->next = head;
    head = new_song;
}

void print_songs() {
    song *current = head;
    while (current != NULL) {
        printf("%s - %s - %s - %d - %d\n", current->title, current->artist, current->album, current->year, current->track);
        current = current->next;
    }
}

void delete_song(char *title) {
    song *current = head;
    song *previous = NULL;

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

int main() {
    add_song("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1);
    add_song("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 4);
    add_song("Hotel California", "Eagles", "Hotel California", 1976, 3);
    add_song("Smells Like Teen Spirit", "Nirvana", "Nevermind", 1991, 1);
    add_song("Imagine", "John Lennon", "Imagine", 1971, 3);

    print_songs();

    delete_song("Hotel California");

    print_songs();

    return 0;
}