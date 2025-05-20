//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct music_track {
    char *title;
    char *artist;
    int year;
    struct music_track *next;
} music_track;

music_track *library = NULL;

void add_track(char *title, char *artist, int year) {
    music_track *new_track = malloc(sizeof(music_track));
    new_track->title = malloc(strlen(title) + 1);
    strcpy(new_track->title, title);
    new_track->artist = malloc(strlen(artist) + 1);
    strcpy(new_track->artist, artist);
    new_track->year = year;
    new_track->next = NULL;

    if (library == NULL) {
        library = new_track;
    } else {
        music_track *current = library;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_track;
    }
}

void print_library() {
    music_track *current = library;
    while (current != NULL) {
        printf("%s by %s (%d)\n", current->title, current->artist, current->year);
        current = current->next;
    }
}

int main() {
    add_track("Bohemian Rhapsody", "Queen", 1975);
    add_track("Stairway to Heaven", "Led Zeppelin", 1971);
    add_track("Hotel California", "Eagles", 1976);
    add_track("Imagine", "John Lennon", 1971);
    add_track("Strawberry Fields Forever", "The Beatles", 1967);

    print_library();

    return 0;
}