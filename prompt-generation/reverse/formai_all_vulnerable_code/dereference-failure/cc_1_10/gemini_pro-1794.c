//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct music_library {
    char *title;
    char *artist;
    char *album;
    int year;
    int length;
    struct music_library *next;
};

struct music_library *add_song(struct music_library *head, char *title, char *artist, char *album, int year, int length) {
    struct music_library *new_song = malloc(sizeof(struct music_library));
    new_song->title = strdup(title);
    new_song->artist = strdup(artist);
    new_song->album = strdup(album);
    new_song->year = year;
    new_song->length = length;
    new_song->next = head;
    return new_song;
}

void print_library(struct music_library *head) {
    while (head != NULL) {
        printf("%s - %s (%s, %d, %d minutes)\n", head->title, head->artist, head->album, head->year, head->length);
        head = head->next;
    }
}

void free_library(struct music_library *head) {
    while (head != NULL) {
        struct music_library *next = head->next;
        free(head->title);
        free(head->artist);
        free(head->album);
        free(head);
        head = next;
    }
}

int main() {
    struct music_library *library = NULL;
    library = add_song(library, "Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 6);
    library = add_song(library, "Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 8);
    library = add_song(library, "Hey Jude", "The Beatles", "Hey Jude", 1968, 7);
    library = add_song(library, "Like a Rolling Stone", "Bob Dylan", "Highway 61 Revisited", 1965, 6);
    library = add_song(library, "Imagine", "John Lennon", "Imagine", 1971, 3);

    print_library(library);

    free_library(library);

    return 0;
}