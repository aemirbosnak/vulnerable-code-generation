//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
    char *title;
    char *artist;
    int year;
    struct song *next;
} song;

song *add_song(song *head, char *title, char *artist, int year) {
    song *new_song = malloc(sizeof(song));
    new_song->title = strdup(title);
    new_song->artist = strdup(artist);
    new_song->year = year;
    new_song->next = head;
    return new_song;
}

void print_song(song *song) {
    printf("%s - %s (%d)\n", song->title, song->artist, song->year);
}

void print_library(song *head) {
    if (head == NULL) {
        printf("The library is empty.\n");
        return;
    }
    print_song(head);
    print_library(head->next);
}

song *find_song_by_title(song *head, char *title) {
    if (head == NULL) {
        return NULL;
    }
    if (strcmp(head->title, title) == 0) {
        return head;
    }
    return find_song_by_title(head->next, title);
}

song *find_song_by_artist(song *head, char *artist) {
    if (head == NULL) {
        return NULL;
    }
    if (strcmp(head->artist, artist) == 0) {
        return head;
    }
    return find_song_by_artist(head->next, artist);
}

song *find_song_by_year(song *head, int year) {
    if (head == NULL) {
        return NULL;
    }
    if (head->year == year) {
        return head;
    }
    return find_song_by_year(head->next, year);
}

song *delete_song(song *head, char *title) {
    if (head == NULL) {
        return NULL;
    }
    if (strcmp(head->title, title) == 0) {
        song *next_song = head->next;
        free(head->title);
        free(head->artist);
        free(head);
        return next_song;
    }
    head->next = delete_song(head->next, title);
    return head;
}

int main() {
    song *head = NULL;
    head = add_song(head, "Bohemian Rhapsody", "Queen", 1975);
    head = add_song(head, "Stairway to Heaven", "Led Zeppelin", 1971);
    head = add_song(head, "Hotel California", "The Eagles", 1976);
    head = add_song(head, "Imagine", "John Lennon", 1971);
    head = add_song(head, "My Heart Will Go On", "Celine Dion", 1997);

    print_library(head);

    song *song = find_song_by_title(head, "Bohemian Rhapsody");
    if (song != NULL) {
        printf("Found song: ");
        print_song(song);
    } else {
        printf("Song not found.\n");
    }

    head = delete_song(head, "Hotel California");
    print_library(head);

    return 0;
}