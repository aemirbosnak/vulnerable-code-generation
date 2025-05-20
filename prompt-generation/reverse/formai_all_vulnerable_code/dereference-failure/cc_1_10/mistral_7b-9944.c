//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Song {
    char title[100];
    char artist[50];
    char album[50];
    int year;
    struct Song *next;
} Song;

void add_song(Song **head, char *title, char *artist, char *album, int year) {
    Song *new_song = (Song *) malloc(sizeof(Song));

    strcpy(new_song->title, title);
    strcpy(new_song->artist, artist);
    strcpy(new_song->album, album);
    new_song->year = year;
    new_song->next = *head;

    *head = new_song;
}

void display_library(Song *head) {
    Song *current = head;

    printf("\nCurrent Music Library:\n");
    printf("%-20s %-20s %-20s %d\n", "Title", "Artist", "Album", "Year");

    while (current != NULL) {
        printf("%-20s %-20s %-20s %d\n", current->title, current->artist, current->album, current->year);
        current = current->next;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [add|display]\n", argv[0]);
        return 1;
    }

    Song *library = NULL;

    if (strcmp(argv[1], "add") == 0) {
        if (argc < 6) {
            printf("Usage: %s add <title> <artist> <album> <year>\n", argv[0]);
            return 1;
        }

        add_song(&library, argv[2], argv[3], argv[4], atoi(argv[5]));
    } else if (strcmp(argv[1], "display") == 0) {
        display_library(library);
    } else {
        printf("Usage: %s [add|display]\n", argv[0]);
        return 1;
    }

    return 0;
}