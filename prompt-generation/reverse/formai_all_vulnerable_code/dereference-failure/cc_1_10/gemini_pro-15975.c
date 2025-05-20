//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    struct song *next;
};

struct song *head = NULL;

void add_song(char *title, char *artist, char *album, int year) {
    struct song *new_song = malloc(sizeof(struct song));
    strcpy(new_song->title, title);
    strcpy(new_song->artist, artist);
    strcpy(new_song->album, album);
    new_song->year = year;
    new_song->next = NULL;

    if (head == NULL) {
        head = new_song;
    } else {
        struct song *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_song;
    }
}

void print_songs() {
    struct song *current = head;
    while (current != NULL) {
        printf("%s by %s from the album %s (%d)\n", current->title, current->artist, current->album, current->year);
        current = current->next;
    }
}

void free_songs() {
    struct song *current = head;
    while (current != NULL) {
        struct song *next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    add_song("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975);
    add_song("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971);
    add_song("Hotel California", "Eagles", "Hotel California", 1976);
    add_song("Imagine", "John Lennon", "Imagine", 1971);
    add_song("Strawberry Fields Forever", "The Beatles", "Sgt. Pepper's Lonely Hearts Club Band", 1967);

    print_songs();

    free_songs();

    return 0;
}