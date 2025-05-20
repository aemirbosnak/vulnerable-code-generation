//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct music {
    char *title;
    char *artist;
    char *album;
    int year;
    struct music *next;
} music_t;

music_t *head = NULL;

void add_music(char *title, char *artist, char *album, int year) {
    music_t *new_music = malloc(sizeof(music_t));
    new_music->title = strdup(title);
    new_music->artist = strdup(artist);
    new_music->album = strdup(album);
    new_music->year = year;
    new_music->next = NULL;

    if (head == NULL) {
        head = new_music;
    } else {
        music_t *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_music;
    }
}

void print_music() {
    music_t *current = head;
    while (current != NULL) {
        printf("%s %s %s %d\n", current->title, current->artist, current->album, current->year);
        current = current->next;
    }
}

void delete_music(char *title) {
    if (head == NULL) {
        return;
    }

    if (strcmp(head->title, title) == 0) {
        head = head->next;
        return;
    }

    music_t *current = head;
    while (current->next != NULL) {
        if (strcmp(current->next->title, title) == 0) {
            music_t *temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}

int main() {
    add_music("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975);
    add_music("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971);
    add_music("Hotel California", "Eagles", "Hotel California", 1976);
    add_music("Imagine", "John Lennon", "Imagine", 1971);
    add_music("Smells Like Teen Spirit", "Nirvana", "Nevermind", 1991);

    print_music();

    delete_music("Bohemian Rhapsody");

    print_music();

    return 0;
}