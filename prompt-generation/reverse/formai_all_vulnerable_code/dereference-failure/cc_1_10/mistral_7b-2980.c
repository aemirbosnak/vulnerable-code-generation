//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Song {
    char title[100];
    char artist[100];
    int play_count;
    struct Song *next;
} Song;

void add_song(Song **head, const char *title, const char *artist) {
    Song *new_song = (Song *) malloc(sizeof(Song));
    strcpy(new_song->title, title);
    strcpy(new_song->artist, artist);
    new_song->play_count = 0;
    new_song->next = *head;
    *head = new_song;
}

void print_library(Song *head) {
    Song *current = head;
    while (current != NULL) {
        printf("%s by %s - Play count: %d\n", current->title, current->artist, current->play_count);
        current = current->next;
    }
}

void play_song(Song **head, const char *title, const char *artist) {
    Song *current = *head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0 && strcmp(current->artist, artist) == 0) {
            current->play_count++;
            printf("Now playing: %s by %s\n", title, artist);
            return;
        }
        current = current->next;
    }
    printf("Song not found!\n");
}

int main() {
    Song *library = NULL;

    add_song(&library, "Bohemian Rhapsody", "Queen");
    add_song(&library, "Stairway to Heaven", "Led Zeppelin");
    add_song(&library, "Comfortably Numb", "Pink Floyd");

    printf("Initial library:\n");
    print_library(library);

    play_song(&library, "Bohemian Rhapsody", "Queen");
    play_song(&library, "Bohemian Rhapsody", "Queen");

    printf("\nUpdated library:\n");
    print_library(library);

    return 0;
}